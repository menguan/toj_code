#include<iostream>
#include<cstring>
using namespace std;
int a[1010];
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
          
         for(int i=1;i<=n;i++)
           cin>>a[i];
         if(k==1)
         {  
           cout<<"Alice"<<endl;
           continue;
         }
         /*
         if(k==2)
         {
             int ans=a[1]-1;
             ans^=(a[2]-a[1]-1);
             if(!ans)
              cout<<"Alice"<<endl;
            else
              cout<<"Bob"<<endl;
            continue;  
         }*/
                 
         if(n%2==0)
         {
            int ans=a[2]-a[1]-1;
            for(int i=4;i<=n;i+=2)
              ans^=(a[i]-a[i-1]-1);
            if(ans)
              cout<<"Alice"<<endl;
            else
              cout<<"Bob"<<endl;
         }
         else
         {
           int ans=a[1];
           if(k==2) ans--;//.............. 
           for(int i=3;i<=n;i+=2)
             ans^=(a[i]-a[i-1]-1);
           if(ans)
             cout<<"Alice"<<endl;
           else
             cout<<"Bob"<<endl;
         }
    }
}    
                                          
