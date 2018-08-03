#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      bool ist[12];
      int now[12];
      memset(ist,0,sizeof(ist));
      memset(now,0,sizeof(now));  
      string s1,s2,s3;
      for(int i=0;i<3;i++)
      {
         cin>>s1>>s2>>s3;
         int len=s1.length();
         if(s3=="even")
         {
             for(int j=0;j<len;j++)
             {
                 ist[s1[j]-'A']=1;
                 ist[s2[j]-'A']=1;
             }
         }
         else if(s3=="up")
         {
              for(int j=0;j<len;j++)
              {
                 now[s1[j]-'A']--;
                 now[s2[j]-'A']++;
                //cout<<now[s1[j]-'A']<<endl;
                 //now[s2[j]-'A']++;
              }
         }
         else
         {
              for(int j=0;j<len;j++)
              {
                 now[s1[j]-'A']++;
                 now[s2[j]-'A']--;
              }                 
         }
      }
      char c;int ans=-1;bool flag;//1qing  0zhong
      for(int i=0;i<12;i++)
      {
        // cout<<now[i]<<endl;
         if(ist[i])
           continue;
         if(abs(now[i])>ans)
         {
             if(now[i]>0)
                flag=1;
             else
                flag=0;
             ans=abs(now[i]);   
             c=i+'A';
         }
      }
      cout<<c<<" is the counterfeit coin and it is ";
      if(!flag)
        cout<<"heavy."<<endl;
      else
        cout<<"light."<<endl;
    }
}                                                       
