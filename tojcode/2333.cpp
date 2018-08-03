#include<iostream>
#include<cstring>
using namespace std;
const int maxn=100100;
int n;int tp;
int s[maxn];int a[maxn];int lst[maxn],nxt[maxn];
long long presum[maxn];
long long ans;
int al,ar;
void getpos(int i)
{
     lst[i]=i;nxt[i]=-1;
     while(tp!=0&&a[s[tp-1]]>a[i])
       nxt[s[--tp]]=i-1;
     s[tp++]=i;
     if(tp==1)  lst[i]=1;
     else  lst[i]=s[tp-2]+1;
}  
int main()
{
    while(cin>>n)
    {
      presum[0]=0;
      tp=0;
      for(int i=1;i<=n;i++)
      {
          cin>>a[i];
          presum[i]=presum[i-1]+a[i];
          getpos(i);
      }
      ans=0;
      al=ar=1;
      for(int i=1;i<=n;i++)
      {
          int l=lst[i],r=nxt[i];
          if(r==-1)  r=n;
           long long tmp=a[i];
           tmp*=(presum[r]-presum[l-1]);
           if(tmp>ans)
           {al=l;ar=r;
             ans=tmp;
           }
      }
      cout<<ans<<endl<<al<<" "<<ar<<endl;
    }
}
                 
                 
