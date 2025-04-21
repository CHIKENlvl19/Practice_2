from typing import List


def continued_fraction(a: int, b: int) -> List[int]:
    coefficients = []
    while b != 0:
        q = a // b
        coefficients.append(q)
        r = a % b
        a, b = b, r
    return coefficients


def gcd(a: int, b: int) -> int:
    while b != 0:
        r = b
        b = a % b
        a = r
    return a


def compact_solution(a: int, a0: int, b: int, b0: int):
    k = min(a // a0, b // b0) if (a0 != 0 and b0 != 0) else 0

    print(f"Одно компактное решение: a = {a + a0 * k}, b = {b - b0 * k}")
    print(f"Компактное общее решение: a = {a + a0 * k} + {a0} * k, "
          f"b = {b - b0 * k} + {b0} * k, где k - целое число.")


def solve_diophantine(a: int, b: int, c: int):
    cf = continued_fraction(a, b)
    x, y = 0, 1
    x_prev, y_prev = 1, 0

    for q in cf:
        x, x_prev = x_prev - q * x, x
        y, y_prev = y_prev - q * y, y

    d = gcd(a, b)
    if c % d != 0:
        print("Нет решений.")
        return

    k = c // d
    a0 = b // d
    b0 = a // d

    print(f"Одно решение: x = {x_prev * k}, y = {y_prev * k}")
    print(f"Общее решение: x = {x_prev * k} + {a0} * k, "
          f"y = {y_prev * k} - {b0} * k, где k - целое число.\n")

    compact_solution(x_prev * k, a0, y_prev * k, b0)


if __name__ == "__main__":
    print("1256x + 847y = 119\n")
    solve_diophantine(1256, 847, 119)