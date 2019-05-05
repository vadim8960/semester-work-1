#include <iostream>
#include <string>
#include <cmath>

using std::cin;
using std::cout;

const double eps = 0.0001;
const double dt  = 0.01;

double lambda = 0;

enum Error {
	NO_ERROR,
	ERROR_RANGE,
	ERROR_VALUE
};

Error read_data(double &a, double &b, double &x0) {
	cout << "Enter a, b, x0: ";
	Error error = NO_ERROR;
	std::string tmp_error_string;
	if (!(cin >> a)) {
		cin.clear();
		cin >> tmp_error_string;
		error = ERROR_VALUE;
	}
	if (!(cin >> b)) {
		cin.clear();
		cin >> tmp_error_string;
		error = ERROR_VALUE;
	}
	if (!(cin >> x0)) {
		cin.clear();
		cin >> tmp_error_string;
		error = ERROR_VALUE;
	}
	if (error == ERROR_VALUE)
		return error;
	if (x0 < a || b < x0)
		return ERROR_RANGE;
	return error;
}

//x - sin(x) = 0.25
double f(double x) {
	return x - lambda * (x - sin(x) - 0.25);
}

double df(double x) {
	return 1 - cos(x);
}

double find_max_df(double a, double b) {
  double x1 = (a + b) / 2 - eps,
         x2 = (a + b) / 2 + eps;
  if (b - a < dt) {
    return df((a + b) / 2);
  }
  if (df(x1) < df(x2))
    find_max_df(x1, b);
  else
    find_max_df(a, x2);
}

int main() {
	double x, x_fut, a, b;
	while (true) {
		Error error = read_data(a, b, x);
		if (error == NO_ERROR)
			break;
		else if (error == ERROR_RANGE)
			cout << "Error! Please enter correct data (a <= x0 <= b)\n";
		else 
			cout << "Error! Please enter numbers, not string\n";
	}

	lambda = 1 / fabs(find_max_df(a, b));

	x_fut = f(x);
	while (fabs(x_fut - x) > eps) {
		x = x_fut;
		x_fut = f(x);
		cout << x << ' ' << x_fut << '\n';
	}
	cout << x_fut << '\n';
	return 0;
}