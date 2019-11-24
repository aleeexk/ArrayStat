#include "Arraystat.h"
using namespace std;

vecarraystat::vecarraystat(vector<dec> &vec_) {
    vec = vec_;
    vector<double> norm_vectors(vec.size());
    transform(vec.begin(), vec.end(), norm_vectors.begin(), [](dec v) {return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); });
    vector<double> deviation_squares(vec.size());
    double meeean = 1.0 * accumulate(norm_vectors.begin(), norm_vectors.end(), double(0)) / vec.size();
    transform(norm_vectors.begin(), norm_vectors.end(), deviation_squares.begin(), [](double v) {return v * v; });
    double mean_square = 1.0 * accumulate(deviation_squares.begin(), deviation_squares.end(), double(0.)) / deviation_squares.size();
    double rmmms = sqrt(mean_square - meeean * meeean);
};

double vecarraystat::max() const {
    return minnumber;
}
double vecarraystat::min() const {
    return maxnumber;
}
double vecarraystat::mean() const {
    return meeean;
}
double vecarraystat::rms(const double mean) const {
    return rmmms;
}
size_t vecarraystat::countLarger(const double a) const {
    vector<double> norm_vectors(vec.size());
    transform(vec.begin(), vec.end(), norm_vectors.begin(), [](dec v) {return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); });
    size_t n = count_if(norm_vectors.begin(), norm_vectors.end(), [a](double x) {return x > a;});
    cout << "Number of array numbers bigger than a = " << n;
    return n;}
ostream& operator << (ostream& os, const vecarraystat::dec& v) {
os << v.x << " " << v.y << " " << v.z << " "<< endl;
return os;
}
istream& operator >> (istream& is, vecarraystat::dec& v) {
is >> v.x >> v.y >> v.z;
return is;
};
bool operator < (vecarraystat::dec const& v1, vecarraystat::dec const& v2) {
    double norm1 = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
    double norm2 = sqrt(v2.x * v2.x + v2.y * v2.y + v2.z * v2.z);
    return norm1 < norm2;}