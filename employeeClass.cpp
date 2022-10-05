#include "employeeClass.h"
#include <Windows.h>

void employeeClass::changeSurname(string surnm) {
  empClass.surname = surnm;
}

long *employeeClass::calcExperience(long ms[3]) {
  unsigned long long bg = empClass.expYear * 365 + (empClass.expMonth-1) * 30 + empClass.expDay;
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

void employeeClass::changeProfessionAndSpeciality(string newProf, string newSpec) {
  empClass.profession = newProf;
  empClass.speciality = newSpec;
}

void employeeClass::showInfo() {
  cout << "===================================================" << endl;
  cout << "Фамилия: " << empClass.surname << endl;
  cout << "Имя: " << empClass.name << endl;
  cout << "Отчество: " << empClass.patronymic << endl;
  cout << "Возраст: " << empClass.age << endl;
  printf("Дата приема на работу: %02d %02d %04d ",empClass.expDay, empClass.expMonth,empClass.expYear); cout << endl;
  cout << "Професия: " << empClass.profession << endl;
  cout << "Специальность: " << empClass.speciality << endl;
  cout << "===================================================" << endl;
}
