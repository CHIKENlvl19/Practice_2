import math
import sys

def aXmodP(a: int, x: int, p: int) -> int:
    degree = x % (p - 1)
    result = 1
    for _ in range(degree):
        result = (result * a) % p
    return result

def gcd(a: int, b: int) -> int:
    while b != 0:
        r = b
        b = a % b
        a = r
    return a

def fermats_condition(p: int, k: int) -> bool:
    if p <= 1 or (p % 2 == 0 and p != 2):
        return False
    a_values = [2, 3, 5, 7, 11, 13, 17, 19, 23]
    current_k = min(k, len(a_values))
    for i in range(current_k):
        a = a_values[i]
        if a >= p:
            continue
        if gcd(p, a) != 1:
            return False
        if aXmodP(a, p-1, p) != 1:
            return False
    return True

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

def tests():
    assert aXmodP(3, 100, 7) == 4, "Тест aXmodP не пройден"
    assert gcd(1234, 54) == 2, "Тест gcd не пройден"
    assert is_prime(23), "Тест is_prime не пройден"
    print("Все тесты пройдены успешно!")

def main():
    tests()
    try:
        a1, x1 = map(int, input("Введите первое число и его степень через пробел: ").split())
        a2, x2 = map(int, input("Введите второе число и его степень через пробел: ").split())
        p = int(input("Введите модуль: "))
        k = int(input("Введите количество проверок для теоремы Ферма: "))
    except ValueError:
        print("Ошибка ввода: введите целые числа")
        sys.exit(1)

    if not is_prime(p):
        print("\nМодуль не является простым числом, попробуйте другой. Модуль обязательно должен быть > 0!")
        sys.exit(1)
    if not fermats_condition(p, k):
        print("\nМодуль не удовлетворяет условию Ферма, попробуйте другой.")
        sys.exit(1)

    res1 = aXmodP(a1, x1, p)
    res2 = aXmodP(a2, x2, p)

    if res1 == res2:
        print(f"{a1}^{x1} mod {p} = {a2}^{x2} mod {p}")
    else:
        print(f"{a1}^{x1} mod {p} != {a2}^{x2} mod {p}")

if __name__ == "__main__":
    main()