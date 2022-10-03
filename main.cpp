#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
class Body {

 public:
  double V = 0, S = 0, num_PI = 3.14;
  virtual double V_find(double *arr){
      return 0;
  };
  virtual double S_find(double *arr){
      return 0;
  };
};

class Parallelepiped : public Body {
 public:
  double V_find(double *arr) {
    V = arr[0]*arr[1]*arr[2];
    return V;
  }
  double S_find(double *arr) {
    S = 2 * (arr[0]*arr[1] + arr[0]*arr[2] + arr[1]*arr[2]);
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
    double arr[3]{};
    for (int i = 0; i < 3; i++) cin >> arr[i];
    double ans = list[0]->V_find(arr);
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
