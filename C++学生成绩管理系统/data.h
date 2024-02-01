/*
 * @Date: 2023-12-30 12:38:58
 * @Author: ywyz
 * @LastModifiedBy: ywyz
 * @Github: https://github.com/ywyz
 * @LastEditors: ywyz
 * @LastEditTime: 2024-01-28 12:04:30
 */
#pragma once
#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
    // ѧ���ṹ�壬�������������䣬�Ա�ѧ��
    string name;
    int age;
    string sex;
    long id;
};

struct Course
{
    // �γ̽ṹ�壬�����γ����ƣ�ѧ�֣��γ̺�
    string name;
    int credit;
    long id;
};

struct Choose
{
    // ѡ�νṹ�壬����ѧ�ţ��γ̺ţ��ɼ�
    long student_id;
    long course_id;
    int score;
};


#endif