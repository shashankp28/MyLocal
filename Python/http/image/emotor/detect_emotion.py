from pymongo import MongoClient
import io
from PIL import Image as im
client = MongoClient("mongodb+srv://shashankp28:229971@cluster0.iy0bw.mongodb.net/?retryWrites=true&w=majority")
db = client.database
images = db.images
def detect_emotion(image):
    image = im.fromarray(image)
    image_bytes = io.BytesIO()
    image.save(image_bytes, format='JPEG')
    image = {'data': image_bytes.getvalue()}
    image_id = images.insert_one(image).inserted_id
    return ([(60, 60, 120, 120)], [[0.5, 0.5, 0.9, 0.5, 0.5, 0.5, 0.5]])

