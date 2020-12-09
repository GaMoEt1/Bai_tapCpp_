#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;
class DT
{
private:
    int n;
    double *a;

public:
    DT()
    {
        this->n = 0;
        this->a = NULL;
    }
    DT(int n1)
    {
        this->n = n1;
        this->a = new double[n1 + 1];
    }
    ~DT()
    {
        if (this != NULL)
            delete[] this->a;
    }

    friend ostream &operator<<(ostream &os, const DT &d)
    {

        for (int i = d.n; i >= 0; i--)
        {
            if (i == d.n)
            {
                if (i == 0)
                    cout << d.a[i];
                else if (i == 1)
                {
                    if (d.a[i] == 1)
                        cout << "x";
                    else if (d.a[i] == -1)
                        cout << "-x";
                    else
                        cout << d.a[i] << "x";
                }

                else if (d.a[i] == 1)
                    cout << "x^" << i;
                else if (d.a[i] == -1)
                    cout << "-x^" << i;
                else
                    cout << d.a[i] << "x^" << i;
            }
            else
            {
                if (d.a[i] > 0)
                {
                    if (i == 0)
                        cout << " + " << d.a[i];
                    else if (i == 1)
                    {
                        if (d.a[i] == 1)
                            cout << " + x";

                        else
                            cout << " + " << d.a[i] << "x";
                    }
                    else if (d.a[i] == 1)
                        cout << " + "
                             << "x^" << i;
                    else
                        cout << " + " << d.a[i] << "x^" << i;
                }
                if (d.a[i] < 0)
                {
                    if (i == 0)
                        cout << " - " << -d.a[i];
                    else if (i == 1)
                    {

                        if (d.a[i] == -1)
                            cout << " - x";
                        else
                            cout << " - " << -d.a[i] << "x";
                    }

                    else if (d.a[i] == -1)
                        cout << " - "
                             << "x^" << i;
                    else
                        cout << " - " << -d.a[i] << "x^" << i;
                }
            }
        }
        return os;
    }; //show DT
    friend istream &operator>>(istream &is, DT &d)
    {
        cout << " N=" << d.n << endl;
        for (int i = d.n; i >= 0; i--)
        {
            cout << " a[" << i << "]=";
            is >> d.a[i];
        }
        return is;
    }; // nhap he so da thuc
    DT &operator-()
    {
        DT *_d = new DT(this->n);
        for (int i = 0; i <= this->n; i++)
        {

            _d->a[i] = -this->a[i];
        }
        return *_d;
    }; //ham dao dau
    DT &operator+(const DT &d2)
    {
        int x = (this->n < d2.n) ? this->n : d2.n;          // lay n nho
        DT *_d = new DT((this->n > d2.n) ? this->n : d2.n); // khoi tao voi n lon nhat
        for (int i = 0; i <= x; i++)
        {
            _d->a[i] = this->a[i] + d2.a[i];
        }
        if (this->n > d2.n)
        {
            for (int i = x + 1; i <= this->n; i++)
            {
                _d->a[i] = this->a[i];
            }
        }
        if (this->n < d2.n)
        {
            for (int i = x + 1; i <= d2.n; i++)
            {
                _d->a[i] = d2.a[i];
            }
        }
        return *_d;
    };
    DT &operator-(const DT &d2)
    {

        int x = (this->n < d2.n) ? this->n : d2.n;          // lay n nho
        DT *_d = new DT((this->n > d2.n) ? this->n : d2.n); // khoi tao voi n lon nhat
        for (int i = 0; i <= x; i++)
        {
            _d->a[i] = this->a[i] - d2.a[i];
        }
        if (this->n > d2.n)
        {
            for (int i = x + 1; i <= this->n; i++)
            {
                _d->a[i] = this->a[i];
            }
        }
        if (this->n < d2.n)
        {
            for (int i = x + 1; i <= d2.n; i++)
            {
                _d->a[i] = -d2.a[i];
            }
        }
        return *_d;
    };
    DT &operator*(const DT &d2)
    {
        DT *d = new DT(this->n + d2.n);
        for (int i = d->n; i >= 0; i--)
        {
            d->a[i] = 0;
        }
        for (int i = this->n; i >= 0; i--)
        {

            for (int j = d2.n; j >= 0; j--)
            {
                d->a[i + j] = d->a[i + j] + this->a[i] * d2.a[j];
            }
        }
        return *d;
    };
    double operator^(const double &x)
    {
        double t = 0;
        for (int i = this->n; i >= 0; i--)
        {
            t = t + static_cast<double>(this->a[i] * pow(x, i));
        }
        return t;
    }
    double operator[](const int i)
    {
        if (i < 0)
            return double(this->n);
        else
            return this->a[i];
    }
    friend double F(DT &p, double x)
    {
        double t = 0;
        for (int i = p.n; i >= 0; i--)
        {
            t += static_cast<double>(p.a[i] * pow(x, i));
        }
        return t;
    }
    DT(const DT &d)
    {
        this->n = d.n;
        this->a = new double[this->n + 1];
        for (int i = this->n; i >= 0; i--)
        {
            this->a[i] = d.a[i];
        }
    }

    DT &operator=(const DT &d)
    {
        if (this != NULL)
            delete[] this->a;
        this->n = d.n;
        this->a = new double[this->n + 1];
        for (int i = this->n; i >= 0; i--)
        {
            this->a[i] = d.a[i];
        }
        return *this;
    }
};

int main()
{
    DT p(1);
    DT q(2);
    DT r(2);
    DT s(3);
    cout << " Nhap cac he so cua p ->" << endl;
    cin >> p;
    cout << " p= " << p << endl;
    cout << " Nhap cac he so cua q ->" << endl;
    cin >> q;
    cout << " q= " << q << endl;
    cout << " Nhap cac he so cua r ->" << endl;
    cin >> r;
    cout << " r= " << r << endl;
    cout << " Nhap cac he so cua s ->" << endl;
    cin >> s;
    cout << " s= " << s << endl;
    DT f;
    f = -(p + q) * (r + s);
    cout<<"\n\n\n";
    cout <<" f=-(p+q)*(r+s)= "<<f<<endl;
    cout <<" tai x=2,tinh theo Operator^ , f(2)="<<double(f^2)<<endl;
    cout<<" tai x=2,tinh theo F,f(2)="<<F(f,2)<<endl;


    system("pause");
    return 0;
};