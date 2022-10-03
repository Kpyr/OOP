//#include <vld.h>
#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
class Line {            //Класс Line3D
 private:
  long long _longX1, _longY1, _longZ1;
  long long _longX2, _longY2, _longZ2;
 public:
  Line();
  Line(const Line&);
  void setLine();                     //Метод задачи координат линии.
  void calculateLen();                //Метод вычисления длины линии
  void transfer();                    //Метод переноса линии
  void showLine();                    //Метод вывода линии в консоль (Выводит координаты начала и конца)
  void createTriangle();              //Метод создания треугольника из двух линий.
  ~Line();
};
Line::Line() {}
Line::Line(const Line& ln1) {           //Копирование
  this->_longX1 = ln1._longX1;
  this->_longX2 = ln1._longX2;
  this->_longY1 = ln1._longY1;
  this->_longY2 = ln1._longY2;
  this->_longZ1 = ln1._longZ1;
  this->_longZ2 = ln1._longZ2;
}
Line::~Line() {}
void Line::showLine() {                 //Вывод в консоль
  cout << "Линия с координатами: (" << this->_longX1 << "; " << this->_longY1 << "; " << this->_longZ1 << ") --------------------> ";
  cout << "(" << this->_longX2 << "; " << this->_longY2 << "; " << this->_longZ2 << ")" << endl;
}


void Line::createTriangle() {           //создание треугольника
  int tl = 0;
  Line ln1, ln2;
  ///Проверка заданы ли координаты первой линии
  if (this->_longX1 == -3689348814741910324 || this->_longX2 == -3689348814741910324 || this->_longY1 == -3689348814741910324 || this->_longY2 == -3689348814741910324 || this->_longZ1 == -3689348814741910324 || this->_longZ2 == -3689348814741910324) {
    cout << "Координаты первой линии не заданы!" << endl;
    this->setLine();
  }
  cout << "Задайте координаты второй линии, для создания замкнутой фигуры!" << endl;
  ln2.setLine();
  try {
    if ((this->_longX1 == this->_longX2 && ln2._longX1 == ln2._longX2 && this->_longY1 == this->_longY2 && ln2._longY1 == ln2._longY2)     ///Проверка лежат ли точки на одной прямой
        || (this->_longX1 == this->_longX2 && ln2._longX1 == ln2._longX2 && this->_longZ1 == this->_longZ2 && ln2._longZ1 == ln2._longZ2)     ///Проверка лежат ли точки на одной прямой
        || (this->_longY1 == this->_longY2 && ln2._longY1 == ln2._longY2 && this->_longZ1 == this->_longZ2 && ln2._longZ1 == ln2._longZ2)) {   ///Проверка лежат ли точки на одной прямой
      tl = 1;
      throw(tl);
    }
    else {
      if (this->_longX2 == ln2._longX1 && this->_longY2 == ln2._longY1 && this->_longZ2 == ln2._longZ1) {                         ///Проверка на общую точку


        this->showLine();
        ln2.showLine();

        Line ln3;
        ln3._longX1 = ln2._longX2;
        ln3._longX2 = this->_longX1;
        ln3._longY1 = ln2._longY2;
        ln3._longY2 = this->_longY1;
        ln3._longZ1 = ln2._longZ2;
        ln3._longZ2 = this->_longZ1;

        ln3.showLine();


      }
      else if (this->_longX1 == ln2._longX2 && this->_longY1 == ln2._longY2 && this->_longZ1 == ln2._longZ2) {                  ///Проверка на общую точку


        this->showLine();
        ln2.showLine();

        Line ln3;
        ln3._longX1 = ln2._longX1;
        ln3._longX2 = this->_longX2;
        ln3._longY1 = ln2._longY1;
        ln3._longY2 = this->_longY2;
        ln3._longZ1 = ln2._longZ1;
        ln3._longZ2 = this->_longZ2;

        ln3.showLine();
      }
      else if (this->_longX1 == ln2._longX1 && this->_longY1 == ln2._longY1 && this->_longZ1 == ln2._longZ1) {                  ///Проверка на общую точку


        this->showLine();
        ln2.showLine();

        Line ln3;
        ln3._longX1 = ln2._longX2;
        ln3._longX2 = this->_longX2;
        ln3._longY1 = ln2._longY2;
        ln3._longY2 = this->_longY2;
        ln3._longZ1 = ln2._longZ2;
        ln3._longZ2 = this->_longZ2;

        ln3.showLine();
      }
      else if (this->_longX2 == ln2._longX2 && this->_longY2 == ln2._longY2 && this->_longZ2 == ln2._longZ2) {                  ///Проверка на общую точку


        this->showLine();
        ln2.showLine();

        Line ln3;
        ln3._longX1 = ln2._longX2;
        ln3._longX2 = this->_longX2;
        ln3._longY1 = ln2._longY2;
        ln3._longY2 = this->_longY2;
        ln3._longZ1 = ln2._longZ2;
        ln3._longZ2 = this->_longZ2;

        ln3.showLine();
      }
      else {                                                                ///в случае если линии не соеденены
        throw (tl);
      }
    }
  }
  catch (int test) {
    if (test == 0) {
      cout << "Ошибка: Линии не являются продолжением друг друга" << endl;
    }
    else if (test == 1) {
      cout << "Ошибка: Лежат на одной прямой!" << endl;
    }
    else {
      cout << "Неизвестная ошибка!" << endl;
    }
  }

}


void Line::setLine() {
  cout << "Задайте координаты 1-ой точки в трехмерном пространстве" << endl;
  cout << "Координата x: "; cin >> _longX1; cout << endl;
  cout << "Координата y: "; cin >> _longY1; cout << endl;
  cout << "Координата z: "; cin >> _longZ1; cout << endl;

  cout << "Задайте координаты 2-ой точки в трехмерном пространстве" << endl;
  cout << "Координата x: "; cin >> _longX2; cout << endl;
  cout << "Координата y: "; cin >> _longY2; cout << endl;
  cout << "Координата z: "; cin >> _longZ2; cout << endl;

}

void Line::calculateLen() {
  cout << "Длина: " << sqrt(pow(this->_longX1 - this->_longX2, 2) + pow(this->_longY1 - this->_longY2, 2) + pow(this->_longZ1 - this->_longZ2, 2)) << endl;
}




void Line::transfer() {
  long tmp;
  long tm;
  Line ln2(*this);            //Копирование текущей линии
  cout << "==================================================" << endl;
  cout << "Доступные команды: " << endl;
  cout << "1) Параллельный перенос по X" << endl;
  cout << "2) Параллельный перенос по Y" << endl;
  cout << "3) Параллельный перенос по Z" << endl;
  cout << "Введите номер команды:"; cin >> tmp;
  cout << "==================================================" << endl;
  switch (tmp) {
    case 1:
      cout << "Введите значение на которое необходимо сделать перенос: ";
      cin >> tm;
      cout << "==================================================" << endl;
      this->_longX1 += tm;
      this->_longX2 += tm;
      break;
    case 2:
      cout << "Введите значение на которое необходимо сделать перенос: ";
      cin >> tm;
      cout << "==================================================" << endl;
      this->_longY1 += tm;
      this->_longY2 += tm;
      break;
    case 3:
      cout << "Введите значение на которое необходимо сделать перенос: ";
      cin >> tm;
      cout << "==================================================" << endl;
      this->_longZ1 += tm;
      this->_longZ2 += tm;
      break;
    default:
      cout << "Неизвестная команда" << endl;
      cout << "==================================================" << endl;
      break;
  }
  ln2.showLine();
  this->showLine();
  cout << "==================================================" << endl;
}


int main() {
  //setlocale(LC_ALL,"RUS");
  system("chcp 65001");






  cout << "==================================================" << endl;

  cout <<
       "████████████████████████████████████████████████████████\n"
       "████████████████████████████████████████████████████████\n"
       "███  ██████  ██  ████  ██      ██████     ████     █████\n"
       "███  ██████  ██   ███  ██  ██████████████  ███  ███  ███\n"
       "███  ██████  ██  █ ██  ██      ██████     ████  ███  ███\n"
       "███  ██████  ██  ██ █  ██  ██████████████  ███  ███  ███\n"
       "███      ██  ██  ███   ██      ██████     ████     █████\n"
       "████████████████████████████████████████████████████████\n"
       "████████████████████████████████████████████████████████" << endl;




  bool chek = true;
  while (chek) {
    cout << "==================================================" << endl;
    cout << "1) Определить длину линии" << endl;
    cout << "2) Параллельный перенос линии" << endl;
    cout << "3) Построение треугольника" << endl;
    cout << "Введите номер команды: ";
    short int choice;
    cin >> choice;
    cout << "==================================================" << endl;
    Line ln1;
    switch (choice) {
      case 1:
        ln1.setLine();
        ln1.calculateLen();
        /*~Line ln1;*/
        break;
      case 2:
        ln1.setLine();
        ln1.transfer();
        /*~Line ln1;*/
        break;
      case 3:
        ln1.createTriangle();
        /*~Line ln1;*/
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


  return 0;
}