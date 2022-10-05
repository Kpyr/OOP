#pragma once
#include <string>
#include <Windows.h>
/*#ifndef OOP_LAB1__EMPLOYEE_H_
#define OOP_LAB1__EMPLOYEE_H_*/
using namespace std;
struct employee{
  string name;        ///имя
  string surname;     ///фамилия
  string patronymic;  ///отчество
  int age;            ///возраст
  long expDay, expMonth, expYear; ///дата приема на работу
  string profession;  ///професия
  string speciality;  ///специальность
};

/*#endif //OOP_LAB1__EMPLOYEE_H_*/
