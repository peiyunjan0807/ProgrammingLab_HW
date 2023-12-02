#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_MINUTE = 10;

class  Timer {
    private:
        int  min, sec;

    public:
    Timer() : min(0), sec(0) {}
    Timer(int s) : min(s / 60), sec(s % 60) {
        while (min >= MAX_MINUTE) min -= MAX_MINUTE;
    }

    Timer(int m,  int s) : min(m), sec(s) {
        while (min >= MAX_MINUTE) min -= MAX_MINUTE;
    }

    Timer  operator++ (){
        sec++;
        if(sec>=60){
            min = min + (sec / 60);
            sec = sec % 60;
        }
        return *this;
    }
    Timer  operator-- (int){
        Timer foo;
        foo = *this;
        if(sec==0){
            if(min>0){
                sec=60;
                min--;
            }
        }
        sec--;
        return foo;
    };
    friend  Timer  operator+ (const Timer& a, const Timer& b);
    friend  ostream &operator<< (ostream& out, const Timer& foo);

};


Timer  operator+ (const Timer& a, const Timer& b){
    Timer foo;
    foo.min = a.min + b.min;
    foo.sec = a.sec + b.sec;
    if(foo.sec>=60){
        foo.min = foo.min + (foo.sec / 60);
        foo.sec = foo.sec % 60;
    }
    return foo;
}

ostream &operator<< (ostream& out, const Timer& foo){
    out<<setw(2)<<setfill('0')<<foo.min<<" : "<<setw(2)<<setfill('0')<<foo.sec;
    return out;
}


int main() {

    int input_1, input_2;
    while (cin >> input_1 >> input_2){
        Timer  foo;
        foo = foo + input_1;
        cout << foo << endl;
        foo = input_2 + foo;
        cout << foo << endl;
        cout << ++foo << endl;
        foo = input_2;
        for (int i = input_2; i >= 0; --i){
            cout << foo-- << endl;
        }
    }
    return 0;
    
}

