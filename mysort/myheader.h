#ifndef __MYHEADER__H__
#define __MYHEADER__H__

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

vector<int> buildVectorFromRandom(int n);

void shuffle(vector<int>& vt);

void printVector(const vector<int> & vt);
#endif