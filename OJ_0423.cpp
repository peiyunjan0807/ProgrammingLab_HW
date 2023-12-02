#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int arr[10];
    while(cin>>arr[8]){
        int k=0;
        for(int i=8; i>=0; i--){
            if(i==8){
                continue;
            }
            cin>>arr[i];
            if(k==0 && arr[i]!=0 && i!=0){
                if(arr[i]==1){
                    if(i>1){
                      k=1;
                      cout<<"x^"<<i;
                    }
                    else if(i==1){
                      k=1;
                      cout<<"x";
                    }
                }
                else if(arr[i]==-1){
                    if(i>1){
                      k=1;
                      cout<<"-x^"<<i;
                    }
                    else if(i==1){
                      k=1;
                      cout<<"-x";
                    }
                }
                else if(arr[i]!=0){
                    if(i>1){
                        k=1;
                        cout<<arr[i]<<"x^"<<i;
                    }
                    else if(i==1){
                        k=1;
                        cout<<arr[i]<<"x";
                    }
                }
            }
            else if(k==1 && arr[i]!=0 && i!=0){
                if(arr[i]>0){
                    if(arr[i]==1){
                        if(i>1){
                          cout<<" + "<<"x^"<<i;
                        }
                        else if(i==1){
                          cout<<" + "<<"x";
                        }
                    }
                    else{
                        if(i>1){
                          cout<<" + "<<arr[i]<<"x^"<<i;
                        }
                        else if(i==1){
                          cout<<" + "<<arr[i]<<"x";
                        }
                    }
                }
                else if(arr[i]<0){
                    if(arr[i]==-1){
                        if(i>1) {
                            cout<<" - "<<"x^"<<i;
                        }
                        else if(i==1){
                          cout<<" - "<<"x";
                        }
                    }
                    else{
                        if(i>1){
                          cout<<" - "<<abs(arr[i])<<"x^"<<i;
                        }
                        else if(i==1){
                          cout<<" - "<<abs(arr[i])<<"x";
                        }
                    }
                }
            }
            else if(i==0){
                if(k==0 && arr[0]!=0){
                    cout<<arr[0];
                }
                else if(k==1 && arr[0]!=0){
                    if(arr[0]>0) {
                      cout<<" + "<<arr[0];
                    }
                    else {
                      cout<<" - "<<abs(arr[0]);
                    }
                }
            }
        }
        cout<<endl;
    }
}
