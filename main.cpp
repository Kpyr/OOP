///Вариант 10
/*Структура – Служащий. Структура должна включать соответствующие поля:
ФИО, возраст, дата приема на работу, профессия, специальность.
Простейшие функции:
1)смена фамилии,
2)вычисление полного стажа на момент введенной даты (годов, месяцев, дней),
3)смена профессии и специальности,
4)вывод данных по служащему.*/


#include "employee.h"
#include "employee.cpp"

#include "employeeClass.h"
#include "employeeClass.cpp"

//#include <vld.h>
#include <stack>
#include <memory>
#include <sstream>
#include <Windows.h>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
  system("chcp 65001");



  //---------------------------------Struct module-----------------------------------------

  long dateafter[3];
  dateafter[0] = 1;
  dateafter[1] = 1;
  dateafter[2] = 2001;


  employee* em1;
  em1 = new employee;
  em1->name = "Oleg";
  em1->surname = "Borisenko";
  em1->patronymic = "Olegovich";
  em1->age = 34;
  em1->expDay = 1;
  em1->expMonth = 1;
  em1->expYear = 2000;
  em1->profession = "Clean";
  em1->speciality = "Clean table";

  showInfo(em1);

  changeSurname(em1,"Glavenko");

  showInfo(em1);

  changeProfessionAndSpeciality(em1,"Boss", "Nothing");

  showInfo(em1);

  long *ms;
  ms = calcExperience(em1, dateafter);
  cout << "Стаж работы: " << endl;
  cout << "Дней всего: " << ms[3] << endl;
  cout << "Дней: " << ms[0] << endl << "Месяцов: " << ms[1] << endl << "Лет: " << ms[2] << endl;

















  //---------------------------------Class module-----------------------------------------

  /*long msDate[3];
  msDate[0] = 1;
  msDate[1] = 1;
  msDate[2] = 2000;
  employeeClass* emp1;
  //emp1 = new employeeClass;
  emp1 = new employeeClass("Oleg","Borisenko","Olegovich",34,msDate,"Clean","Clean table");



  emp1->showInfo();
  emp1->changeSurname("Brosky");
  emp1->showInfo();
  emp1->changeProfessionAndSpeciality("Boss", "Nothing");
  emp1->showInfo();
  long dateafter[3];
  dateafter[0] = 1;
  dateafter[1] = 1;
  dateafter[2] = 2001;
  long *ms;
  ms = emp1->calcExperience(dateafter);
  cout << "Стаж работы: " << endl;
  cout << "Дней всего: " << ms[3] << endl;
  cout << "Дней: " << ms[0] << endl << "Месяцов: " << ms[1] << endl << "Лет: " << ms[2] << endl;*/

  return 0;
}
