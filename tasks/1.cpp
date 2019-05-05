#include <iostream>
#include <cmath>

using namespace std;

const double eps = 0.0001;
const double dt  = 0.01;

double lambda = 0;

//x - sin(x) = 0.25
double f(double x) {
	return x - lambda * (x - sin(x) - 0.25);
}

// double f(double x) {
// 	return x - sin(x) - 0.25;
// }

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
	cin >> a >> b >> x;
	lambda = 1 / fabs(find_max_df(a, b));

	cout << lambda << '\n';

	x_fut = f(x);
	while (fabs(x_fut - x) > eps) {
		x = x_fut;
		x_fut = f(x);
		cout << x << ' ' << x_fut << '\n';
	}
	cout << x_fut << '\n';
	return 0;
}