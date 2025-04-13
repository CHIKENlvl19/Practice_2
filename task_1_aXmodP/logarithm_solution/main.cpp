#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cassert>
#include "header.h"

using namespace std;

int main(){

    Tests();

    int a1, x1;
    cout << "Введите первое число и его степень через пробел: ";
    cin >> a1 >> x1;
    
    int a2, x2;
    cout << "Введите второе число и его степень через пробел: ";
    cin >> a2 >> x2;

    int p, k;
    cout << "Введите модуль: ";
    cin >> p;
    cout << "Введите количество проверок для теоремы Ферма: ";
    cin >> k;

    modValidation(p, k);

    int result1 = aXmodPviaLog(a1, x1, p);
    int result2 = aXmodPviaLog(a2, x2, p);

    if(result1 == result2){
        cout << a1 << "^" << x1 << " mod " << p << " = " << a2 << "^" << x2 << " mod " << p << endl;
    }
    else{
        cout << a1 << "^" << x1 << " mod " << p << " != " << a2 << "^" << x2 << " mod " << p << endl;
    }
}