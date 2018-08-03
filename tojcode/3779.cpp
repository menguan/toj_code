#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int can[100],bowl;
int main()
{
    int n,p;
    while(cin>>n>>p&&(n+p))
    {
        memset(can,0,sizeof(can));
        bool flag=1;
        bowl=p;
        int ans;
        while(flag)
        {
            for(int i=0;i<n;i++)
            {
                //cout<<"kk"<<i<<endl;
                if(!flag)
                  break;
                if(bowl)
                {
                    bowl--;
                    can[i]++;
                    if(can[i]==p)
                    {
                        ans=i;
                        flag=0;
                    }
                }
                else
                {
                    bowl+=can[i];
                    can[i]=0;
                }
            }
        }
        cout<<ans<<endl;
    }
}                                 
