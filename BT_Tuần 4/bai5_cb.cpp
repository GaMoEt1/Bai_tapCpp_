#include <iostream>
using namespace std;
int main(){
    string str;
    
    char *t=new char;
    while(true){
         cout<<" nhap chuoi str =";cin>>str;
         cout<<" tao mang tuong ung : "<<endl;
    for(int i=0;i<str.length();i++){
        t[i]=str.at(i);
        cout<<" t["<<i<<"]="<<t[i]<<endl;

    }
    }
   
    
    system("pause");
    return 0;
}