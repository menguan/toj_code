#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a;
    while(cin>>a)
    {
        if(a==-1)
          return 0;
        
        int b[a];
        int c[a];
        int d[a];
        long long v[a];
        char e[a][10];
        for(int i=0;i<a;i++)
        {
            cin>>b[i]>>c[i]>>d[i]>>e[i];
            v[i]=b[i]*c[i]*d[i];
        }
        string s1;
        long long low=0;
        for(int i=0;i<a;i++)
        {
            if(v[i]>low)
            {
              low=v[i];
              s1=e[i];
            }
        }
        string s2;
        long long high=10000000000000;
        for(int i=0;i<a;i++)
        {
            if(v[i]<high)
            {
              high=v[i];
              s2=e[i];
            }
        }      
        cout<<s1<<" took clay from "<<s2<<"."<<endl;
    }
    return 0;
} 