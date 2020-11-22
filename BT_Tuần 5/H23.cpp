#include <iomanip>
#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;
/*
Bài tập: Nhập vào một danh sách gồm N sinh viên có các thuộc tính sau
1. Họ tên -string 
2. Mã số -string 
3. Lớp -string 
4. Năm sinh -int 
5. Môn học: Toán, Lý, Hóa -string 

// ý là điểm từng môn học -float

6. Điểm trung bình học kỳ
Yêu cầu thực hiện chương trình sau
1. In ra tên các sinh viên có cùng năm sinh
2. In ra tên các sinh viên học cùng lớp
3. In ra tên các sinh viên cùng tên và cùng năm sinh
4. In ra sinh viên cùng lớp chỉ học môn Toán, và sinh viên học cả 3 môn.
5. Sắp xếp sinh viên theo thứ tự điểm trung bình học kỳ giảm dần.
6. In ra số lượng sinh viên có cùng điểm trung bình học kỳ.
Ưu tiên: Chương trình có phân hoạch hàm, sử dụng khai báo con trỏ hàm con trỏ biến linh
động. 
*/

#pragma region //obj
struct obj
{
    string Ho_ten;
    string Ma_so;
    string Lop;
    int Nam_sinh;
    string Mon_Hoc;
    float Diem_Tb;
    obj *obj_next;
};
#pragma endregion

#pragma region //chon mon hoc
int is_x()
{ // lua chon mon hoc
    int x;
    cout << "\n 1: Toan \n"
         << " 2: Ly \n"
         << " 3: Hoa" << endl;
    cout << " lua chon gia tri :";
    cin >> x;

    while (x < 1 || x > 3)
    {

        cout << "Xin Lua chon gia tri (1;2;3) ! :";
        cin >> x;
    }
    return x;
}
string Lua_chon_Mon(int x)
{ // tim ra mon tuong ung
    if (x == 1)
        return "Toan";
    if (x == 2)
        return "Ly";
    if (x == 3)
        return "Hoa";
}

#pragma endregion

void Update_value(obj *&obj_new)
{

    fflush(stdin);
    cout << "Ho Ten(string):";
    getline(cin, obj_new->Ho_ten);
    cout << "Ma So(string):";
    cin >> obj_new->Ma_so;
    cout << "Lop(string):";
    cin >> obj_new->Lop;
    cout << "Nam Sinh(int)<1995 ->> 2005>:";
    cin >> obj_new->Nam_sinh;
    while (obj_new->Nam_sinh < 1995 || obj_new->Nam_sinh > 2005)
    {
        cout << " xin Nhap lai !:";
        cin >> obj_new->Nam_sinh;
    }

    cout << "Mon_Hoc(string):";
    obj_new->Mon_Hoc = Lua_chon_Mon(is_x());
    cout << "Diem TB(float):";
    cin >> obj_new->Diem_Tb;
    obj_new->obj_next = NULL;
}
void Add_obj(obj *&obj_h, obj *obj_new)
{

    if (obj_h == NULL)
    {
        obj_h = obj_new;
        return;
    }
    //obj *p = obj_h->obj_next;
    // while (p != NULL)
    // {
    //     p = p->obj_next; ------------------------????????????????
    // }
    // p = obj_new;
    obj *p = obj_h;
    while (p->obj_next != NULL)
    {
        p = p->obj_next;
    }
    p->obj_next = obj_new;
}

void Show_list(obj *obj_h)
{
    obj *p = obj_h;
    int i = 1;
    cout << "\t";
    cout << setw(5) << left << "STT";
    cout << setw(20) << left << "Ho Va Ten ";
    cout << setw(15) << left << "Ma So";
    cout << setw(15) << left << "Lop";
    cout << setw(15) << left << "Nam Sinh";
    cout << setw(15) << left << "Mon Hoc";
    cout << setw(15) << left << "Diem TB";
    cout << endl;
    while (p != NULL)
    {
        cout << "\t";
        cout << setw(5) << i;
        cout << setw(20) << left << p->Ho_ten;
        cout << setw(15) << left << p->Ma_so;
        cout << setw(15) << left << p->Lop;
        cout << setw(15) << left << p->Nam_sinh;
        cout << setw(15) << left << p->Mon_Hoc;
        cout << setw(15) << left << p->Diem_Tb;
        cout << endl;
        p = p->obj_next;
        i++;
    }
}
#pragma region //

void h26(obj *obj_h)
{ //4. In ra sinh viên cùng lớp chỉ học môn Toán, và sinh viên học cả 3 môn.
    int i = 0;
    string *a = new string;
    a[0] = "     ";
    obj *p = obj_h;
    bool is_b = true;
    while (p->obj_next != NULL)
    {
        for (int j = 0; j < i; j++)
        { // xac ding co trung trong voi a khong;
            if (a[j] == p->Lop)
            {
                is_b = false;
                break;
            }
        }
        obj *k = p;
        while (is_b)
        {
            if (k->Lop == k->obj_next->Lop)
            {
                a[i] = k->Lop;
                i++;
                break;
            }
        }
        is_b = true;
        p = p->obj_next;
    }
    for (int k = 0; k < i; k++)
    {
        cout << "Lop :" << a[k] << " hoc toan" << endl;
        for (obj *j = obj_h; j != NULL; j = j->obj_next)
        {
            if (a[k] == j->Lop && j->Mon_Hoc == "Toan")
                cout << j->Ho_ten << endl;
        }
    }
}

#pragma endregion

#pragma region            //tim ra trung lap
int H(obj *obj_h, int *a) //cung nam sinh
{
    int i = 0;

    a[0] = 0;
    obj *p = obj_h;
    bool is_b = true;
    while (p->obj_next != NULL)
    {
        for (int j = 0; j < i; j++)
        { // xac ding co trung trong voi a khong;
            if (a[j] == p->Nam_sinh)
            {
                is_b = false;
                break;
            }
        }
        obj *k = p;
        while (is_b)
        {
            if (k->Nam_sinh == k->obj_next->Nam_sinh)
            {
                a[i] = k->Nam_sinh;
                i++;
                break;
            }
            break;
        }
        is_b = true;
        p = p->obj_next;
    }
    return i;
}
int H(obj *obj_h, string *s) //cung lop
{

    int i = 0;
    s[0] = "     ";
    obj *p = obj_h;
    bool is_b = true;
    while (p->obj_next != NULL)
    {
        for (int j = 0; j < i; j++)
        {
            if (s[j] == p->Lop)
            {
                is_b = false;
                break;
            }
        }
        obj *k = p;
        while (is_b)
        {
            if (k->Lop == k->obj_next->Lop)
            {
                s[i] = k->Lop;
                i++;
                break;
            }
            break;
        }
        is_b = true;
        p = p->obj_next;
    }
    return i;
}

int H(obj *obj_h, string *s, int *a) //cung ten va nam sinh
{

    int i = 0;
    a[0] = 0;
    s[0] = "     ";
    obj *p = obj_h;
    bool is_b = true;
    while (p->obj_next != NULL)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] == p->Nam_sinh && s[j] == p->Ho_ten)
            {
                is_b = false;
                break;
            }
            break;
        }
        obj *k = p;
        while (is_b)
        {
            if (k->Nam_sinh == k->obj_next->Nam_sinh && k->Ho_ten == k->obj_next->Ho_ten)
            {
                a[i] = k->Nam_sinh;
                s[i] = k->Ho_ten;
                i++;
                break;
            }
        }
        is_b = true;
        p = p->obj_next;
    }
    return i;
}
#pragma endregion
#pragma region       //show gia tri
void H23(obj *obj_h) // 1.
{
    int *a = new int;
    int i = H(obj_h, a);
    if(i==0) {
        cout<<" _______________khong co du lieu nao nhu vay________________ ";
        return;
    }
    for (int k = 0; k < i; k++)
    {
        cout << "Nam :" << a[k] << endl;
        for (obj *j = obj_h; j != NULL; j = j->obj_next)
        {
            if (a[k] == j->Nam_sinh)
                cout << j->Ho_ten << endl;
        }
    }
}

void H24(obj *obj_h)
{ // 2.
    string *s = new string;
    int i = H(obj_h, s);
    if(i==0) {
        cout<<" _______________khong co du lieu nao nhu vay________________ ";
        return;
    }
    for (int k = 0; k < i; k++)
    {
        cout << "Lop :" << s[k] << endl;
        for (obj *j = obj_h; j != NULL; j = j->obj_next)
        {
            if (s[k] == j->Lop)
                cout << j->Ho_ten << endl;
        }
    }
}

void H25(obj *obj_h)
{ //3.
    int *a = new int;
    string *s = new string;
    int i = H(obj_h, s, a);
    if(i==0) {
        cout<<" _______________khong co du lieu nao nhu vay________________ ";
        return;
    }
    for (int k = 0; k < i; k++)
    {
        cout << "cung ten : " << s[k] << " cung nam: " << a[k] << endl;
        for (obj *j = obj_h; j != NULL; j = j->obj_next)
        {
            if (a[k] == j->Nam_sinh && s[k] == j->Ho_ten)
                cout << j->Ho_ten << "   " << j->Nam_sinh << endl;
        }
    }
}
void H26(obj *obj_h) //4.
{
    string *s = new string;
    int i = H(obj_h, s);
    if(i==0) {
        cout<<" _______________khong co du lieu nao nhu vay________________ ";
        return;
    }
    for (int k = 0; k < i; k++)
    {
        cout << "cung lop  : " << s[k] << " va hoc mon toan" << endl;
        for (obj *j = obj_h; j != NULL; j = j->obj_next)
        {
            if (s[k] == j->Lop && j->Mon_Hoc == "Toan")
                cout << j->Ho_ten << endl;
        }
    }
}
// ham hoan doi
void Swap_data_Obj(obj *p, obj *q)
{
    string name = p->Ho_ten;
    string code = p->Ma_so;
    string class_ = p->Lop;
    string subject = p->Mon_Hoc;
    int year = p->Nam_sinh;
    float point_av = p->Diem_Tb;
    //
    p->Ho_ten = q->Ho_ten;
    p->Diem_Tb = q->Diem_Tb;
    p->Ma_so = q->Ma_so;
    p->Lop = q->Lop;
    p->Mon_Hoc = q->Mon_Hoc;
    p->Nam_sinh = q->Nam_sinh;
    //
    q->Nam_sinh = year;
    q->Diem_Tb = point_av;
    q->Lop = class_;
    q->Mon_Hoc = subject;
    q->Ho_ten = name;
    q->Ma_so = code;
}
void Sort_Obj(obj *&p)
{
    if (p == NULL)
        return;
    for (obj *i = p; i->obj_next != NULL; i = i->obj_next)
    {
        obj *j;
        j = i->obj_next;
        while (j != NULL)
        {
            if (i->Diem_Tb < j->Diem_Tb)
                Swap_data_Obj(i, j);
            j = j->obj_next;
        }
    }
}
#pragma endregion
// gia phong bo nho
void Free_data(obj *&obj_h)
{
    obj *p;
    while ((p = obj_h) != NULL)
    {
        obj_h = obj_h->obj_next;
        delete p;
    }
}

#pragma region //set color
/*
Name   | Value 
      | 
Black  | 0 
Blue   | 1 
Green  | 2 
Cyan   | 3 
Red   | 4 
Magenta  | 5 
Brown  | 6 
Light Gray | 7 
Dark Gray | 8 
Light Blue | 9 
Light Green | 10 
Light Cyan | 11 
Light Red | 12 
Light Magenta| 13 
Yellow  | 14 
White  | 15 
*/
void SetColor(int ForgC) 
{ 
    WORD wColor; 

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 
     CONSOLE_SCREEN_BUFFER_INFO csbi;         
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) 
    {       
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F); 
      SetConsoleTextAttribute(hStdOut, wColor); 
    } 
    return; 
} 
#pragma endregion
int main()
{
   SetColor(6);
 /*
_________________________________________________

6. In ra số lượng sinh viên có cùng điểm trung bình học kỳ..........11 59" 

*/  
    obj *obj_h;
    obj_h = NULL;
    int n;
    cout << "Nha So Luong N=";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "===============No." << i + 1 << "=================" << endl;
        obj *p = new obj;
        Update_value(p);
        Add_obj(obj_h, p);
        system("cls");
    }
    
    cout << "\t\t\t\t\t"
         << "Danh sach sinh vien ^(-_-)^\n\n";
    Show_list(obj_h);
    cout << "\n\n\n\n";
    //-----------------------Tao MENU-------------------------------------------
    string ol;
    cout << "\t\t 1. Ten Cac sinh vien Co cung nam sinh " << endl;    //1
    cout << "\t\t 2. Ten sinh co cung ma lop " << endl;               //2
    cout << "\t\t 3. Cung Ten va nam sinh" << endl;                   //3
    cout << "\t\t 4. Ten sinh vien cung lop va hoc mon toan" << endl; //4
    cout << "\t\t 5. Sap xep gia tri trung binh giam dan" << endl;    //5
    while (true)
    {
        cout << "\n xin nhap lua chon :";
        cin >> ol;
        while (ol.at(0) != '1' && ol.at(0) != '2' && ol.at(0) != '3'&& ol.at(0) != '4' && ol.at(0) != '5')
        {
            cout << "xin nhap lai :";
            cin >> ol;
        }
        if (ol.at(0) == '1')
            H23(obj_h);
        if (ol.at(0) == '2')
            H24(obj_h);
        if (ol.at(0) == '3')
            H25(obj_h);
        if (ol.at(0) == '4')
            H26(obj_h);
        if (ol.at(0) == '5')
        {
            cout << " danh sach sau khi sap xep:" << endl;
            Sort_Obj(obj_h);
            Show_list(obj_h);
        }
    }

    
    system("pause");
    return 0;
}