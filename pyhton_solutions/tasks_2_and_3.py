import sys


def gcd(a: int, b: int) -> int:
    while b != 0:
        r = b
        b = a % b
        a = r
    return a


def extended_euclidean(a: int, b: int, m: int) -> int:
    print("-------------------------")
    print("r \tx \ty \tq ")
    print("-------------------------")

    x0, x1 = 1, 0
    y0, y1 = 0, 1

    while b != 0:
        r = a % b
        q = a // b

        new_x = x0 - q * x1
        new_y = y0 - q * y1

        print(f"{r}\t{new_x}\t{new_y}\t{q}")
        print("-------------------------")

        a, b = b, r
        x0, x1 = x1, new_x
        y0, y1 = y1, new_y

    if x0 < 0:
        x0 += m

    return x0


def mutually_prime_check(gcd_value: int):
    if gcd_value != 1:
        print("Ошибка: c и m не взаимно просты, обратный элемент не существует.", file=sys.stderr)
        sys.exit(1)


def main():
    try:
        c = int(input("Введите c (число для обратного элемента): "))
        m = int(input("Введите m (модуль): "))
    except ValueError:
        print("Ошибка: введите целые числа", file=sys.stderr)
        sys.exit(1)

    gcd_value = gcd(c, m)
    mutually_prime_check(gcd_value)

    d = extended_euclidean(c, m, m)

    print(f"\nОбратный элемент d = {d}")
    print(f"{c}^(-1) mod {m} = {d}")
    print(f"{c}*{d} mod {m} = {(c * d) % m}")


if __name__ == "__main__":
    main()