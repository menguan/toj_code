#include <iostream>//直接求就可以  懒得自己打了 我就加个注释好了
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define M 1<<20
int pri[33],dp[M];
int gstate(int s,int x){//在s状态下去掉x
    for(int i=x;i<=20;i+=x){//去掉x的倍数
        if(s&(1<<(i-2))){
            s=s&(~(1<<(i-2)));
        }
    }
    for(int i=2;i<=20;i++){//去掉其它数加上x的倍数
        if(s&(1<<(i-2)))
        for(int j=x;i-j>=2;j=j+x){
            if(!(s&(1<<(i-j-2)))){
                 s=s&(~(1<<(i-2)));
                 break;
               }
        }
    }
    return s;
}
int getsg(int x){
    if(dp[x]!=-1)return dp[x];
    int ans=0;
    for(int i=2;i<=20;i++){
        if(x&(1<<(i-2))){
            int k=gstate(x,i);//去掉i后的状态
            if(!getsg(k))//假如此状态会导致输  次状态就赢
            return dp[x]=1;
        }
    }
    return dp[x]=0;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int tcase,n,i,state,tt=1;
    scanf("%d",&tcase);
    while(tcase--){
        scanf("%d",&n);
        for(i=0,state=0;i<n;i++){
            scanf("%d",&pri[i]);
            state|=(1<<(pri[i]-2));
        }
        sort(pri,pri+n);
        printf("Scenario #%d:\n",tt++);
        if(!getsg(state))printf("There is no winning move.\n");//给出的状态会输
        else {
            printf("The winning moves are:");
            for(i=0;i<n;i++){
                int s=gstate(state,pri[i]);
                if(!getsg(s))//假如去掉pri[i] 后会导致必输态  此为必胜步
                    printf(" %d",pri[i]);
            }
            printf(".\n");
        }
        printf("\n");
    }
}
