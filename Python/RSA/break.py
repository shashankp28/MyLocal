"""
Playing with RSA
"""
import sympy
from sympy.ntheory.primetest import is_square
from rsa import RSA


def generate_private_key(a, m):
    """
    Generate a private key given the public key and phi
    """
    if sympy.gcd(a, m) != 1:
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


def get_etf(p, q):
    """
    Calculate the Euler Totient Function
    """
    return (p - 1) * (q - 1)


def fermat_method(rsa_obj):
    """
    Fermat's factorization method to Find p and q
    """
    private = None
    public_key, n = rsa_obj.get_public_key()
    if is_square(n):
        p = int(sympy.sqrt(n))
        phi = get_etf(p, p)
        private = generate_private_key(public_key, phi)
        print(f"private key: {private} {rsa_obj.match_private_key(private)}")

    else:
        a = int(sympy.sqrt(n)) + 1
        while True:
            b_squared = a ** 2 - n
            if is_square(b_squared):
                b = int(sympy.sqrt(b_squared))
                p = a - b
                q = a + b
                phi = get_etf(p, q)
                private = generate_private_key(public_key, phi)
                return private
            a += 1


def multiply(c, d):
    result = 0
    while d > 0:
        if d % 2 == 1:
            result += c
        c = c << 1
        d = d >> 1
    return result


if __name__ == "__main__":
    # my_rsa = RSA(seed=10, bits=10)
    # print("Public key:", my_rsa.get_public_key())
    # private_found = fermat_method(my_rsa)
    # print(
    #     f"Private key: {private_found} Verfied: {my_rsa.match_private_key(private_found)}")
    x, y = 20, 1
    print(multiply(x, y))
