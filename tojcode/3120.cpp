#include <iostream>
using namespace std;
int find(int *a,int len,int n)//若返回值为x,则a[x]>=n>a[x-1]
{
    int left=0,right=len,mid=(left+right)/2;
    while(left<=right)
    {
        if(n>a[mid]) left=mid+1;
        else if(n<a[mid]) right=mid-1;
        else return mid;
        mid=(left+right)/2;
    }
    return left;  
}
void fill(int *a,int n)
{
    for(int i=0;i<=n;i++)
        a[i]=1000010;
}
int main(void)
{
    int maxn,i,j,n,a[100010],b[100010],c[100010];
    while(cin>>n)
    {
        fill(c,n+1);
        for(i=0;i<n;i++)
            cin>>a[i];
        c[0]=-1;
        c[1]=a[0];
        b[0]=1;
        for(i=1;i<n;i++)
        {
            j=find(c,n+1,a[i]);
            c[j]=a[i];
            b[i]=j;
        }
        for(maxn=i=0;i<n;i++)
            if(b[i]>maxn)
                maxn=b[i];
       cout<<maxn<<endl;
    }
    return 0;
}
