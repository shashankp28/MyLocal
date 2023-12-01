"""
Code to implement RSA encryption
"""
import math
import random
from sympy import isprime


class RSA:

    """
    Class that implements the simple RSA algorithm
    """

    def __init__(self, seed=10, bits=1024):
        random.seed(seed)
        self.exclude = set()
        self.p = self.generate_random_prime(pow(2, bits - 1), pow(2, bits))
        self.exclude.add(self.p)
        self.q = self.generate_random_prime(pow(2, bits - 1), pow(2, bits))
        self.n = self.p * self.q
        self.phi = (self.p - 1) * (self.q - 1)
        self.e = self.generate_public_key()
        self.__d = self.generate_private_key()

    def generate_random_prime(self, min_val, max_val):
        """
        Generate a random prime number within a range, excluding a set of numbers
        """
        prime = None
        while prime is None or prime in self.exclude:
            candidate = random.randint(min_val, max_val)
            if isprime(candidate):
                prime = candidate
        return prime

    def generate_public_key(self):
        """
        Generate a public key given the private key and phi
        """
        # possible_keys = []
        # for e in range(2, self.phi):
        #     if math.gcd(e, self.phi) == 1:
        #         possible_keys.append(e)
        # assert possible_keys, "No possible public keys"
        return 65537

    def generate_private_key(self):
        """
        Generate a private key given the public key and phi
        """
        a, m = self.e, self.phi
        if math.gcd(a, m) != 1:
            return None  # No mod inverse if a & m aren't relatively prime.
        u1, u2, u3 = 1, 0, a
        v1, v2, v3 = 0, 1, m
        while v3 != 0:
            q = u3 // v3
            v1, v2, v3, u1, u2, u3 = (
                u1 - q * v1), (u2 - q * v2), (u3 - q * v3), v1, v2, v3
        d = u1 % m
        assert (a * d) % m == 1, "Mod inverse failed"
        return d

    def get_public_key(self):
        """
        Return the public key
        """
        return (self.e, self.n)

    def encrypt(self, message: str, public: bool = True, key: tuple[int, int] = None) -> list[int]:
        """
        Encrypt a message using the public or private key
        """
        encrypted = []
        for ch in message:
            if key is not None:
                encrypted.append(pow(ord(ch), key[0], key[1]))
            elif public:
                encrypted.append(pow(ord(ch), self.e, self.n))
            else:
                encrypted.append(pow(ord(ch), self.__d, self.n))
        return encrypted

    def decrypt(self, encrypted: list, public: bool = False, key: tuple[int, int] = None) -> str:
        """
        Decrypt a message using the public or private key
        """
        decrypted = ""
        for ch in encrypted:
            if key is not None:
                decrypted += chr(pow(ch, key[0], key[1]))
            elif public:
                decrypted += chr(pow(ch, self.e, self.n))
            else:
                decrypted += chr(pow(ch, self.__d, self.n))
        return decrypted

    def match_private_key(self, key: int) -> bool:
        """
        Check if a given key matches the private key
        """
        return key == self.__d


if __name__ == "__main__":
    bob = RSA()
    print("Bob's public key:", bob.get_public_key())
    print()

    SECRET = "Hello, world!"
    print("Original message:", SECRET)
    print()
    encrypted_message = bob.encrypt(SECRET, public=True)
    print("Bob Public Encrypt:", encrypted_message)
    print()
    print("Bob Private Decrypt:", bob.decrypt(encrypted_message, public=False))
