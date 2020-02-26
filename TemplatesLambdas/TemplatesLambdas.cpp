#include <cmath>
#include <iostream>
#include <functional>
#include <vector>

using std::vector;
using std::function;

using namespace std;

template<typename T, typename FunType>
vector<T> filter(const vector<T>& v, FunType p) {
	vector<T> result;
	for (T x : v) {
		if (p(x) == true) {
			result.push_back(x);
		}
	}
	return result;
}

template<typename T, typename FunType1, typename FunType2>
vector<T> transfilt(vector<T>& v, FunType1 t, FunType2 p) {
	vector<T> result;
	for (T& x : v) {
		x = t(x);
		if (p(x) == true) {
			result.push_back(x);
		}
	}
	return  result;
}

template<typename T>
void printVec(const vector<T>& v) {
	for (T x : v) {
		cout << "[" << x << "] ";
	}
	cout << endl;
}

int main() {
	vector<int> v{ 1, -3, 4, -2, 6, -8, 5 };
	printVec(v);
	vector<int> r = filter(v, [](auto x) -> bool {
		return x % 2 == 0 ? true : false;
		});
	printVec(r);
	vector<int> s = filter(v, [](auto x) -> bool {
		return x > 0;
		});
	printVec(s);

	vector<double> w{ 1.5, -3.1, 4.0, -2.0, 6.3 };
	printVec(w);
	double mn = -0.5, mx = 0.5;
	vector<double> d =
		transfilt(w, [](auto x) -> double {
		return sin(x);
			},
			[mn, mx](auto x) -> bool {
				if (x < mx && x > mn) {
					return true;
				}
			});
	printVec(w);
	printVec(d);
}