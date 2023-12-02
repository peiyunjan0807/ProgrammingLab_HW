#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, const char * argv[]) {
    string id, city, borg;
    while(cin>>id){
        int k=0;
        int count=0;
        if(id.size()!=10){
            k=1;
        }
        if(isupper(id[0])==0) k=1;
        for(int i=1; i<9; i++){
            if(isalpha(id[i])!=0){
                k=1;
            }
            else{
                int number = id[i] - '0';
                count = count + number*(9-i);
            }
        }
        if(isalpha(id[9])!=0){
            k=1;
        }
        else{
            int number = id[9] - '0';
            count = count + number;
        }
        int id_2=id[1]-'0';
        if(id_2 == 1){
            borg = "男性";
        }
        else if(id_2 == 2){
            borg = "女性";
        }
        else{
            k=1;
        }
        int chang;
        switch(id[0]){
          case 'A':
                chang = 10;
                city = "台北市";
                break;
          case 'B':
                chang = 11;
                city = "台中市";
                break;
          case 'C':
                chang = 12;
                city = "基隆市";
                break;
          case 'D':
                chang = 13;
                city = "台南市";
                break;
          case 'E':
                chang = 14;
                city = "高雄市";
                break;
          case 'F':
                chang = 15;
                city = "台北縣";
                break;
          case 'G':
                chang = 16;
                city = "宜蘭縣";
                break;
          case 'H':
                chang = 17;
                city = "桃園縣";
                break;
          case 'I':
                chang = 34;
                city = "嘉義市";
                break;
          case 'J':
                chang = 18;
                city = "新竹縣";
                break;
          case 'K':
                chang = 19;
                city = "苗栗縣";
                break;
          case 'L':
                chang = 20;
                city = "台中縣";
                break;
          case 'M':
                chang = 21;
                city = "南投縣";
                break;
          case 'N':
                chang = 22;
                city = "彰化縣";
                break;
          case 'O':
                chang = 35;
                city = "新竹市";
                break;
          case 'P':
                chang = 23;
                city = "雲林縣";
                break;
          case 'Q':
                chang = 24;
                city = "嘉義縣";
                break;
          case 'R':
                chang = 25;
                city = "台南縣";
                break;
          case 'S':
                chang = 26;
                city = "高雄縣";
                break;
          case 'T':
                chang = 27;
                city = "屏東縣";
                break;
          case 'U':
                chang = 28;
                city = "花蓮縣";
                break;
          case 'V':
                chang = 29;
                city = "台東縣";
                break;
          case 'W':
                chang = 32;
                city = "金門縣";
                break;
          case 'X':
                chang = 30;
                city = "澎湖縣";
                break;
          case 'Y':
                chang = 31;
                city = "陽明山";
                break;
          case 'Z':
                chang = 33;
                city = "連江縣";
                break;
        }

        count = count + (chang/10)+(chang%10*9);
        if(count%10!=0){
            k=1;
        }
        if(k==1){
            cout<<"無效"<<endl;
        }
        else{
            cout<<city<<" "<<borg<<endl;
        }
    }

}
