/*#ifndef OOP_LAB1__EMPLOYEECLASS_H_
#define OOP_LAB1__EMPLOYEECLASS_H_*/
#pragma once
#include <string>
#include <Windows.h>
class employeeClass {
 private:
  employee empClass;
 public:
  employeeClass(string newName, string newSurname, string newPatronymic,long newAge, long ms[3], string newProf, string newSpec){
    empClass.name = newName;
    empClass.surname = newSurname;
    empClass.patronymic = newPatronymic;
    empClass.age = newAge;
    empClass.expDay = ms[0];
    empClass.expMonth = ms[1];
    empClass.expYear = ms[2];
    empClass.profession = newProf;
    empClass.speciality = newSpec;
  }
  employeeClass(){
    cout << "Введите Имя: ";
    cin >> empClass.name;
    cout << "Введите Фамилию: ";
    cin >> empClass.surname;
    cout << "Введите Отчество: ";
    cin >> empClass.patronymic;
    cout << "Введите Возраст: ";
    cin >> empClass.age;
    cout << "Введите День приема на работу: ";
    cin >> empClass.expDay;
    cout << "Введите Месяц приема на работу: ";
    cin >> empClass.expMonth;
    cout << "Введите Год приема на работу: ";
    cin >> empClass.expYear;
    cout << "Введите Професию: ";
    cin >> empClass.profession;
    cout << "Введите Специальность: ";
    cin >> empClass.speciality;
  }
  void changeSurname(string);
  long *calcExperience(long ms[3]);
  void changeProfessionAndSpeciality(string, string);
  void showInfo(void);
};

/*#endif //OOP_LAB1__EMPLOYEECLASS_H_*/
