#include<iostream>
#include<cstring>
using namespace std;
const int mMax=100000;

int main()
{
   char m[mMax];
   long long sin[mMax],dou[mMax];   
   int i,len;
   while(cin>>m&&m[0]!='0')
   {
      sin[0]=1;
      dou[0]=0;
      len=strlen(m);   
      for(i=1;i<len;i++)
      {
         if(m[i]=='0')
         {
            sin[i]=0;
            dou[i]=sin[i-1];
         }   
         else if(m[i-1]=='1' || m[i-1]=='2'&&m[i]<='6')
         {
            sin[i]=sin[i-1]+dou[i-1];
            dou[i]=sin[i-1];
         }   
         else
         {
            sin[i]=sin[i-1]+dou[i-1];
            dou[i]=0;
         }  
      }
      cout<<sin[len-1]+dou[len-1]<<endl;
   }
   return 0;
}

