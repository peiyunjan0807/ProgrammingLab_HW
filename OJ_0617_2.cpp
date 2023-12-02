#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
using namespace std;

template <typename T> //可自由設計樣板 Abs, inner_product
struct Abs{
    T operator()(T &a){
        return a>static_cast<T>(0)?a:-a;
    }
};
template <typename S, typename T, typename M, typename F>
M inner_product(S a, S b, T c, M s, F fn){
    T j=c;
    for(S i=a; i!=b; ++i, ++j) s+= fn(*i)*fn(*j);
    return s;
}

int main() {

    vector<int> a;
    list<int> b;
    int input, sum = 0;

    cin >> input; //將元素輸入至容器vector,list中
    for(int i=0;i<input;i++){
        int element;
        cin >> element;
        a.push_back(element);
    }
    for(int i=0;i<input;i++){
        int element;
        cin>>element;
        b.push_back(element);
    }
    //輸出兩個容器元素的絕對值乘積和
    cout << "The absolute inner product of a and b = "
         << inner_product( a.begin() , a.end() ,
                           b.begin() , sum , Abs<int>() ) << endl;
    //Abs<int>()可看成Abs結構/類別中的運算子()覆載
    return 0 ;
}

