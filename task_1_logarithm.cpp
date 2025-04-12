#include <iostream>
#include <math.h>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

bool isPrime(int p){
    if (p % 2 == 0 || p % 3 == 0 || p <= 1){
        return false;
    }

    int squareRootN = static_cast<int>(sqrt(p)) + 1;
    int maxI = (squareRootN + 1) / 6;

    for(int i = 1; i < maxI; i++){
        int dividerMinusOne = 6 * i - 1;
        int dividerPlusOne = 6 * i + 1;
            
        if (dividerMinusOne <= squareRootN) {
            if (p % dividerMinusOne == 0) return false;
        }
        if (dividerPlusOne <= squareRootN) {
            if (p % dividerPlusOne == 0) return false;
        }
    }

    return true;
}

void Tests(){
    
}

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

    int result1 = aXmodP(a1, x1, p);
    int result2 = aXmodP(a2, x2, p);

    if(result1 == result2){
        cout << a1 << "^" << x1 << " mod " << p << " = " << a2 << "^" << x2 << " mod " << p << endl;
    }
    else{
        cout << a1 << "^" << x1 << " mod " << p << " != " << a2 << "^" << x2 << " mod " << p << endl;
    }

}