#include<iostream>
#include<string>
using namespace std;

int f(int a,int b)
{
    int b2=b%2;
    int b4=b%4;
    if(a==0)
      return 0;
    if(a==1)
      return 1;
    if(a==5)
      return 5;
    if(a==6)
      return 6;   
    if(a==4)
    {
       switch(b2)
       {
         case 0:return 6;
         case 1:return 4;
       }
    }       
    if(a==9)
    {
       switch(b2)
       {
         case 0:return 1;
         case 1:return 9;
       }
    }            
    if(a==2)
    {
       switch(b4)
       {
         case 0:return 6;
         case 1:return 2;
         case 2:return 4;
         case 3:return 8;
       }
    }
    if(a==3)
    {
       switch(b4)
       {
         case 0:return 1;
         case 1:return 3;
         case 2:return 9;
         case 3:return 7;
       }
    }if(a==7)
    {
       switch(b4)
       {
         case 0:return 1;
         case 1:return 7;
         case 2:return 9;
         case 3:return 3;
       }
    }if(a==8)
    {
       switch(b4)
       {
         case 0:return 6;
         case 1:return 8;
         case 2:return 4;
         case 3:return 2;
       }
    }
}         
          
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        if(s1=="0"&&s2=="0")
          return 0;
          
        if(s2=="0")
        {
           cout<<1<<endl;
           continue;
        }
        
        int ls1=s1.length();
        int last1=s1[ls1-1]-'0';
                
        int ls2=s2.length();
        int last2;
        if(ls2>1)
          last2=(s2[ls2-2]-'0')*10+(s2[ls2-1]-'0');
        else
          last2=s2[ls2-1]-'0';
        
        cout<<f(last1,last2)<<endl;
    }
}  