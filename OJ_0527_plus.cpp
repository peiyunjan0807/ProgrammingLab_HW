#include <iostream>
#include <string>
#include <algorithm>

using namespace std ;

struct DNA{
    string str1;
    int num=0;
}DNA_arr[100];

int main() {
    int n,m;

    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>DNA_arr[i].str1;
    }
    
    for(int i=0; i<m; i++){
        for(int k=0; k<n; k++){
            for(int k1=k; k1<n; k1++){
                if((DNA_arr[i].str1[k]-'A') > (DNA_arr[i].str1[k1]-'A')){
                    DNA_arr[i].num++;
                }
            }
        }
    }
    
    for(int i=0; i<m; i++){
        for(int k=0; k<m-1; k++){
            if(DNA_arr[k].num>DNA_arr[k+1].num){
                swap(DNA_arr[k], DNA_arr[k+1]);
            }
        }
    }
    for(int i=0; i<m; i++){
        cout<<DNA_arr[i].str1<<endl;
    }
}
