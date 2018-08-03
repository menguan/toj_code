#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char a[110][110];
int main()
{
   string s;int r,c;
   while(cin>>s&&s!="ENDOFINPUT")
   {
     memset(a,0,sizeof(a));
     cin>>r>>c;
     for(int i=0;i<r;i++)
     for(int j=0;j<c;j++)
       cin>>a[i][j];
     cin>>s;
    
     for(int i=0;i<r-1;i++)
     {
       for(int j=0;j<c-1;j++)
       {
         cout<<(a[i][j]-'0'-'0'-'0'-'0'+a[i][j+1]+a[i+1][j]+a[i+1][j+1])/4;
       }
       cout<<endl;
     }
   }
 }          