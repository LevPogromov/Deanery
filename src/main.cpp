#include "../include/deanery.hpp"
int main() {
    Deanery deanery;
    //Загрузка из файла информации о студентах и группах. Вывод данных
    deanery.create_groups_from_file();
    deanery.create_students_from_file();
    cout << "-----------------" << endl;
    deanery.data_output();
    cout << "-----------------" << endl;
    //Перевод студента в другую группу(Патрушев Денис теперь в другой группе)
    deanery.transfer_student(90, "23KNT4");
    //Создадим новую группу, добавим студента
    Group new_group;
    new_group.create_group("23KNT7", "IMIKN");
    vector<Group*>new_groups = deanery.get_groups();
    new_groups.push_back(&new_group);
    deanery.set_groups(new_groups);
    //Создадим нового студента, добавим ему оценки и прикрепим к новой группе и сделаем его старостой
    Student new_student;
    new_student.create_student(91, "Zemelin Andrey Matveevich");
    new_student.add_mark(5);
    new_student.add_mark(10);
    new_student.add_mark(10);
    new_student.add_mark(8);
    new_student.add_mark(7);
    new_student.add_to_group(deanery.get_groups()[3]);
    deanery.get_groups()[3]->set_head(&new_student);
    //Выполним поиск по группе по id и fio
    cout << deanery.get_groups()[3]->search_student(91)->get_fio() << " " << "was found" << endl;
    cout << deanery.get_groups()[3]->search_student("Zemelin Andrey Matveevich")->get_fio() << " "
    << "was found" << endl;
    //Отчисление по неуспеваемости(изначально в каждой группе отчисляется по 1 человеку из введенных данных)
    deanery.expel_students();
    //Добавление случайных оценок (итого у каждого студента по 7 оценок)
    deanery.add_random_marks();
    deanery.add_random_marks();
    //Вывод стастистики
    cout << "-----------------" << endl;
    deanery.get_stat_of_groups();
    cout << "-----------------" << endl;
    //Сменим старосту в 4-ой группе(старостой становится студент с наивысшим средним баллом)
    deanery.get_groups()[0]->choose_head();
    //Сохраним измененные данные в файлы
    deanery.save_groups_to_file();
    deanery.save_students_to_file();
    //По итогу выполнения программы создана группа 23КНТ-7 с единственным новым студентом
    //Отчислены 3 студента 
    //Патрушев Денис переведен в группу 23КНТ4
    //Новый староста группы 23КНТ4
    //Всем студентам добавлены 2 рандомные оценки
    //Все изменения сохранены в файлах папки bd
}
