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
 public:
  double S;
  Point* arc = 0;
  string ID="";
  virtual ~Shape(){};
};

class Triangle:public Shape{
 public:
  Triangle(){
    arc = new Point[3];
    cout << "Введите координаты точек начиная с левого-нижнего угла против часовой стрелки" << endl;
    for (int i = 0; i < 3; ++i) {
      cout << "Введите координаты " << i+1 << " точки: ";
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

class Operation:public Shape {
 public:
  static long Compare(Shape *first, Shape *second) {
    float first_S, second_S;
    if (first->ID == "Triangle") {
      float a, b, c, p;
      a = sqrt(pow(first->arc[0].x - first->arc[1].x, 2) + pow(first->arc[0].y - first->arc[1].y, 2));
      b = sqrt(pow(first->arc[1].x - first->arc[2].x, 2) + pow(first->arc[1].y - first->arc[2].y, 2));
      c = sqrt(pow(first->arc[2].x - first->arc[0].x, 2) + pow(first->arc[2].y - first->arc[0].y, 2));
      p = (a + b + c) / 2;

      first_S = sqrt(p * (p - a) * (p - b) * (p - c));
    } else if (first->ID == "Trapeze") {
      float a, b, c, d;
      a = sqrt(pow(first->arc[0].x - first->arc[1].x, 2) + pow(first->arc[0].y - first->arc[1].y, 2));
      b = sqrt(pow(first->arc[1].x - first->arc[2].x, 2) + pow(first->arc[1].y - first->arc[2].y, 2));
      c = sqrt(pow(first->arc[2].x - first->arc[3].x, 2) + pow(first->arc[2].y - first->arc[3].y, 2));
      d = sqrt(pow(first->arc[3].x - first->arc[0].x, 2) + pow(first->arc[3].y - first->arc[0].y, 2));

      first_S = (((a + b) / 2) * sqrt(pow(c, 2) - pow((pow(b - a, 2) + pow(c, 2) - pow(d, 2)) / (2 * (b - a)), 2)));
      //cout << first_S << endl;
    }

    if (second->ID == "Triangle") {
      float a, b, c, p;
      a = sqrt(pow(second->arc[0].x - second->arc[1].x, 2) + pow(second->arc[0].y - second->arc[1].y, 2));
      b = sqrt(pow(second->arc[1].x - second->arc[2].x, 2) + pow(second->arc[1].y - second->arc[2].y, 2));
      c = sqrt(pow(second->arc[2].x - second->arc[0].x, 2) + pow(second->arc[2].y - second->arc[0].y, 2));
      p = (a + b + c) / 2;

      second_S = sqrt(p * (p - a) * (p - b) * (p - c));
    } else if (second->ID == "Trapeze") {
      float a, b, c, d;
      a = sqrt(pow(second->arc[0].x - second->arc[1].x, 2) + pow(second->arc[0].y - second->arc[1].y, 2));
      b = sqrt(pow(second->arc[1].x - second->arc[2].x, 2) + pow(second->arc[1].y - second->arc[2].y, 2));
      c = sqrt(pow(second->arc[2].x - second->arc[3].x, 2) + pow(second->arc[2].y - second->arc[3].y, 2));
      d = sqrt(pow(second->arc[3].x - second->arc[0].x, 2) + pow(second->arc[3].y - second->arc[0].y, 2));

      second_S = (((a + b) / 2) * sqrt(pow(c, 2) - pow((pow(b - a, 2) + pow(c, 2) - pow(d, 2)) / (2 * (b - a)), 2)));
    }

    if (first_S > second_S) {
      return 1;
    } else if (first_S == second_S) {
      return 2;
    } else {
      return 3;
    }
  }

  static long isIntersect(Shape *first, Shape *second) {
    double first_havyX, first_havyY, second_havyX, second_havyY;
    double first_R, second_R;
    double tmp1, tmp2, tmp3, tmp4;

    if (first->ID == "Triangle") {
      first_havyX = (first->arc[0].x + first->arc[1].x + first->arc[2].x) / 3;
      first_havyY = (first->arc[0].y + first->arc[1].y + first->arc[2].y) / 3;

      tmp1 = sqrt(pow(first_havyX - first->arc[0].x, 2) + pow(first_havyY - first->arc[0].y, 2));
      tmp2 = sqrt(pow(first_havyX - first->arc[1].x, 2) + pow(first_havyY - first->arc[1].y, 2));
      tmp3 = sqrt(pow(first_havyX - first->arc[2].x, 2) + pow(first_havyY - first->arc[2].y, 2));

      first_R = max(tmp1, max(tmp2, tmp3));
    } else if (first->ID == "Trapeze") {
      first_havyX = (first->arc[0].x + first->arc[1].x + first->arc[2].x + first->arc[3].x) / 4;
      first_havyY = (first->arc[0].y + first->arc[1].y + first->arc[2].y + first->arc[3].y) / 4;

      tmp1 = sqrt(pow(first_havyX - first->arc[0].x, 2) + pow(first_havyY - first->arc[0].y, 2));
      tmp2 = sqrt(pow(first_havyX - first->arc[1].x, 2) + pow(first_havyY - first->arc[1].y, 2));
      tmp3 = sqrt(pow(first_havyX - first->arc[2].x, 2) + pow(first_havyY - first->arc[2].y, 2));
      tmp4 = sqrt(pow(first_havyX - first->arc[3].x, 2) + pow(first_havyY - first->arc[3].y, 2));

      first_R = max(tmp1, max(tmp2, max(tmp3, tmp4)));
    }

    if (second->ID == "Triangle") {
      second_havyX = (second->arc[0].x + second->arc[1].x + second->arc[2].x) / 3;
      second_havyY = (second->arc[0].y + second->arc[1].y + second->arc[2].y) / 3;

      tmp1 = sqrt(pow(second_havyX - second->arc[0].x, 2) + pow(second_havyY - second->arc[0].y, 2));
      tmp2 = sqrt(pow(second_havyX - second->arc[1].x, 2) + pow(second_havyY - second->arc[1].y, 2));
      tmp3 = sqrt(pow(second_havyX - second->arc[2].x, 2) + pow(second_havyY - second->arc[2].y, 2));

      second_R = max(tmp1, max(tmp2, tmp3));
    } else if (second->ID == "Trapeze") {
      second_havyX = (second->arc[0].x + second->arc[1].x + second->arc[2].x + second->arc[3].x) / 4;
      second_havyY = (second->arc[0].y + second->arc[1].y + second->arc[2].y + second->arc[3].y) / 4;

      tmp1 = sqrt(pow(second_havyX - second->arc[0].x, 2) + pow(second_havyY - second->arc[0].y, 2));
      tmp2 = sqrt(pow(second_havyX - second->arc[1].x, 2) + pow(second_havyY - second->arc[1].y, 2));
      tmp3 = sqrt(pow(second_havyX - second->arc[2].x, 2) + pow(second_havyY - second->arc[2].y, 2));
      tmp4 = sqrt(pow(second_havyX - second->arc[3].x, 2) + pow(second_havyY - second->arc[3].y, 2));

      second_R = max(tmp1, max(tmp2, max(tmp3, tmp4)));
    }

    double len = sqrt(pow(first_havyX - second_havyX, 2) + pow(first_havyY - second_havyY, 2));

    if (len > (first_R + second_R)) {
      return 1;
    } else if (len == (first_R + second_R)) {
      return 2;
    } else {
      return 3;
    }
  }
  static long isInclude(Shape* first, Shape* second){
    /*if(isIntersect(first,second) == 2 || isIntersect(first,second) == 3){
      return 1;
    }
    else{*/
      double first_havyX, first_havyY, second_havyX, second_havyY;
      double first_R, second_R;
      double tmp1, tmp2, tmp3, tmp4;

      if (first->ID == "Triangle") {
        first_havyX = (first->arc[0].x + first->arc[1].x + first->arc[2].x) / 3;
        first_havyY = (first->arc[0].y + first->arc[1].y + first->arc[2].y) / 3;

        tmp1 = sqrt(pow(first_havyX - first->arc[0].x, 2) + pow(first_havyY - first->arc[0].y, 2));
        tmp2 = sqrt(pow(first_havyX - first->arc[1].x, 2) + pow(first_havyY - first->arc[1].y, 2));
        tmp3 = sqrt(pow(first_havyX - first->arc[2].x, 2) + pow(first_havyY - first->arc[2].y, 2));

        first_R = max(tmp1, max(tmp2, tmp3));
      } else if (first->ID == "Trapeze") {
        first_havyX = (first->arc[0].x + first->arc[1].x + first->arc[2].x + first->arc[3].x) / 4;
        first_havyY = (first->arc[0].y + first->arc[1].y + first->arc[2].y + first->arc[3].y) / 4;

        tmp1 = sqrt(pow(first_havyX - first->arc[0].x, 2) + pow(first_havyY - first->arc[0].y, 2));
        tmp2 = sqrt(pow(first_havyX - first->arc[1].x, 2) + pow(first_havyY - first->arc[1].y, 2));
        tmp3 = sqrt(pow(first_havyX - first->arc[2].x, 2) + pow(first_havyY - first->arc[2].y, 2));
        tmp4 = sqrt(pow(first_havyX - first->arc[3].x, 2) + pow(first_havyY - first->arc[3].y, 2));

        first_R = max(tmp1, max(tmp2, max(tmp3, tmp4)));
      }

      if (second->ID == "Triangle") {
        second_havyX = (second->arc[0].x + second->arc[1].x + second->arc[2].x) / 3;
        second_havyY = (second->arc[0].y + second->arc[1].y + second->arc[2].y) / 3;

        tmp1 = sqrt(pow(second_havyX - second->arc[0].x, 2) + pow(second_havyY - second->arc[0].y, 2));
        tmp2 = sqrt(pow(second_havyX - second->arc[1].x, 2) + pow(second_havyY - second->arc[1].y, 2));
        tmp3 = sqrt(pow(second_havyX - second->arc[2].x, 2) + pow(second_havyY - second->arc[2].y, 2));

        second_R = max(tmp1, max(tmp2, tmp3));
      } else if (second->ID == "Trapeze") {
        second_havyX = (second->arc[0].x + second->arc[1].x + second->arc[2].x + second->arc[3].x) / 4;
        second_havyY = (second->arc[0].y + second->arc[1].y + second->arc[2].y + second->arc[3].y) / 4;

        tmp1 = sqrt(pow(second_havyX - second->arc[0].x, 2) + pow(second_havyY - second->arc[0].y, 2));
        tmp2 = sqrt(pow(second_havyX - second->arc[1].x, 2) + pow(second_havyY - second->arc[1].y, 2));
        tmp3 = sqrt(pow(second_havyX - second->arc[2].x, 2) + pow(second_havyY - second->arc[2].y, 2));
        tmp4 = sqrt(pow(second_havyX - second->arc[3].x, 2) + pow(second_havyY - second->arc[3].y, 2));

        second_R = max(tmp1, max(tmp2, max(tmp3, tmp4)));
      }

      double len = sqrt(pow(first_havyX - second_havyX, 2) + pow(first_havyY - second_havyY, 2));

      if(len < abs(first_R - second_R)){
        if(first_R > second_R){
          return 2;
        }
        else{
          return 3;
        }
      }
      else{
        return 1;
      }

    }
 /* }*/
};

int main() {
  system("chcp 65001");
  setlocale(LC_ALL,"RUS");
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
      case 1: {
        Shape *s1 = nullptr;
        Shape *s2 = nullptr;
        cout << "Для выполнения данной опции необходимо создать два объекта!" << endl;
        cout << "=================================================================" << endl;
        cout << "Выберите фигуру, которую необходимо создать:" << endl;
        cout << "1) Треугольник" << endl;
        cout << "2) Трапеция" << endl;
        short int ch;
        cin >> ch;
        cout << "=================================================================" << endl;
        s1 = Factory::createShape(ch);
        cout << "=================================================================" << endl;
        cout << "Выберите фигуру, которую необходимо создать:" << endl;
        cout << "1) Треугольник" << endl;
        cout << "2) Трапеция" << endl;
        cin >> ch;
        cout << "=================================================================" << endl;
        s2 = Factory::createShape(ch);



        long d = Operation::Compare(s1,s2);
        if(d == 1){
          cout << "Фигура - " << s1->ID << " Больше чем - " << s2->ID << endl;
        }
        else if(d == 2){
          cout << "Фигуры равны" << endl;
        }
        else if(d == 3){
          cout << "Фигура - " << s2->ID << " Больше чем - " << s1->ID << endl;
        }

        delete s1;
        delete s2;
        break;
      }
      case 2: {
        Shape *s1 = nullptr;
        Shape *s2 = nullptr;
        cout << "Для выполнения данной опции необходимо создать два объекта!" << endl;
        cout << "=================================================================" << endl;
        cout << "Выберите фигуру, которую необходимо создать:" << endl;
        cout << "1) Треугольник" << endl;
        cout << "2) Трапеция" << endl;
        short int ch;
        cin >> ch;
        cout << "=================================================================" << endl;
        s1 = Factory::createShape(ch);
        cout << "=================================================================" << endl;
        cout << "Выберите фигуру, которую необходимо создать:" << endl;
        cout << "1) Треугольник" << endl;
        cout << "2) Трапеция" << endl;
        cin >> ch;
        cout << "=================================================================" << endl;
        s2 = Factory::createShape(ch);


        long d = Operation::isIntersect(s1,s2);
        if(d == 1){
          cout << "Фигуры не пересекаются!" << endl;
        }
        else if(d == 2){
          cout << "Фигуры касаются!" << endl;
        }
        else if(d == 3){
          cout << "Фигуры пересекаются!" << endl;
        }



        delete s1;
        delete s2;
        break;
      }
      case 3: {
        Shape *s1 = nullptr;
        Shape *s2 = nullptr;
        cout << "Для выполнения данной опции необходимо создать два объекта!" << endl;
        cout << "=================================================================" << endl;
        cout << "Выберите фигуру, которую необходимо создать:" << endl;
        cout << "1) Треугольник" << endl;
        cout << "2) Трапеция" << endl;
        short int ch;
        cin >> ch;
        cout << "=================================================================" << endl;
        s1 = Factory::createShape(ch);
        cout << "=================================================================" << endl;
        cout << "Выберите фигуру, которую необходимо создать:" << endl;
        cout << "1) Треугольник" << endl;
        cout << "2) Трапеция" << endl;
        cin >> ch;
        cout << "=================================================================" << endl;
        s2 = Factory::createShape(ch);


        long d = Operation::isInclude(s1,s2);
        if(d == 1){
          cout << "Включение отсутсвует" << endl;
        }
        else if(d == 2){
          cout << "Вторая фигура включается в первую" << endl;
        }
        else if(d == 3){
          cout << "Первая фигура включается во вторую" << endl;
        }



        delete s1;
        delete s2;
        break;
      }
      default:
        cout << "Ошибка: Неизвестная опция!" << endl;
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

  return 0;
}