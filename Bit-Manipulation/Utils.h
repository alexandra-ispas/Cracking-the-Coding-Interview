#ifndef BIT_MANIPULATION_UTILS_H
#define BIT_MANIPULATION_UTILS_H

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int insertion(int M, int N, int i , int j);
void writeBit(int *N, int k, int kthBit);
string binaryToString(double number);
int flipBitToWin(int number);
pair<int, int> countSetBits(int number);
int nextSmallestNumber(int number);
int nextBiggestNumber(int number);
int conversion(int a, int b);
int conversion2(int a, int b);
int pairwiseSwap(int number);

#endif //BIT_MANIPULATION_UTILS_H
