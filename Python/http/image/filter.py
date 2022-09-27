import cv2
import os
import matplotlib.pyplot as plt
from tqdm import tqdm
import numpy as np
pwd = os.getcwd()
lis = os.listdir(pwd+"/"+"images")
i=0
pb = tqdm(total=len(lis))
print(lis)
for wd in lis:
    pb.update(n=1)
    image = cv2.imread(pwd+"/images/image"+str(i)+".png")
    im2 = image.copy()
    plt.imshow(im2)
    plt.savefig("images_f/image"+str(i)+".png")
    i+=1