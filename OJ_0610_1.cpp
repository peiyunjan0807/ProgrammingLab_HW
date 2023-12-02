#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std ;


struct Time {

int  hr , min ;

Time( int h , int m ) : hr(h) , min(m) {}
Time(){hr=0,min=0;}

Time( const string& time ) {
    char  ch ;
    istringstream  foo(time) ;//使用sstream，建立一個流 foo
    foo >> hr >> ch >> min ;
}

};
struct compare{
    bool operator()(const Time& a, const Time& b) const{
        if(a.hr<b.hr){
            return true;
        }
        else if(a.hr>b.hr){
            return false;
        }
        else
            return a.min<b.min;
    }
};

ostream& operator<<(ostream& out, const Time& foo){
    return out<<setw(2)<<setfill('0')<<foo.hr<<":"<<setw(2)<<setfill('0')<<foo.min<<setfill(' ');
}

int main(){
    string str1;
    Time t[1000];
    int i, S;
    for(int temp=0;(cin>>str1);temp++,S=temp)
        t[temp]=Time(str1);
    
    sort(t, t+S, compare());
    for(int k=0; k<S; ++k){
        cout<<t[k]<<" ";
    }
    cout<<endl;
}
