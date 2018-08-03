#include<iostream>
#include<cstring>
#include<stdio.h>
#include<ctype.h>
#include<algorithm>
using namespace std;
char s[1000010];
int main()
{
    while(gets(s))
    {
        int ans=0;
        int len=strlen(s);
        if(isdigit(s[0])||s[0]=='l'||s[0]=='o'||s[0]=='O')
            ans++;
            int shu=0,le=0,nshu=0,nle=0;
         for(int i=1;i<len;i++)
         {
             if(s[i]=='l'||s[i]=='o'||s[i]=='O')
                ans++;
             else if(isdigit(s[i]))
                shu++;
             else
                le++;
         }
         int tmp=1010101000;
         for(int i=0;i<len;i++)
         {
            if(s[i]=='l'||s[i]=='o'||s[i]=='O') continue;
            if(i!=0)
            {
                if(isdigit(s[i]))
                    nshu++;
                else
                    nle++;
            }
           // cout<<nshu<<" "<<le-nle<<endl;
            tmp=min(tmp,nshu+le-nle)
;         }
 tmp=min(tmp,nshu+le-nle);
         ans+=tmp;
         cout<<ans<<endl;
    }
}

