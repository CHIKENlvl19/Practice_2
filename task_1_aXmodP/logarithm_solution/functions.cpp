#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cassert>
#include "header.h"

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

int aXmodP (int a, int x, int p){ // быстрое возведение в степень по модулю
    int degree = x % (p - 1); // применение теоремы Ферма
    if(x == 0){
        degree = 1;
    }

    int result = 1;
    for(int i = 1; i <= degree; i++){
        result = result * a;
        result %= p;
    }

    return result;
}

vector<short> DecToBin(int number) {
    vector<short> BinNumbers;
    while (number != 0) {
        BinNumbers.push_back(number % 2);
        number /= 2;
    }
    return BinNumbers;
}

int aXmodPviaLog(int a, int x, int p) {
    if (x == 0) return 1 % p;
    if (p == 1) return 0;

    int maxPowerOfTwo = static_cast<int>(ceil(log2(x)));
    if (pow(2, maxPowerOfTwo) < x) maxPowerOfTwo++;

    vector<int> rowOfAs;
    for (int i = 0; i <= maxPowerOfTwo; ++i) {
        int exponent = 1 << i;
        rowOfAs.push_back(aXmodP(a, exponent, p));
    }

    vector<short> BinX = DecToBin(x);

    int result = 1;
    for (int i = 0; i < static_cast<int>(BinX.size()); ++i) {
        if (i < static_cast<int>(rowOfAs.size()) && BinX[i] == 1) {
            result = (result * rowOfAs[i]) % p;
        }
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

void Tests(){
    assert(aXmodPviaLog(3, 13, 7) == 3);
    assert(aXmodPviaLog(5, 13, 7) == 5);
    assert(aXmodPviaLog(5, 0, 7) == 1);
    assert(aXmodPviaLog(3, 100, 7) == 4);
    assert(aXmodPviaLog(3, 1, 7) == 3);
}
