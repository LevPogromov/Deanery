// Copyright 2024 by Contributors
#include "../include/student.hpp"
void Student::create_student(int new_id, string new_fio) {
    id = new_id;
    fio = new_fio;
}
void Student::add_to_group(Group *new_group) {
    group = new_group;
    new_group->add_student(this);
}
void Student::add_mark(int new_mark) {
    marks.push_back(new_mark);
}
void Student::add_marks(vector<int>new_marks) {
    for (int i = 0; i < new_marks.size(); i++) {
        marks.push_back(new_marks[i]);
    }
}
float Student::avarage_rating() {
    float a = 0;
    for (int i = 0; i < marks.size(); i++) {
        a+=marks[i];
    }
    return a/marks.size();
}
void Student::set_id(int new_id) {
    id = new_id;
}
void Student::set_fio(string new_fio) {
    fio = new_fio;
}
void Student::set_group(Group* new_group) {
    group = new_group;
}
void Student::set_marks(vector<int>new_marks) {
    marks = new_marks;
}
int Student::get_id() {
    return id;
}
string Student::get_fio() {
    return fio;
}
Group* Student::get_group() {
    return group;
}
vector<int> Student::get_marks() {
    return marks;
}
Student Student::operator=(Student new_student) {
    id = new_student.id;
    fio = new_student.fio;
    group = new_student.group;
    marks = new_student.marks;
    return *this;
}
