#include <iostream>
#include <string>
#include <cstdlib> // библиотека для рандомайзера srand
#include <ctime>
#include <sstream>

using namespace std;

// поиск НОД по алгоритму Евклида для проверки на взаимную простоту
int gcd(int a, int b) { 
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//проверка на взаимную простоту с включением алгоритма Евклида
bool areCoprime(int a, int b) { 
    return gcd(a, b) == 1;
}

bool key_check(int p, int g, int x)
{
    if (g < p && x < p)
        return true;
    else
        return false;
}

int aXmodP (int a, int x, int p){ // быстрое возведение в степень по модулю
    int degree = x % (p - 1); // применение теоремы Ферма

    int result = 1;
    for(int i = 1; i <= degree; i++){
        result = result * a;
        result %= p;
    }

    return result;
}

// a*b mod n
int mul(int a, int b, int n) { 
    int sum = 0;
    for (int i = 0; i < b; i++) {
        sum += a;
        if (sum >= n) {
            sum -= n;
        }
    }
    return sum;
}

// функция шифрования
void crypt(int p, int g, int x, const string& plaintext, string& ciphertext) {

    int y = aXmodP(g, x, p);
    cout << "Открытый ключ (p, g, y) = (" << p << ", " << g << ", " << y << ")" << endl;
    cout << "Закрытый ключ x = " << x << endl;

    cout << "\nШифруемый текст: " << plaintext << endl << endl;

    cout << "Зашифрованный текст: ";
    for (int i = 0; i < plaintext.length(); ++i) {
        int m = plaintext[i];
        int k = rand() % (p - 2) + 1; // 1 < k < (p-1)
        int p_for_crypt = p - 1;
        while (!(1 < k < (p - 1)) && areCoprime(k, p_for_crypt) )
        {
            k = rand() % (p - 2) + 1;
        }
        int a = aXmodP(g, k, p);
        int b = mul(aXmodP(y, k, p), m, p);
        ciphertext += to_string(a) + " " + to_string(b) + " ";
        cout << "(" + to_string(a) + ", " + to_string(b) + ") ";
    }
    cout << endl;
}

// функция дешифрования
void decrypt(int p, int x, const string& ciphertext, string& decryptedText) {
    cout << "\nДешифрованный текст: ";

    string temp;
    stringstream ss(ciphertext);
    string token;
    while (getline(ss, token, ' ')) {
        if (!temp.empty()) {
            int a = stoi(temp);
            int b = stoi(token);
            int deM = mul(b, aXmodP(a, p - 1 - x, p), p);
            decryptedText += char(deM);
            temp = "";
        }
        else {
            temp = token;
        }
    }

    cout << decryptedText << endl;
}


int main() {
    srand(time(NULL));

    int p = rand() % 900 + 1;
    int g = rand() % 300 + 1;
    int x = rand() % 10 + 1;
    
    // написать рандом для p, g, x + проверка на g < p, x < p, 1<k<(p - 1) - ПО АЛГОРИТМУ ЕВКЛИДА
    //int p = 593;
    //int g = 123;
    //int x = 7;
   
    string plaintext;
    string ciphertext;
    if (key_check(p, g, x))
    {
        cout << "Введите строку: ";
        cin >> plaintext;
        cout << endl;

        crypt(p, g, x, plaintext, ciphertext);

        string decryptedText;
        decrypt(p, x, ciphertext, decryptedText);

        return 0;
    }
}


// http://e-maxx.ru/algo/euclid_algorithm - легкий алгоритм Евклида
// алгоритм Эль-Гамаля - ассиметричная криптосистема