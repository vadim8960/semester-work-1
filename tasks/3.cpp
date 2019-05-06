#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

const double eps = 0.0001;

double ** create_mat(unsigned _w, unsigned _h) {
	double ** tmp = new double*[_h];
	for (unsigned iter1 = 0; iter1 < _h; ++iter1) {
		tmp[iter1] = new double[_w];
		for (unsigned iter2 = 0; iter2 < _w; ++iter2) {
			tmp[iter1][iter2] = 0;
		}
	}
	return tmp;
}

void delete_mat(double ** mat, unsigned _w, unsigned _h) {
	for (unsigned iter = 0; iter < _h; ++iter)
		delete [] mat[iter];
	delete [] mat;
}

void generate_mat(double ** mat, unsigned _w, unsigned _h, std::ifstream & in) {
	for (unsigned iter1 = 0; iter1 < _h; ++iter1)
		for (unsigned iter2 = 0; iter2 < _w; ++iter2)
			in >> mat[iter1][iter2];
}

void print_mat(double ** mat, unsigned _w, unsigned _h) {
	for (unsigned iter1 = 0; iter1 < _h; ++iter1) {
		for (unsigned iter2 = 0; iter2 < _w; ++iter2) {
			if (iter2 == _w - 1)
				cout << "| ";
			cout << std::fixed << std::setprecision(1) << 
			        std::setw(5) << mat[iter1][iter2] << ' ';
		}
		cout << '\n';
	}
	cout << "\n\n";
}

void print_ans(double * ans, double _h) {
	cout << " Answer: \n";
	for (unsigned iter = 1; iter <= _h; ++iter)
		cout << " x" << iter << " = " << ans[iter - 1] << '\n';
	cout << "\n\n";
}

bool end_loop(double * xk, double * xkp, unsigned _h) {
	double norm = 0;
	for (unsigned iter = 0; iter < _h; ++iter) 
		norm += (xk[iter] - xkp[iter]) * (xk[iter] - xkp[iter]);
	return (sqrt(norm) < eps);
}

void get_roots(double ** mat, unsigned _w, unsigned _h, double * ans_now, double * ans_past) {
	do {
		for (unsigned iter1 = 0; iter1 < _h; ++iter1)
			ans_past[iter1] = ans_now[iter1];
		for (unsigned iter1 = 0; iter1 < _h; ++iter1) {
			double val = 0;
			for (unsigned iter2 = 0; iter2 < iter1; ++iter2)
				val += (mat[iter1][iter2] * ans_now[iter2]);
			for (unsigned iter2 = iter1 + 1; iter2 < _h; ++iter2)
				val += (mat[iter1][iter2] * ans_past[iter2]);
			ans_now[iter1] = (mat[iter1][_w - 1] - val) / mat[iter1][iter1];
		}
	} while (!end_loop(ans_now, ans_past, _h));
}

int main() {
	std::ifstream in("mat_3_1");
	unsigned w, h;
	in >> w >> h;
	double ** mat = create_mat(w, h);
	generate_mat(mat, w, h, in);
	double * ans_now  = new double[h];
	double * ans_past  = new double[h];
	for (unsigned iter = 0; iter < h; ++iter) {
		ans_now[iter] = 0;
		ans_past[iter] = 0;
	}
	print_mat(mat, w, h);
	get_roots(mat, w, h, ans_now, ans_past);
	print_ans(ans_now, h);
	delete_mat(mat, w, h);
	delete [] ans_now;
	delete [] ans_past;
	return 0;
}