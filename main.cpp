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
    ID = "Triangle";
  }
  ~Triangle(){delete[] arc;}
};

class Trapeze:public Shape{
 public:
  Trapeze(){
    arc = new Point[4];
    cout << "Введите координаты точек начиная с левого-нижнего угла против часовой стрелки" << endl;
    for (int i = 0; i < 4; ++i) {
      cout << "Введите координаты " << i+1 << " точки: ";
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
  static Shape* Compare(Shape* first, Shape* second){
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
      return first;
    }
    else{
      return second;
    }
  }
  /*bool isInclude(Shape* first, Shape* second){
    return true;
  }*/
};

int main() {
  system("chcp 65001");
  bool chek = true;

  while (chek) {
    cout << "=================================================================" << endl;
    cout << "Выберите опцию:" << endl;
    cout << "1) Сравнить объекты по площади" << endl;
    cout << "2) Определить факт пересечения" << endl;
    cout << "3) Определить факт включения одного объекта в другой" << endl;
    short int choice;
    cin >> choice;
    cout << "=================================================================" << endl;


    switch (choice){
      case 1:
        Shape* s1 = nullptr;
        Shape* s2 = nullptr;
        cout << "Для выполнения данной опции необходимо создать два объекта!" << endl;
        cout << "=================================================================" << endl;
        cout << "Выберите фигуру, которую необходимо создать:" << endl;
        cout << "1) Треугольник" << endl;
        cout << "2) Трапеция" << endl;
        short int ch;
        cin >> ch;
        cout << "=================================================================" << endl;
        s1 = Factory::createShape(ch);
        break;
      case 2:

        break;
      case 3:
        break;
      default:
        cout << "Ошибка: Неизвестная опция!" << endl;
        break;
    }



    /*cout << "=================================================================" << endl;
    cout << "Выберите фигуру, которую необходимо создать:" << endl;
    cout << "1) Треугольник" << endl;
    cout << "2) Трапеция" << endl;
    short int choice;
    cin >> choice;
    cout << "=================================================================" << endl;
    s1 = Factory::createShape(choice);
    if(s1){
      //cout << s1->ID << endl;
      cout << Operation::Compare(s1,s1)->ID;
    }
    else{
      cout << "Невозможно создать такую фигуру" << endl;
    }*/
    if(s1) delete s1;
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

  return 0;
}
