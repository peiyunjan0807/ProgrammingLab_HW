#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include<sstream>

using namespace std ;

int main(int argc, const char * argv[]) {
    int k, str[10000], i_count=0, a;
    string str1, str2, str3;
    while(cin>>k){
        cin>>str1;
        for(int i=0; i<str1.size(); i++){
            str[i_count]=str1[i]-'A'+(k%26+1);
            i_count++;
        }
        stringstream ss, ss1;
        for(int i=0; i<i_count; i++){
            ss<<bitset<5>(str[i]);
        }
        ss>>str2;

        for(int i=0; i<str2.size(); i+=4){
            int temp=8*(str2[i]-'0') + 4*(str2[i+1]-'0') + 2*(str2[i+2]-'0') + (str2[i+3]-'0');
            cout<<hex<<temp;
        }
        
    }
}
