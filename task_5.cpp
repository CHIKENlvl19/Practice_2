#include <iostream>
#include <vector>

using namespace std;

vector<int> continued_fraction(int a, int b) {
    vector<int> coefficients;
    while (b != 0) {
        int q = a / b;
        coefficients.push_back(q);
        int r = a % b;
        a = b;
        b = r;
    }
    return coefficients;
}

int EVK(int a, int b) {
    while (b != 0) {
        int r = b;
        b = a % b;
        a = r;
    }
    
    return a;
}

void CompactSolution(int a, int a0, int b, int b0){
    int k = ( (a / a0) < (b / b0) ) ? (a / a0) : (b / b0);

    cout << "Компактное общее решение: a = " << a + (a0 * k) << " + " << a0 << " * k"
        << ", b = " << b + (-b0 * k) << " + " << b0 << " * k"
        << ", где k - целое число." << endl;
}

void solve_diophantine(int a, int b, int c) {
    vector<int> cf = continued_fraction(a, b);
    int x = 0, y = 1;
    int x_prev = 1, y_prev = 0;
    for (int q : cf) {
        int x_temp = x;
        x = x_prev - q * x;
        x_prev = x_temp;
        
        int y_temp = y;
        y = y_prev - q * y;
        y_prev = y_temp;
    }

    int gcd = EVK(a, b);
    if (c % gcd != 0) {
        cout << "Нет решений." << endl;
        return;
    }
    
    int k = c / gcd;
    cout << "Одно решение: a = " << x_prev * k << ", b = " << y_prev * k << endl;
    cout << "Общее решение: a = " << x_prev * k << " + " << b/gcd << " * t," 
         << " b = " << y_prev * k << " - " << a/gcd << " * t" 
         << ", где t - целое число." << endl;

    CompactSolution(x_prev * k, b/gcd, y_prev * k, a/gcd);
}

int main() {
    cout << "1256a + 847b = 119" << endl;
    solve_diophantine(1256, 847, 119);

    return 0;
}