#include <iostream>

using namespace std;

int EVK(int a, int b) {
    while (b != 0) {
        int r = b;
        b = a % b;
        a = r;
    }
    
    return a;
}

int extendedEuclidean(int a, int b, int m) {
    cout << "-------------------------" << endl;
    cout << "r \tx \ty \tq " << endl;
    cout << "-------------------------" << endl;
    int x0 = 1, x1 = 0;
    int y0 = 0, y1 = 1;
    int r = 0, q = 0;

    while (b != 0) {
        r = a % b;
        q = a / b;

        int new_x = x0 - q * x1;
        int new_y = y0 - q * y1;

        cout << r << "\t" << new_x << "\t" << new_y << "\t" << q << endl;
        cout << "-------------------------" << endl;
        
        a = b;
        b = r;
        
        x0 = x1;
        x1 = new_x;
        y0 = y1;
        y1 = new_y;
    }

    if (x0 < 0) {
        x0 += m;
    }
    
    return x0;
}

void MutuallyPrimeCheck(int gcd){
    if(gcd != 1){
        cerr << "Ошибка: c и m не взаимно просты, обратный элемент не существует." << endl;
        exit(1);
    }
}

int main() {
    int c = 0, m = 0;
    cout << "Введите c (число для обратного элемента): ";
    cin >> c;
    cout << "Введите m (модуль): ";
    cin >> m;

    MutuallyPrimeCheck(EVK(c, m));

    int d = extendedEuclidean(c, m, m);
    
    cout << "Обратный элемент d = " << d << endl;
    cout << c << "^(-1) mod " << m << " = " << d << endl;
    cout << c << "*" << d << " mod " << m << " = " << (c * d) % m << endl;

    return 0;
}
