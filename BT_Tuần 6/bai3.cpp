#include <iostream>
using namespace std;
// a[i][j]=*(*(a+i)+j)

void Nhap(int N, int *mangA)
{
    for (int i = 0; i < N; i++)
    {
        cout << " mangA[" << i << "]=";
        cin >> mangA[i];
    }
}
void Swap_A(int &x, int &y)
{
    int i = x;
    x = y;
    y = i;
}
int *SapXep(int N, int *mangA) // theo tang dan
{

    for (int i = 0; i < N-1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (mangA[i] <= mangA[j])
                continue;

            Swap_A(mangA[i], mangA[j]);
        }
    }
    return mangA;
}
int **TanSuat(int N, int *mangA)
{
    int **p = new int *[2];
    p[0] = new int[N]; //p[0][i] value
    p[1] = new int[N]; //p[1][i] frequency

    for (int i = 0; i < N; i++)
    {
        p[0][i] = mangA[i];
        p[1][i] = 1;
    }
    for (int i = 0; i < N -1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            if (p[0][i] == mangA[j])
            {
                p[1][i]++;
            }
        }
    }
    return p;
}
void Show_mangA(int N, int *mangA)
{
    for (int i = 0; i < N; i++)
    {
        cout << mangA[i] << " ";
    }
}
int main()
{
    int N;

    cout << " nhap gia tri cua N =";
    cin >> N;
    int *mangA = new int[N];
    Nhap(N, mangA);
    cout << " Mang da nhap la : ";
    Show_mangA(N, mangA);
    cout << "\n Mang da sap xep la : ";
    //  int *mangB=SapXep(N,mangA);
    int **h23 = TanSuat(N, mangA);
    Show_mangA(N, SapXep(N, mangA));
    int k;
    cout<<endl;
    for (int i = 0; i < N; i++)
     {
        if (i == 0)
        {
            cout << " so :" << h23[0][i] << " xuat hien " << h23[1][i] << endl;
            
            
        }
          //cout << " so :" << h23[0][i] << " xuat hien " << h23[1][i] << endl;
        
        else {
             k=0;
            for(int j=0;j<i;j++){
                if(mangA[j]==mangA[i]) {k=1; break;}
            }
            while(k!=1){
                cout << " so :" << h23[0][i] << " xuat hien " << h23[1][i] << endl;
                k=1;
            }
        }
    }

    system("pause");
    return 0;
}