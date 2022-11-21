//#include <vld.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <Windows.h>
#include <string>
using namespace std;

long long value;

class Notebook{
 private:
  long long index;
  string name,secondname,thirdname;
  string number;
  long long dd,mm,yy;
  long long fulldate;
 public:


  Notebook (long long id, string s1, string s2, string s3, string num, long ddd, long mmm, long yyy):index(id), name(s1), secondname(s2), thirdname(s3), number(num), dd(ddd), mm(mmm), yy(yyy){
    fulldate = dd + (mm * 30) + ((yy * 12) * 30);
  }


  static void showAll(Notebook* tmp){
    cout << "Индекс: " << tmp->index << endl;
    cout << "Фамилия: " << tmp->secondname << endl;
    cout << "Имя: " << tmp->name << endl;
    cout << "Отчество: " << tmp->thirdname << endl;
    cout << "Телефон: " << tmp->number << endl;
    cout << "Дата: " << tmp->dd << "." << tmp->mm << "." << tmp->yy << endl;
    cout << string(40,'=') << endl;
  }

  string getName() const {return name;}
  string getSecondName() const {return secondname;}
  string getThirdName() const {return thirdname;}
  string getNumber() const { return number; }

  long getDay() const {return dd;}
  long getMonth() const {return mm;}
  long getYear() const {return yy;}

  long long getFullDate() const {return fulldate;}

  ~Notebook(){};
};

struct foName {
  bool operator()(Notebook* a) {
    return (a->getFullDate() == value);
  }
};

class mapCon {
 private:
  multimap <int, Notebook*> mapList;
 public:

};

class vectorCon {
 private:
  vector <Notebook*> vecList;
 public:
  void enter(long long id, string s1, string s2, string s3, string num, long ddd, long mmm, long yyy) {
    vecList.push_back(new Notebook(id, s1, s2, s3, num, ddd, mmm, yyy));
  }

  void show_vector(long long ind) {
    /*  cout << "Индекс: " << ind << endl;
      cout << "Фамилия: " << vecList[ind]->getSecondName() << endl;
      cout << "Имя: " << vecList[ind]->getName() << endl;
      cout << "Отчество: " << vecList[ind]->getThirdName() << endl;
      cout << "Телефон: " << vecList[ind]->getNumber() << endl;
      cout << "Дата: " << vecList[ind]->getDay() << "." << vecList[ind]->getMonth() << "." << vecList[ind]->getYear() << endl;
      cout << string(40, '=') << endl;*/
    vecList[ind]->showAll;
  }

  vector <Notebook*> search(long long fDate) {
    vector <Notebook*> temp;
    value = fDate;
    auto it = vecList.begin();
    while (it != vecList.end()) {
      it = find_if(it, vecList.end(), foName());
      if (it != vecList.end()) {
        temp.push_back(*it);
        it++;
      }
      else break;
    }
    return temp;
  }
};


int main() {
  system("chcp 65001");
  long local_index = 0;
  multimap <int, Notebook> mapN;
  vector<Notebook*> vec;
  vector<Notebook*> vecP;


  bool fl = true;
  while(fl){

    string name,secondname,thirdname;
    string number;
    long long dd,mm,yy;
    long long dd1,mm1,yy1,date_find;

    cout << string(40,'=') << endl;
    cout << "Выберите опцию из списка: " << endl;
    cout << "0) Выход" << endl;
    cout << "1) Добавить контакт" << endl;
    cout << "2) Найти контакт по дате" << endl;
    cout << "3) Показать все данные" << endl;
    cout << "Выбор: " << endl;
    long chek; cin >> chek;
    switch (chek){
      case 0:
        fl = false;
        break;
      case 1: {
        cout << "Введите Фамилию: ";
        cin >> secondname;
        cout << "Введите Имя: ";
        cin >> name;
        cout << "Введите Отчество: ";
        cin >> thirdname;
        bool ch = true;
        do {
          cout << "Введите Номер в формате +7xxxxxxxxxx : ";
          cin >> number;
          bool plus = false, cnt = false;
          if (number.length() == 12) {
            cnt = true;
          }
          for (int i = 0; i < number.length(); ++i) {
            if (number[i] == '+') { plus = true; }
          }
          if (cnt && plus) {
            ch = false;
          } else {
            cout << "Неверный формат номера!" << endl;
          }
        } while (ch);
        cout << "Введите дату!" << endl;
        cout << "Введите День: ";
        cin >> dd;
        cout << "Введите Месяц: ";
        cin >> mm;
        cout << "Введите Год: ";
        cin >> yy;

        vec.push_back(new Notebook(local_index, name, secondname, thirdname, number, dd, mm, yy));
        local_index++;


        break;
      }
      case 2: {
        vecP.clear();

        cout << "Введите дату!" << endl;
        cout << "Введите День: ";
        cin >> dd;
        cout << "Введите Месяц: ";
        cin >> mm;
        cout << "Введите Год: ";
        cin >> yy;

        date_find = dd + (mm * 30) + ((yy * 12) * 30);

        value = date_find;

        auto it = vec.begin();

        while(it != vec.end()){
          it = find_if(it,vec.end(),foName());
          if(it != vec.end()){
            vecP.push_back(*it);
            it++;
          }
          else{
            break;
          }
        }

        auto it2 = vecP.begin();

        while(it2 != vecP.end()){
          //cout << *it2.get << endl;

          Notebook::showAll(*it2);

          it2++;
        }



        break;
      }
      case 3:{
        cout << string(40,'=') << endl;
        for (long i = 0; i < vec.size(); ++i) {
          Notebook::showAll(vec[i]);
        }
        break;
      }
      default: {
        cout << "Неизвестная команда" << endl;
        break;
      }
    }

  }

  /*Notebook p[] = {Notebook("Alex","Alexandrit","Alexandrovich","+79185777777",8,10,2022),
                  Notebook("Alexxx","Alexandrit","Alexandrovich","+79185777778",8,10,2022),
                  Notebook("AlexXX","Alexandrit","Alexandrovich","+79185777779",8,10,2022)};*/


  return 0;
}
