#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <Windows.h>
#include <string>
#include <fstream>
using namespace std;

long long value;

class Notebook {
private:
    long long index;
    string name, secondname, thirdname;
    string number;
    long long dd, mm, yy;
    long long fulldate;
public:


    Notebook(long long id, string s1, string s2, string s3, string num, long ddd, long mmm, long yyy) :index(id), name(s1), secondname(s2), thirdname(s3), number(num), dd(ddd), mm(mmm), yy(yyy) {
        fulldate = dd + (mm * 30) + ((yy * 12) * 30);
    }


    static void showAll(Notebook* tmp) {
        cout << "Индекс: " << tmp->index << endl;
        cout << "Фамилия: " << tmp->secondname << endl;
        cout << "Имя: " << tmp->name << endl;
        cout << "Отчество: " << tmp->thirdname << endl;
        cout << "Телефон: " << tmp->number << endl;
        cout << "Дата: " << tmp->dd << "." << tmp->mm << "." << tmp->yy << endl;
        cout << string(40, '=') << endl;
    }

    string getName() const { return name; }
    string getSecondName() const { return secondname; }
    string getThirdName() const { return thirdname; }
    string getNumber() const { return number; }

    long getDay() const { return dd; }
    long getMonth() const { return mm; }
    long getYear() const { return yy; }

    long long getFullDate() const { return fulldate; }

    ~Notebook() {};
};

struct foName {
    bool operator()(Notebook* a) {
        return (a->getFullDate() == (value - 3));
    }
};

class Cont {
public:
    Cont() = default;
    virtual void enter(long long id, string s1, string s2, string s3, string num, long ddd, long mmm, long yyy) = 0;
    virtual void show() = 0;
    virtual vector<Notebook*> search(long long temp) = 0;
    ~Cont() = default;
};

class mapCon :public Cont {
private:
    multimap <int, Notebook*> mapList;
public:
    void enter(long long id, string s1, string s2, string s3, string num, long ddd, long mmm, long yyy) override {
        Notebook* temp = new Notebook(id, s1, s2, s3, num, ddd, mmm, yyy);
        long long tempTime = ddd + (30 * mmm) + ((12 * yyy) * 30);
        mapList.insert(pair<long long, Notebook*>(tempTime, temp));
    }

    void show() override {
        for (auto it = mapList.begin(); it != mapList.end(); it++) {
            it->second->showAll(it->second);
        }
    }

    vector <Notebook*> search(long long fDate) override {
        vector <Notebook*> temp;
        value = fDate - 3;
        auto range = mapList.equal_range(value);
        for (auto it = range.first; it != range.second; it++) {
            temp.push_back(it->second);
        }
        return temp;
    }
};

class vectorCon :public Cont {
private:
    vector <Notebook*> vecList;
public:
    void enter(long long id, string s1, string s2, string s3, string num, long ddd, long mmm, long yyy) override {
        vecList.push_back(new Notebook(id, s1, s2, s3, num, ddd, mmm, yyy));
    }

    void show() override {
        /*  cout << "Индекс: " << ind << endl;
          cout << "Фамилия: " << vecList[ind]->getSecondName() << endl;
          cout << "Имя: " << vecList[ind]->getName() << endl;
          cout << "Отчество: " << vecList[ind]->getThirdName() << endl;
          cout << "Телефон: " << vecList[ind]->getNumber() << endl;
          cout << "Дата: " << vecList[ind]->getDay() << "." << vecList[ind]->getMonth() << "." << vecList[ind]->getYear() << endl;
          cout << string(40, '=') << endl;*/
        for (int i = 0; i < vecList.size(); i++) {
            vecList[i]->showAll(vecList[i]);
        }
    }

    vector <Notebook*> search(long long fDate) override {
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

class interFace {
public:
    static Cont* choose(char c) {
        switch (c) {
        case 'v': {
            Cont* temp1 = new vectorCon();
            return temp1;
            break;
        }
        case 'm': {
            Cont* temp2 = new mapCon();
            return temp2;
            break;
        }
        default:
            cout << "Error!" << endl;
        }

    };
};

int main() {
    setlocale(LC_ALL, "RUS");
    long tt;
    long local_index = 0;
    multimap <int, Notebook> mapN;
    vector<Notebook*> vec;
    vector<Notebook*> vecP;

    bool Try = true;
    bool fl = true;
    char temp = 0;
    cout << "Введите 'v' - для создания вектора или 'm' - для создания map" << endl;
    do {
        try {
            Try = true;
            cin >> temp;

            if (temp != 'v' && temp != 'm') throw (temp);
        }
        catch (char) {
            cout << "Ввден неверный символ!" << endl;
            Try = false;
            cout << "Введите символ заново" << endl;
        }
    } while (!Try);

    ifstream fin("test.txt");
    int index;
    Cont* container = interFace::choose(temp);
    fin >> index;
    for (int i = 0; i < index; i++) {
        string name, secname, thirdname, number;
        long long ind, dd, mm, yy;
        fin >> ind >> name >> secname >> thirdname >> number >> dd >> mm >> yy;
        container->enter(ind, name, secname, thirdname, number, dd, mm, yy);
        tt = ind;
    }

    /*long long tm1, tm2, tm3;
    cin >> tm1 >> tm2 >> tm3;
    long long sDate = tm1 + (30 * tm2) + (30 * 12 * tm3);
    vector <Notebook*> ans = container->search(sDate);
    for (int i = 0; i < ans.size(); i++) ans[i]->showAll(ans[i]);*/
    fl = true;
    while (fl) {
        string name,secondname,thirdname;
        string number;
        long long dd,mm,yy;
        long long dd1,mm1,yy1,date_find;
        cout << string(40, '=') << endl;
        cout << "Выберите опцию из списка: " << endl;
        cout << "0) Выход" << endl;
        cout << "1) Добавить контакт" << endl;
        cout << "2) Найти контакт по дате" << endl;
        cout << "3) Показать все данные" << endl;
        cout << "Выбор: " << endl;
        long chek; cin >> chek;
        switch (chek){
          case 0: {
                fl = false;
                break;
          }
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
                  if (number[0] == '+') { plus = true; }
                  if (cnt && plus) {
                      ch = false;
                  }
                  else {
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
              tt++;
              container->enter(tt, name, secondname, thirdname, number, dd, mm, yy);

              //vec.push_back(new Notebook(local_index, name, secondname, thirdname, number, dd, mm, yy));
              //local_index++;


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

              cout << string(40, '=') << endl;
              vecP = container->search(date_find);

              if (vecP.size() == 0) {
                  cout << "Не найдено!" << endl;
              }
              else {
                  for (int i = 0; i < vecP.size(); i++) vecP[i]->showAll(vecP[i]);
              }


             /* auto it = vec.begin();

              while (it != vec.end()) {
                  it = find_if(it, vec.end(), foName());
                  if (it != vec.end()) {
                      vecP.push_back(*it);
                      it++;
                  }
                  else {
                      break;
                  }
              }*/

              //auto it2 = vecP.begin();

              //while (it2 != vecP.end()) {
              //    //cout << *it2.get << endl;

              //    Notebook::showAll(*it2);

              //    it2++;
              //}





              break;
          }
          case 3: {
              cout << string(40, '=') << endl;
              //Notebook::showAll(vec[i]);
              container->show();

              break;
          }
          default: {
              cout << "Неизвестная команда" << endl;
              break;
          }
          }
    }

    //while(fl){

    //  string name,secondname,thirdname;
    //  string number;
    //  long long dd,mm,yy;
    //  long long dd1,mm1,yy1,date_find;

    //  cout << string(40,'=') << endl;
    //  cout << "Выберите опцию из списка: " << endl;
    //  cout << "0) Выход" << endl;
    //  cout << "1) Добавить контакт" << endl;
    //  cout << "2) Найти контакт по дате" << endl;
    //  cout << "3) Показать все данные" << endl;
    //  cout << "Выбор: " << endl;
    //  long chek; cin >> chek;
    //  switch (chek){
    //    case 0:
    //      fl = false;
    //      break;
    //    case 1: {
    //      cout << "Введите Фамилию: ";
    //      cin >> secondname;
    //      cout << "Введите Имя: ";
    //      cin >> name;
    //      cout << "Введите Отчество: ";
    //      cin >> thirdname;
    //      bool ch = true;
    //      do {
    //        cout << "Введите Номер в формате +7xxxxxxxxxx : ";
    //        cin >> number;
    //        bool plus = false, cnt = false;
    //        if (number.length() == 12) {
    //          cnt = true;
    //        }
    //        for (int i = 0; i < number.length(); ++i) {
    //          if (number[i] == '+') { plus = true; }
    //        }
    //        if (cnt && plus) {
    //          ch = false;
    //        } else {
    //          cout << "Неверный формат номера!" << endl;
    //        }
    //      } while (ch);
    //      cout << "Введите дату!" << endl;
    //      cout << "Введите День: ";
    //      cin >> dd;
    //      cout << "Введите Месяц: ";
    //      cin >> mm;
    //      cout << "Введите Год: ";
    //      cin >> yy;

    //      vec.push_back(new Notebook(local_index, name, secondname, thirdname, number, dd, mm, yy));
    //      local_index++;


    //      break;
    //    }
    //    case 2: {
    //      vecP.clear();

    //      cout << "Введите дату!" << endl;
    //      cout << "Введите День: ";
    //      cin >> dd;
    //      cout << "Введите Месяц: ";
    //      cin >> mm;
    //      cout << "Введите Год: ";
    //      cin >> yy;

    //      date_find = dd + (mm * 30) + ((yy * 12) * 30);

    //      value = date_find;

    //      auto it = vec.begin();

    //      while(it != vec.end()){
    //        it = find_if(it,vec.end(),foName());
    //        if(it != vec.end()){
    //          vecP.push_back(*it);
    //          it++;
    //        }
    //        else{
    //          break;
    //        }
    //      }

    //      auto it2 = vecP.begin();

    //      while(it2 != vecP.end()){
    //        //cout << *it2.get << endl;

    //        Notebook::showAll(*it2);

    //        it2++;
    //      }



    //      break;
    //    }
    //    case 3:{
    //      cout << string(40,'=') << endl;
    //      for (long i = 0; i < vec.size(); ++i) {
    //        Notebook::showAll(vec[i]);
    //      }
    //      break;
    //    }
    //    default: {
    //      cout << "Неизвестная команда" << endl;
    //      break;
    //    }
    //  }

    //}

    /*Notebook p[] = {Notebook("Alex","Alexandrit","Alexandrovich","+79185777777",8,10,2022),
                    Notebook("Alexxx","Alexandrit","Alexandrovich","+79185777778",8,10,2022),
                    Notebook("AlexXX","Alexandrit","Alexandrovich","+79185777779",8,10,2022)};*/


    return 0;
}
