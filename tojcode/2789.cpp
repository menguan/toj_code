#include<iostream>
#include<cstring>
using namespace std;
int a[100010];
int n,m;
int main()
{
    cin>>n>>m;
    int sum=0;int maxn=-1;
    for(int i=0;i<n;i++)
    {
         cin>>a[i];
         sum+=a[i];
         if(a[i]>maxn)
           maxn=a[i];
    }
    int l=maxn,r=sum;
    int mid;int cnt;
    int ans;
    while(l<r)
    {
        mid=(l+r)/2;
        sum=0;cnt=0;
        for(int i=0;i<n;i++)
        {
           /*
           if(sum+a[i]>mid)
           {
              sum=0;
              cnt++;
           }
           else
             sum+=a[i];
           */  
           sum+=a[i];
           if(sum>mid)
           {
              sum=a[i];
              cnt++;
           }        
        }
        //if(cnt==m)
          //ans=mid;
        if(cnt<m)
          r=mid;
        else
          l=mid+1;
    }
    cout<<l<<endl;
    //while(1);
}                          
       
