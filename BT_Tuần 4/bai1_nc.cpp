#include <iostream>
#include<iomanip>
using namespace std;
int tan_suat(int *a;int x){
    int dem=1;
    for(int i=0;i<10;i++){
        if(i==x) continue;
        if(a[i]==a[x]) dem=++;
    }
}
int main(){
    
    int *a=new int[10];
    for (int i = 0; i < 10; i++)
    {
        cout<<"s"<<i+1<<" =";cin>>a[i];
    }
    


    
    system("pause");
    return 0;
}