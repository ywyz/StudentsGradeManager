#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "data.h"

using namespace std;
string checkInput(int type);      // 检查输入的字符串是否合法
int checkInput(int min, int max); // 检查输入的数字是否合法
long checkInput();

extern vector<Student> student;
extern vector<Course> course;
extern vector<Choose> choose;

class DisplayMessage
{
public:
    void displayMenu();
    void displayStudent();
    void displayCourse();
    void displayChoose();
    void displayStudent(Student stu);
    void displayCourse(Course cou);
    void displayChoose(Choose cho);
    void displayMessage(int i);
    void displayWrongMessage(int i);
    void displayClear();
};

class FileManager
{
private:
    string FilePath = "data.txt";
    fstream file;

public:
    FileManager();
    ~FileManager();
    void saveData();
    void readData();
    bool isFileExist(string path);
    string getFilePath();
    void openFile();
};

// 基类Manager，包含公共的属性和方法
class Manager
{
protected:
    FileManager fileManager;       // 文件管理对象
    DisplayMessage displayMessage; // 显示信息对象
public:
    Manager();             // 构造函数
    ~Manager();            // 析构函数
    virtual void add();    // 添加信息的虚函数，由子类重写
    virtual void del();    // 删除信息的虚函数，由子类重写
    virtual void change(); // 修改信息的虚函数，由子类重写
    virtual void search(); // 查询信息的虚函数，由子类重写
    virtual void sorted(); // 排序信息的虚函数，由子类重写
};

// 子类StudentManager，负责学生信息管理
class StudentManager : public Manager
{

public:
    StudentManager(); // 构造函数
    void add();       // 添加学生信息
    void del();       // 删除学生信息
    void change();    // 修改学生信息
    void search();    // 查询学生信息
    void sorted();    // 排序学生信息
};

// 子类CourseManager，负责课程信息管理
class CourseManager : public Manager
{

public:
    CourseManager(); // 构造函数

    void add();    // 添加课程信息
    void del();    // 删除课程信息
    void change(); // 修改课程信息
    void search(); // 查询课程信息
    void sorted(); // 排序课程信息
};

// 子类ChooseManager，负责选课信息管理
class ChooseManager : public Manager
{

public:
    ChooseManager(); // 构造函数

    void add();    // 添加选课信息
    void del();    // 删除选课信息
    void change(); // 修改选课信息
    void search(); // 查询选课信息
    void sorted(); // 排序选课信息
};

#endif //
