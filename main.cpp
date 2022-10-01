#include <iostream>
#include <cmath>
#include <Windows.h>
#include <vector>
using namespace std;
class Body{
  long long countPoints, countElm;
  vector <vector <float>> points(countPoints, vector <float>(countElm));
 public:
  virtual void showinfo(){};
  virtual ~Body() = default;
};
class Parallelepiped:public Body{
 public:
  Parallelepiped():Body(){
  };
  setPoints(){
    cout << "Введите координаты "
  }
};
class Cone:public Body{

};
class Ball:public Body{

};
int main() {

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
