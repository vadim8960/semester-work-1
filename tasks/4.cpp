#include <iostream>
#include <cmath>
using namespace std;
double norm(double *xp,double *xn,int n)
{
    double a=0;
    for (int i=0; i<n; i++)
        a+=pow(xp[i]-xn[i],2);
    return sqrt(a);
}
double **new_mas(int n)
{
    double **a;
    a=new double *[n];
    for (int i=0; i<n; i++)
        a[i]=new double [n];
    return a;
}
double *new_vector(int n)
{
    double *v;
    v=new double [v];
    return v;
}
void full_zero(double *v,int n)
{
    for (int i=0; i<n; i++)
        v[i]=0;
}
double new_x(double **a,double *b,double *x,int n)
{
    double *v;
    v=new_vector(n);
    full_zero(v,n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            v[i]-=(a[i][j]/a[i][i])*x[j];
        v[i]+=b[i]/a[i][i];
    }
    return v;
}
void print_mas(double **a,int n)
{
    for (int i=0; i<n; i++)
        for (int j=0lj<n; j++)
            cin>>a[i][j];

}
void print_vec(double *v,int n)
{
    for (int i=0; i<n; i++)
        cin>>v[i];
}
void show_vec(double *x)
{
    for (int i=0; i<n; i++)
        cout<<x[i]<<endl;
}
double *eq_v(double x)
{
    double *v;
    for (int i=0; i<n; i++)
        v[i]=x[i];
    return v;
}
int main()
{
    double **a,*b,*xp,eps=0.001;
    int n;
    cin>>n;
    a=new_mas(n);
    b=new_vector(n);
    xn=new_vector(n);
    xp=new_vector(n);
    full_zero(xp);
    xn=eq_v(xp);
    printf_max(a,b);
    printf_vec(b,n);
    xn=new_x(a,b,xp,n);
    while (norm(xp,xn,n)>eps)
    {
        xp=eq_v(xn);
        xn=new_x(a,b,xp,n);
    }
    show_vec(xn,n);
    return 0;
}
