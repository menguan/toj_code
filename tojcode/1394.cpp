#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXN=1000010;
char str[MAXN];
int next[MAXN];
int n;
void getNext()
{
    int j,k;
    j=0;
    k=-1;
    next[0]=-1;
    while(str[j]!='\0')
    {
        if(k==-1||str[j]==str[k])
        {
            j++;
            k++;
            next[j]=k;
        }
        else k=next[k];
    }
}
int main()
{
    int cas=1;
    while(~scanf("%s",&str))
    {
        if(strcmp(str,".")==0)
          break;
        n=strlen(str);
        getNext();
        int ans=1;
        //cout<<next[n]<<endl;
        if(n%(n-next[n])==0)
         ans=n/(n-next[n]);
        printf("%d\n",ans);
    }
    return 0;
}
