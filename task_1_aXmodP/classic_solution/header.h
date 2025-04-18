#pragma once

using namespace std;

int aXmodP (int a, int x, int p);
int gcd(int a, int b);
template<typename T>
bool FermatsCondition(T p, T& k);
bool isPrime(int p);
void Tests();
bool modValidation(int p, int k);