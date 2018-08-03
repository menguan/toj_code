#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n,m,a[1100],b[1100],cnt;
int cmp(int a,int b)
{return a>b;}
void dfs(int posa,int sum,int posb)
{
     int i;
     if(sum>n)
       return;
     if(sum==n)
     {
        cnt++;
        for(i=0;i<posb;i++)
        {
             if(i)  cout<<"+";
             cout<<b[i];
        }
        cout<<endl;
        return ;
     }
     for(i=posa;i<m;i++)
     {
        b[posb]=a[i];//cout<<i<<" "<<b[i]<<endl;
        dfs(i+1,sum+a[i],posb+1);
        while(i+1<m&&a[i]==a[i+1]) i++;
     }
}                  
int main()
{
    int i;
    while(cin>>n>>m&&n)
    {
        for(int i=0;i<m;i++)
          cin>>a[i];
        sort(a,a+m,cmp);
        cout<<"Sums of "<<n<<":"<<endl;
        cnt=0;
        dfs(0,0,0);
        if(cnt==0)
          cout<<"NONE"<<endl;
    }
}
                                 
                                    
 
