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
    std::vector<int> list, sortlist;
    int maxnumber, minnumber;
public:
    Arraystat();

    Arraystat(std::vector<int> newlist);

    int min() const;

    int max() const;

    double mean() const;

    double rms() const;

    void print();

    size_t countLarger(int a);
};
class vecarraystat{
public:
    struct dec{
        double x;
        double y;
        double z;
    };
    vecarraystat() = default;
    vecarraystat(std::vector<dec> &vec_);
    vecarraystat read_file(const std::string name);
    void SortArray();
    double max() const;
    double min() const;
    double mean() const;
    double rms(const double mean) const;
    size_t countLarger(const double a) const;
private:
    std::vector<dec> vec, sortvec;
    double minnumber, maxnumber, rmmms, rmsss, meeean;
};