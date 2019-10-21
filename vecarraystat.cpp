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
	ostream&  operator << (ostream& os, const dec& v) {
		os << v.x << " " << v.y << " " << v.z << " " << endl;
		return os;
	}
	istream& operator >> (istream& is, dec& v) {
		is >> v.x >> v.y >> v.z;
		return is;
	}
	void vecarraystat::print() const {
		int vector_size = vec.size();
		cout << "array: \n";
		for (int q = 0; q < vector_size; q++) {
			cout << vec[q] ;
		}
		cout << "\n";
	}
	void vecarraystat::SortArray(){
		sort(vec.begin(), vec.end());
	};
	int vecarraystat::max() const {
		return minnumber;
	}
	int vecarraystat::min() const {
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
		cout << "Number of array nambers bigger than a = " << n;
		return n;
	}
