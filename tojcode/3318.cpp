#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long n;
const long long mod=200907;
struct ma
{
    long long a[3][3];
};
ma operator *(ma aa,ma bb)
{
    ma tmp;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            tmp.a[i][j]=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                tmp.a[i][j]=(tmp.a[i][j]+aa.a[i][k]*bb.a[k][j])%mod;
    return tmp;
}
ma operator ^(ma aa,long long b)
{
    ma tmp;
    for(int i=0;i<3;i++)
       for(int j=0;j<3;j++)
          tmp.a[i][j]=(i==j);
    while(b)
    {
        if(b&1)
            tmp=tmp*aa;
        b/=2;
        aa=aa*aa;
    }
    return tmp;
}
int main()
{
    while(cin>>n,n)
    {
        if(n==1){cout<<1<<endl;continue;}
        if(n==2){cout<<2<<endl;continue;}
        ma aa;
        aa.a[0][0]=1;
        aa.a[0][1]=2;
        aa.a[0][2]=1;
        aa.a[1][0]=1;
        aa.a[1][1]=0;
        aa.a[1][2]=0;
        aa.a[2][0]=0;
        aa.a[2][1]=0;
        aa.a[2][2]=1;
        aa=aa^(n-2);
        cout<<(2*aa.a[0][0]+aa.a[0][1]+aa.a[0][2])%mod<<endl;
    }
}
