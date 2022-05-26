#include <iostream>
#include <cmath>
using namespace std;

bool possibleTriang(double x, double y, double z) {
	return (x + y) > z && (x + z) > y && (y + z) > x;
}

double PL(double x, double y, double z) {
	if (possibleTriang(x, y, z)) {
		double p = (x + y + z) / 2;
		return sqrt(p * (p - x) * (p - y) * (p - z));
	}
	else {
		cout << "impossible to build triangle \n"; // якщо не можна побудувати з заданих відрвзків
		return 0;
	}
}

int main()
{
	double a, b, c, d;

	cout << "Enter a,b,c,d: \n";
	cout << "a: ";
	cin >> a;
	cout << endl;
	cout << "b :";
	cin >> b;
	cout << endl;
	cout << "c :";
	cin >> c;
	cout << endl;
	cout << "d :";
	cin >> d;
	cout << endl;

	cout << "Triangle formed by a, b, c:" << PL(a, b, c) << "\n\n";
	cout << "Triangle formed by a, b, d:" << PL(a, b, d) << "\n\n";
	cout << "Triangle formed by b, c, d:" << PL(b, c, d) << "\n\n";
	cout << "Triangle formed by a, c, d:" << PL(a, c, d) << "\n\n";
}

// Лещинський Богдан КА-07 Microsoft Visual Studio