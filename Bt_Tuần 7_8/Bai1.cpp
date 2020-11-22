#include <iomanip>
#include <iostream>
using namespace std;
typedef int MT[20][20];

void nhapmt(MT a, char *ten, int m, int n) //nhap ma tran chu nhat
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ten << "[" << i << "][" << j << "]=";
            cin >> a[i][j];
        }
    }
};
void inmt(MT a, char *ten, int m, int n) //in ma tran chu nhat
{
    cout << "\n\tmatrix " << ten << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "\t" << setw(5) << left << a[i][j];
        }
        cout << endl;
    }
};
void nhapmt(MT a, char *ten, int n)  //nhap ma tran vuong
{
    nhapmt(a, ten, n, n);
};
void inmt(MT a, char *ten, int n) //in ma tran vuong
{
    inmt(a, ten, n, n);
};                                                 
void nhanmt(MT a, MT b,MT c, int m, int n, int p)//nhan 2 ma tran chu nhat. thu tu D=A*B*C
{ 
    //c[m,n]=a[m,p]*b[p,n]
    for(int i=0;i<m;i++){// n la chung
        for(int j=0;j<n;j++){
            c[i][j]=0; 
            for(int k=0;k<p;k++){
                c[i][j]+=a[i][k]*b[k][j];

            }       
            

        }
    }     

}; 
void nhanmt(MT a, MT b,MT c, int n) //nhan hai ma tran vuong
{
     nhanmt(a,b,c,n,n,n); 
};              

int main()
{

    char *a_ = new char;
    char *b_=new char;
    char *c_=new char;
    char *d_=new char;
    MT a,b,c,d,z;
    a_="A";
    b_="B";
    c_="C";
    d_="D";

    cout<<"-Nhap ma tran A :\n";
    nhapmt(a,a_,3,2);
    cout<<"-Nhap ma tran B :\n";
    nhapmt(b,b_,2,3);
    cout<<"-Nhap ma tran C :\n";
    nhapmt(c,c_,3);
    
    nhanmt(a,b,z,3,3,2);
    nhanmt(c,z,d,3);

    inmt(d,d_,3);
    delete a_;
    delete b_;
    delete c_;
    delete d_;
   

    system("pause");
    return 0;
}