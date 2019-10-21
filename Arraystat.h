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

class Arraystat {
private:
double minnumber, maxnumber, rmss, rmsss, meann;
 std::vector <int> sortlist, newlist, list;
public:
    Arraystat() = default;
    Arraystat(std::vector<int> &newlist);
    int min() const;
    int max() const;
    double mean() const;
    double rms() const;
    void print();
    size_t countLarger(int a);
    void pushArray(int a);
};
class vecarraystat{
    struct dec{
        double x;
        double y;
        double z;
    };
private:
   std::vector<dec> vec, sortvec;
   double minnumber, maxnumber, rmmms, rmsss, meeean;
public:
vecarraystat() = default;
vecarraystat(std::vector<dec> &vec_);
vecarraystat read_file(const std::string name);
void print() const;
void SortArray();
int max() const;
int min() const;
double mean() const;
double rms(const double mean) const;
size_t countLarger(const double a) const;
friend std::ostream&  operator << (std::ostream& os, const dec& v);
friend std::istream& operator >> (std::istream& is, dec& v);
friend bool operator <  (dec const& v1, dec const& v2);
};