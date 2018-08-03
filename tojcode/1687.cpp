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
            if(j%(j-k)==0&&j/(j-k)>1)
              printf("%d %d\n",j,j/(j-k));
            next[j]=k;
        }
        else k=next[k];
    }
}
int main()
{
    int cas=1;
    while(~scanf("%d",&n),n)
    {
        scanf("%s",&str);
        printf("Test case #%d\n",cas++);
        getNext();
        printf("\n");
    }
    return 0;
}
