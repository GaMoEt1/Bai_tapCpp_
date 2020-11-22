#include <iostream>
#include<iomanip>
using namespace std;
int main(){
    int n1,n2;
   
    float *f =new float[n1+n2];
    cout<<" nhap so phan tu mang f1 =";cin>>n1;
    cout<<" nhap so phan tu mang f2 =";cin>>n2;
    cout<<" nhap mang f1 theo gia tri tang dan :"<<endl;
    for(int i=0;i<n1;i++){// nhap mang 1
        if(n1==0) break;
        if(i==0) {
            cout<<" f1["<<i<<"]=";
            cin>>f[i];
        }
        else {
            cout<<" f1["<<i<<"]=";
            cin>>f[i];
            while(f[i]<=f[i-1]){
                cout<<" xin nhap lai gia tri cua f1["<<i<<"]=";cin>>f[i];

            }

        }        
    }
    for(int i=n1;i<n2+n1;i++){// nhap mang 2
        if(n2==0) break;
        if(i==n1) {
            cout<<" f2["<<i<<"]=";
            cin>>f[i];
        }
        else {
            cout<<" f2["<<i<<"]=";
            cin>>f[i];
            while(f[i]<=f[i-1]){
                cout<<" xin nhap lai gia tri cua f2["<<i<<"]=";cin>>f[i];

            }

        }  
    }
    cout<<"\n gop 2 mang thang mang f :";
    int swap;
    for(int i=0;i<n1+n2-1;i++){// ham sap xep f
        for(int j=i+1;j<n1+n2;j++){
            if(f[i]>f[j]) {
                swap=f[i];
                f[i]=f[j];
                f[j]=swap;
            }
        }

    }
    for (int i = 0; i < n1+n2; i++)// ham show 
    {
        cout<<setw(3)<<f[i];
    }
    

    system("pause");
    return 0;
}