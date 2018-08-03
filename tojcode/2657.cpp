#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;
int len;
char now[30];char temp[30];
void f(char op)
{
     char c;
     if(op=='C')
     {
         c=now[0];
         for(int i=0;i<len-1;i++)
           now[i]=now[i+1];
         now[len-1]=c;
     }
     else if(op=='J')
     {
        c=now[len-1];
       for(int i=len-1;i>0;i--)
          now[i]=now[i-1];
        now[0]=c;
       }
     else if(op=='E')
     {
       int q=len%2;
       for(int i=0;i<len/2;i++)
       {
          swap(now[i],now[i+len/2+q]);
       }
     }
     else if(op=='A')
     {
       for(int i=0,j=len-1;i<len;i++,j--)
       {
           temp[j]=now[i];
       }
       for(int i=0;i<len;i++)
         now[i]=temp[i];
     }
     else if(op=='M')
     {
       for(int i=0;i<len;i++)
       {
          if(isdigit(now[i]))
          {
             if(now[i]=='9')
               now[i]='0';
             else
               now[i]++;
          }
       }
     } 
     else if(op=='P')
     {
       for(int i=0;i<len;i++)
       {
          if(isdigit(now[i]))
          {
             if(now[i]=='0')
               now[i]='9';
             else
               now[i]--;
          }
       }
     }                                    
                            
}                          
int main()
{
    int t;char op[30];
    cin>>t;
    while(t--)
    {
        cin>>op>>now;
        len=strlen(now);
        for(int i=strlen(op)-1;i>=0;i--)
        {
           f(op[i]);
        }
        cout<<now<<endl;
    }
}
                   
