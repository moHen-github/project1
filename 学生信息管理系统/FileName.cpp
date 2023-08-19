#include <iostream>
#include <list>
#include <windows.h>

using namespace std;

int Select()
{
    int select;
    cout << "\n请选择： ***********0.返回菜单******************1.继续***************************\n";
    cin >> select;
    return select;
}

//复杂复杂细细琢磨
typedef struct
{
    string name;
    int age;
    string sex;
    string id;
    string phone;
}Student;
list<Student>stulist;//list容器
list<Student>::iterator stu;//定义迭代器stu用来遍历list容器

void inputStudent()
{
    cout << "\n姓名\t\t年龄\t\t性别\t\t学号\t\t电话" << endl;
    Student data;
    cin >> data.name >> data.age >> data.sex >> data.id >> data.phone;
    stulist.push_back(data);
    int select = Select();
loop1:
    if (select == 0);
    else if (select == 1)
        inputStudent();
    else
    {
        cout << "选择错误，请重新输入：\n";
        cin >> select;
        goto loop1;
    }
    return;
}

void printStudent()
{
    cout << "\n姓名\t\t年龄\t\t性别\t\t学号\t\t电话" << endl;
    for (stu = stulist.begin(); stu != stulist.end(); stu++)
        cout << (*stu).name << "\t\t" << (*stu).age << "\t\t" << (*stu).sex 
             << "\t\t" << (*stu).id << "\t" << (*stu).phone << endl;
    int select = Select();
    loop1:
    if (select == 0);
    else if (select == 1)
        printStudent();
    else
    {
        cout << "选择错误，请重新输入：\n";
        cin >> select;
        goto loop1;
    }
}

void changeStudent()
{
    string str;
    bool f = true;
    cout << "请输入要修改信息的学生学号\n";
    cin >> str;
    for (stu = stulist.begin(); stu != stulist.end(); stu++)
        if (str == (*stu).id)
        {
            cout << "请输入希望修改后的学生信息\n";
            Student data;
            cin >> data.name >> data.age >> data.sex >> data.id >> data.phone;
            *stu = data;
            cout << "修改成功！\n";
            f = !f;
            break;
        }
    if (f)
        cout << "该同学信息不存在\n";
    int select = Select();
loop1:
    if (select == 0);
    else if (select == 1)
        changeStudent();
    else
    {
        cout << "选择错误，请重新输入：\n";
        cin >> select;
        goto loop1;
    }
}

void deleteStudent()
{
    string str;
    bool f = true;
    cout << "请输入要删除信息的学生学号\n";
    cin >> str;
    for (stu = stulist.begin(); stu != stulist.end(); stu++)
        if (str == (*stu).id)
        {
            stulist.erase(stu);
            cout << "删除成功！\n";
            f = !f;
            break;
        }
    if (f)
        cout << "该同学信息不存在\n";
    int select = Select();
loop1:
    if (select == 0);
    else if (select == 1)
        deleteStudent();
    else
    {
        cout << "选择错误，请重新输入：\n";
        cin >> select;
        goto loop1;
    }
}



void searchStudent()
{
    string str;
    bool f = true;
    cout << "请输入要修改信息的学生学号\n";
    cin >> str;
    for (stu = stulist.begin(); stu != stulist.end(); stu++)
        if (str == (*stu).id)
        {
            cout << "\n姓名\t\t年龄\t\t性别\t\t学号\t\t电话" << endl;
            cout << (*stu).name << "\t\t" << (*stu).age << "\t\t" << (*stu).sex
                << "\t\t" << (*stu).id << "\t" << (*stu).phone << endl;
            f = !f;
            break;
        }
    if (f)
        cout << "该同学信息不存在\n";
    int select = Select();
loop1:
    if (select == 0);
    else if (select == 1)
        searchStudent();
    else
    {
        cout << "选择错误，请重新输入：\n";
        cin >> select;
        goto loop1;
    }
}




void menu()
{
    cout << "\n                               学生信息管理系统\n\n"
        << " *******************************************************************\n\n"
        << "\t\t\t\t 0.退出系统\n\n"
        << "\t\t\t\t 1.录入信息\n\n"
        << "\t\t\t\t 2.浏览信息\n\n"
        << "\t\t\t\t 3.修改信息\n\n"
        << "\t\t\t\t 4.删除信息\n\n"
        << "\t\t\t\t 5.查找信息\n\n"
        << " *******************************************************************\n";
}

void keydown()
{
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 0:
        exit(0);
        break;
    case 1:
        system("cls");//不懂不懂不懂不懂不懂
        cout << " ****************************【录入信息】*********************************\n";
        inputStudent();
        break;
    case 2:
        system("cls");
        cout << " ****************************【浏览信息】*********************************\n";
        printStudent();
        break;
    case 3:
        system("cls");
        cout << " ****************************【修改信息】*********************************\n";
        changeStudent();
        break;
    case 4:
        system("cls");
        cout << " ****************************【删除信息】*********************************\n";
        deleteStudent();
        break;
    case 5:
        system("cls");
        cout << " ****************************【查找信息】*********************************\n";
        searchStudent();
        break;
    default:
        cout << " 选择错误，重新输入\n";
        system("pause");
        break;
    }
}


int main()
{
    system("color F0");
    while (1)
    {
        system("cls");
        menu();
        keydown();
    }
    system("pause");
    return 0;
}

