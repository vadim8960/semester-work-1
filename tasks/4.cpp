#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double eps = 0.001;

void print_vector(double * x, int size) {
    for (unsigned i = 0; i < size; ++i)
        cout << x[i] << '\n';
}

void print_mat(double ** mat, double * b, int size) {
    for (unsigned i = 0; i < size; ++i) {
        for (unsigned j = 0; j < size; ++j)
            cout << mat[i][j] << ' ';
        cout <<  " | " << b[i] << '\n';
    }
}

void read_mat(double ** mat, double * b, int size) {
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = 0; j < size; j++) 
            cin >> mat[i][j];
        cin >> b[i];
    }
}

void read_vec(double * vec, int size) {
    for (unsigned i = 0; i < size; ++i)
        cin >> vec[i];
}

double * copy_vector(double * xp, double * xn, int size) {
    for (unsigned i = 0; i < size; i++)
        xp[i] = xn[i];
}

double norm(double * xp, double * xn, unsigned size) {
    double n = 0;
    for (unsigned i = 0; i < size; ++i)
        n += (xp[i] - xn[i]) * (xp[i] - xn[i]);
    return sqrt(n);
}

double ** create_mat(unsigned size) {
    double **mat = new double*[size];
    for (unsigned i = 0; i < size; ++i)
        mat[i] = new double[size];
    return mat;
}

double * create_vector(int size) {
    double * vec  = new double[size];
    for (unsigned i = 0; i < size; i++)
        vec[i] = 0.00001;
    return vec;
}

void new_x(double ** mat, double * b, double * xn, double * xp, int size) {
    for (unsigned i = 0; i < size; i++) {
        double sum = b[i];
        for (unsigned j = 0; j < size; j++)
            if (i != j)
                sum += ( -mat[i][j] * xp[j] );
        cout << "sum = " << sum / mat[i][i] << '\n';
        xn[i] = sum / mat[i][i];
    }
    cout << "Xn = {";
    for (unsigned iter = 0; iter < size; ++iter)
        cout << xn[iter] << ' ';
    cout << "}\n";
}

int main() {
    int size;
    cin >> size;

    double ** mat = create_mat(size);
    double * b    = create_vector(size);
    double * xn   = create_vector(size);
    double * xp   = create_vector(size);

    read_mat(mat, b, size);

    print_mat(mat, b, size);
    new_x(mat, b, xn, xp, size);
    // while (norm(xp, xn, size) > eps) {
    //     copy_vector(xp, xn, size);
    //     new_x(mat, b, xn, xp, size);
    // }
    for (unsigned iter = 0; iter < 10; ++iter) {
        copy_vector(xp, xn, size);
        new_x(mat, b, xn, xp, size);
    }
    print_vector(xn, size);
    return 0;
}
