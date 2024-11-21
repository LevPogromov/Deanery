// Copyright 2024 by Contributors
#include "../include/deanery.hpp"
void Deanery::create_groups_from_file() {
    ifstream file;
    file.open("../bd/groups.txt");
    string line, new_title, new_spec, name, surname, lastname, head;
    while (getline(file, line)) {
        istringstream iss(line);
        iss >> new_title >> new_spec >> name >> surname >> lastname;
        head = name + " " + surname + " " + lastname;
        Group *group = new Group;
        group->create_group(new_title, new_spec);
        Student *head_of_group = new Student;
        head_of_group->create_student(0, head);
        group->set_head(head_of_group);
        groups.push_back(group);
    }
    file.close();
}
void Deanery::create_students_from_file() {
    ifstream file;
    file.open("../bd/students.txt");
    string line, fio, name, surname, lastname, new_title;
    int id;
    while (getline(file, line)) {
        istringstream iss(line);
        iss >> id >> name >> surname >> lastname >> new_title;
        fio = name + " " + surname + " " + lastname;
        vector<int>new_marks;
        int mark;
        while (iss >> mark) {
            new_marks.push_back(mark);
        }
        Student *student = new Student;
        student->create_student(id, fio);
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i]->get_title() ==  new_title) {
                student->set_group(groups[i]);
                student->set_marks(new_marks);
                groups[i]->add_student(student);
                break;
            }
        }
    }
    file.close();
}
void Deanery::save_students_to_file() {
    ofstream file;
    int new_id = 1;
    file.open("../bd/students.txt");
    for (int i = 0; i < groups.size(); i++) {
        vector<Student*>new_students = groups[i]->get_group();
        for (int j = 0; j < new_students.size(); j++) {
            file << new_id << " " << new_students[j]->get_fio() << " "
            << new_students[j]->get_group()->get_title() << " ";
            new_id++;
            vector<int>new_marks = new_students[j]->get_marks();
            for (int k = 0; k < new_marks.size(); k++) {
                file << new_marks[k] << " ";
            }
            file << endl;
        }
    }
    cout << "Data in students.txt is saved" << endl;
    file.close();
}
void Deanery::save_groups_to_file() {
    ofstream file;
    file.open("../bd/groups.txt");
    for (int i = 0; i < groups.size(); i++) {
        file << groups[i]->get_title() << " " << groups[i]->get_spec() << " "
         << groups[i]->get_head()->get_fio() << endl;
    }
    cout << "Data in groups.txt is saved" << endl;
    file.close();
}
void Deanery::add_random_marks() {
    for (int i = 0; i < groups.size(); i++) {
        vector<Student*>new_students = groups[i]->get_group();
        for (int j = 0; j < new_students.size(); j++) {
            new_students[j]->add_mark(rand()%11);
        }
    }
}
void Deanery::get_stat_of_groups() {
    cout << "Statistic" << endl;
    for (int i = 0; i < groups.size(); i++) {
        cout << "Title: " << groups[i]->get_title() << endl;
        cout << "Spec: " << groups[i]->get_spec() << endl;
        cout << "Head: " << groups[i]->get_head()->get_fio() << endl;
        cout << "Avarage rate:  " << groups[i]->avarage_rating_of_group()
        << endl << endl;
        vector<Student*>new_students = groups[i]->get_group();
        for (int j = 0; j < new_students.size(); j++) {
            cout << "Student: " << new_students[j]->get_fio() << endl;
            vector<int>new_marks = new_students[j]->get_marks();
            for (int k = 0; k < new_marks.size(); k++) {
                cout << new_marks[k] << " ";
            }
            cout << endl;
            cout << "Avarage mark: " << new_students[j]->avarage_rating()
            << endl << endl;
        }
    }
}
void Deanery::expel_students() {
    for (int i = 0; i < groups.size(); i++) {
        vector<Student*>new_students = groups[i]->get_group();
        for (int j = 0; j < new_students.size(); j++) {
            if (new_students[j]->avarage_rating() < 4) {
                groups[i]->delete_student(new_students[j]);
                cout << new_students[j]->get_fio() << " was expelled, id: "
                << new_students[j]->get_id() << endl;
            }
        }
    }
}
void Deanery::transfer_student(int this_id, string new_title) {
    Student* student = nullptr;
    for (int i = 0; i < groups.size(); i++) {
        vector<Student*>new_students = groups[i]->get_group();
        for (int j = 0; j < new_students.size(); j++) {
            if (new_students[j]->get_id() == this_id) {
                student = new_students[j];
                break;
            }
        }
    }
    if (student == nullptr) {
        cout << "Student is not found" << endl;
        return;
    }
    Group* group = nullptr;
    for (int i = 0; i < groups.size(); i++) {
        if (groups[i]->get_title() == new_title) {
            group = groups[i];
            break;
        }
    }
    if (group == nullptr) {
        cout << "Group is not found" << endl;
        return;
    }
    student->get_group()->delete_student(student);
    student->set_group(group);
    group->add_student(student);
    cout << "Student is transferred" << endl;
}
void Deanery::data_output() {
    cout << "Data" << endl;
    int new_id = 1;
    for (int i = 0; i < groups.size(); i++) {
        cout << "Group " << groups[i]->get_title() << endl;
        cout << "Spec " << groups[i]->get_spec() << endl;
        cout << "Head " << groups[i]->get_head()->get_fio() << endl;
        vector<Student*>new_students = groups[i]->get_group();
        for (int j = 0; j < new_students.size(); j++) {
            cout << new_id << " " << new_students[j]->get_fio()
            << " " << new_students[j]->get_group()->get_title() << " ";
            groups[i]->get_group()[j]->set_id(new_id);
            new_id++;
            vector<int>new_marks = new_students[j]->get_marks();
            for (int k = 0; k < new_marks.size(); k++) {
                cout << new_marks[k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
void Deanery::set_groups(vector<Group*>new_groups) {
    groups = new_groups;
}
vector<Group*> Deanery::get_groups() {
    return groups;
}
