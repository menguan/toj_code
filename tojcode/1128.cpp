#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string ss;
int num[10];
string change(string str){
    int i,j,n=str.length(),k=0;
    char ans[100];
    memset(num,0,sizeof(num));
    for(i=0;i<n;i++)
        num[str[i]-'0']++;
    for(i=0;i<10;i++)
        if(num[i]){
            if(num[i]<10)   ans[k++]=num[i]+'0';
            else{
                ans[k++]=num[i]/10+'0';
                num[i]%=10;
                ans[k++]=num[i]+'0';
            }
            ans[k++]=i+'0';
        }
    ans[k]='\0';
    return ans;
}
void deal(string ss){
    int i,j;
    string tem=ss;
    string ta[16];
    for(i=0;i<15;i++){
        bool flag=false;
        tem=change(tem);
        //cout<<tem<<endl;
        for(j=0;j<i;j++)
            if(tem==ta[j]){
                flag=true;
                break;
            }
        if(flag){
            if(j==0&&i==1){
                cout<<ss<<" is self-inventorying"<<endl;
                return ;
            }
            if(j==i-1){
                cout<<ss<<" is self-inventorying after "<<i<<" steps"<<endl;
                return ;
            }
            else{
                cout<<ss<<" enters an inventory loop of length "<<i-j<<endl;
                return ;
            }
        }
        ta[i]=tem;
    }
    cout<<ss<<" can not be classified after 15 iterations"<<endl;
}
int main(void){
    while(cin>>ss){
        if(ss=="-1")   break;
        deal(ss);
    }
    return 0;
}
