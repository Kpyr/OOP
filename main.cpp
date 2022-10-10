//#include <vld.h>
#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
class Point{
 public:
  float x=0, y=0;
};
class Shape{
 protected:

 public:
  Point* arc = 0;
  string ID="";
  virtual ~Shape(){};
};

class Triangle:public Shape{
 public:
  Triangle(){
    arc = new Point[3];
    cout << "������� ���������� ����� ������� � ������-������� ���� ������ ������� �������" << endl;
    for (int i = 0; i < 3; ++i) {
      cout << "������� ���������� " << i+1 << " �����: ";
      cout << "x = ";
      cin >> arc[i].x;
      cout << "y = ";
      cin >> arc[i].y;
    }
    ID = "Triangle";
  }
  ~Triangle(){delete[] arc;}
};

class Trapeze:public Shape{
 public:
  Trapeze(){
    arc = new Point[4];
    cout << "������� ���������� ����� ������� � ������-������� ���� ������ ������� �������" << endl;
    for (int i = 0; i < 4; ++i) {
      cout << "������� ���������� " << i+1 << " �����: ";
      cout << "x = ";
      cin >> arc[i].x;
      cout << "y = ";
      cin >> arc[i].y;
    }
    ID = "Trapeze";
  }
  ~Trapeze(){delete[] arc;}
};

class Factory{
 public:
  static Shape* createShape(short int ch){
    switch (ch){
      case 1:
        return new Triangle();
        break;
      case 2:
        return new Trapeze();
        break;
      default: return nullptr;
    }
  }
};

class Operation:public Shape{
 public:
  static long Compare(Shape* first, Shape* second){
    float first_S, second_S;
    if(first->ID == "Triangle"){
      float a,b,c,p;
      a = sqrt(pow(first->arc[0].x - first->arc[1].x,2) + pow(first->arc[0].y - first->arc[1].y,2));
      b = sqrt(pow(first->arc[1].x - first->arc[2].x,2) + pow(first->arc[1].y - first->arc[2].y,2));
      c = sqrt(pow(first->arc[2].x - first->arc[0].x,2) + pow(first->arc[2].y - first->arc[0].y,2));
      p = (a + b + c)/2;

      first_S = sqrt(p * (p - a) * (p - b) * (p - c));
    }
    else if(first->ID == "Trapeze"){
      float a,b,c,d;
      a = sqrt(pow(first->arc[0].x - first->arc[1].x,2) + pow(first->arc[0].y - first->arc[1].y,2));
      b = sqrt(pow(first->arc[1].x - first->arc[2].x,2) + pow(first->arc[1].y - first->arc[2].y,2));
      c = sqrt(pow(first->arc[2].x - first->arc[3].x,2) + pow(first->arc[2].y - first->arc[3].y,2));
      d = sqrt(pow(first->arc[3].x - first->arc[0].x,2) + pow(first->arc[3].y - first->arc[0].y,2));

      first_S = (((a+b)/2) * sqrt(pow(c,2) - pow((pow(b-a,2) + pow(c,2) - pow(d,2))/(2 * (b - a)),2)));
      //cout << first_S << endl;
    }


    if(second->ID == "Triangle"){
      float a,b,c,p;
      a = sqrt(pow(second->arc[0].x - second->arc[1].x,2) + pow(second->arc[0].y - second->arc[1].y,2));
      b = sqrt(pow(second->arc[1].x - second->arc[2].x,2) + pow(second->arc[1].y - second->arc[2].y,2));
      c = sqrt(pow(second->arc[2].x - second->arc[0].x,2) + pow(second->arc[2].y - second->arc[0].y,2));
      p = (a + b + c)/2;

      second_S = sqrt(p * (p - a) * (p - b) * (p - c));
    }
    else if(second->ID == "Trapeze"){
      float a,b,c,d;
      a = sqrt(pow(second->arc[0].x - second->arc[1].x,2) + pow(second->arc[0].y - second->arc[1].y,2));
      b = sqrt(pow(second->arc[1].x - second->arc[2].x,2) + pow(second->arc[1].y - second->arc[2].y,2));
      c = sqrt(pow(second->arc[2].x - second->arc[3].x,2) + pow(second->arc[2].y - second->arc[3].y,2));
      d = sqrt(pow(second->arc[3].x - second->arc[0].x,2) + pow(second->arc[3].y - second->arc[0].y,2));

      second_S = (((a+b)/2) * sqrt(pow(c,2) - pow((pow(b-a,2) + pow(c,2) - pow(d,2))/(2 * (b - a)),2)));
    }

    if(first_S > second_S){
      return 1;
    }
    else{
      return 2;
    }
  }

  static bool isIntersect(Shape* first, Shape* second){

    // ax + by = e
    // cx + dy = f


    // double det = a * d - b * c;

    // double x = (e * d - b * f) / det;
    // double y = (a * f - e * c) / det;

    //-----------------------------------------------------------------

    // k * x1 + b = y1;
    // k * x2 + b = y2;

    // k*3 + b = 2,
    // k*(-1) + b = -1.

    //double det = x1 - x2;

    //double k = (y1 - y2) / det
    //double b = (x1 * y2 - y1 * x2) / det




    double kx = first->arc[1].y - first->arc[0].y;
    double kx = first->arc[0].x - first->arc[1].x;






  }

  static bool isInclude(Shape* first, Shape* second){

  }
};

int main() {
  system("chcp 65001");
  setlocale(LC_ALL,"RUS");
  bool chek = true;

  while (chek) {
    cout << "=================================================================" << endl;
    cout << "�������� �����:" << endl;
    cout << "1) �������� ������� �� �������" << endl;
    cout << "2) ���������� ���� �����������" << endl;
    cout << "3) ���������� ���� ��������� ������ ������� � ������" << endl;
    short int choice;
    cin >> choice;
    cout << "=================================================================" << endl;


    switch (choice){
      case 1: {
        Shape *s1 = nullptr;
        Shape *s2 = nullptr;
        cout << "��� ���������� ������ ����� ���������� ������� ��� �������!" << endl;
        cout << "=================================================================" << endl;
        cout << "�������� ������, ������� ���������� �������:" << endl;
        cout << "1) �����������" << endl;
        cout << "2) ��������" << endl;
        short int ch;
        cin >> ch;
        cout << "=================================================================" << endl;
        s1 = Factory::createShape(ch);
        cout << "=================================================================" << endl;
        cout << "�������� ������, ������� ���������� �������:" << endl;
        cout << "1) �����������" << endl;
        cout << "2) ��������" << endl;
        cin >> ch;
        cout << "=================================================================" << endl;
        s2 = Factory::createShape(ch);



        long d = Operation::Compare(s1,s2);
        if(d == 1){
          cout << "������ - " << s1->ID << " ������ ��� - " << s2->ID << endl;
        }
        else{
          cout << "������ - " << s2->ID << " ������ ��� - " << s1->ID << endl;
        }

        break;
      }
      case 2: {
        cout << 2 << endl;
        break;
      }
      case 3: {
        cout << 2 << endl;
        break;
      }
      default:
        cout << "������: ����������� �����!" << endl;
        break;
    }



    /*cout << "=================================================================" << endl;
    cout << "�������� ������, ������� ���������� �������:" << endl;
    cout << "1) �����������" << endl;
    cout << "2) ��������" << endl;
    short int choice;
    cin >> choice;
    cout << "=================================================================" << endl;
    s1 = Factory::createShape(choice);
    if(s1){
      //cout << s1->ID << endl;
      cout << Operation::Compare(s1,s1)->ID;
    }
    else{
      cout << "���������� ������� ����� ������" << endl;
    }*/



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

  return 0;
}
