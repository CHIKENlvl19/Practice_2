#pragma once

#include <vector>
using namespace std;

bool isPrime(int p);
int aXmodP (int a, int x, int p);
vector<short> DecToBin(int number);
int aXmodPviaLog(int a, int x, int p);
int gcd(int a, int b);
template<typename T>
bool FermatsCondition(T p, T& k);
bool modValidation(int p, int k);
void Tests();