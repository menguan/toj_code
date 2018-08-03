#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char t[1000];
    int p[10000];
    while(cin>>t)
    {
        if(t[0]=='*'&&t[1]=='\0')
          return 0;
          
        bool s=1;
        for(int i=1;i<strlen(t)&&s;i++)
        {
           memset(p,0,sizeof(p));
           for(int j=0;j+i<strlen(t)&&s;j++)
           {
               int zhi=100*(t[j+i]-'A')+(t[j]-'A');
               if(p[zhi]==0)
                 p[zhi]=1;
               else
                 s=0;
           }
        }
        if(s)
          cout<<t<<" is surprising.\n";
        else
          cout<<t<<" is NOT surprising.\n";
    }
    return 0;
}