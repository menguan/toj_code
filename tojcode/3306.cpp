#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;


int num[1001],row[1001];

int cmp(int a,int b){
    return a>b;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        getchar();
        memset(num,0,sizeof(num));
        int i,j,ans=0;
        char ch;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%c",&ch);
                if(ch=='1')
                    num[j]++;
                else
                    num[j]=0;
                row[j]=num[j];
            }
            sort(row+1,row+m+1,cmp);
            for(j=1;j<=m;j++)
                if(ans<row[j]*j)
                    ans=row[j]*j;
            getchar();
        }
        printf("%d\n",ans);
    }
    return 0;
}
