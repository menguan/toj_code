#include<iostream>
#include<algorithm>
using namespace std;

int a[1000010];
int main()
{
    int m,n;
    while(cin>>m>>n&&(m+n))
    {
       for(int i=0;i<n;i++)
         cin>>a[i];
       
       if(n%2)
       {
              n++;
              a[n-1]=0;
              }
          
       int ans=0;
       sort(a,a+n);
       //for(int i=0;i<n;i++)cout<<a[i]<<endl;
       for(int i=n-1;i>0;i-=2)
       {
               ans^=(a[i]-a[i-1]-1);
       }  
       if(ans)
         cout<<"Win"<<endl;
       else
         cout<<"Lose"<<endl;
    }
}             
                      
                                      
