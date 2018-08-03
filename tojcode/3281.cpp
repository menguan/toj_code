#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int n,x;
int a[100010];
int be[2][10000];
int af[2][10000];
int t[200020];
int main()
{
    while(cin>>n>>x)
    {
        int pos;
       // memset(be,0,sizeof(be));
       // memset(af,0,sizeof(af));
        memset(t,0,sizeof(t));
        for(int i=1;i<=n;i++)
        {


            cin>>a[i];
            if(a[i]==x) pos=i;
        }//int cnt=0;
        //system("pause");
            int cha=0;
            t[100010]=1;
        for(int i=pos-1;i>=1;i--)
        {

            if(a[i]<x)  cha--;
            else   cha++;
                t[cha+100010]++;
            //cnt^=1;
        }cha=0;

        long long ans=t[cha+100010];;

        for(int i=pos+1;i<=n;i++)
        {

            if(a[i]<x)  cha++;
            else  cha--;
            ans+=t[cha+100010];
        }
        cout<<ans<<endl;
    }
}
