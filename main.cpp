//--------------------------------------------------------
// ����� ���
// ������� ��� ���
// ���
// ������������ ������ �2, ������ 4
// ����2-8
// ��������� ������ ���������
// ��������� ������ ���������
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

  virtual double V_find(double* arr) {
    return 0;
  };
  virtual double S_find(double* arr) {
    return 0;
  };
  ~Body() {};
};

class Parallelepiped : public Body {
 public:
  double V_find(double* arr) {
    V = arr[0] * arr[1] * arr[2];
    return V;
  }
  double S_find(double* arr) {
    S = 2 * (arr[0] * arr[1] + arr[0] * arr[2] + arr[1] * arr[2]);
    return S;
  }
};

class Cone : public Body {
 public:
  double V_find(double* arr) {
    V = (num_PI * arr[0] * arr[0] * arr[1]) / 3;
    return V;
  }
  double S_find(double* arr) {
    S = (num_PI * arr[0] * arr[1]) + (num_PI * arr[0] * arr[0]);
    return S;
  }

};

class Ball : public Body {
 public:
  double V_find(double* arr) {
    V = (num_PI * arr[0] * arr[0] * arr[0] * 4) / 3;
    return V;
  }
  double S_find(double* arr) {
    S = 4 * num_PI * arr[0] * arr[0];
    return S;
  }
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
    cout << "�������� ������, ��� ������� ���������� ��������� ����������:" << endl;
    cout << "1) ������������� ��������������" << endl;
    cout << "2) �����" << endl;
    cout << "3) ���" << endl;
    short int choice;
    cin >> choice;
    cout << "=================================================================" << endl;
    double arr[3]{};
    double V = 0, S = 0;
    short int math;
    switch (choice) {
      case 1:
        cout << "��� ���������� ������ ������ ������� 1, ��� ���������� ������� ������� 2: " << endl;
        cin >> math;
        if (math == 1) {
          cout << "������� �������� �����, ������ � ������ ���������������: " << endl;
          for (int i = 0; i < 3; i++)cin >> arr[i];
          V = list[0]->V_find(arr);
          cout << "����� ������ ����� = " << V << endl;
        }
        else {
          cout << "������� �������� �����, ������ � ������ ���������������: " << endl;
          for (int i = 0; i < 3; i++)cin >> arr[i];
          S = list[0]->S_find(arr);
          cout << "������� ������ ����� = " << S << endl;
        }
        break;
      case 2:
        cout << "��� ���������� ������ ������ ������� 1, ��� ���������� ������� ������� 2: " << endl;
        cin >> math;
        if (math == 1) {
          cout << "������� �������� ������� ��������� � ������ ������: " << endl;
          for (int i = 0; i < 2; i++)cin >> arr[i];
          V = list[1]->V_find(arr);
          cout << "����� ������ ����� = " << V << endl;
        }
        else {
          cout << "������� �������� ������� ��������� � ����� ����������: " << endl;
          for (int i = 0; i < 2; i++)cin >> arr[i];
          S = list[1]->S_find(arr);
          cout << "������� ������ ����� = " << S << endl;
        }
        break;
      case 3:
        cout << "��� ���������� ������ ������ ������� 1, ��� ���������� ������� ������� 2: " << endl;
        cin >> math;
        if (math == 1) {
          cout << "������� �������� ������� ������: " << endl;
          for (int i = 0; i < 1; i++)cin >> arr[i];
          V = list[2]->V_find(arr);
          cout << "����� ������ ����� = " << V << endl;
        }
        else {
          cout << "������� �������� ������� ������: " << endl;
          for (int i = 0; i < 1; i++)cin >> arr[i];
          S = list[2]->S_find(arr);
          cout << "������� ������ ����� = " << S << endl;
        }
        break;
      default:
        cout << "����������� �������!" << endl;
        break;
    }
    string str;
    bool flg = true;
    do {
      cout << "������� 'end' ��� �� ��������� ��������� ��� 'nxt', ��� �� ��������� ������." << endl;
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
          cout << "����������� �������, ��������� �������!" << endl;
        }
      }
    } while (flg);
  }
  delete pram;
  delete list[1];
  delete list[2];
  return 0;
}
