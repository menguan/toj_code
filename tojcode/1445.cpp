#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        int l,b;
        cin>>l>>b;
        int c[b];
        for(int i=0;i<b;i++)
        {
            cin>>c[i];
        }
        sort(c,c+b);
        int d=0,e=0;
        for(int i=0;i<b;i++)
        {
            if(l%2==0)
            {
              if(c[i]>l/2&&l-c[i]>d)
              d=l-c[i];
              else if(c[i]<=l/2&&c[i]>d)
              d=c[i];
            }
            else
            {
                double ll=l*1.0;
                
                if(c[i]>ll/2&&ll-c[i]>d)
                d=l-c[i];
                else if(c[i]<ll/2&&c[i]>d)
                d=c[i];
            }
            
        }
        cout<<d<<" ";
        for(int i=0;i<b;i++)
        {
            if(l%2==0)
            {
              if(c[i]<l/2&&l-c[i]>e)
              e=l-c[i];
              else if(c[i]>=l/2&&c[i]>e)
              e=c[i];
            }
            else
            {
                double ll=l*1.0;
                
                if(c[i]<ll/2&&ll-c[i]>e)
                e=l-c[i];
                else if(c[i]>ll/2&&c[i]>e)
                e=c[i];
            }
            
        }
        cout<<e<<endl;       
        
    }
    return 0;
} 