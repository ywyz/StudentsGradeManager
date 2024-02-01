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
    cout << "1.�����ʼ���ݣ�" << endl;
    cout << "2.��ʾ��Ϣ��" << endl;
    cout << "3.�����¼��" << endl;
    cout << "4.ɾ����¼��" << endl;
    cout << "5.��ѯ��Ϣ��" << endl;
    cout << "6.�༭��¼��" << endl;
    cout << "7.ȥ�أ�" << endl;
    cout << "8.�����������ݣ�" << endl;
    cout << "0.�˳���" << endl;
    cout << "����������ѡ��";
}

void DisplayMessage::displayStudent()
{
    cout << "ѧ����Ϣ��ʾ��" << endl;
    cout << "ѧ������    ѧ������    ѧ���Ա�    ѧ��ѧ��" << endl;
    for (auto& item : student)
    {
        cout << item.name << "  " << item.age << "  " << item.sex << "  " << item.id << endl;
    }
}

void DisplayMessage::displayCourse()
{
    cout << "�γ���Ϣ��ʾ��" << endl;
    cout << "�γ�����    �γ�ѧ��    �γ̺�" << endl;
    for (auto& item : course)
    {
        cout << item.name << "  " << item.credit << "  " << item.id << endl;
    }
}

void DisplayMessage::displayChoose()
{
    cout << "ѡ����Ϣ��ʾ��" << endl;
    cout << "ѧ��ѧ��    �γ̺�    �ɼ�" << endl;
    for (auto& item : choose)
    {
        cout << item.student_id << "  " << item.course_id << "  " << item.score << endl;
    }
}

void DisplayMessage::displayStudent(Student stu)
{
    cout << "ѧ����Ϣ��ʾ��" << endl;
    cout << "ѧ������: " << stu.name << endl;
    cout << "ѧ�����䣺" << stu.age << endl;
    cout << "ѧ���Ա�" << stu.sex << endl;
    cout << "ѧ��ѧ�ţ�" << stu.id << endl;
}

void DisplayMessage::displayCourse(Course cou)
{
    cout << "�γ���Ϣ��ʾ��" << endl;
    cout << "�γ����ƣ�" << cou.name << endl;
    cout << "�γ�ѧ�֣�" << cou.credit << endl;
    cout << "�γ̺ţ�" << cou.id << endl;
}

void DisplayMessage::displayChoose(Choose cho)
{
    cout << "ѡ����Ϣ��ʾ��" << endl;
    cout << "ѧ�ţ�" << cho.student_id << endl;
    cout << "�γ̺ţ�" << cho.course_id << endl;
    cout << "�ɼ���" << cho.score << endl;
}

void DisplayMessage::displayMessage(int i)
{
    
    switch (i)
    {
    case 1:
    {
        cout << "�������ļ����ƣ�default:data.txt��: ";
        break;
    }
    case 2:
    {
        cout << "��������Ҫ��ʾ����Ϣ��" << endl;
        cout << "1.ȫ��ѧ����Ϣ" << endl;
        cout << "2.ȫ���γ���Ϣ" << endl;
        cout << "3.ȫ��ѡ����Ϣ" << endl;
        break;
    }
    case 3:
    {
        cout << "��ѡ����Ҫ�༭����Ϣ��" << endl;
        cout << "1.ѧ����Ϣ" << endl;
        cout << "2.�γ���Ϣ" << endl;
        cout << "3.ѡ����Ϣ" << endl;
        break;
    }
    case 4:
    {
        cout << "��ѡ����Ҫɾ������Ϣ��" << endl;
        cout << "1.ѧ����Ϣ" << endl;
        cout << "2.�γ���Ϣ" << endl;
        cout << "3.ѡ����Ϣ" << endl;
        break;
    }

    case 5:
    {
        cout << "��ѡ����Ҫ��ѯ����Ϣ��" << endl;
        cout << "1.ѧ����Ϣ" << endl;
        cout << "2.�γ���Ϣ" << endl;
        cout << "3.ѡ����Ϣ" << endl;
        break;
    }
    case 6:
    {
        cout << "��ѡ����Ҫ�޸ĵ���Ϣ��" << endl;
        cout << "1.ѧ����Ϣ" << endl;
        cout << "2.�γ���Ϣ" << endl;
        cout << "3.ѡ����Ϣ" << endl;
        break;
    }
    case 7:
    {
        cout << "��ѡ����Ҫȥ�ص���Ϣ��" << endl;
        cout << "1.ѧ����Ϣ" << endl;
        cout << "2.�γ���Ϣ" << endl;
        cout << "3.ѡ����Ϣ" << endl;
        break;
    }
    default:
        break;
    }
}

void DisplayMessage::displayClear()
{
    cout << "�����������..." << endl;
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
        cout << "����������������룡" << endl;
        break;
    }
    case 2:
    {
        cout << "δ��ѯ����Ϣ����������" << endl;
        break;
    }
    case 3:
    {
        cout << "�ļ���ռ�ã���ر��ļ������ԣ�" << endl;
        break;
    }
    case 4:
    {
        cout << "�ļ���ʧ�ܣ������ļ��Ƿ���ڣ�" << endl;
        break;
    }
    case 5:
    {
        cout << "�ļ�д��ʧ�ܣ������ļ��Ƿ���ڣ�" << endl;
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
        ss >> name >> id >> age >> sex; // ��ȡѧ����Ϣ
        if (!ss.fail())                 // ��ȡ�ɹ���˵����ѧ��������
        {
            Student stu{ name, stoi(age), sex, stol(id) };
            student.push_back(stu);
        }
        else
        {
            ss.clear();
            string name, id, credit;
            ss >> name >> id >> credit; // ��ȡ�γ���Ϣ
            if (!ss.fail())             // ��ȡ�ɹ���˵���ǿγ̵�����
            {
                Course cou{ name, stoi(credit), stol(id) };
                course.push_back(cou);
            }
            else
            {
                ss.clear();
                string student_id, course_id, score;
                ss >> student_id >> course_id >> score; // ��ȡѡ����Ϣ
                if (!ss.fail())                         // ��ȡ�ɹ���˵����ѡ�ε�����
                {
                    Choose cho{ stol(student_id), stol(course_id), stoi(score) };
                    choose.push_back(cho);
                }
            }
        }
    }
    cout << "��ȡ�ļ��ɹ�" << endl;
    file.close();
}

StudentManager::StudentManager() : Manager() {

}; // ���캯��

void StudentManager::add()
{
    string name, sex;
    int age;
    long id;
    cout << "������ѧ��������";
    name = checkInput(0);
    cout << "������ѧ�����䣺";
    age = checkInput(0, 100);
    cout << "������ѧ���Ա�";
    sex = checkInput(1);
    cout << "������ѧ��ѧ�ţ�8λ����";
    id = checkInput();

    Student newstu{ name, age, sex, id };
    student.push_back(newstu);
    cout << "��ӳɹ�" << endl;
}

void StudentManager::del()
{
    cout << "��������Ҫɾ����ѧ��ѧ�ţ�";
    long id = checkInput();
    for (auto it = student.begin(); it != student.end(); it++)
    {
        if (it->id == id)
        {
            student.erase(it);
            cout << "ɾ���ɹ�" << endl;
            return;
        }
    }
    cout << "δ��ѯ����ѧ����Ϣ����������" << endl;
}

void StudentManager::search()
{
    cout << "��������Ҫ��ѯ��ѧ��ѧ�ţ�";
    long id = checkInput();
    for (auto item : student)
    {
        if (item.id == id)
        {
            displayMessage.displayStudent(item);
            return;
        }
    }
    cout << "δ��ѯ����ѧ����Ϣ����������" << endl;
}

void StudentManager::change()
{
    cout << "��������Ҫ�޸ĵ�ѧ��ѧ�ţ�";
    long id = checkInput();
    for (auto item : student)
    {
        if (item.id == id)
        {
            cout << "������ѧ��������";
            item.name = checkInput(0);
            cout << "������ѧ�����䣺";
            item.age = checkInput(0, 100);
            cout << "������ѧ���Ա�";
            item.sex = checkInput(1);
            cout << "������ѧ��ѧ�ţ�8λ����";
            item.id = checkInput();
            cout << "�޸ĳɹ�" << endl;
            return;
        }
    }
    cout << "δ��ѯ����ѧ����Ϣ����������" << endl;
}

void StudentManager::sorted()
{
    cout << "��ѡ������ʽ��" << endl;
    cout << "1.��ѧ������" << endl;
    cout << "2.����������" << endl;
    int i = checkInput(1, 2);
    switch (i)
    {
    case 1:
    {
        sort(student.begin(), student.end(), [](const Student& a, const Student& b)
            { return a.id < b.id; });
        cout << "����ɹ�" << endl;
        break;
    }
    case 2:
    {
        sort(student.begin(), student.end(), [](Student a, Student b)
            { return a.name < b.name; });
        cout << "����ɹ�" << endl;
        break;
    }
    default:
        break;
    }
}

CourseManager::CourseManager() : Manager() {

}; // ���캯��

void CourseManager::add()
{
    string name;
    int credit;
    long id;
    cout << "������γ����ƣ�";
    name = checkInput(0);
    cout << "������γ�ѧ�֣�";
    credit = checkInput(0, 10);
    cout << "������γ̺ţ�8λ����";
    id = checkInput();

    Course newcou{ name, credit, id };
    course.push_back(newcou);
    cout << "��ӳɹ�" << endl;
}

void CourseManager::del()
{
    cout << "��������Ҫɾ���Ŀγ̺ţ�";
    long id = checkInput();
    for (auto it = course.begin(); it != course.end(); it++)
    {
        if (it->id == id)
        {
            course.erase(it);
            cout << "ɾ���ɹ�" << endl;
            return;
        }
    }
    cout << "δ��ѯ���ÿγ���Ϣ����������" << endl;
}

void CourseManager::search()
{
    cout << "��������Ҫ��ѯ�Ŀγ̺ţ�";
    long id = checkInput();
    for (auto item : course)
    {
        if (item.id == id)
        {
            displayMessage.displayCourse(item);
            return;
        }
    }
    cout << "δ��ѯ���ÿγ���Ϣ����������" << endl;
}

void CourseManager::change()
{
    cout << "��������Ҫ�޸ĵĿγ̺ţ�";
    long id = checkInput();
    for (auto item : course)
    {
        if (item.id == id)
        {
            cout << "������γ����ƣ�";
            item.name = checkInput(0);
            cout << "������γ�ѧ�֣�";
            item.credit = checkInput(0, 10);
            cout << "������γ̺ţ�8λ����";
            item.id = checkInput();
            cout << "�޸ĳɹ�" << endl;
            return;
        }
    }
    cout << "δ��ѯ���ÿγ���Ϣ����������" << endl;
}

void CourseManager::sorted()
{
    cout << "��ѡ������ʽ��" << endl;
    cout << "1.���γ̺�����" << endl;
    cout << "2.���γ���������" << endl;
    int i = checkInput(1, 2);
    switch (i)
    {
    case 1:
    {
        sort(course.begin(), course.end(), [](const Course& a, const Course& b)
            { return a.id < b.id; });
        cout << "����ɹ�" << endl;
        break;
    }
    case 2:
    {
        sort(course.begin(), course.end(), [](Course a, Course b)
            { return a.name < b.name; });
        cout << "����ɹ�" << endl;
        break;
    }
    default:
        break;
    }
}

ChooseManager::ChooseManager() : Manager() {

}; // ���캯��

void ChooseManager::add()
{
    long student_id, course_id;
    int score;
    cout << "������ѧ��ѧ�ţ�";
    student_id = checkInput();
    cout << "������γ̺ţ�";
    course_id = checkInput();
    cout << "������ɼ���";
    score = checkInput(0, 100);

    Choose newcho{ student_id, course_id, score };
    choose.push_back(newcho);
    cout << "��ӳɹ�" << endl;
}

void ChooseManager::del()
{
    cout << "��������Ҫɾ����ѧ��ѧ�ţ�";
    long student_id = checkInput();
    cout << "��������Ҫɾ���Ŀγ̺ţ�";
    long course_id = checkInput();
    for (auto it = choose.begin(); it != choose.end(); it++)
    {
        if (it->student_id == student_id && it->course_id == course_id)
        {
            choose.erase(it);
            cout << "ɾ���ɹ�" << endl;
            return;
        }
    }
    cout << "δ��ѯ����ѡ����Ϣ����������" << endl;
}

void ChooseManager::search()
{
    cout << "��������Ҫ��ѯ��ѧ��ѧ�ţ�";
    long student_id = checkInput();
    cout << "��������Ҫ��ѯ�Ŀγ̺ţ�";
    long course_id = checkInput();
    for (auto item : choose)
    {
        if (item.student_id == student_id && item.course_id == course_id)
        {
            displayMessage.displayChoose(item);
            return;
        }
    }
    cout << "δ��ѯ����ѡ����Ϣ����������" << endl;
}

void ChooseManager::change()
{
    cout << "��������Ҫ�޸ĵ�ѧ��ѧ�ţ�";
    long student_id = checkInput();
    cout << "��������Ҫ�޸ĵĿγ̺ţ�";
    long course_id = checkInput();
    for (auto item : choose)
    {
        if (item.student_id == student_id && item.course_id == course_id)
        {
            cout << "������ѧ��ѧ�ţ�";
            item.student_id = checkInput();
            cout << "������γ̺ţ�";
            item.course_id = checkInput();
            cout << "������ɼ���";
            item.score = checkInput(0, 100);
            cout << "�޸ĳɹ�" << endl;
            return;
        }
    }
    cout << "δ��ѯ����ѡ����Ϣ����������" << endl;
}

void ChooseManager::sorted()
{
    cout << "��ѡ������ʽ��" << endl;
    cout << "1.��ѧ������" << endl;
    cout << "2.���γ̺�����" << endl;
    int i = checkInput(1, 2);
    switch (i)
    {
    case 1:
    {
        sort(choose.begin(), choose.end(), [](const Choose& a, const Choose& b)
            { return a.student_id < b.student_id; });
        cout << "����ɹ�" << endl;
        break;
    }
    case 2:
    {
        sort(choose.begin(), choose.end(), [](Choose a, Choose b)
            { return a.course_id < b.course_id; });
        cout << "����ɹ�" << endl;
        break;
    }
    default:
        break;
    }
}



Manager::Manager() : fileManager(), displayMessage() {}

Manager::~Manager() {}; // ��������

void Manager::add() {}; // �����Ϣ���麯������������д
void Manager::change() {};
void Manager::del() {};    // ɾ����Ϣ���麯������������д
void Manager::search() {}; // ��ѯ��Ϣ���麯������������д
void Manager::sorted() {}; // ������Ϣ���麯������������д

string checkInput(int type)
{
    string input;
    cin >> input;
    while (true)
    {
        if (type != 0 && (input != "��" && input != "Ů"))
        {
            cout << "������������������" << endl;
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
            cout << "������������������" << endl;
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
            cout << "������������������" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> input;
            continue;
        }
        return input;
    }
}