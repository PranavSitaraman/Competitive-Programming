#include<iostream>
#include<string>
#include<cmath>
#include<complex>
#include<unordered_map>
using namespace std;
namespace std { template<> struct hash<complex<double>> { std::size_t operator()(const complex<double>& k) const { return hash<double>()(k.imag()) ^ hash<double>()(k.real()); } }; }
string cycleLength(float realPartC, float imagPartC)
{
    unordered_map<complex<double>, int> previous; complex<double> orig = { realPartC, imagPartC }, q = 0;
    for (int i = 1; ; previous[q] = i++)
    {
        if (previous.find((q = { round((pow(q, 2) + orig).real() * 100) / 100.0, round((pow(q, 2) + orig).imag() * 100) / 100.0 })) != previous.end()) return to_string(i - previous[q]);
        if (abs(q) > 4) return "ESCAPES " + to_string(i);
    }
}
void acslfibonaccimandelbrot()
{
	cout << cycleLength(-1.21, -0.32) << endl;
}