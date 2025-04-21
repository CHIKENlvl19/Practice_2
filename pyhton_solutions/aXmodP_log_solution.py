import math
import sys
from typing import List


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


def aXmodP(a: int, x: int, p: int) -> int:
    if p == 1:
        return 0
    if x == 0:
        return 1 % p

    degree = x % (p - 1)
    result = 1
    for _ in range(degree):
        result = (result * a) % p
    return result


def dec_to_bin(number: int) -> List[int]:
    bin_numbers = []
    while number != 0:
        bin_numbers.append(number % 2)
        number //= 2
    return bin_numbers


def aXmodPviaLog(a: int, x: int, p: int) -> int:
    if x == 0:
        return 1 % p
    if p == 1:
        return 0

    max_power_of_two = math.ceil(math.log2(x))
    if (1 << max_power_of_two) < x:
        max_power_of_two += 1

    row_of_as = []
    for i in range(max_power_of_two + 1):
        exponent = 1 << i
        row_of_as.append(aXmodP(a, exponent, p))

    bin_x = dec_to_bin(x)

    result = 1
    for i in range(len(bin_x)):
        if i < len(row_of_as) and bin_x[i] == 1:
            result = (result * row_of_as[i]) % p

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
        if aXmodP(a, p - 1, p) != 1:
            return False

    return True


def mod_validation(p: int, k: int):
    if not is_prime(p):
        print("\nМодуль не является простым числом, попробуйте другой. Модуль обязательно должен быть > 0!",
              file=sys.stderr)
        sys.exit(1)
    if not fermats_condition(p, k):
        print("\nМодуль не удовлетворяет условию Ферма, попробуйте другой.", file=sys.stderr)
        sys.exit(1)


def tests():
    assert aXmodPviaLog(3, 13, 7) == 3, "Тест 1 не пройден"
    assert aXmodPviaLog(5, 13, 7) == 5, "Тест 2 не пройден"
    assert aXmodPviaLog(5, 0, 7) == 1, "Тест 3 не пройден"
    assert aXmodPviaLog(3, 100, 7) == 4, "Тест 4 не пройден"
    assert aXmodPviaLog(3, 1, 7) == 3, "Тест 5 не пройден"
    print("Все тесты пройдены успешно!")


def main():
    tests()

    try:
        a1, x1 = map(int, input("Введите первое число и его степень через пробел: ").split())
        a2, x2 = map(int, input("Введите второе число и его степень через пробел: ").split())
        p = int(input("Введите модуль: "))
        k = int(input("Введите количество проверок для теоремы Ферма: "))
    except ValueError:
        print("Ошибка ввода: введите целые числа", file=sys.stderr)
        sys.exit(1)

    mod_validation(p, k)

    result1 = aXmodPviaLog(a1, x1, p)
    result2 = aXmodPviaLog(a2, x2, p)

    if result1 == result2:
        print(f"{a1}^{x1} mod {p} = {a2}^{x2} mod {p}")
    else:
        print(f"{a1}^{x1} mod {p} != {a2}^{x2} mod {p}")


if __name__ == "__main__":
    main()