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

using namespace std;

class Arraystat {
private:
    vector<int> list, sortlist;
    int maxnumber, minnumber;

    void pushsort(int x) {
        if (!sortlist.empty()) {
            vector<int>::iterator it;
            it = sortlist.begin();
            int pos = 0;
            while (pos < sortlist.size() && x > sortlist[pos]) {
                pos++;
            }
            it = it + pos;
            if (pos != sortlist.size()) sortlist.insert(it, x);
            else sortlist.push_back(x);
        } else sortlist.push_back(x);
    }

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
