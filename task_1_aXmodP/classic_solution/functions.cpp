#include <iostream>
#include <math.h>
#include <vector>
#include <cassert>
#include "header.h"

using namespace std;

int aXmodP (int a, int x, int p){ // быстрое возведение в степень по модулю
    int degree = x % (p - 1); // применение теоремы Ферма

    int result = 1;
    for(int i = 1; i <= degree; i++){
        result = result * a;
        result %= p;
    }

    return result;
}

int gcd(int a, int b){ // алгоритм Евклида для эффективного нахождения НОД
    while( b!= 0){
        int r = b;
        b = a % b;
        a = r;
    }

    return a;
}

template<typename T>
bool FermatsCondition(T p, T& k){
    if(p <= 1 || (p % 2 == 0 && p != 2)){
        return false;
    }

    vector<int> aValues = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    if(k > static_cast<int>(aValues.size())){
        k = aValues.size();
    }

    for(int i = 0; i < k; i++){
        T a = aValues[i];

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
    assert(aXmodP(3, 100, 7) == 4);
    assert(gcd(1234, 54) == 2);
    assert(isPrime(23));
}

bool modValidation(int p, int k){
    if(!isPrime(p)){
        cerr << endl << "Модуль не является простым числом, попробуйте другой. Модуль обязательно должен быть > 0!" << endl;
        exit(1);
    }
    
    if(!FermatsCondition(p, k)){
        cerr << endl << "Модуль не удовлетворяет условию Ферма, попробуйте другой." << endl;
        exit(1);
    }

    return 1;
}
