#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,unin;
int a[1000010];
int b[1000010];
int num[1000010];
int ans[1000010];
int main()
{
    memset(num,0,sizeof(num));
    memset(ans,0,sizeof(ans));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
        num[a[i]]++;
    }
    sort(a,a+n);
    unin=unique(a,a+n)-a;
    /*
    for(int i=0;i<n;i++)
    {
        while(i+1<n&&a[i]==a[i+1])
        {
            for(int j=i;j<)
        }
    }*/
    //int d=
    for(int i=0;i<unin;i++)
    {
        for(int j=a[i];j<=1000000;j+=a[i])
            ans[j]+=num[a[i]];
    }
    for(int i=0;i<n;i++)
        printf("%d\n",ans[b[i]]-1);

}

