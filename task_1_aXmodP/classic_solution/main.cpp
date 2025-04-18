#include <iostream>
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

    if(!isPrime(p)){
        cout << endl << "Модуль не является простым числом, попробуйте другой. Модуль обязательно должен быть > 0!" << endl;
        return 0;
    }
    
    if(!FermatsCondition(p, k)){
        cout << endl << "Модуль не удовлетворяет условию Ферма, попробуйте другой." << endl;
        return 0;
    }

    if(aXmodP(a1, x1, p) == aXmodP(a2, x2, p)){
        cout << a1 << "^" << x1 << " mod " << p << " = " << a2 << "^" << x2 << " mod " << p << endl;
    }
    else{
        cout << a1 << "^" << x1 << " mod " << p << " != " << a2 << "^" << x2 << " mod " << p << endl;
    }

}