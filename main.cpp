#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
class Body {

 public:
  double V = 0, S = 0, num_PI = 3.14;
  virtual double V_find(double temp1,double temp2){
      return 0;
  };
  virtual double S_find(double temp1, double temp2, double temp3){
      return 0;
  };
};

class Parallelepiped : public Body {
 public:
  double V_find(double length, double width, double height) {
    V = length * width * height;
    return V;
  }
  double S_find(double length, double width, double height) {
    S = 2 * (length * width + length * height + width * height);
    return S;
  }
};

class Cone : public Body {
 public:
  double V_find(double H, double R) {
    V =(num_PI*R*R*H)/3;
    return V;
  }
  double S_find(double L, double R) {
    S = (num_PI * R * L) + (num_PI * R * R);
    return S;
  }

};

class Ball : public Body {
 public:
  double V_find(double R) {
    V = (num_PI * R * R * R*4) / 3;
    return V;
  }
  double S_find(double R) {
    S = 4*num_PI*R*R;
    return S;
  }
};
//class Employee {
//public:
//	virtual void virt() {
//		cout << "EMP" << endl;
//	}
//};
//class Manager : public Employee {
//public:
//	void virt() {
//		cout << "MAN" << endl;
//	}
//};
//class Rob : public Employee {
//public:
//	void virt() {
//		cout << "Rob" << endl;
//		cout << "Privet";
//	}
//};
int main() {
  setlocale(LC_ALL, "eng");
	Body* list[3];
	Cone* conus = new Cone;
	Ball* shar = new Ball;
	Parallelepiped* pram = new Parallelepiped;
	list[0] = pram; list[1] = conus; list[2] = shar;
	double temp1, temp2, temp3;
	cin >> temp1 >> temp2 >> temp3;
    double ans = list[1]->V_find(temp1,temp2);
    cout << ans;
 
  

  /*Cone cn1;
  cn1.V_find(1,2);*/
 /* Employee* list[2];
  Rob* ro = new Rob;
  Manager* man = new Manager;
  list[0] = ro; list[1] = man;
  for (int i = 0; i < 2; i++) list[i]->virt();*/
      return 0;
}
