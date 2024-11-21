// Copyright 2024 by Contributors
#pragma once
#ifndef INCLUDE_GROUP_HPP
#define INCLUDE_GROUP_HPP
#include "student.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Student;
class Group {
 private:
    string title;
    string spec;
    vector<Student*>students;
    Student* head;
 public:
    void create_group(string new_title, string new_spec);
    void add_student(Student *student);
    void choose_head();
    Student* search_student(string new_fio);
    Student* search_student(int new_id);
    float avarage_rating_of_group();
    void delete_student(Student *student);
    // setters
    void set_title(string new_title);
    void set_spec(string new_spec);
    void set_group(vector<Student*>new_students);
    void set_head(Student*new_head);
    // getters
    string get_title();
    string get_spec();
    vector<Student*> get_group();
    Student* get_head();
    Group operator=(Group new_group);
};
#endif  // INCLUDE_GROUP_HPP
