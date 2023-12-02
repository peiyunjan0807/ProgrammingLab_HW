#include <iostream>
#include <string>
#include <algorithm>

using namespace std ;

int main(int argc, const char * argv[]) {
    int N,Q,count=1;
    while(cin>>N>>Q){
        int N1[65], Q1[65], num[1000]={0};
        if(N==0 && Q==0){
            break;
        }
        for(int i=0; i<N; i++){
            cin>>N1[i];
        }
        sort(N1, N1+N);

        for(int i=0; i<Q; i++){
            cin>>Q1[i];
        }
        
        cout<<"CASE# "<<count<<":"<<endl;
        for(int i=0; i<Q; i++){
            for(int k=0; k<N; k++){
                if(Q1[i]==N1[k] && num[i]==0){
                    cout<<Q1[i]<<" found at "<<k+1<<endl;
                    num[i]=1;
                }
                if(k==N-1 && num[i]==0){
                    cout<<Q1[i]<<" not found"<<endl;
                }
            }
        }
        count++;
    }
}
