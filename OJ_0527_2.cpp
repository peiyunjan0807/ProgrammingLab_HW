#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
using namespace std;
long Length = 5;
class Xarray {
public:
    vector<double> X;
    double sumX = 0, aveX = 0;
    double sumx(){
        sumX = accumulate(X.begin(), X.end(), sumX);
        return sumX;
    }
    double avex(){
        aveX = sumX / double(Length);
        return aveX;
    }
    
};
class Yarray {
public:
    vector<double>Y;
    double sumY = 0, aveY = 0;
    double sumy(){
        sumY = accumulate(Y.begin(), Y.end(), sumY);
        return sumY;
    }
    double avey(){
        aveY = sumY / double(Length);
        return aveY;
    }
};
class CC : public Xarray, public Yarray{
public:
    double R1=0, R2=0, R3=0, r=0;
    double cc(){
        for(int i=0; i<Length; i++){
            R1 += (X[i]-aveX)*(Y[i]-aveY);
            R2 += pow((X[i]-aveX),2);
            R3 += pow((Y[i]-aveY),2);
        }
        r = (R1 / sqrt(R2*R3));
        r = fabs(r);
        return r;
    }
};
int main() {
    double total[10], r;
    while (cin >> total[0]) {
        CC c1;
        for (int i = 1; i < 10; i++)    cin >> total[i];
        for (int i = 0; i < 5; i++)    c1.X.push_back(total[i]);
        for (int i = 5; i < 10; i++)    c1.Y.push_back(total[i]);
        
        c1.sumx();
        c1.sumy();
        c1.avex();
        c1.avey();
        r = c1.cc();
        
        if(r == 0){
            cout<<"無相關"<<endl;
        }
        else if(r == 1){
            cout<<"完全相關"<<endl;
        }
        else if(r <= 0.4){
            cout<<"低度線性相關"<<endl;
        }
        else if(0.4<r && r<=0.7){
            cout<<"顯著線性相關"<<endl;
        }
        else if(0.7<r && r<1){
            cout<<"高度線性相關"<<endl;
        }
        else{
            cout<<"無"<<endl;
        }
    }
    return 0;
}
