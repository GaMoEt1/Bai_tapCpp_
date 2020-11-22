#include <String>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
#pragma region //Bai 1
// ham tim x^n
double Pow(double x, int n)
{
    if (x == 0 && n == 0)
        return -1; // khong co gia tri
    if (x == 0)
        return 0;
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    else if (n > 1)
        return x * Pow(x, n - 1);
    else if (n < 0)
        return (double)1 / (x * Pow(x, -n - 1));
}
//hàm tìm N!
int Factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * Factorial(n - 1);
}
//
int Fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
//Viết hàm tìm số nghiệm và giá trị
//các nghiệm của phương trình bậc 2
int Root(double a, double b, double c, double *x)
{ // trả ra số ngiệm của pT bậc 2
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                return -1; // pt vo so ngiem return -1;
            return 0;      // phuong trinh vo ngiem return 0;
        }
        x[0] = static_cast<double>(-c) / b;
        return 1;
    }
    double deta = b * b - 4 * a * c;
    if (deta < 0)
        return 0;
    if (deta == 0)
    {
        x[0] = x[1] = static_cast<double>(-b) / (2 * a);
        return 1;
    }
    x[0] = static_cast<double>(-b + sqrt(deta)) / (2 * a);
    x[1] = static_cast<double>(-b - sqrt(deta)) / (2 * a);
    return 2;
}
//Viết hàm tính do K và do F tu do C

void Temperature(double c, double *k, double *f)
{
    *k = c + 273.15;
    *f = c * 1.8 + 32;
}
#pragma endregion

#pragma region //Bai 2
// in ra mang so nguyen N phan tu
void Print(const int *a, int n)
{
    cout << " ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
// ham tinh tong so nguyen co N phan tu
int Sum(const int *a, int n)
{
    if (n == 0)
        return a[0];
    return a[n] + Sum(a, n - 1);
}
// ham tinh trung binh cong
double Average(const int *a, int n)
{
    return static_cast<double>(Sum(a, n)) / n;
}
/*
Viết hàm tìm giá trị của đa thức bậc n
tại x (hệ số của đa thức là một mảng
số thực)
*/
double Sum(const double *a, int n)
{
    if (n == 0)
        return a[0];
    return a[n] + Sum(a, n - 1);
}
double Polynorm(const double *he_so, int n, double x)
{
    double *h23 = new double;
    for (int i = 0; i <= n; i++)
    {
        h23[i] = he_so[i] * Pow(x, i);
    }
    return Sum(h23, n);
}
//Viết hàm đổi xâu ký tự sang số
double Number(const char *a)
{
    double h23 = 0;
    double h24 = 0;
    string str = a;
    for (int i = 0; i < str.length(); i++)
    {
        if (str.at(i) == '.')
        {
            for (int j = i + 1; j < str.length(); j++)
            {
                h24 = h24 + static_cast<double>(str.at(j) - '0') * Pow(10, i - j);
            }
            break;
        }

        h23 = h23 * Pow(10, i) + static_cast<double>(str.at(i) - '0');
    }
    return h23 + h24;
}
// ham ma hoa ho ten tieng viet
char *Viet(char *a)
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (i == 0)  a[0] = a[0] - 32;
            if(a[i]==' '&&a[i+1]!=' '){
                a[i+1]=a[i+1]-32;
            }

    }
    return a;
}
#pragma endregion
int main()
{
    char *str = new char;


    str[0]='a';
    //    for(i=0;i<=strlen(str);i++){
    //       if(str[i]>=97&&str[i]<=122)
    //          str[i]=str[i]-32;
    //    }
    char *a;
    a=Viet(str);
    cout << " Hoa :" <<a<<endl;

    system("pause");
    return 0;
}