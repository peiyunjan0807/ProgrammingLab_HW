#include <iostream>
#include<iomanip>
using namespace std;

class matrix{
    private:
        double a11, a12, a21, a22;
    public:
        void inverse();
        friend istream& operator>>(istream& in,matrix& A);
        friend ostream& operator<<(ostream&,matrix&);
};
void matrix::inverse(){
    double all = (a11*a22)-(a12*a21);
    double a11_control = a11;
    if(all==0){
        a11=a12=a21=a22=0;
    }
    else{
        a11 = a22/all;
        a12 = -(a12/all);
        a21 = -(a21/all);
        a22 = a11_control/all;
    }
}
istream& operator>>(istream& in,matrix& A){
    in>>A.a11;
    in>>A.a12;
    in>>A.a21;
    in>>A.a22;
    return in;
}
ostream& operator<<(ostream& out,matrix& A){
    double all = (A.a11*A.a22)-(A.a12+A.a21);
    if(all==0){
        out<<"singular matrix"<<endl;
    }
    else{
        out<<setprecision(1)<<fixed<<A.a11<<" "<<setprecision(1)<<fixed<<A.a12<<endl;
        out<<setprecision(1)<<fixed<<A.a21<<" "<<setprecision(1)<<fixed<<A.a22<<endl;
    }
    return out;
}
int main(){
    matrix matrix_A;
    while(cin >> matrix_A){
        matrix_A.inverse();
        cout << matrix_A;
    }
}
