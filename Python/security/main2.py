from urllib.request import Request
from fastapi import FastAPI, Request
from passlib.hash import scrypt

app = FastAPI()

@app.get("/hash")
def generate(password: str, s: int, r: int, b: int, p: int):
    h = scrypt.using(salt_size=s, rounds=r, block_size=b, parallelism=p).hash(password)
    return {"result": h}

@app.get("/verify")
def verify(password: str, hash: str):
    verified = scrypt.verify(password, hash)
    return {"result": str(verified)}

@app.get("/")
def home(req: Request):
    return {"Your IP": req.client.host}