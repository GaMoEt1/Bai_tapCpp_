#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*
Bài 2: Tham khảo cách viết hàm và tổ chức CT bài 1, thực hiện các hàm sau
– Nhập dãy cấu trúc (mỗi cấu trúc chứa dữ liệu 1 thí sinh: Tên, Tổng điểm)
– Hoán vị hai biến cấu trúc
– Sắp xếp dãy thí sinh theo thứ tự giảm dần của tổng điểm
– In một biến cấu trúc
Yêu cầu: CT sẽ nhập dữ liệu một ds thí sinh, nhập điểm chuẩn và in ra ds thí sinh trúng tuyển 
*/
struct thi_sinh
{
    string name;
    float s_point;
    thi_sinh *pNext;
};
void Update_data(thi_sinh *&p, string name, float point_s)
{
    p->name = name;
    p->s_point = point_s;
    p->pNext = NULL;
}
void Add_thi_sinh(thi_sinh *&p, thi_sinh *new_p)
{
    if (p == NULL)
    {
        p = new_p;
        return;
    }
    thi_sinh *q = p;
    while (q->pNext != NULL)
    {
        q = q->pNext;
    }
    q->pNext = new_p;
}
void SwapDataTo_tS(thi_sinh *&p, thi_sinh *&q)
{
    string str = p->name;
    float is_point = p->s_point;
    //
    p->s_point = q->s_point;
    p->name = q->name;
    //
    q->name = str;
    q->s_point = is_point;
}

void sap_xep_giam_dan(thi_sinh *&p)
{
    if (p == NULL)
        return;
    for (thi_sinh *i = p; i->pNext != NULL; i = i->pNext)
    {
        thi_sinh *j;
        j = i->pNext;
        while (j != NULL)
        {
            if (i->s_point < j->s_point)
                SwapDataTo_tS(i, j);
            j = j->pNext;
        }
    }
}
thi_sinh *is_a_point(thi_sinh *p, float diem_chuan)
{
    if (p == NULL)
        return NULL;
    thi_sinh *q;
    q = NULL;
    for (thi_sinh *i = p; i != NULL; i = i->pNext)
    {
        if (i->s_point < diem_chuan)
            break; // truoc do da sap xep diem theo thu tu giam dan
        thi_sinh *t = new thi_sinh;
        Update_data(t, i->name, i->s_point);
        Add_thi_sinh(q, t);
    }
    return q;
}

void ShowList(thi_sinh *p)
{
    thi_sinh *q = p;
    int i = 1;
    cout << "\t";
    cout << setw(5) << left << "STT";
    cout << setw(20) << left << "Ho Va Ten";
    cout << setw(15) << left << "Tong Diem";
    cout << endl;
    while (q != NULL)
    {
        cout << "\t";
        cout << setw(5) << left << i;
        cout << setw(20) << left << q->name;
        cout << setw(15) << left << q->s_point;
        cout << endl;
        q = q->pNext;
    }
}
void Free_data(thi_sinh *&p)
{
    thi_sinh *q;
    while ((q = p) != NULL)
    {
        p = p->pNext;
        delete q;
    }
}
int main()
{
    thi_sinh *root;
    root = NULL;
    int N;
    cout << "Nhap so luong danh sach thi vien N(int)=";
    cin >> N;
    while (N < 0)
    {
        cout << "Xin nhap lai (N>=0),N=";
        cin >> N;
    }
    if (N == 0)
        cout << "\nDanh sach rong (^_^)! \n\n";
    else
    {
        for (int i = 0; i < N; i++)
        {
            cout << "===============No." << i + 1 << "=================" << endl;
            thi_sinh *p = new thi_sinh;
            fflush(stdin);
            cout << "Ho Va Ten(string) :";
            getline(cin, p->name);
            cout << "Tong diem(float) :";
            cin >> p->s_point;
            p->pNext = NULL;
            Add_thi_sinh(root, p);
            system("cls");
        }
        cout << "\n______________________Danh sach chua duoc sap xep__________________\n" << endl;
        ShowList(root);
        cout << "\n_______________________Danh sach da duoc sap xep___________________\n" << endl;
        sap_xep_giam_dan(root);
        ShowList(root);
        cout<<"\n\n\n nhap diem chuan trung tuyen :";
        float x;cin>>x;
        thi_sinh *q;q=NULL;
        q=is_a_point(root,x);
        if(q==NULL) cout<<"\n KHong co thi sinh nao trung tuyen !"<<endl;
        else {
             cout<<"\n______________________Danh sach thi sinh trung tuyen_________________\n"<<endl;
        ShowList(q);
        }        
        Free_data(root);
        Free_data(q);

    

    }

    system("pause");
    return 0;
}