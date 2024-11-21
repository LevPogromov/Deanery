// Copyright 2024 by Contributors
#include "../include/group.hpp"
void Group::create_group(string new_title, string new_spec) {
    title = new_title;
    spec = new_spec;
}
void Group::add_student(Student *student) {
    students.push_back(student);
}
void Group::choose_head() {
    if (students.size() == 0) {
        cout << "Group is empty";
        return;
    }
    head = students[0];
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->avarage_rating() > head->avarage_rating()) {
            head = students[i];
        }
    }
}
Student* Group::search_student(string new_fio) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->get_fio() == new_fio) {
            return students[i];
        }
    }
    return nullptr;
}
Student* Group::search_student(int new_id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->get_id() == new_id) {
            return students[i];
        }
    }
    return nullptr;
}
float Group::avarage_rating_of_group() {
    float mark;
    for (int i = 0; i < students.size(); i++) {
        mark = mark + students[i]->avarage_rating();
    }
    return mark / students.size();
}
void Group::delete_student(Student *student) {
    for (int i = 0; i < students.size() ; i++) {
        if (students[i] == student) {
            students[i]->set_group(nullptr);
            students.erase(students.begin()+i);
            return;
        }
    }
}
void Group::set_title(string new_title) {
    title = new_title;
}
void Group::set_spec(string new_spec) {
    spec = new_spec;
}
void Group::set_group(vector<Student*>new_students) {
    students = new_students;
}
void Group::set_head(Student *new_head) {
    head = new_head;
}
string Group::get_title() {
    return title;
}
string Group::get_spec() {
    return spec;
}
vector <Student*> Group::get_group() {
    return students;
}
Student* Group::get_head() {
    return head;
}
Group Group::operator=(Group new_group) {
    title = new_group.title;
    spec = new_group.spec;
    students = new_group.students;
    head = new_group.head;
    return *this;
}
