#include<iostream>
using namespace std;
int a[1000];
int main()
{
    int n;
    int i;
    while(cin>>n,n)
    {
        for(i=0;i<n;i++) 
          cin>>a[i];
        int re=0;
        while(1)
        {
            for(i=1;i<n;i++)
              if(a[i-1]!=a[i]) 
                break;
            if(i==n) 
              break;
            re++;
            int temp=a[n-1]/2;
            for(i=n-1;i>0;i--)
            {
                a[i]/=2;
                a[i]+=a[i-1]/2;
            }   
            a[0]/=2; 
            a[0]+=temp;
            for(i=0;i<n;i++)
             if(a[i]%2) a[i]++;
        }    
        cout<<re<<" "<<a[0]<<endl;
    }    
    return 0;
}