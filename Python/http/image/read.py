from pymongo import MongoClient
from PIL import Image
import io
import matplotlib.pyplot as plt
from tqdm import tqdm

client = MongoClient("mongodb+srv://shashankp28:229971@cluster0.iy0bw.mongodb.net/test")
db = client.database
images = db.images
images = list(images.find({}))
i = 0
pb = tqdm(total=len(images))
for image in images:
    pb.update(n=1)
    pil_img = Image.open(io.BytesIO(image['data']))
    plt.imshow(pil_img)
    plt.savefig("images/image"+str(i)+".png")
    i+=1