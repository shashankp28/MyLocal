from fastapi import FastAPI, Response, Query
from fastapi.middleware.cors import CORSMiddleware
from fastapi.responses import FileResponse
from fastapi.staticfiles import StaticFiles
from pathlib import Path
from typing import List
from PIL import Image
import io
import urllib.parse


app = FastAPI()

# ✅ Mount the static folder (for frontend)
app.mount("/static", StaticFiles(directory="static"), name="static")

# ✅ Serve index.html at root


@app.get("/", response_class=FileResponse)
def serve_index():
    return FileResponse("static/index.html")


# ✅ Enable CORS for JS frontend access
app.add_middleware(
    CORSMiddleware,
    allow_origins=['*'],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# ✅ Configure folders containing images
PHOTO_DIRS = [
    Path("/media/mystic/D3B3-9B4C/Reception"),
    Path("/media/mystic/D3B3-9B4C/weddding candid"),
    Path("/media/mystic/D3B3-9B4C/WEdding Function"),
    Path("/media/mystic/D3B3-9B4C/Pooje"),
]


def is_path_allowed(requested_path: Path) -> bool:
    try:
        requested_path = requested_path.resolve()
        for base_dir in PHOTO_DIRS:
            if base_dir.resolve() in requested_path.parents:
                return True
        return False
    except Exception:
        return False


# ✅ Return all image file paths from the configured folders


@app.get("/images", response_model=List[str])
def list_images():
    image_paths = []
    for folder in PHOTO_DIRS:
        for path in folder.rglob("*"):
            if path.is_file() and path.suffix.lower() in [".jpg", ".jpeg"]:
                image_paths.append(str(path.resolve()))
    return sorted(image_paths)

# ✅ Return a compressed version of the image


@app.get("/image")
def get_compressed_image(path: str = Query(..., description="Full Linux file path (URL encoded)")):
    decoded_path = urllib.parse.unquote(path)
    img_path = Path(decoded_path)

    if not img_path.exists() or not img_path.is_file() or not is_path_allowed(img_path):
        return Response(status_code=404, content="Image not found")

    try:
        image = Image.open(img_path)
        image.thumbnail((500, 500))
        buf = io.BytesIO()
        image.save(buf, format="JPEG", quality=80)
        buf.seek(0)
        return Response(content=buf.getvalue(), media_type="image/jpeg")
    except Exception as e:
        return Response(status_code=500, content=f"Error processing image: {e}")

# ✅ Return full-resolution image for download


@app.get("/image/download")
def get_full_image(path: str = Query(..., description="Full Linux file path (URL encoded)")):
    decoded_path = urllib.parse.unquote(path)
    img_path = Path(decoded_path)

    if not img_path.exists() or not img_path.is_file() or not is_path_allowed(img_path):
        return Response(status_code=404, content="Image not found")

    return FileResponse(
        path=img_path,
        media_type="image/jpeg",
        filename=img_path.name,
        headers={"Content-Disposition": f"attachment; filename={img_path.name}"}
    )
