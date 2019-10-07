#include "Arraystat.h"

Arraystat::Arraystat(vector<int> newlist) {
    list = newlist;
    sortlist = list;
    sort(sortlist.begin(), sortlist.end());
    maxnumber = *std::max_element(newlist.begin(), newlist.end());
    minnumber = *std::min_element(newlist.begin(), newlist.end());
}

Arraystat::Arraystat() = default;

void Arraystat::pushArray(int a) {
    if (!list.empty()) {
        maxnumber = ::max(maxnumber, a);
        minnumber = ::min(minnumber, a);
    } else {
        maxnumber = a;
        minnumber = a;
    }
    list.push_back(a);
    this->pushsort(a);

}

void Arraystat::print() {
    cout << "Unsorted";
    cout << endl;
    for (int i = 0; i < sortlist.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
    cout << "Sorted";
    cout << endl;
    for (int i : sortlist) {
        cout << i << " ";
    }
}

int Arraystat::max() const {
    return maxnumber;
}

int Arraystat::min() const{
    return minnumber;
}

double Arraystat::mean() const{
    float result = 0;
    result = accumulate(list.begin(), list.end(), 0) / list.size();
    return result;
}

double Arraystat::rms() const{
    double result = 0;
    double mean;
    mean = this->mean();
    for (int i : list) {
        result += (mean - i) * (mean - i) / list.size();
    }
    return sqrt((double) result);
}

size_t Arraystat::countLarger(int a) {
    size_t count = 0;
    for (int i : list) {
        if (i >= a) count++;
    }
    return count;
}