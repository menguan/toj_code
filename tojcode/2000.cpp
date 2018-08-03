#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
char s[600],tmp[600];
char crib[20];
int main()
{
    int t;int len;int ff;
    int ss,m;
    bool flag;
    cin>>t;
    while(t--)
    {
        flag=0;
        cin>>len;
        cin>>s;
        for(int i=0;i<(len-5)/5+(len%5!=0);i++)
        {
            cin>>tmp;
            strcat(s,tmp);
        }
        cin>>crib;
        ff=strlen(crib);
        for(int i=1;i<=25;i++)
        {
            if(flag)break;
            for(int j=5;j<=20;j++)
            {
                if(flag)break;
                strcpy(tmp,s);
                for(int k=0;k<len;k++)
                {
                    tmp[k]-=i;
                    if(tmp[k]<'A') tmp[k]+=26;
                }
                int k;
                for(k=0;k<len-j;k+=j)
                {
                   reverse(tmp+k,tmp+k+j);
                }
                reverse(tmp+k,tmp+len);
                int aa=0,bb=0;
                while(aa<len)
                {

                    if(tmp[aa]==crib[bb])
                    {
                        aa++;
                        bb++;
                    }
                    else
                    {
                        aa-=bb;
                        aa++;
                        bb=0;
                    }
                    if(bb==ff)
                    {
                       flag=1;
                       ss=i;m=j;
                       break;
                    }
                }
            }
        }
        if(flag)
            cout<<ss<<" "<<m<<endl;
        else
            cout<<"Crib is not encrypted."<<endl;

    }
}
