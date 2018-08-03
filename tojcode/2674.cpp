#include<iostream>
#include<string>
using namespace std;
int main()
{
   string s;
   cin>>s;
   int len=s.length();
   if((((int)s[0])>=65&&((int)s[0])<=90)||s[0]=='_')
   {
         cout<<"Error!"<<endl;
         //while(1);
         return 0;
       }
   bool cpp=1,java=1;
   for(int i=0;i<len;i++)
   {
     if(s[i]=='_')
     {
       java=0;
       break;
     }
   }
   if(s[len-1]=='_')
       cpp=0;
   for(int i=0;i<len;i++)
   {
     
     if(((int)s[i])>=65&&((int)s[i])<=90)
       cpp=0;
   }
   for(int i=0;i<len-1;i++)
   {
     if(s[i]=='_'&&s[i+1]=='_')
       cpp=0;
   }
   if(cpp)
   {
     for(int i=0;i<len;i++)
     if(s[i]=='_')
     {
         s.erase(i,1);
         s[i]=(char)(s[i]-32);
         len--;
     }
   }
   else if(java)
   {
     for(int i=0;i<len;i++)
     if(((int)s[i])>=65&&((int)s[i])<=90)
     {
       s.insert(i,"_");
       //cout<<i<<s[i+1]<<endl;
       s[i+1]=(char)(s[i+1]+32);
       len++;
     }
   }
   else
   {
         cout<<"Error!"<<endl;
         //while(1);
         return 0;
       }  
           
        
               
   
   cout<<s<<endl;
   //while(1);
}           
   