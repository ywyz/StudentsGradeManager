#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "data.h"
#include "manager.h"

using namespace std;
vector<Student> student;
vector<Course> course;
vector<Choose> choose;
void DisplayMessage::displayMenu()
{
    cout << "1.导入初始数据：" << endl;
    cout << "2.显示信息：" << endl;
    cout << "3.输入记录：" << endl;
    cout << "4.删除记录：" << endl;
    cout << "5.查询信息：" << endl;
    cout << "6.编辑记录：" << endl;
    cout << "7.去重：" << endl;
    cout << "8.批量导出数据：" << endl;
    cout << "0.退出：" << endl;
    cout << "请输入您的选择：";
}

void DisplayMessage::displayStudent()
{
    cout << "学生信息显示：" << endl;
    cout << "学生姓名    学生年龄    学生性别    学生学号" << endl;
    for (auto& item : student)
    {
        cout << item.name << "  " << item.age << "  " << item.sex << "  " << item.id << endl;
    }
}

void DisplayMessage::displayCourse()
{
    cout << "课程信息显示：" << endl;
    cout << "课程名称    课程学分    课程号" << endl;
    for (auto& item : course)
    {
        cout << item.name << "  " << item.credit << "  " << item.id << endl;
    }
}

void DisplayMessage::displayChoose()
{
    cout << "选课信息显示：" << endl;
    cout << "学生学号    课程号    成绩" << endl;
    for (auto& item : choose)
    {
        cout << item.student_id << "  " << item.course_id << "  " << item.score << endl;
    }
}

void DisplayMessage::displayStudent(Student stu)
{
    cout << "学生信息显示：" << endl;
    cout << "学生姓名: " << stu.name << endl;
    cout << "学生年龄：" << stu.age << endl;
    cout << "学生性别：" << stu.sex << endl;
    cout << "学生学号：" << stu.id << endl;
}

void DisplayMessage::displayCourse(Course cou)
{
    cout << "课程信息显示：" << endl;
    cout << "课程名称：" << cou.name << endl;
    cout << "课程学分：" << cou.credit << endl;
    cout << "课程号：" << cou.id << endl;
}

void DisplayMessage::displayChoose(Choose cho)
{
    cout << "选课信息显示：" << endl;
    cout << "学号：" << cho.student_id << endl;
    cout << "课程号：" << cho.course_id << endl;
    cout << "成绩：" << cho.score << endl;
}

void DisplayMessage::displayMessage(int i)
{
    
    switch (i)
    {
    case 1:
    {
        cout << "请输入文件名称（default:data.txt）: ";
        break;
    }
    case 2:
    {
        cout << "请输入需要显示的信息：" << endl;
        cout << "1.全部学生信息" << endl;
        cout << "2.全部课程信息" << endl;
        cout << "3.全部选课信息" << endl;
        break;
    }
    case 3:
    {
        cout << "请选择需要编辑的信息：" << endl;
        cout << "1.学生信息" << endl;
        cout << "2.课程信息" << endl;
        cout << "3.选课信息" << endl;
        break;
    }
    case 4:
    {
        cout << "请选择需要删除的信息：" << endl;
        cout << "1.学生信息" << endl;
        cout << "2.课程信息" << endl;
        cout << "3.选课信息" << endl;
        break;
    }

    case 5:
    {
        cout << "请选择需要查询的信息：" << endl;
        cout << "1.学生信息" << endl;
        cout << "2.课程信息" << endl;
        cout << "3.选课信息" << endl;
        break;
    }
    case 6:
    {
        cout << "请选择需要修改的信息：" << endl;
        cout << "1.学生信息" << endl;
        cout << "2.课程信息" << endl;
        cout << "3.选课信息" << endl;
        break;
    }
    case 7:
    {
        cout << "请选择需要去重的信息：" << endl;
        cout << "1.学生信息" << endl;
        cout << "2.课程信息" << endl;
        cout << "3.选课信息" << endl;
        break;
    }
    default:
        break;
    }
}

void DisplayMessage::displayClear()
{
    cout << "按任意键继续..." << endl;
    getchar();
    getchar();
    system("clear");
}

void DisplayMessage::displayWrongMessage(int i)
{
    switch (i)
    {
    case 1:
    {
        cout << "输入错误，请重新输入！" << endl;
        break;
    }
    case 2:
    {
        cout << "未查询到信息，请检查输入" << endl;
        break;
    }
    case 3:
    {
        cout << "文件被占用，请关闭文件后重试！" << endl;
        break;
    }
    case 4:
    {
        cout << "文件打开失败，请检查文件是否存在！" << endl;
        break;
    }
    case 5:
    {
        cout << "文件写入失败，请检查文件是否存在！" << endl;
        break;
    }

    default:
        break;
    }
}

FileManager::FileManager()
{}

FileManager::~FileManager()
{
}
void FileManager::openFile()
{
    FilePath = getFilePath();
    file.open(FilePath, ios::in | ios::out);
    if (!file)
    {
        DisplayMessage display;
        display.displayWrongMessage(4);
        exit(0);
    }
}

string FileManager::getFilePath()
{
    DisplayMessage displayMessage;
    displayMessage.displayMessage(1);
    string path;
    getline(cin, path);
    if (path == "")
    {
        path = FilePath;
    }
    if (isFileExist(path))
    {
        return path;
    }
    else
    {
        displayMessage.displayWrongMessage(4);
        return "";
    }
    return path;
}

bool FileManager::isFileExist(string path)
{
    ifstream f(path.c_str());
    return f.good();
}

void FileManager::saveData()
{
    for (auto item : student)
    {
        file << item.name << ' ' << item.id << ' ' << item.age << ' ' << item.sex << endl;
    }
    file << "-------------------------" << endl;
    for (auto item : course)
    {
        file << item.name << ' ' << item.id << ' ' << item.credit << endl;
    }
    file << "-------------------------" << endl;
    for (auto item : choose)
    {
        file << item.student_id << ' ' << item.course_id << ' ' << item.score << endl;
    }
    file.close();
}

void FileManager::readData()
{
    string line;
    while (getline(file, line))

    {
        if (line == "-------------------------")
            continue;
        stringstream ss(line);
        string name, id, age, sex;
        ss >> name >> id >> age >> sex; // 读取学生信息
        if (!ss.fail())                 // 读取成功，说明是学生的数据
        {
            Student stu{ name, stoi(age), sex, stol(id) };
            student.push_back(stu);
        }
        else
        {
            ss.clear();
            string name, id, credit;
            ss >> name >> id >> credit; // 读取课程信息
            if (!ss.fail())             // 读取成功，说明是课程的数据
            {
                Course cou{ name, stoi(credit), stol(id) };
                course.push_back(cou);
            }
            else
            {
                ss.clear();
                string student_id, course_id, score;
                ss >> student_id >> course_id >> score; // 读取选课信息
                if (!ss.fail())                         // 读取成功，说明是选课的数据
                {
                    Choose cho{ stol(student_id), stol(course_id), stoi(score) };
                    choose.push_back(cho);
                }
            }
        }
    }
    cout << "读取文件成功" << endl;
    file.close();
}

StudentManager::StudentManager() : Manager() {

}; // 构造函数

void StudentManager::add()
{
    string name, sex;
    int age;
    long id;
    cout << "请输入学生姓名：";
    name = checkInput(0);
    cout << "请输入学生年龄：";
    age = checkInput(0, 100);
    cout << "请输入学生性别：";
    sex = checkInput(1);
    cout << "请输入学生学号（8位）：";
    id = checkInput();

    Student newstu{ name, age, sex, id };
    student.push_back(newstu);
    cout << "添加成功" << endl;
}

void StudentManager::del()
{
    cout << "请输入需要删除的学生学号：";
    long id = checkInput();
    for (auto it = student.begin(); it != student.end(); it++)
    {
        if (it->id == id)
        {
            student.erase(it);
            cout << "删除成功" << endl;
            return;
        }
    }
    cout << "未查询到该学生信息，请检查输入" << endl;
}

void StudentManager::search()
{
    cout << "请输入需要查询的学生学号：";
    long id = checkInput();
    for (auto item : student)
    {
        if (item.id == id)
        {
            displayMessage.displayStudent(item);
            return;
        }
    }
    cout << "未查询到该学生信息，请检查输入" << endl;
}

void StudentManager::change()
{
    cout << "请输入需要修改的学生学号：";
    long id = checkInput();
    for (auto item : student)
    {
        if (item.id == id)
        {
            cout << "请输入学生姓名：";
            item.name = checkInput(0);
            cout << "请输入学生年龄：";
            item.age = checkInput(0, 100);
            cout << "请输入学生性别：";
            item.sex = checkInput(1);
            cout << "请输入学生学号（8位）：";
            item.id = checkInput();
            cout << "修改成功" << endl;
            return;
        }
    }
    cout << "未查询到该学生信息，请检查输入" << endl;
}

void StudentManager::sorted()
{
    cout << "请选择排序方式：" << endl;
    cout << "1.按学号排序" << endl;
    cout << "2.按姓名排序" << endl;
    int i = checkInput(1, 2);
    switch (i)
    {
    case 1:
    {
        sort(student.begin(), student.end(), [](const Student& a, const Student& b)
            { return a.id < b.id; });
        cout << "排序成功" << endl;
        break;
    }
    case 2:
    {
        sort(student.begin(), student.end(), [](Student a, Student b)
            { return a.name < b.name; });
        cout << "排序成功" << endl;
        break;
    }
    default:
        break;
    }
}

CourseManager::CourseManager() : Manager() {

}; // 构造函数

void CourseManager::add()
{
    string name;
    int credit;
    long id;
    cout << "请输入课程名称：";
    name = checkInput(0);
    cout << "请输入课程学分：";
    credit = checkInput(0, 10);
    cout << "请输入课程号（8位）：";
    id = checkInput();

    Course newcou{ name, credit, id };
    course.push_back(newcou);
    cout << "添加成功" << endl;
}

void CourseManager::del()
{
    cout << "请输入需要删除的课程号：";
    long id = checkInput();
    for (auto it = course.begin(); it != course.end(); it++)
    {
        if (it->id == id)
        {
            course.erase(it);
            cout << "删除成功" << endl;
            return;
        }
    }
    cout << "未查询到该课程信息，请检查输入" << endl;
}

void CourseManager::search()
{
    cout << "请输入需要查询的课程号：";
    long id = checkInput();
    for (auto item : course)
    {
        if (item.id == id)
        {
            displayMessage.displayCourse(item);
            return;
        }
    }
    cout << "未查询到该课程信息，请检查输入" << endl;
}

void CourseManager::change()
{
    cout << "请输入需要修改的课程号：";
    long id = checkInput();
    for (auto item : course)
    {
        if (item.id == id)
        {
            cout << "请输入课程名称：";
            item.name = checkInput(0);
            cout << "请输入课程学分：";
            item.credit = checkInput(0, 10);
            cout << "请输入课程号（8位）：";
            item.id = checkInput();
            cout << "修改成功" << endl;
            return;
        }
    }
    cout << "未查询到该课程信息，请检查输入" << endl;
}

void CourseManager::sorted()
{
    cout << "请选择排序方式：" << endl;
    cout << "1.按课程号排序" << endl;
    cout << "2.按课程名称排序" << endl;
    int i = checkInput(1, 2);
    switch (i)
    {
    case 1:
    {
        sort(course.begin(), course.end(), [](const Course& a, const Course& b)
            { return a.id < b.id; });
        cout << "排序成功" << endl;
        break;
    }
    case 2:
    {
        sort(course.begin(), course.end(), [](Course a, Course b)
            { return a.name < b.name; });
        cout << "排序成功" << endl;
        break;
    }
    default:
        break;
    }
}

ChooseManager::ChooseManager() : Manager() {

}; // 构造函数

void ChooseManager::add()
{
    long student_id, course_id;
    int score;
    cout << "请输入学生学号：";
    student_id = checkInput();
    cout << "请输入课程号：";
    course_id = checkInput();
    cout << "请输入成绩：";
    score = checkInput(0, 100);

    Choose newcho{ student_id, course_id, score };
    choose.push_back(newcho);
    cout << "添加成功" << endl;
}

void ChooseManager::del()
{
    cout << "请输入需要删除的学生学号：";
    long student_id = checkInput();
    cout << "请输入需要删除的课程号：";
    long course_id = checkInput();
    for (auto it = choose.begin(); it != choose.end(); it++)
    {
        if (it->student_id == student_id && it->course_id == course_id)
        {
            choose.erase(it);
            cout << "删除成功" << endl;
            return;
        }
    }
    cout << "未查询到该选课信息，请检查输入" << endl;
}

void ChooseManager::search()
{
    cout << "请输入需要查询的学生学号：";
    long student_id = checkInput();
    cout << "请输入需要查询的课程号：";
    long course_id = checkInput();
    for (auto item : choose)
    {
        if (item.student_id == student_id && item.course_id == course_id)
        {
            displayMessage.displayChoose(item);
            return;
        }
    }
    cout << "未查询到该选课信息，请检查输入" << endl;
}

void ChooseManager::change()
{
    cout << "请输入需要修改的学生学号：";
    long student_id = checkInput();
    cout << "请输入需要修改的课程号：";
    long course_id = checkInput();
    for (auto item : choose)
    {
        if (item.student_id == student_id && item.course_id == course_id)
        {
            cout << "请输入学生学号：";
            item.student_id = checkInput();
            cout << "请输入课程号：";
            item.course_id = checkInput();
            cout << "请输入成绩：";
            item.score = checkInput(0, 100);
            cout << "修改成功" << endl;
            return;
        }
    }
    cout << "未查询到该选课信息，请检查输入" << endl;
}

void ChooseManager::sorted()
{
    cout << "请选择排序方式：" << endl;
    cout << "1.按学号排序" << endl;
    cout << "2.按课程号排序" << endl;
    int i = checkInput(1, 2);
    switch (i)
    {
    case 1:
    {
        sort(choose.begin(), choose.end(), [](const Choose& a, const Choose& b)
            { return a.student_id < b.student_id; });
        cout << "排序成功" << endl;
        break;
    }
    case 2:
    {
        sort(choose.begin(), choose.end(), [](Choose a, Choose b)
            { return a.course_id < b.course_id; });
        cout << "排序成功" << endl;
        break;
    }
    default:
        break;
    }
}



Manager::Manager() : fileManager(), displayMessage() {}

Manager::~Manager() {}; // 析构函数

void Manager::add() {}; // 添加信息的虚函数，由子类重写
void Manager::change() {};
void Manager::del() {};    // 删除信息的虚函数，由子类重写
void Manager::search() {}; // 查询信息的虚函数，由子类重写
void Manager::sorted() {}; // 排序信息的虚函数，由子类重写

string checkInput(int type)
{
    string input;
    cin >> input;
    while (true)
    {
        if (type != 0 && (input != "男" && input != "女"))
        {
            cout << "输入有误，请重新输入" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> input;
            continue;
        }
        return input;
    }
}

int checkInput(int min, int max)
{
    int input;
    cin >> input;
    while (true)
    {
        if (!cin.good() || input < min || input > max)
        {
            cout << "输入有误，请重新输入" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> input;
            continue;
        }
        else
            return input;
    }
}

long checkInput()
{
    int input;
    cin >> input;
    while (true)
    {
        if ((to_string(input)).length() != 8)
        {
            cout << "输入有误，请重新输入" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> input;
            continue;
        }
        return input;
    }
}