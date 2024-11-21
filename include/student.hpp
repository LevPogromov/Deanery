// Copyright 2024 by Contributors
#pragma once
#ifndef INCLUDE_STUDENT_HPP
#define INCLUDE_STUDENT_HPP
#include "group.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Group;
class Student {
 private:
    int id;
    string fio;
    Group *group;
    vector<int>marks;
 public:
    void create_student(int new_id, string new_fio);
    void add_to_group(Group *new_group);
    void add_mark(int new_mark);
    void add_marks(vector<int>new_mark);
    float avarage_rating();
    // setters
    void set_id(int new_id);
    void set_fio(string new_fio);
    void set_group(Group *new_group);
    void set_marks(vector<int>new_marks);
    // getters
    int get_id();
    string get_fio();
    Group* get_group();
    vector<int> get_marks();

    Student operator=(Student new_student);
};
#endif  // INCLUDE_STUDENT_HPP
