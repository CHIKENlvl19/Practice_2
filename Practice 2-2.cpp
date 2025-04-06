#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    int c, d, m, a, b; // инициализация необходимых переменных 
    int lastX = 1, lastY = 0, X = 0, Y = 1;

    cin >> a >> b; // ввод значений пользователем   
    m = a;
    d = b;

    while (d != 0) 
    {
        int remain = m % d;
        int evenly = m / d;
        m = d;
        d = remain;

        int tempX = X;
        X = lastX - (evenly * X);
        lastX = tempX;

        int tempY = Y;
        Y = lastY - (evenly * Y);
        lastY = tempY;
    }

    if (m == 1)
    {
        cout << lastX;
    }
    else
    {
        cout << "Невозможно найти обратный элемент, так как " << a << " и " << b << " не взаимно просты." << endl;
    }

    return 0;
}