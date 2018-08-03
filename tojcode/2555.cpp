#include<iostream>
#include<cstring>
using namespace std;
int c;
char s[500];
int main()
{
    while(cin>>c,c)
    {
        cin>>s;
        int len=strlen(s);
        int tt=0;
        int r=len/c;
        int x=0,y=0;
        int cnt=0;
        int num=0;
        int gg=1;
        while(tt++<len)
        {
            num<<=1;
            num+=(s[x*c+y]-'0');
            cnt++;
            if(cnt==7)
            {
                if(num==0) break;
                cout<<(char)(num);
                num=0;
                cnt=0;
            }
            x++;
            y--;
            if(x>=r||y<0)
            {
                if(gg<c)
                {
                    x=0;y=gg++;
                }
                else
                {
                    x=gg-c+1;y=c-1;
                    gg++;
                }
            }

        }
        cout<<endl;
    }
}
