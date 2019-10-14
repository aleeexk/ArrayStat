#include "Arraystat.h"

Arraystat::Arraystat(vector<int> &newlist) {
    sortlist = newlist;
    sort(sortlist.begin(), sortlist.end());
    maxnumber = sortlist.back();
    minnumber = sortlist.front();
    meann = accumulate(newlist.begin(), newlist.end(), 0) / newlist.size();
    for (int i : newlist) {
        rmss += (meann - i) * (meann - i) / list.size();
    }
    rmsss = sqrt(rmss)
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
    for (int i : list) {
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
    return meann;
}

double Arraystat::rms() const{
    return rmsss;
}

size_t Arraystat::countLarger(int a) {
    size_t count = 0;
    count = distance(lower_bound(sortlist.begin(), sortlist.end()), sortlist.end());
    return count;
}