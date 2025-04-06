#include <iostream>
using namespace std;
int EVK(int a, int b) {
    int r = 0;
    while (b != 0) {
        r = b;
        b = a % b;
        a = r;
    }
    return a;
}

// Расширенный алгоритм Евклида
int NOD(int a, int b) {
    // Таблица, где r - остаток, q - множитель, x и y - множители (Из уравнения Безу: ax + by = НОД(a, b))
    cout << " r \tx \ty \tq " << endl;
    int r, x, y, q = 0;
    // Зададим начальные значения
    int x0 = 1, y0 = 0; // первая строка
    int x1 = 0, y1 = 1; // вторая строка
    int m = b; // Сохранение значения модуля в случае, если d < 0
    r = a;

    while (r > 0) {
        // вычисление нового остатка, частного, и новых значений x и y
        r = a % b;
        q = a / b;
        x = x0 - x1 * q;
        y = y0 - y1 * q;
        cout << " " << r << "\t" << x << "\t" << y << "\t" << q << "\t " << endl; // вывод промежуточных значений
        // обновление значений для следующей итерации (сдвигаем элементы) 
        a = b; // Делимое становится делителем
        b = r; // Делитель становится остатком
        //Переходим на следующую строку
        x0 = x1;
        x1 = x;
        y0 = y1;
        y1 = y;
    }
    if (x0 < 0) { // d < 0 
        x0 += m;
    }
    return x0;
}

int main() {
    int c = 0;
    cout << "Расширенный алгоритм Евклида - a*x + b*y = НОД(a,b)" << endl;
    cout << "Вычисление c*d mod m = 1" << endl;
    cout << "Вычисление c^-1 mod m = d" << endl;
    cout << "Введите c: ";
    cin >> c;
    int m = 0;
    cout << "Введите m: ";
    cin >> m;
    int nod = EVK(c, m);
    cout << "EVK = " << nod << endl;

    if (nod != 1) {
        cout << "ОШИБКА: введенные числа не взаимно обратны";
        return 0;
    }
    int d = NOD(c, m);
    if (d == 0) {
        return 0;
    }
    cout << "d = " << d << endl;
    cout << c << " * " << d << " mod " << m << " = " << "1" << endl;
    cout << c << "^-1" << " mod " << m << " = " << d;
    return 0;
}
