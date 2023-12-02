#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;
const double TOL = 1e-10;
class ERR{//異常處理類別
  public:
    string msg(){
        return "retry";
    }
};
class Point{//資料包含輸入三個點的x,y座標
  private:
    double x, y;
  public:
    Point(double a = 0., double b = 0.):x(a), y(b){}
    //外部可藉由getx(),gety()獲得x,y的資訊
    double getx() {return x;}
    double gety() {return y;}
    friend istream& operator>> (istream& in, Point& pt);
};
  
istream& operator>> (istream& in , Point& pt){
    return in >> pt.x >> pt.y;
}

class Triangle{
  private:
    Point pt1, pt2, pt3;//三角形三個點座標
  public:
    Triangle(Point& p, Point& q, Point& r) noexcept(false)//throw(ERR)
        :pt1(p), pt2(q), pt3(r){
        if(area() < TOL) throw ERR();//若面積等於0則擲出ERR物件
    }
    double area(){//待完成部分1(面積)
        double a = pt2.getx()-pt1.getx();
        double b = pt2.gety()-pt1.gety();
        double c = pt3.getx()-pt1.getx();
        double d = pt3.gety()-pt1.gety();
        double area = 0.5*(abs((a*d)-(b*c)));
        return area;
    }
    double perimeter(){//待完成部分2(周長)
        double ax = pow(pt2.getx()-pt1.getx(), 2);
        double ay = pow(pt2.gety()-pt1.gety(), 2);
        double a = sqrt(ax+ay);
        double bx = pow(pt3.getx()-pt1.getx(), 2);
        double by = pow(pt3.gety()-pt1.gety(), 2);
        double b = sqrt(bx+by);
        double cx = pow(pt3.getx()-pt2.getx(), 2);
        double cy = pow(pt3.gety()-pt2.gety(), 2);
        double c = sqrt(cx+cy);
        return a+b+c;
    }
    friend ostream& operator<< (ostream& out, Triangle& foo){//待完成部分3
        out<<fixed <<setprecision(2)<<"area = "<<foo.area()<<endl;
        out<<"perimeter = "<<foo.perimeter()<<endl;
        return out;
    }
};
  
int main(){
    Point a, b, c;
    while(1){
        try{//測試區
            cin >> a >> b >> c;
            Triangle foo(a,b,c);
            cout << foo << endl;
            break;
        }
        catch (ERR& err){//異常處理區
            cout << err.msg() << endl;
        }
    }
    return 0;
}
