#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double eps = 0.001;

int main() {
    cout.precision(4);
    cout.setf(ios::fixed);
    int n, flag = 0, count = 0;
    cout << "\nEnter the no. of equations\n";           
    cin >> n;        
    double mat[n][n + 1];
    double x[n] = {};    
    double y;

    cout << "\nEnter the elements of the augmented matrix row-wise:\n";
    for (unsigned i = 0; i < n; i++)
        for (unsigned j = 0; j <= n; j++)
            cin >> mat[i][j];

    for (unsigned i = 0; i < n; i++)
        for (unsigned k = i + 1; k < n; k++)
            if (abs(mat[i][i]) < abs(mat[k][i]))
                for (unsigned j = 0; j <= n; j++) {
                    double temp = mat[i][j];
                    mat[i][j] = mat[k][j];
                    mat[k][j] = temp;
                }
    }

    cout << "\nIter" << setw(10);
    for(unsigned i = 0; i < n; i++)
        cout << "x" << i << setw(18);
    cout << "\n----------------------------------------------------------------------\n";

    do {
    	flag = 0;
        cout << count + 1 << "." << setw(16);
        for (unsigned i = 0; i < n; i++) {
            y = x[i];
            x[i] = mat[i][n];
            for (unsigned j = 0; j < n; j++) {
                if (j != i)
                	x[i] = x[i] - mat[i][j] * x[j];
            }
            x[i] = x[i] / mat[i][i];
            if (abs(x[i] - y) <= eps) 
                flag++;
            cout << x[i] << setw(18);
        }
        cout << "\n";
        count++;   
    } while(flag < n);        
   
    cout << "\n The solution is as follows:\n";
    for (unsigned i = 0; i < n; i++)
        cout << "x" << i << " = " << x[i] << endl; 
    return 0;
}