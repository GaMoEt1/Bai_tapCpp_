#include <iostream>
using namespace std;
int main(){
    string s1,s2;
    cout<<" nhap chuoi s1:";cin>>s1;
    cout<<" nhap chuoi s2:";cin>>s2;
    if(s1.length()!=s2.length()) cout<<" s1 != S2";
    else{

        for (int i = 0; i < s1.length(); i++)
        {
            if(s1.at(i)!=s2.at(i)) {
                cout<<" s1 != S2";
                break;
            }
        }
        cout<<" s1 == s2 ";
    }
    cout<<endl;
    
    system("pause");
    return 0;
}