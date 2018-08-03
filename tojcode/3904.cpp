#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string s1,s2;
int c[2000000];
int lb(int x)
{
    return x&-x;
}
int len;
int getsum(int n)
{
    int ret=0;
    while(n)
    {
        ret+=c[n];
        n-=lb(n);
    }
    return ret;
}
int seti(int i,int p)
{
    while(i<=len)
    {
        c[i]+=p;
        i+=lb(i);
    }
}
int op,p,a,b;
char tt;
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        cout<<"Case "<<cas<<":"<<endl;
        memset(c,0,sizeof(c));
        cin>>s1>>s2;
        len=min(s1.length(),s2.length())+1;
        for(int i=0;i<len-1;i++)
        {
            if(s1[i]==s2[i])
            {
               seti(i+1,1);
            }

        }
        cin>>op;
        while(op--)
        {
            cin>>p;
            if(p==2)
            {
                cin>>a;
                a++;
                int l=a,r=len,mid=a;
                int tmp;
                while(l<=r)
                {
                    int mid=(l+r)/2;
                    tmp=getsum(mid)-getsum(a-1);
                    if(tmp==mid-a+1)
                        l=mid+1;
                    else
                        r=mid-1;
                    //cout<<l<<" "<<r<<" "<<mid<<endl;
                }
                cout<<l-a<<endl;
            }
            if(p==1)
            {
                cin>>a>>b>>tt;
                if(s1[b]==s2[b])
                {
                    seti(b+1,-1);
                }
                if(a==1)s1[b]=tt;
                else s2[b]=tt;
                if(s1[b]==s2[b]&&b<len-1)
                    seti(b+1,1);
            }
        }
    }
}

