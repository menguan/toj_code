#include<iostream>
#include<string>
using namespace std;
int re(char a)
{
 if(a=='B'||a=='F'||a=='P'||a=='V')
 return 1;
 if(a=='C'||a=='G'||a=='J'||a=='K'||a=='Q'||a=='S'||a=='X'||a=='Z')
 return 2;
 if(a=='D'||a=='T')
 return 3;
 if(a=='L')
 return 4;
 if(a=='M'||a=='N')
 return 5;
 if(a=='R')
 return 6;
 else
 return 0;
} 

int main()
{  
   
   string s;
   while(cin>>s)
   {
       for(int i=0;i<=s.length();i++)
       {   
           if(i>0&&(re(s[i])==re(s[i-1])))
           continue;
           if(re(s[i])!=0)
           cout<<re(s[i]);
       }
       cout<<endl;
   }
  return 0;
}   
   