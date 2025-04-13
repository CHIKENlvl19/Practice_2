#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

bool isPrime(int p);
int aXmodP (int a, int x, int p);
vector<short> DecToBin(int number);
int mod_pow(int a, int exponent, int p);
int aXmodPviaLog(int a, int x, int p);
int gcd(int a, int b);
template<typename T>
bool FermatsCondition(T p, T& k);
bool modValidation(int p, int k);
void Tests();