#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <string>

using namespace std;

struct Student
{
    // 学生结构体，包括姓名，年龄，性别，学号
    string name;
    int age;
    string sex;
    long id;
};

struct Course
{
    // 课程结构体，包括课程名称，学分，课程号
    string name;
    int credit;
    long id;
};

struct Choose
{
    // 选课结构体，包括学号，课程号，成绩
    long student_id;
    long course_id;
    int score;
};

#endif