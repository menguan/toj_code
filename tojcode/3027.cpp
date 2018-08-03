
//******************************************************************8
//************         ************************************************************8
//************  *****  ******************************************************************8
//************  *****  ********************************************************************
//************         **********************************************************************
//*******************************************************************************************

#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int Min=10000;
const int Max=999999;
char x[5];
int a[5];
int T,n;
int up;
int MIN()
{
    int i=1;
    int mm=a[i],index=1;
    for(i=2;i<=4;i++)
    {
        if(a[i]<mm)
        {
            mm=a[i];
            index=i;
        }
    }
    return index;
}
int First(int x)
{
    int b[5];
    int i=5;
    int tmp=x;
    while(tmp)
    {
        b[--i]=tmp%100;
        tmp=tmp/100;
    }
    int up=MIN();
    int sum=(Min/a[up])*a[up]+b[up];
    while(sum<Min)sum=sum+a[up];
    while(sum<Max)
    {
        int num=0;
        for(i=1;i<=4;i++)
        {
            if(i!=up&&sum%a[i]==b[i])num++;
        }
        if(num==3)return sum;
        else sum+=a[up];
    }
}

void cou(int x,int j)
{
    int b[6];
    int i=4;
    int tmp=x;
    while(tmp)
    {
        b[--i]=tmp%100;
        tmp=tmp/100;
    }
    char ch[6];
    for(i=1;i<=3;i++)
    {
        if(b[i]!=27)ch[i]=char(b[i]+'A'-1);
        else ch[i]=' ';
    }
    int con=4;
    if(j==n)
    {
        for(i=3;i>=1;i--)
        {
            if(ch[i]==' ')con=i;
            else break;
        }
    }ch[con]='\0';
    printf("%s",ch+1);
}





int main()
{
    cin>>T;
    int in,i;
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=4;i++)cin>>a[i];
        for(i=1;i<=n;i++)
        {
            cin>>in;
            int tmp=First(in);
            cou(tmp,i);
        }
        cout<<endl;
    }
    return 0;
}
