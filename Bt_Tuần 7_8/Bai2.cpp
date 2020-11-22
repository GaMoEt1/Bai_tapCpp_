#include<iostream>
#include<fstream>
using namespace std;
typedef struct
{
    int a, b;
}PS;
ostream& operator<< (ostream& os, PS p){
    os<<p.a<<"/"<<p.b;
    return os;

};
istream& operator>> (istream& is, PS& p){
    cout<<" Nhap tu so:";is>>p.a;
    cout<<" Nhap mau so: ";is>>p.b;
    if(p.b==0) {
        cout<<" Xin nhap lai mau so :";
        cin>>p.b;
        }
    return is;

};

int ucln(int x,int y){
    if(y==0) return x;
    return ucln(y,x%y);
    
}
PS rutgon(PS p){
    int t=ucln(p.a,p.b);
    p.a=p.a/t;
    p.b=p.b/t;
    return p;
}

PS operator +(PS p1, PS p2){
    PS p;
    p.a=p1.a*p2.b+p1.b*p2.a;
    p.b=p2.b*p1.b;
    return rutgon(p);
    
};
PS operator-(PS p1, PS p2){
    PS p;
    p.a=p1.a*p2.b-p1.b*p2.a;
    p.b=p1.b*p2.b;
    
    return rutgon(p);
};
PS operator*(PS p1, PS p2){
    PS p;
    p.a=p1.a*p2.a;
    p.b=p1.b*p2.b;
    return rutgon(p);
};

int main(){ 

    PS p1,p2;
    cout<<" Nhap p1 :"<<endl;
    cin>>p1;
    cout<<" p1="<<p1<<endl;
    
    cout<<" Nhap p2 :"<<endl;
    cin>>p2;
    cout<<" p2="<<p2<<endl;
    cout<<endl;
    cout<<" p1+P2="<<p1+p2<<endl;
    cout<<" p1-p2="<<p1-p2<<endl;
    cout<<" p1*p2="<<p1*p2<<endl;
    

    system("pause");
    return 0;
}