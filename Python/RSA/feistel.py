"""
Module has a class to implement Feistel cipher
"""
import random
from PIL import Image
import numpy as np
from tqdm import tqdm
random.seed(10)


class Feistel:

    """
    Feistel cipher implementation
    """

    def __init__(self, hash_func, key: list[int], stages: int):
        assert len(
            key) % stages == 0, "Key length must be divisible by number of stages"
        self.hash_func = hash_func
        self.key = key
        self.keys = [np.array(key[i:i+len(key)//stages])
                     for i in range(0, len(key), len(key)//stages)]
        self.stages = stages

    def partial_key_length(self):
        """
        Returns partial key for a particular stage
        """
        return len(self.key)//self.stages

    def run(self, data: list[int], encrypt: bool = True, nonce: list[int] = None):
        """
        Runs the Feistel cipher pipeline based on encrypt flag
        """
        assert len(data) == 2*len(self.key) // self.stages, \
            "Length of data must be twice the length of partial key"
        start, end, steps = 0, self.stages, 1
        if not encrypt:
            start, end, steps = end-1, -1, -1
        if nonce is None:
            nonce = [0]*len(data)
        nonce = np.array(nonce)
        for stage in range(start, end, steps):
            new_data = [0]*len(data)
            new_data[:len(data)//2] = data[len(data)//2:]
            new_data[len(
                data)//2:] = np.bitwise_xor(self.hash_func(data[len(data)//2:], self.keys[stage]),
                                            data[:len(data)//2])
            data = np.array(new_data)
        temp = data[:len(data)//2].copy()
        data[:len(data)//2] = data[len(data)//2:]
        data[len(data)//2:] = temp
        return np.bitwise_xor(data, nonce)


if __name__ == "__main__":
    image = Image.open("flower.jpg")
    frame = np.asarray(image)
    original_shape = frame.shape
    frame = frame.flatten()
    STAGES, KEY_LENGTH = 3, 54
    KEY = [1+i+i**2 for i in range(KEY_LENGTH)]
    random.shuffle(KEY)
    data_length = len(frame)
    print("Segmented Key Length:", KEY_LENGTH//STAGES)

    def hash_function(x, y):
        """
        A good hash function
        """
        partial = np.bitwise_xor(x, y)
        total = np.sum(partial)
        if total == 0:
            return partial
        return np.round(255 * partial / total).astype(int)

    feistel_cipher = Feistel(hash_function, KEY, STAGES)
    BLOCK_SIZE = 2*feistel_cipher.partial_key_length()
    for i in tqdm(range(0, data_length, BLOCK_SIZE)):
        nonce = list(range(BLOCK_SIZE))
        random.seed(i)
        random.shuffle(nonce)
        frame[i:i+BLOCK_SIZE] = feistel_cipher.run(
            frame[i:i+BLOCK_SIZE], encrypt=True, nonce=nonce)
    frame = frame.reshape(original_shape)
    image = Image.fromarray(frame)
    image.save("encrypted.jpg")
    print("Encrypted Image Saved")

    # Decryption
    frame = frame.flatten()
    for i in tqdm(range(0, data_length, BLOCK_SIZE)):
        nonce = list(range(BLOCK_SIZE))
        random.seed(i)
        random.shuffle(nonce)
        frame[i:i+BLOCK_SIZE] = feistel_cipher.run(
            frame[i:i+BLOCK_SIZE], encrypt=False, nonce=nonce)
    frame = frame.reshape(original_shape)
    image = Image.fromarray(frame)
    image.save("decrypted.jpg")
    print("Decrypted Image Saved")
