import random
import math
from typing import List, Tuple
import sys


def is_prime(p: int) -> bool:
    if p <= 1:
        return False
    if p % 2 == 0:
        return p == 2
    if p % 3 == 0:
        return p == 3

    square_root_n = int(math.sqrt(p)) + 1
    max_i = (square_root_n + 1) // 6

    for i in range(1, max_i):
        divider_minus_one = 6 * i - 1
        divider_plus_one = 6 * i + 1

        if divider_minus_one <= square_root_n and p % divider_minus_one == 0:
            return False
        if divider_plus_one <= square_root_n and p % divider_plus_one == 0:
            return False

    return True


def gcd(a: int, b: int) -> int:
    while b != 0:
        r = b
        b = a % b
        a = r
    return a


def aXmodP(a: int, x: int, p: int) -> int:
    if p == 1:
        return 0
    degree = x % (p - 1)
    result = 1
    for _ in range(degree):
        result = (result * a) % p
    return result


def mul_mod(a: int, b: int, n: int) -> int:
    return (a * b) % n


def prime_factors(n: int) -> List[int]:
    factors = []
    if n % 2 == 0:
        factors.append(2)
        while n % 2 == 0:
            n //= 2
    i = 3
    while i * i <= n:
        if n % i == 0:
            factors.append(i)
            while n % i == 0:
                n //= i
        i += 2
    if n > 2:
        factors.append(n)
    return factors


def is_primitive_root(g: int, p: int) -> bool:
    if g == 1:
        return False
    if gcd(g, p) != 1:
        return False
    m = p - 1
    factors = prime_factors(m)
    for q in factors:
        if aXmodP(g, m // q, p) == 1:
            return False
    return True


def keys_generator() -> Tuple[int, int, int, int]:
    while True:
        p = random.randint(1000, 9999)
        if is_prime(p):
            break

    while True:
        g = random.randint(1, p - 1)
        if is_primitive_root(g, p):
            break

    x = random.randint(1, p - 2)
    y = aXmodP(g, x, p)

    return (p, g, x, y)


def crypt(p: int, g: int, x: int, y: int, plaintext: str) -> str:
    ciphertext = []
    for c in plaintext:
        m = ord(c)
        while True:
            k = random.randint(2, p - 2)
            if gcd(k, p - 1) == 1:
                break
        a = aXmodP(g, k, p)
        b = mul_mod(aXmodP(y, k, p), m, p)
        ciphertext.extend([str(a), str(b)])
    return ' '.join(ciphertext)


def decrypt(p: int, x: int, ciphertext: str) -> str:
    parts = list(map(int, ciphertext.split()))
    decrypted = []
    for i in range(0, len(parts), 2):
        a = parts[i]
        b = parts[i + 1]
        deM = mul_mod(b, aXmodP(a, p - 1 - x, p), p)
        decrypted.append(chr(deM))
    return ''.join(decrypted)


def main():
    random.seed()

    try:
        with open('input.txt', 'r', encoding='utf-8') as f:
            plaintext = f.read()
    except FileNotFoundError:
        print("Файл input.txt не найден", file=sys.stderr)
        return

    p, g, x, y = keys_generator()

    ciphertext = crypt(p, g, x, y, plaintext)

    _, _, wrong_x, _ = keys_generator()

    decrypted_text = decrypt(p, wrong_x, ciphertext)

    with open('output.txt', 'w', encoding='utf-8') as f:
        f.write(f"Открытый ключ (p, g, y) = ({p}, {g}, {y})\n")
        f.write(f"Закрытый ключ x = {x}\n\n")
        f.write(f"Шифруемый текст: {plaintext}\n\n")
        f.write(f"Зашифрованный текст: {' '.join(ciphertext.split())}\n\n")
        f.write(
            "ВНИМАНИЕ! ВНЕШТАТНАЯ СИТУАЦИЯ. НАБЛЮДАЕТСЯ АТАКА ПОСЕРЕДИНЕ. РАСШИФРОВКА МОЖЕТ НЕ СООТВЕТСТВОВАТЬ ОЖИДАНИЮ.\n")
        f.write(f"\nДешифрованный текст: {decrypted_text}\n")


if __name__ == "__main__":
    main()