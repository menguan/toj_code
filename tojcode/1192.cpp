#include<iostream>
using namespace std;
int a[21];
int b[21];
int main()
{
    int n;
    bool flag=0;
    while(cin>>n,n)
    {
       
       int suma=0;
       int sumb=0;
       for(int i=0;i<n;i++)
         cin>>a[i];
       for(int i=0;i<n;i++)
         cin>>b[i]; 
       for(int i=0;i<n;i++)
       {
          if(a[i]==b[i])
            continue;
          else if(a[i]==1&&b[i]==2)
            suma+=6;
          else if(a[i]==2&&b[i]==1) 
            sumb+=6;
          else if(a[i]-b[i]==1)
            sumb+=(a[i]+b[i]);
          else if(b[i]-a[i]==1)
            suma+=(a[i]+b[i]);
          else if(a[i]-b[i]>1)
            suma+=a[i];
          else if(b[i]-a[i]>1)
            sumb+=b[i];
            }
            if(flag==1)
            cout<<endl;
            cout<<"A has "<<suma<<" points. B has "<<sumb<<" points."<<endl;
            flag=1;
        }  
        }                               
        