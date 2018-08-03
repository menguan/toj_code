#include<iostream>
#include<cstring>
using namespace std;
int dir[4][2]={-1,0,0,1,1,0,0,-1};
int map[60][60];
int main()
{
    int t,n,r;
    cin>>t;
    while(t--)
    {cin>>n>>r;
        memset(map,0,sizeof(map));
        int a,b;
        for(int i=0;i<r;i++)
        {
              cin>>a>>b;
              map[a][b]=1;
        }
        cin>>a>>b;
        int tt;
        if(a==0)
          tt=2;
        else if(a==n+1)
          tt=0;
        else if(b==0)
          tt=1;
        else
          tt=3;
        do{
            a+=dir[tt][0];b+=dir[tt][1];
            if(map[a][b])
              tt=(tt+1)%4;
        }while(a&&a!=n+1&&b&&b!=n+1);
        cout<<a<<" "<<b<<endl;
    }
}           
            
                                      
