#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>
using namespace std;
char temp[400];
int main()
{
    int n;string now,next;
    int ans=0;
    scanf("%d",&n);
    while(n--)
    {
       scanf("%s",temp);
       if(!ans)
       {
          now=temp;
          ans=now.length();
       }
       else
       {
          next=temp;
          int same=0;
          for(int i=0;i<now.length()&&i<next.length();i++)
          {
               if(now[i]==next[i])
                 same++;
               else
                 break;
          }
          now=next;
           // cout<<next.length()<<" "<<same<<endl;cout<<ans<<endl;
            ans+=next.length()-same+1;
       }
    }
    printf("%d\n",ans);
    //while(1);
}
                                
