#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
typedef long long ll;
using namespace std;
const int maxn=32000;
ll inf=2147483647;
ll a[maxn],cnt,sum[maxn],d[maxn];
ll digit(ll n)
{
    ll cnt=0;
    while(n) cnt++,n/=10;
    return cnt;
}
int binarySearch(ll a[],int n,ll key)
{
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(a[mid]>=key) r=mid;
        else l=mid+1;
    }
    return l;
}

int main()
{
    for(int i=1;i<maxn;i++)
    {
        int dit=digit(i);
        a[i]=a[i-1]+dit;
        sum[i]=sum[i-1]+a[i];
    }
    int ci;cin>>ci;
    while(ci--)
    {
        ll n;cin>>n;
        int p;
        p=binarySearch(sum,maxn,n);
        int pos=n-sum[p-1];
        int l=binarySearch(a,maxn,pos);
        int k=pos-a[l-1];
        string str;
        while(l) str+=l%10+'0',l/=10;
        reverse(str.begin(),str.end());
        cout<<str[k-1]<<endl;
    }
    return 0;
}
