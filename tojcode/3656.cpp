#include<stdio.h>
#define ll long long
#include<math.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
char str[10010];
ll a[30000],len,num[30000];
void print(int cur){
    if(cur==len){
        for(int i=0;i<4*(len);i++) printf(" ");
        for(int i=0;i<len;i++)
            for(int j=0;j<num[i]-1;j++) printf(" ");
        printf("%lld\n",a[len]);
        return ;
    }
    for(int i=0;i<4*len;i++) printf(" ");
    for(int i=0;i<=len;i++) for(int j=0;j<num[i]-1;j++) printf(" ");
    printf("1");
    printf("\n");
    for(int i=0;i<4*cur;i++) printf(" ");
    for(int i=0;i<cur;i++) for(int j=0;j<num[i]-1;j++) printf(" ");
    printf("%lld + ",a[cur]);
    for(int i=0;i<4*(len-cur)-3;i++) printf("-");
    for(int i=cur+1;i<=len;i++) for(int j=0;j<num[i]-1;j++) printf("-");
    printf("\n");
    print(cur+1);
}
int main(){
    while(scanf("%s",str)!=EOF){
        int l=strlen(str);
        char ch=str[0];
        if(str[0]=='L') a[0]=0,a[1]=1,len=1;
        else a[0]=1,len=0;
        for(int i=1;i<l;i++){
            if(str[i]==ch) a[len]++;
            else ch=str[i],a[++len]=1;
        }
        a[len]++;
        for(int i=len;i>=0;i--){
            ll k=a[i];
            num[i]=0;
            while(k){
                num[i]++;
                k/=10;
            }
        }
        print(0);
    }
}