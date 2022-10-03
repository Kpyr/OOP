//--------------------------------------------------------
// ИКТИБ ЮФУ
// Кафедра МОП ЭВМ
// ООП
// Лабораторная работа №2, варант 4
// КТбо2-8
// Степочкин Михаил Андреевич
// Кузьменко Кирилл Сергеевич
// 03.10.2022
//--------------------------------------------------------
#pragma once
//#include <vld.h>
#include <stack>
#include <memory>
#include <sstream>
#include "Windows.h"
#include <iostream>
#include <cmath>
using namespace std;
class Body {
 protected:
  double V = 0, S = 0, num_PI = 3.14;
 public:
  Body(){};
  virtual double V_find(double* arr) {   ///База
    return 0;
  };
  virtual double S_find(double* arr) {  ///База
    return 0;
  };
  ~Body() {};
};

class Parallelepiped : public Body {
 public:
  Parallelepiped(){};
  double V_find(double* arr) {          ///Переопределение виртуальной функции
    V = arr[0] * arr[1] * arr[2];       ///для производного класса Parallelepiped
    return V;                           ///которая вычисляет Объем паралелепипеда
  }
  double S_find(double* arr) {                                      ///Переопределение виртуальной функции
    S = 2 * (arr[0] * arr[1] + arr[0] * arr[2] + arr[1] * arr[2]);  ///для производного класса Parallelepiped
    return S;                                                       ///которая вычисляет Площадь паралелепипеда
  }
  ~Parallelepiped(){};
};

class Cone : public Body {
 public:
  Cone(){};
  double V_find(double* arr) {                    ///Переопределение виртуальной функции
    V = (num_PI * arr[0] * arr[0] * arr[1]) / 3;  ///для производного класса Cone
    return V;                                     ///которая вычисляет Объем конуса
  }
  double S_find(double* arr) {                                    ///Переопределение виртуальной функции
    S = (num_PI * arr[0] * arr[1]) + (num_PI * arr[0] * arr[0]);  ///для производного класса Cone
    return S;                                                     ///которая вычисляет Площадь конуса
  }
  ~Cone(){};
};

class Ball : public Body {
 public:
  Ball(){};
  double V_find(double* arr) {                        ///Переопределение виртуальной функции
    V = (num_PI * arr[0] * arr[0] * arr[0] * 4) / 3;  ///для производного класса Ball
    return V;                                         ///которая вычисляет Объем шара
  }
  double S_find(double* arr) {                        ///Переопределение виртуальной функции
    S = 4 * num_PI * arr[0] * arr[0];                 ///для производного класса Ball
    return S;                                         ///которая вычисляет площадь шара
  }
  ~Ball(){};
};

int main() {
  setlocale(LC_ALL, "rus");
  Body* list[3];
  //Cone* conus = new Cone;
  //Ball* shar = new Ball;
  Parallelepiped* pram = new Parallelepiped;
  list[0] = pram;
  list[1] = new Cone;
  list[2] = new Ball;
  //list[1] = conus;
  //list[2] = shar;
  bool chek = true;

  while (chek) {
    cout << "=================================================================" << endl;
    cout << "Выберите фигуру, для которой необходимо выполнить вычисления:" << endl;
    cout << "1) Прямоугольный параллелипипед" << endl;
    cout << "2) Конус" << endl;
    cout << "3) Шар" << endl;
    short int choice;
    cin >> choice;
    cout << "=================================================================" << endl;
    double arr[3]{};
    double V = 0, S = 0;
    short int math = 0;
    switch (choice) {
      case 1:
        while(math != 1 && math != 2) {
          cout << "Для вычисления объёма фигуры введите 1, для вычиселния площади введите 2: " << endl;
          cin >> math;
          switch (math){
            case 1:
              cout << "Введите значения длины параллелипипеда: ";
              cin >> arr[0];
              cout << "Введите значения Ширины параллелипипеда: ";
              cin >> arr[1];
              cout << "Введите значения Высоты параллелипипеда: ";
              cin >> arr[2];

              V = list[0]->V_find(arr);

              cout << "Объём фигуры равен = " << V << endl;
              break;
            case 2:
              cout << "Введите значения длины параллелипипеда: ";
              cin >> arr[0];
              cout << "Введите значения Ширины параллелипипеда: ";
              cin >> arr[1];
              cout << "Введите значения Высоты параллелипипеда: ";
              cin >> arr[2];

              S = list[0]->S_find(arr);

              cout << "Площадь фигуры равна = " << S << endl;
              break;
            default:
              cout << "Неизвестная команда!" << endl;
              break;
          }
        }
        break;
      case 2:
        while(math != 1 && math != 2) {
          cout << "Для вычисления объёма фигуры введите 1, для вычиселния площади введите 2: " << endl;
          cin >> math;
          switch (math){
            case 1:
              cout << "Введите значения Радиуса основания: ";
              cin >> arr[0];
              cout << "Введите значения Высоты конуса: ";
              cin >> arr[1];

              V = list[1]->V_find(arr);
              cout << "Объём фигуры равен = " << V << endl;
              break;
            case 2:
              cout << "Введите значения Радиуса основания: ";
              cin >> arr[0];
              cout << "Введите значения Длины образующей конуса: ";
              cin >> arr[1];

              S = list[1]->S_find(arr);
              cout << "Площадь фигуры равна = " << S << endl;
              break;
            default:
              cout << "Неизвестная команда!" << endl;
              break;
          }
        }
        break;
      case 3:
        while(math != 1 && math != 2) {
          cout << "Для вычисления объёма фигуры введите 1, для вычиселния площади введите 2: " << endl;
          cin >> math;
          switch (math){
            case 1:
              cout << "Введите значения Радиуса: ";
              cin >> arr[0];

              V = list[2]->V_find(arr);
              cout << "Объём фигуры равен = " << V << endl;
              break;
            case 2:
              cout << "Введите значения Радиуса: ";
              cin >> arr[0];

              S = list[2]->S_find(arr);
              cout << "Площадь фигуры равна = " << S << endl;
              break;
            default:
              cout << "Неизвестная команда!" << endl;
              break;
          }
        }
        break;
      default:
        cout << "Неизвестная команда!" << endl;
        break;
    }
    string str;
    bool flg = true;
    do {
      cout << "Введите 'end' что бы завершить программу или 'nxt', что бы повторить запрос." << endl;
      cin >> str;
      {
        if (str == "end") {
          chek = false;
          flg = false;
        }
        else if (str == "nxt") {
          flg = false;
        }
        else {
          cout << "Неизвестная команда, повторите попытку!" << endl;
        }
      }
    } while (flg);
  }
  delete pram;
  delete list[1];
  delete list[2];
  return 0;
}
