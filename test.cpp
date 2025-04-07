#include <iostream>
#include <math.h>
using namespace std;

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

int main() {

    int p;
    cin >> p;
    if (isPrime(p)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}