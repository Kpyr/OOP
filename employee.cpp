#pragma once
#include <string>
#include "employee.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void changeSurname(struct employee* emp, string surnm){
  emp->surname = surnm;
}

long *calcExperience(struct employee* emp, long ms[3]){
  unsigned long long bg = emp->expYear * 365 + (emp->expMonth-1) * 30 + emp->expDay;
  unsigned long long ed = ms[2] * 365 + (ms[1]-1) * 30 + ms[0];
  if(ed > bg) {
    unsigned long long res = ed - bg;
    //
    static long tmpms[4];
    tmpms[3] = res;
    tmpms[2] = res / 365;
    res -= tmpms[2] * 365;
    //
    tmpms[1] = res / 30;
    //
    res -= tmpms[1] * 30;
    tmpms[0] = res;
    return tmpms;
  }
  else{
    static long tmpms[4]{0};
    return tmpms;
  }
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
