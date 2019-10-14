#pragma once

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iterator>
#include <numeric>
#include <string>
#include <fstream>
#include <array>

using namespace std;
class Arraystat {
private:
public:
    Arraystat();
    Arraystat(vector<int> newlist);
    int min() const;
    int max() const;
    double mean() const;
    double rms() const;
    void print();
    size_t countLarger(int a);
    void pushArray(int a);
};
class vecarraystat{
private:
    vector<vector<int>> vec, sortvec;



};
