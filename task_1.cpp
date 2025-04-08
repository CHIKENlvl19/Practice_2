#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int aXmodP (int a, int x, int p){
    int degree = x % (p - 1);

    int result = 1;
    for(int i = 1; i <= degree; i++){
        result = result * a;
        result %= p;
    }

    return result;
}

int gcd(int a, int b){
    while( b!= 0){
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

bool FermatsCondition(int p, int k){
    if(p <= 1 || (p % 2 == 0 && p != 2)){
        return false;
    }

    vector<int> aValues = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    if(k > static_cast<int>(aValues.size())){
        k = aValues.size();
    }

    for(int i = 0; i < k; i++){
        int a = aValues[i];

        if(a >= p) continue;

        if(gcd(p, a) != 1){
            return false;
        }

        if(aXmodP(a, p-1, p) != 1){
            return false;
        }
    }

    return true;
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

int main(){
    int a, x, p, k;
    cout << "Введите число: ";
    cin >> a;
    cout << "Введите степень: ";
    cin >> x;
    cout << "Введите модуль: ";
    cin >> p;
    cout << "Введите количество проверок для теоремы Ферма: ";
    cin >> k;

    if(!isPrime(p)){
        cout << endl << "Модуль не является простым числом, попробуйте другой." << endl;
        return 0;
    }
    
    if(!FermatsCondition(p, k)){
        cout << endl << "Модуль не удовлетворяет условию Ферма, попробуйте другой." << endl;
        return 0;
    }

    cout << endl << "Результат: " << aXmodP(a, x, p) << endl;
}