#include <iostream>
#include<iomanip>
using namespace std;
int main(){
    int n;
    int *a=new int[n];
    cout<<"nhap so nguyen n=";cin>>n;
    for(int i=0;i<n;i++){
        cout<<"a["<<i<<"]=";cin>>a[i];
    }
    cout<<"gia tri cua day so :";
    for(int j=n-1;j>=0;j--){
        cout<<setw(3)<<a[j];

    }
    cout<<endl;
    system("pause");
    return 0;
}