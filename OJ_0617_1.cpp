#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//請設計一樣板函式，完成找出最小排序數的功能。

template<class T>
void smallestNumber(T c){
    //typename T::iterator i=c.begin();
    sort(c.begin(), c.end());
    std::swap(*std::find_if_not(c.begin(), c.end(), [&](int k){return k==0 || k=='0';}), c[0]);
    for(auto ele : c){
        cout<<ele;
    }
    cout<<endl;
}

int main()
{
    string str;
    std::cin >> str;
    smallestNumber(str);
    std::vector<int> nums;
    std::transform(str.begin(), str.end(), std::back_inserter(nums),
        [](char c){ return c-'0'; });
    smallestNumber(nums);
}
