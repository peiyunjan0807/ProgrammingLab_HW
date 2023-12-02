#include <iostream>
#include <cmath>
using namespace std ;

template <class T> //可自由設計樣板sum, abs_sum,product, compute
T sum(T foo[], T S, T v){
    for(int i=0; i<S; i++) v += foo[i];
    return v;
}

template <class T>
T abs_sum(T foo[], T S, T v){
    for(int i=0; i<S; i++) v += abs(foo[i]);
    return v;
}

template <class T>
T product(T foo[], T S, T v){
    for(int i=0; i<S; i++) v *= foo[i];
    return v;
}

template <class F, class T>
T compute(F fn, T foo[], T S, T v){
    return fn(foo, S, v);
}

int main() { 
    int foo[10];
    int S;
    cin >> S;
    for(int i=0; i<S; i++) cin >>foo[i];
    int v;
    v = 0;
    cout << compute(sum<int>, foo, S, v) << endl;
    v = 0;
    cout << compute(abs_sum<int>, foo, S, v) << endl;
    v = 1;
    cout << compute(product<int>, foo, S, v) << endl;
    return 0;
}
