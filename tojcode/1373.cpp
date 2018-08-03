#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int a[1010];
int n;
int mid;
int find(int low,int high,int num)
{
     mid=(high+low)/2;
     if(a[mid]==num)
          return mid;
     while(low<=high)
     {
        //cout<<mid<<" "<<high<<" "<<num<<endl;
        
        if(a[mid]==num)
          return mid;
        else if(a[mid]>num)
          high=mid-1;
        else
          low=mid+1;
        mid=(high+low)/2;
     }
     return -1;
}                
int main()
{
    kk:while(~scanf("%d",&n)&&n)
    {
       for(int i=0;i<n;i++)
         scanf("%d",&a[i]);
       sort(a,a+n);
       for(int i=n-1;i>=0;i--)
       {
          for(int j=n-1;j>=0;j--)
          {
              if(i==j) continue;
              for(int k=n-1;k>=0;k--)
              {
                  if(i==k||j==k)  continue;
                  // for(int l=k-1;l>=0;l--)
                   //{if(a[i]==a[j]+a[k]+a[l])
                   //  {printf("%d\n",a[i]);
                   //    goto kk;
                   //  }}
                   //cout<<i<<" "<<j<<" "<<k<<endl;
                   if(find(0,k-1,a[i]-a[j]-a[k])!=-1&&mid!=i&&mid!=j&&mid!=k)
                   {
                      printf("%d\n",a[i]);
                      goto kk;
                   }
              }
          }
       }
       puts("no solution");
    }
}                           
                                                 
                                                                    
                             
