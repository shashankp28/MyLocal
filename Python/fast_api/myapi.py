from fastapi import FastAPI
app = FastAPI()

@app.get("/")
def my_func():
    return {"Hi": "Hello"}