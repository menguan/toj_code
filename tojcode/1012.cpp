#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int a[100010];
bool vis[100010];
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    int cas;int n;
    cin>>cas;
    for(int t=1;t<=cas;t++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);    
        for(int i=n-1;i>=0;i--)
            a[i]/=a[0];
        queue<int> q;
        memset(vis,0,sizeof(vis));
        vis[1]=1;
        q.push(1);
        while(!q.empty())
        {
            int tt=q.front();q.pop();
            for(int i=0;i<n;i++)
            {
                int tmp=tt*a[i];
                if(tmp<=10000&&!vis[tmp])
                {
                    vis[tmp]=1;
                    q.push(tmp);
                }
                tmp=tt/a[i];
                if(a[i]*tmp==tt&&!vis[tmp])
                {
                    vis[tmp]=1;
                    q.push(tmp);
                }
            }
        }
        cout<<"Scenario #"<<t<<":"<<endl;
        int qq;
        cin>>qq;
        int a,b;
        while(qq--)
        {
            cin>>a>>b;
            cout<<"Gear ratio "<<a<<":"<<b;
            int tmp=gcd(a,b);
            a/=tmp;
            b/=tmp;
            for(int i=2;i<=a;i++)
                if(vis[i]&&a%i==0)
                  a/=i;
            for(int i=2;i<=b;i++)
                if(vis[i]&&b%i==0)
                  b/=i;

            if(vis[a]==1&&vis[b]==1)
                cout<<" can ";
            else
                cout<<" cannot ";
            cout<<"be realized."<<endl;

        }
        cout<<endl;
    }
}
