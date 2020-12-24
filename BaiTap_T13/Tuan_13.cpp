#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#pragma region // đoạn code đề bài ra

class person
{
private:
    int id;
    string name;
    string gender;
    person *next;

public:
    person(int _id = 0, string _name = "unknow", string _gender = "unknow", person *_next = NULL)
    {
        id = _id;
        name = _name;
        gender = _gender;
        next = _next;
    }
    person(const person &per1)
    {
        id = per1.id;
        name = per1.name;
        gender = per1.gender;
        next = per1.next;
    }
    person &operator=(const person &per2)
    {
        id = per2.id;
        name = per2.name;
        gender = per2.gender;
        next = per2.next;
        return *this;
    }
    ~person()
    {
        if (next != NULL)
            next = NULL;
        // next = NULL;
    }
    void input_pers(int &id, string &name, string &gender)
    {
        cout << "nhap ma dinh danh: ";
        cin >> id;
        cout << "\n nhap ho ten: ";
        cin.ignore(1);
        getline(cin, name);
        cin.ignore(1);
        cout << "\n nhap gioi tinh: ";
        getline(cin, gender);
    }
    void swap(person &pers2)
    {
        person tmp = *this;
        *this = pers2;
        pers2 = tmp;
    }
    void display()
    {
        cout << "Person:\n";
        cout << "ID:\t" << id << endl;
        cout << "Name:\t" << name << endl;
        cout << "Gender:\t" << gender << endl;
    }
    friend class listofperson;
};

//khai bao lop danh sach doi tuong person

class listofperson
{
private:
    person *firstpers;
   
public:
    listofperson()
    {
        this->firstpers = NULL;
    }
    void lopers_Init(listofperson *lofpers)
    {
        lofpers->firstpers = NULL;
    }
    void add_pers(listofperson *lofpers, person &per2)
    {
        if (lofpers->firstpers == NULL)
            lofpers->firstpers = &per2;
        else
        {
            person *p = lofpers->firstpers;
            per2.next = p;
            lofpers->firstpers = &per2;
        }

    }; //ham them doi tuong person vao danh sach
    void dd_pers_Final_input(listofperson *lofpers, person &per2)
    {
        if (lofpers->firstpers == NULL)
            lofpers->firstpers = &per2;
        else
        {
            person *p = lofpers->firstpers;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = &per2;
        }

    }; //ham them doi tuong person vao cuoi danh sach
    int lofperson_Length(listofperson *lofpers)
    {
        int i = 0;
        person *p = lofpers->firstpers;
        while (p != NULL)
        {
            p = p->next;
            i++;
        }
        return i;
    };
    void lofpers_Display(listofperson *lofpers)
    {
        int t = 0;
        cout << setw(8) << left << "stt" << setw(14) << left << "ID"
             << setw(30) << left << "Full Name " << setw(8) << left << "GenDer" << endl;
        for (person *i = lofpers->firstpers; i != NULL; i = i->next)
        {
            t++;
            cout << setw(8) << left << t << setw(14) << left << i->id
                 << setw(30) << left << i->name << setw(8) << left << i->gender << endl;
        }
    };
    person *lofperson_Search(listofperson *lofpers, string name)
    {
        for (person *i = lofpers->firstpers; i != NULL; i = i->next)
        {
            if (name == i->name)
                return i;
        }
        return NULL;
    };
    void lofpers_RemoveAfter(person *node)
    {
        person *p = this->firstpers;
        if (p == NULL)
            return;
        if (p == node)
        {
            this->firstpers = this->firstpers->next;
            return;
        }
        while (p->next != node)
        {
            p = p->next;
        }
        if (p->next->next == NULL)
            p->next = NULL;
        else
        {
            p->next = p->next->next;
        }
    };
    void sortListPerson(listofperson *lofpers)
    {
        //     if (lofpers->firstpers == NULL)
        //         return;
        for (person *i = lofpers->firstpers->next; i != NULL; i = i->next)
        {

            for (person *j = lofpers->firstpers; j != i; j = j->next)
            {

                if (i->id < j->id)
                {
                    int _id = j->id;
                    string _name = j->name;
                    string _gender = j->gender;
                    j->id = i->id;
                    j->name = i->name;
                    j->gender = i->gender;
                    i->id = _id;
                    i->name = _name;
                    i->gender = _gender;
                }
            }
        }
    };
};
class student : public person
{
    int stuID;
    string clas;
   

public:
    student(int _id = 0, string _name = "unknow", string _gender = "unknow", person *_next = NULL,
            int _stuID = 0, string _clas = "unknow") : person(_id, _name, _gender, _next)
    {
        this->stuID = _stuID;
        this->clas = _clas;
        
    }
    
    student(const student &stu1) : person(stu1)
    {
        stuID = stu1.stuID;
        clas = stu1.clas;
    }

    student &operator=(const student &stu2)
    {
        person::operator=(stu2);
        stuID = stu2.stuID;
        clas = stu2.clas;
        return (*this);
    }
    void display()
    {
        person::display();
        cout << "student ID:\t" << stuID << endl;
        cout << "Class:\t" << clas << endl;
    }
    friend class list_std;
};

#pragma endregion
#pragma region student list
class list_std : private listofperson
{
private:
public:
    student *head;
    list_std()
    {
        this->head = NULL;
    }
    void add_head(student *std_)
    {

        listofperson::add_pers(this, *std_);
        
        
    }
    void add_final(student *std_)
    {
        listofperson::dd_pers_Final_input(this, *std_);
    }
    void show()
    {

       
        
    }
};
#pragma endregion
int main()
{
#if true // doan code de bai cho
    person per1(01, "nguyen van a", "male");
    person per2 = per1;
    cout << "thong tin nguoi 2: " << endl;
    per2.display();
    person per3(02, "nguyen van b", "male");
    per3.swap(per2);
    per2.display();
    listofperson lofpers;
    lofpers.lopers_Init(&lofpers);
    lofpers.add_pers(&lofpers, per1);
    lofpers.add_pers(&lofpers, per2);
    lofpers.add_pers(&lofpers, per3);
    lofpers.sortListPerson(&lofpers);
    cout << "\nnoi dung list 1 " << endl;
    lofpers.lofpers_Display(&lofpers);
    student std1(01, "le thi mai", "female", NULL, 0022, "ET4");
    student std2(02, "le thi hoa", "female", NULL, 0023, "ET4");
    std1.display();
    per2 = std1;
    per2.display();
#endif

    
    system("pause");
    return 0;
}