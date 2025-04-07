#include <iostream>
#include <math.h>

using namespace std;

bool FermatsCondition(int p){
    if(p % 2 == 0 && p != 2){
        return false;
    }


}

bool isPrime(int p){
    if (p % 2 == 0 || p % 3 == 0){
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

int aXmodP (int a, int x, int p){
    int degree = x % (p - 1);

    int result = 1;
    for(int i = 1; i <= degree; i++){
        result = result * a;
        result %= p;
    }

    return result;
}

int main(){
    int a, x, p;
    cout << "Введите число: ";
    cin >> a;
    cout << "Введите степень: ";
    cin >> x;
    cout << "Введите модуль: ";
    cin >> p;

    if( !isPrime(p) ){
        cout << endl << "Модуль не является простым числом, попробуйте другой." << endl;
        return 0;
    }

    /*if( !FermatsCondition(p)){
        cout << endl << "Модуль не удовлетворяет условию Ферма, попробуйте другой." << endl;
    }*/
    
    cout << endl << "Результат: " << aXmodP(a, x, p) << endl;
}