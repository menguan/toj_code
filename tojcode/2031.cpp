#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char str[1000][1000];
int nIndex;


int main(){
    while(gets(str[0])){
        nIndex = 1;
        while(gets(str[nIndex]), str[nIndex++][0]!='.') ;

        int status=0;
        bool flag=true;
        int maxNum = (1<<16)-1;
        while(status <= maxNum){

            flag = true;
            for(int i=0; i<nIndex-1; ++i){
                bool ok = false;
                int pos=0;
                while(pos < strlen(str[i])){
                    if(str[i][pos]=='+'){
                        if((status >> (str[i][pos+1]-'A')) & 1 ){
                            ok = true; break;
                        }
                    }
                    else if(str[i][pos]=='-'){
                        if( !((status >> (str[i][pos+1]-'A')) & 1)){
                            ok = true;
                            break;
                        }
                    }
                    pos += 2;
                }
                if(!ok){flag=false ; break; }
            }
            if(flag) break;
            ++status;
        }
        if(!flag) printf("No pizza can satisfy these requests.\n") ;
        else{
            int pos=0;
            printf("Toppings: ");
            while(pos <16){
                if(status & 1) printf("%c", pos+'A');
                ++pos; status >>= 1;
            }
            puts("");
        }
    }
}
