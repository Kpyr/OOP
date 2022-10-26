//#include <vld.h>
#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

class Point {
public:
    double x = 0, y = 0;
};

class Shape {
protected:
    Point* arc = 0;
    string ID = "";
public:
    virtual double square() { return 0; };
    virtual double mss_x() { return 0; };
    virtual double mss_y() { return 0; };
    virtual void move(double x, double y) {};
    virtual void rotate(double deg) {};
    virtual void show() {};
    virtual double max_len() { return 0; };
    virtual ~Shape() = default;
};

class Triangle :public Shape {
public:
    Triangle(double ms[8]) {
        arc = new Point[3];
        arc[0].x = ms[0]; arc[0].y = ms[1];
        arc[1].x = ms[2]; arc[1].y = ms[3];
        arc[2].x = ms[4]; arc[2].y = ms[5];
        ID = "Triangle";
    }

    void move(double x, double y) override;
    void rotate(double deg) override;
    double square() override;
    double mss_x() override;
    double mss_y() override;
    void show() override;
    double max_len() override;
    ~Triangle() { delete[] arc; }
};

class Trapeze :public Shape {
public:
    Trapeze(double ms[8]) {
        arc = new Point[4];
        arc[0].x = ms[0]; arc[0].y = ms[1];
        arc[1].x = ms[2]; arc[1].y = ms[3];
        arc[2].x = ms[4]; arc[2].y = ms[5];
        arc[3].x = ms[6]; arc[3].y = ms[7];
        ID = "Trapeze";
    }

    void move(double x, double y) override;
    void rotate(double deg) override;
    double square() override;
    double mss_x() override;
    double mss_y() override;
    void show() override;
    double max_len() override;

    ~Trapeze() { delete[] arc; }
};

class Factory {
public:
    static Shape* createShape(short int ch, double ms[8]) {
        switch (ch) {
        case 1:
            return new Triangle(ms);
            break;
        case 2:
            return new Trapeze(ms);
            break;
        default: return nullptr;
        }
    }
};

class Operation {
public:
    static long Compare(Shape* first, Shape* second) {
        double first_S, second_S;
        first_S = first->square();
        second_S = second->square();
        if (first_S > second_S) {
            return 1;
        }
        else if (first_S == second_S) {
            return 2;
        }
        else {
            return 3;
        }
    }

    static long isIntersect(Shape* first, Shape* second) {
        double first_havyX, first_havyY, second_havyX, second_havyY;
        double first_R, second_R;
        double tmp1, tmp2, tmp3, tmp4;

        first_havyX = first->mss_x(); first_havyY = first->mss_y();
        second_havyX = second->mss_x(); second_havyY = second->mss_y();

        first_R = first->max_len();
        second_R = second->max_len();

        double len = sqrt(pow(first_havyX - second_havyX, 2) + pow(first_havyY - second_havyY, 2));

        if (len > (first_R + second_R)) {
            return 1;
        }
        else if (len == (first_R + second_R)) {
            return 2;
        }
        else {
            return 3;
        }
    }
    static long isInclude(Shape* first, Shape* second) {
        double first_havyX, first_havyY, second_havyX, second_havyY;
        double first_R, second_R;
        double tmp1, tmp2, tmp3, tmp4;

        first_havyX = first->mss_x();
        first_havyY = first->mss_y();
        second_havyX = second->mss_x();
        second_havyY = second->mss_y();

        first_R = first->max_len();
        second_R = second->max_len();

        double len = sqrt(pow(first_havyX - second_havyX, 2) + pow(first_havyY - second_havyY, 2));

        if (len < abs(first_R - second_R)) {
            if (first_R > second_R) {
                return 2;
            }
            else {
                return 3;
            }
        }
        else {
            return 1;
        }
    }
};

const double PI = 3.141592653589793;

double Triangle::max_len() {
    double tmp1, tmp2, tmp3, first_R;
    double havyX, havyY;
    havyX = this->mss_x();
    havyY = this->mss_y();

    tmp1 = sqrt(pow(havyX - arc[0].x, 2) + pow(havyY - arc[0].y, 2));
    tmp2 = sqrt(pow(havyX - arc[1].x, 2) + pow(havyY - arc[1].y, 2));
    tmp3 = sqrt(pow(havyX - arc[2].x, 2) + pow(havyY - arc[2].y, 2));

    first_R = max(tmp1, max(tmp2, tmp3));
    return first_R;
};

double Triangle::square() {
    float a, b, c, p, S;
    a = sqrt(pow(arc[0].x - arc[1].x, 2) + pow(arc[0].y - arc[1].y, 2));
    b = sqrt(pow(arc[1].x - arc[2].x, 2) + pow(arc[1].y - arc[2].y, 2));
    c = sqrt(pow(arc[2].x - arc[0].x, 2) + pow(arc[2].y - arc[0].y, 2));
    p = (a + b + c) / 2;

    S = sqrt(p * (p - a) * (p - b) * (p - c));
    return S;
};

void Triangle::move(double x, double y) {
    arc[0].x += x; arc[0].y += y;
    arc[1].x += x; arc[1].y += y;
    arc[2].x += x; arc[2].y += y;
};

void Triangle::rotate(double deg) {
    //������� �������� � ���������� ������������
    double degr = deg * (PI / 180);
    if (degr > 0) {
        double  tmpX = arc[0].x, tmpY = arc[0].y;
        arc[0].x = tmpX * cos(degr) - tmpY * sin(degr); arc[0].y = tmpX * sin(degr) + tmpY * cos(degr);
        tmpX = arc[1].x; tmpY = arc[1].y;
        arc[1].x = tmpX * cos(degr) - tmpY * sin(degr); arc[1].y = tmpX * sin(degr) + tmpY * cos(degr);
        tmpX = arc[2].x; tmpY = arc[2].y;
        arc[2].x = tmpX * cos(degr) - tmpY * sin(degr); arc[2].y = tmpX * sin(degr) + tmpY * cos(degr);
    }
    else {
        double  tmpX = arc[0].x, tmpY = arc[0].y;
        arc[0].x = tmpX * cos(degr) + tmpY * sin(degr); arc[0].y = -tmpX * sin(degr) + tmpY * cos(degr);
        tmpX = arc[1].x; tmpY = arc[1].y;
        arc[1].x = tmpX * cos(degr) + tmpY * sin(degr); arc[1].y = -tmpX * sin(degr) + tmpY * cos(degr);
        tmpX = arc[2].x; tmpY = arc[2].y;
        arc[2].x = tmpX * cos(degr) + tmpY * sin(degr); arc[2].y = -tmpX * sin(degr) + tmpY * cos(degr);
    }
};

double Triangle::mss_x() {
    double havyX;
    havyX = (arc[0].x + arc[1].x + arc[2].x) / 3;
    return havyX;
};

double Triangle::mss_y() {
    double havyY;
    havyY = (arc[0].y + arc[1].y + arc[2].y) / 3;
    return havyY;
};

void Triangle::show() {
    cout << "x1 =  " << arc[0].x << "  y1 = " << arc[0].y << endl;
    cout << "x2 =  " << arc[1].x << "  y2 = " << arc[1].y << endl;
    cout << "x3 =  " << arc[2].x << "  y3 = " << arc[2].y << endl;
};



double Trapeze::max_len() {
    double havyX, havyY, tmp1, tmp2, tmp3, tmp4, first_R;
    havyX = this->mss_x();
    havyY = this->mss_y();

    tmp1 = sqrt(pow(havyX - arc[0].x, 2) + pow(havyY - arc[0].y, 2));
    tmp2 = sqrt(pow(havyX - arc[1].x, 2) + pow(havyY - arc[1].y, 2));
    tmp3 = sqrt(pow(havyX - arc[2].x, 2) + pow(havyY - arc[2].y, 2));
    tmp4 = sqrt(pow(havyX - arc[3].x, 2) + pow(havyY - arc[3].y, 2));

    first_R = max(tmp1, max(tmp2, max(tmp3, tmp4)));
    return first_R;
};


void Trapeze::move(double x, double y) {
    arc[0].x += x; arc[0].y += y;
    arc[1].x += x; arc[1].y += y;
    arc[2].x += x; arc[2].y += y;
    arc[3].x += x; arc[3].y += y;
};

void Trapeze::rotate(double deg) {
    //������� �������� � ���������� ������������
    deg = deg * (PI / 180);
    if (deg > 0) {
        double  tmpX = arc[0].x, tmpY = arc[0].y;
        arc[0].x = tmpX * cos(deg) - tmpY * sin(deg); arc[0].y = tmpX * sin(deg) + tmpY * cos(deg);
        tmpX = arc[1].x; tmpY = arc[1].y;
        arc[1].x = tmpX * cos(deg) - tmpY * sin(deg); arc[1].y = tmpX * sin(deg) + tmpY * cos(deg);
        tmpX = arc[2].x; tmpY = arc[2].y;
        arc[2].x = tmpX * cos(deg) - tmpY * sin(deg); arc[2].y = tmpX * sin(deg) + tmpY * cos(deg);
        tmpX = arc[3].x; tmpY = arc[3].y;
        arc[3].x = tmpX * cos(deg) - tmpY * sin(deg); arc[3].y = tmpX * sin(deg) + tmpY * cos(deg);
    }
    else {
        double  tmpX = arc[0].x, tmpY = arc[0].y;
        arc[0].x = tmpX * cos(deg) + tmpY * sin(deg); arc[0].y = -tmpX * sin(deg) + tmpY * cos(deg);
        tmpX = arc[1].x; tmpY = arc[1].y;
        arc[1].x = tmpX * cos(deg) + tmpY * sin(deg); arc[1].y = -tmpX * sin(deg) + tmpY * cos(deg);
        tmpX = arc[2].x; tmpY = arc[2].y;
        arc[2].x = tmpX * cos(deg) + tmpY * sin(deg); arc[2].y = -tmpX * sin(deg) + tmpY * cos(deg);
        tmpX = arc[3].x; tmpY = arc[3].y;
        arc[3].x = tmpX * cos(deg) + tmpY * sin(deg); arc[3].y = -tmpX * sin(deg) + tmpY * cos(deg);
    }
};

double Trapeze::square() {
    float a, b, c, d, S;
    a = sqrt(pow(arc[0].x - arc[1].x, 2) + pow(arc[0].y - arc[1].y, 2));
    b = sqrt(pow(arc[1].x - arc[2].x, 2) + pow(arc[1].y - arc[2].y, 2));
    c = sqrt(pow(arc[2].x - arc[3].x, 2) + pow(arc[2].y - arc[3].y, 2));
    d = sqrt(pow(arc[3].x - arc[0].x, 2) + pow(arc[3].y - arc[0].y, 2));

    S = (((a + b) / 2) * sqrt(pow(c, 2) - pow((pow(b - a, 2) + pow(c, 2) - pow(d, 2)) / (2 * (b - a)), 2)));
    return S;
};

double Trapeze::mss_x() {
    double havyX;
    havyX = (arc[0].x + arc[1].x + arc[2].x + arc[3].x) / 4;
    return havyX;
};

void Trapeze::show() {
    cout << "x1 =  " << arc[0].x << "  y1 = " << arc[0].y << endl;
    cout << "x2 =  " << arc[1].x << "  y2 = " << arc[1].y << endl;
    cout << "x3 =  " << arc[2].x << "  y3 = " << arc[2].y << endl;
    cout << "x4 =  " << arc[3].x << "  y4 = " << arc[3].y << endl;
};


double Trapeze::mss_y() {
    double havyY;
    havyY = (arc[0].y + arc[1].y + arc[2].y + arc[3].y) / 4;
    return havyY;
};



int main() {
    system("chcp 65001");
    setlocale(LC_ALL, "RUS");
    bool chek = true;
    double arr1[8];
    Shape* s1 = nullptr;
    Shape* s2 = nullptr;
    short int ch;

    while (chek) {
        do {
            cout << "�������� ������ ������" << endl;
            cout << "=================================================================" << endl;
            cout << "�������� ������, ������� ���������� �������:" << endl;
            cout << "1) �����������" << endl;
            cout << "2) ��������" << endl;
            cin >> ch;
            cout << "=================================================================" << endl;
        } while (ch != 1 && ch != 2);

        int cnt = 0;

        if (ch == 1) {
            for (int i = 0; i < 3; ++i) {
                cout << "������� ���������� " << i+1 << "-�� �����: " << endl;
                cout << "X = "; cin >> arr1[cnt];
                cout << "Y = "; cin >> arr1[cnt + 1];
                cnt += 2;
            }
        }
        else if (ch == 2) {
            for (int i = 0; i < 4; ++i) {
                cout << "������� ���������� " << i+1 << "-�� �����: " << endl;
                cout << "X = "; cin >> arr1[cnt];
                cout << "Y = "; cin >> arr1[cnt + 1];
                cnt += 2;
            }
        }

        s1 = Factory::createShape(ch, arr1);

        bool fl = true;
        string str;
        short int tt;
        while (fl) {
            cout << "=================================================================" << endl;
            cout << "��� ������ ������ �������� ��������� �����: " << endl;
            cout << "1) ����������� ������� �����" << endl;
            cout << "2) ������� �����" << endl;
            cout << "3) ���������� ������� �����" << endl;
            cout << "4) ����� ��������� ����� �����" << endl;
            cout << "5) ������� � �������� ������ ������" << endl;
            cout << "������� ����� �������: ";
            cin >> tt;
            cout << "=================================================================" << endl;
            switch (tt) {
            case 1:
            {
                double tm1, tm2;
                cout << "������� �������� ��� ��������: " << endl;
                cout << "�� X= ";
                cin >> tm1;
                cout << "�� Y= ";
                cin >> tm2;
                cout << "=================================================================" << endl;
                cout << "����������� ����������: " << endl;
                s1->show();
                cout << "=================================================================" << endl;
                s1->move(tm1, tm2);
                string st;
                bool ff = true;
                while (ff) {
                    cout << "���������� ����� ����������? [Y/N]: ";
                    cin >> st;
                    if (st == "Y") {
                        s1->show();
                        ff = false;
                        
                    }
                    else if (st == "N") {
                        ff = false;
                    }
                    cout << "=================================================================" << endl;
                }
                break;
            }
            case 2:
            {
                double tm1, tm2;
                cout << "������� �������� � ��������: ";
                cin >> tm1;
                cout << "=================================================================" << endl;
                cout << "����������� ����������: " << endl;
                s1->show();
                cout << "=================================================================" << endl;
                s1->rotate(tm1);
                string st;
                bool ff = true;
                while (ff) {
                    cout << "=================================================================" << endl;
                    cout << "���������� ����� ����������? [Y/N]: ";
                    cin >> st;
                    if (st == "Y") {
                        s1->show();
                        ff = false;
                    }
                    else if (st == "N") {
                        ff = false;
                    }
                    cout << "=================================================================" << endl;
                }
                break;
            }
            case 3:
            {
                double S = s1->square();
                cout << "������� ������ = " << S << endl;
                break;
            }
            case 4:
            {
                cout << "���������� ����� ������: " << endl;
                s1->show();
                break;
            }
            case 5:
            {
                fl = false;
            }
            break;
            default:
                cout << "������: ����������� �������!" << endl;
                break;
            }
        }

        do {
            cout << "�������� ������ ������" << endl;
            cout << "=================================================================" << endl;
            cout << "�������� ������, ������� ���������� �������:" << endl;
            cout << "1) �����������" << endl;
            cout << "2) ��������" << endl;
            cin >> ch;
            cout << "=================================================================" << endl;
        } while (ch != 1 && ch != 2);

        cnt = 0;

        if (ch == 1) {
            for (int i = 0; i < 3; ++i) {
                cout << "������� ���������� " << i+1 << "-�� �����: " << endl;
                cout << "X = "; cin >> arr1[cnt];
                cout << "Y = "; cin >> arr1[cnt + 1];
                cnt += 2;
            }
        }
        else if (ch == 2) {
            for (int i = 0; i < 4; ++i) {
                cout << "������� ���������� " << i+1 << "-�� �����: " << endl;
                cout << "X = "; cin >> arr1[cnt];
                cout << "Y = "; cin >> arr1[cnt + 1];
                cnt += 2;
            }
        }

        s2 = Factory::createShape(ch, arr1);

        fl = true;

        while (fl) {
            cout << "=================================================================" << endl;
            cout << "��� ������ ������ �������� ��������� �����: " << endl;
            cout << "1) ����������� ������� �����" << endl;
            cout << "2) ������� �����" << endl;
            cout << "3) ���������� ������� �����" << endl;
            cout << "4) ����� ��������� ����� �����" << endl;
            cout << "5) ������� � ��������� ��� ��������" << endl;
            cout << "������� ����� �������: ";
            cin >> tt;
            cout << "=================================================================" << endl;
            switch (tt) {
            case 1:
            {
                double tm1, tm2;
                cout << "������� �������� ��� ��������: " << endl;
                cout << "�� X= ";
                cin >> tm1;
                cout << "�� Y= ";
                cin >> tm2;
                cout << "=================================================================" << endl;
                cout << "����������� ����������: " << endl;
                s2->show();
                cout << "=================================================================" << endl;
                s2->move(tm1, tm2);
                string st;
                bool ff = true;
                while (ff) {
                    cout << "=================================================================" << endl;
                    cout << "���������� ����� ����������? [Y/N]: ";
                    cin >> st;
                    if (st == "Y") {
                        s2->show();
                        ff = false;
                    }
                    else if (st == "N") {
                        ff = false;
                    }
                    cout << "=================================================================" << endl;
                }
                break;
            }
            case 2:
            {
                double tm1, tm2;
                cout << "������� �������� � ��������: ";
                cin >> tm1;
                cout << "=================================================================" << endl;
                cout << "����������� ����������: ";
                s2->show();
                cout << "=================================================================" << endl;
                s2->rotate(tm1);
                string st;
                bool ff = true;
                while (ff) {
                    cout << "=================================================================" << endl;
                    cout << "���������� ����� ����������? [Y/N]: ";
                    cin >> st;
                    if (st == "Y") {
                        s2->show();
                        ff = false;
                    }
                    else if (st == "N") {
                        ff = false;
                    }
                    cout << "=================================================================" << endl;
                }
                break;
            }
            case 3:
            {
                double S = s2->square();
                cout << "������� ������ = " << S << endl;
                break;
            }
            case 4:
            {
                cout << "���������� ����� ������: " << endl;
                s2->show();
                break;
            }
            case 5:
            {
                fl = false;
            }
            break;
            default:
                cout << "������: ����������� �������!" << endl;
                break;
            }
        }


        fl = true;


        while (fl) {
            cout << "=================================================================" << endl;
            cout << "�������� �����:" << endl;
            cout << "1) �������� ������� �� �������" << endl;
            cout << "2) ���������� ���� �����������" << endl;
            cout << "3) ���������� ���� ��������� ������ ������� � ������" << endl;
            cout << "4) �����" << endl;
            short int choice;
            cin >> choice;
            cout << "=================================================================" << endl;

            switch (choice) {
            case 1: {
                long d = Operation::Compare(s1, s2);
                if (d == 1) {
                    cout << "������ ������ " << "������ ��� ������!" << endl;
                }
                else if (d == 2) {
                    cout << "������ �����" << endl;
                }
                else if (d == 3) {
                    cout << "������ ������ " << "������ ��� ������" << endl;
                }
                break;
            }
            case 2: {
                long d = Operation::isIntersect(s1, s2);
                if (d == 1) {
                    cout << "������ �� ������������!" << endl;
                }
                else if (d == 2) {
                    cout << "������ ��������!" << endl;
                }
                else if (d == 3) {
                    cout << "������ ������������!" << endl;
                }
                break;
            }
            case 3: {
                long d = Operation::isInclude(s1, s2);
                if (d == 1) {
                    cout << "��������� ����������" << endl;
                }
                else if (d == 2) {
                    cout << "������ ������ ���������� � ������" << endl;
                }
                else if (d == 3) {
                    cout << "������ ������ ���������� �� ������" << endl;
                }
                break;
            }
            case 4: {
                fl = false;
                break;
            }
            default: {
                cout << "������: ����������� �������!" << endl;
                break;
            }

            }

        }

        string str1;
        bool flg = true;
        do {
            cout << "=================================================================" << endl;
            cout << "������� 'end' ��� �� ��������� ��������� ��� 'nxt', ��� �� ��������� ������." << endl;
            cin >> str1;
            {
                if (str1 == "end") {
                    chek = false;
                    flg = false;
                }
                else if (str1 == "nxt") {
                    flg = false;
                }
                else {
                    cout << "����������� �������, ��������� �������!" << endl;
                }
            }
            cout << "=================================================================" << endl;
        } while (flg);


    }


    delete s1;
    delete s2;
    return 0;
}