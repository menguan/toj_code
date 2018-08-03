#include<iostream>
#include<cstring>
using namespace std;
long long n,k;
long long a[100010];
bool judge(long long p)
{
     long long ti=0;
     for(int i=0;i<n;i++)
     {
       if(p<a[i])
       {
          ti+=(a[i]-p)/(k-1);//因为每次自己干1点 总共是k 已经刨去干了的所以要k-1 
          if((a[i]-p)%(k-1)!=0)
            ti++;
       }
       if(ti>p)
         return 0;
     }
     return 1;
}               
int main()
{
    while(cin>>n){
    long long high=-1;
    for(int i=0;i<n;i++)
    {
       cin>>a[i];
       if(high<a[i])
         high=a[i];
    }
    cin>>k;
    if(k==1)
    {  cout<<high<<endl;
    
      continue;
    }
   long long int low=0;
    long long mid;
    while(low<high)
    {
       mid=(low+high-1)/2;
       if(judge(mid)==1) 
       {
            high=mid;
       }
       else
         low=mid+1;
    }
    cout<<(low+high)/2<<endl;
    //while(1);
    }
}                      
