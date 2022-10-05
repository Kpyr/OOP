#pragma once
#include <string>
#include "employee.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void changeSurname(struct employee* emp, string surnm){
  emp->surname = surnm;
}

void calcExperience(struct employee* emp, long ms[3]){

}

void changeProfessionAndSpeciality(struct employee* emp, string newProf, string newSpec){
  emp->profession = newProf;
  emp->speciality = newSpec;
}

void showInfo(struct employee* emp){
  cout << "===================================================" << endl;
  cout << "Фамилия: " << emp->surname << endl;
  cout << "Имя: " << emp->name << endl;
  cout << "Отчество: " << emp->patronymic << endl;
  cout << "Возраст: " << emp->age << endl;
  printf("Дата приема на работу: %02d %02d %04d ",emp->expDay, emp->expMonth,emp->expYear); cout << endl;
  cout << "Професия: " << emp->profession << endl;
  cout << "Специальность: " << emp->speciality << endl;
  cout << "===================================================" << endl;
}
