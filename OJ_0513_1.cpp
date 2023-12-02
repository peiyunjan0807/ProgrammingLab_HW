#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    string str1;
    string strarr[100];
    int strarr_count[100]={0};
    int num;
    while(cin>>str1){
        cin>>num;
        unsigned long k = str1.size()-num;
        int i=0, test2=0;
        for(i=0; i<=k; i++){
            test2=0;
            for(int j=0; j<i; j++){
                string test = str1.substr(i,num);
                if(test == strarr[j]){
                    strarr_count[j] += 1;
                    test2=1;
                }
            }
            if(test2 == 1){
                continue;
            }
            else{
                strarr[i] = str1.substr(i,num);
                strarr_count[i] += 1;
            }

        }
        for(int j=0; j<i; j++){
            if(strarr[j] != ""){
                cout<<"> "<<strarr[j]<<" : "<<strarr_count[j]<<endl;
            }
            
        }
    }
}
