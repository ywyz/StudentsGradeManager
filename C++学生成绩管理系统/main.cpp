#include <iostream>
#include "manager.h"
#include <algorithm>

using namespace std;
void run();
/*
 std::string generateName();
int generateAge();
std::string generateSex();
long generateId();
long generateCourseId();
int generateCredit();
int generateScore();
void generateData();
*/


int main()
{
    run();

    return 0;
}

void run()
{
    StudentManager stumanager;
    CourseManager coumanager;
    ChooseManager chomanager;
    DisplayMessage displayMessage;
    FileManager fileManager;
    displayMessage.displayMenu();
    // generateData();
    while (true)
    {
        int i = checkInput(0, 8);
        switch (i)
        {
        case 0:
        {
            return;
        }
        case 1:
        {
            fileManager.openFile();
            fileManager.readData();
            displayMessage.displayClear();
            displayMessage.displayMenu();
            break;
        }
        case 2:
        {
            displayMessage.displayMessage(2);
            int j = checkInput(1, 3);
            switch (j)
            {
            case 1:
            {
                displayMessage.displayStudent();
                break;
            }
            case 2:
            {
                displayMessage.displayCourse();
                break;
            }
            case 3:
            {
                displayMessage.displayChoose();
                break;
            }
            default:
                break;
            }
            displayMessage.displayClear();
            displayMessage.displayMenu();
            break;
        }

        case 3:
        {
            displayMessage.displayMessage(3);
            int j = checkInput(1, 3);
            switch (j)
            {
            case 1:
            {
                stumanager.add();
                break;
            }
            case 2:
            {
                coumanager.add();
                break;
            }
            case 3:
            {
                chomanager.add();
                break;
            }
            default:
                break;
            }
            displayMessage.displayClear();
            displayMessage.displayMenu();
            break;
        }
        case 4:
        {
            displayMessage.displayMessage(4);
            int j = checkInput(1, 3);
            switch (j)
            {
            case 1:
            {
                stumanager.del();
                break;
            }
            case 2:
            {
                coumanager.del();
                break;
            }
            case 3:
            {
                chomanager.del();
                break;
            }
            default:
                break;
            }
            displayMessage.displayClear();
            displayMessage.displayMenu();
            break;
        }

        case 5:
        {
            displayMessage.displayMessage(5);
            int j = checkInput(1, 3);
            switch (j)
            {
            case 1:
            {
                stumanager.search();
                break;
            }
            case 2:
            {
                coumanager.search();
                break;
            }
            case 3:
            {
                chomanager.search();
                break;
            }
            default:
                break;
            }
            displayMessage.displayClear();
            displayMessage.displayMenu();
            break;
        }

        case 6:
        {
            displayMessage.displayMessage(6);
            int j = checkInput(1, 3);
            switch (j)
            {
            case 1:
            {
                stumanager.change();
                break;
            }
            case 2:
            {
                coumanager.change();
                break;
            }
            case 3:
            {
                chomanager.change();
                break;
            }
            default:
                break;
            }
            displayMessage.displayClear();
            displayMessage.displayMenu();
            break;
        }

        case 7:
        {
            displayMessage.displayMessage(7);
            int j = checkInput(1, 3);
            switch (j)
            {
            case 1:
            {
                student.erase(unique(student.begin(), student.end(), [](const Student& a, const Student& b)
                    { return a.id == b.id; }),
                    student.end());
                cout << "去重成功" << endl;
                break;
            }
            case 2:
            {
                course.erase(unique(course.begin(), course.end(), [](const Course& a, const Course& b)
                    { return a.id == b.id; }),
                    course.end());
                cout << "去重成功" << endl;
                break;
            }
            case 3:
            {
                choose.erase(unique(choose.begin(), choose.end(), [](const Choose& a, const Choose& b)
                    { return a.student_id == b.student_id && a.course_id == b.course_id; }),
                    choose.end());
                cout << "去重成功" << endl;
                break;
            }
            default:
                break;
            }
            displayMessage.displayClear();
            displayMessage.displayMenu();
            break;
        }

        case 8:
        {
            fileManager.saveData();
            displayMessage.displayClear();
            displayMessage.displayMenu();
            break;
        }
        }
    }
}

#include <random>
#include <ctime>

// 生成随机姓名
std::string generateName() {
    std::string name;
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, sizeof(alphanum) - 2);

    for (int i = 0; i < 5; ++i) {
        name += alphanum[dis(gen)];
    }

    return name;
}

// 生成随机年龄
int generateAge() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(18, 22);

    return dis(gen);
}

// 生成随机性别
std::string generateSex() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    return dis(gen) == 0 ? "男" : "女";
}

// 生成随机学号
long generateId() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long> dis(10000000, 99999999);

    return dis(gen);
}

// 生成随机课程号
long generateCourseId() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long> dis(10000000, 99999999);

    return dis(gen);
}

// 生成随机学分
int generateCredit() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 5);

    return dis(gen);
}

// 生成随机成绩
int generateScore() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(60, 100);

    return dis(gen);
}

// 生成模拟数据
void generateData() {
    for (int i = 0; i < 100; ++i) {
        Student stu{ generateName(), generateAge(), generateSex(), generateId() };
        student.push_back(stu);

        Course cou{ generateName(), generateCredit(), generateCourseId() };
        course.push_back(cou);

        Choose cho{ stu.id, cou.id, generateScore() };
        choose.push_back(cho);
    }
}
