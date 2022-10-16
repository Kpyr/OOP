///Вариант 10
/*10.Классы рюкзак и учебники.
 * Класс обработчик реализует формирование расписания предметов и заполнение рюкзака согласно этому расписанию. */




//#include <vld.h>
#include <stack>
#include <memory>
#include <sstream>
#include <Windows.h>
#include <iostream>
#include <cmath>
#include<conio.h>
#include <clocale>

using namespace std;


//******* Класс часть ***************************
class Book{
 private:
  string name;
 public:
  Book(){};// Конструктор по умолчанию
  Book(string str);
  ~Book();// Деструктор
  void Print();
  void setName(string str){name = str;};
  string GetName() {return name;};
};
Book::Book(string str){// Конструктор инициализатор
  name = str;
}
void Book::Print(){// Метод вывода
  cout << name;
}
Book::~Book(){ // Деструктор
}



class Backpack{
 private:
  Book **Array;
  int bcount;
 public:
  Backpack(); // Конструктор по умолчанию
  void printAll();
  virtual ~Backpack(); // Деструктор класса
  void AddBook(Book* TovarBuf);
  void DelBook(int id);
  void SetN(int n){ bcount=n; };
  int GetN(){ return bcount; }
  Book* GetMas(int i) {	return Array[i]; }
  void SetMas(int i,Book *f){ Array[i]=f; }
};
Backpack::Backpack(){
  bcount=0;
  Array=NULL;
};

void Backpack::AddBook(Book* TovarBuf){
  int j;
  Book **TovarArray;
  TovarArray = new Book*[this->GetN()+1];
  for(j=0; j<this->GetN(); j++){
    TovarArray[j] = this->GetMas(j);
  }
  TovarArray[j] =  TovarBuf;

  delete[] Array;
  Array = new Book*[this->GetN()+1];
  this->SetN(this->GetN()+1);
  for(j=0; j<this->GetN(); j++){
    Array[j] = TovarArray[j];
  }
};

void Backpack::DelBook(int id){
  int i, j, k=0;
  Book *TovarBuf;
  TovarBuf = this->GetMas(id-1);
  Book **TovarArray;
  TovarArray = new Book*[this->GetN()-1];
  for(j=0;j<this->GetN();j++){
    if (j!=(id-1)){
      TovarArray[k] = this->GetMas(j);
      k++;
    }
  }
  for(j=0;j<this->GetN()-1;j++){
    Array[j] = TovarArray[j];
  }
  this->SetN(this->GetN()-1);
  delete TovarBuf;
};
void Backpack::printAll(){
  int i;
  for(i=0; i<bcount; i++){
    Array[i]->Print();
    cout << endl;
  }
}
Backpack::~Backpack(){
  for(int i=0; i<bcount; i++)
    delete Array[i];
  delete[] Array;
  printf(" Деструктор класса Торговый Зал\n");
}


class TProcessor{
 private:
  string *ms;
  Backpack *BckP;
  long cnt=0;
 public:
  TProcessor(Backpack *A);
  void initBackpack(long day);
  void SetTimetable(){
    cout << "Введите количсетво уроков: ";
    long tmp;
    cin >> tmp;
    cnt = tmp;
    ms = new string [tmp];
    for (int i = 0; i < tmp; ++i) {
      cout << "Введите название предмета: ";
      cin >> ms[i];
    }
  };
  long Cnt(long day) {
    long k = 0;
    return k;
  }
  ~TProcessor();
};

void TProcessor::initBackpack(long day) {
  if(day >= 1 && day <= 7){
    for (int i = 0; i < cnt; ++i) {
      BckP->AddBook(new Book(ms[i]));
    }
  }
  else{
    cout << "Несуществующий день недели!" << endl;
  }
}


TProcessor::TProcessor(Backpack *A) {
  BckP = A;
};



TProcessor::~TProcessor(){
}

int main(){
  system("chcp 65001");
  /*setlocale(LC_ALL, "RUS");*/


  Backpack *bk = new Backpack();
  TProcessor *tp = new TProcessor(bk);
  tp->SetTimetable();

  tp->initBackpack(1);
  bk->printAll();


  return 0;
}

