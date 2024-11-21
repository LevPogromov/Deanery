// Copyright 2024 by Contributors
#pragma once
#ifndef INCLUDE_DEANERY_HPP
#define INCLUDE_DEANERY_HPP

#include "student.hpp"
#include "group.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
class Deanery {
 private:
    vector<Group*>groups;
 public:
    void create_students_from_file();
    void save_students_to_file();
    void create_groups_from_file();
    void save_groups_to_file();
    void add_random_marks();
    void get_stat_of_groups();
    void transfer_student(int this_id, string new_title);
    void expel_students();
    void data_output();
    // setter
    void set_groups(vector<Group*>new_groups);
    // getter
    vector<Group*> get_groups();
};
#endif  // INCLUDE_DEANERY_HPP
