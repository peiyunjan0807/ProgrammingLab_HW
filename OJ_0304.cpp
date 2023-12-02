#include <iostream>
#include <functional>
using namespace std;
template <class Fn, class Iter, class T>
T compute( Iter start, Iter end, T val, Fn fn) {
    for (; start != end; ++start ) { val= fn(val, *start);}
    return val;
    
}
int main() {
    int a[5] = { 24, 2, 3, 4, 5};
        cout << compute( a, a+5, 0, plus<int>() ) << " ";
        cout << compute( a, a+5, 2*a[0], minus<int>() ) << " , ";
        cout << compute( a, a+5, 1, multiplies <int>() ) << " ";
        cout << compute( a, a+5, a[0]*a[0], divides<int>()) << endl;
        return 0;
        
    }
