#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "data.h"

using namespace std;
string checkInput(int type);      // ���������ַ����Ƿ�Ϸ�
int checkInput(int min, int max); // �������������Ƿ�Ϸ�
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

// ����Manager���������������Ժͷ���
class Manager
{
protected:
    FileManager fileManager;       // �ļ��������
    DisplayMessage displayMessage; // ��ʾ��Ϣ����
public:
    Manager();             // ���캯��
    ~Manager();            // ��������
    virtual void add();    // �����Ϣ���麯������������д
    virtual void del();    // ɾ����Ϣ���麯������������д
    virtual void change(); // �޸���Ϣ���麯������������д
    virtual void search(); // ��ѯ��Ϣ���麯������������д
    virtual void sorted(); // ������Ϣ���麯������������д
};

// ����StudentManager������ѧ����Ϣ����
class StudentManager : public Manager
{

public:
    StudentManager(); // ���캯��
    void add();       // ���ѧ����Ϣ
    void del();       // ɾ��ѧ����Ϣ
    void change();    // �޸�ѧ����Ϣ
    void search();    // ��ѯѧ����Ϣ
    void sorted();    // ����ѧ����Ϣ
};

// ����CourseManager������γ���Ϣ����
class CourseManager : public Manager
{

public:
    CourseManager(); // ���캯��

    void add();    // ��ӿγ���Ϣ
    void del();    // ɾ���γ���Ϣ
    void change(); // �޸Ŀγ���Ϣ
    void search(); // ��ѯ�γ���Ϣ
    void sorted(); // ����γ���Ϣ
};

// ����ChooseManager������ѡ����Ϣ����
class ChooseManager : public Manager
{

public:
    ChooseManager(); // ���캯��

    void add();    // ���ѡ����Ϣ
    void del();    // ɾ��ѡ����Ϣ
    void change(); // �޸�ѡ����Ϣ
    void search(); // ��ѯѡ����Ϣ
    void sorted(); // ����ѡ����Ϣ
};

#endif //
