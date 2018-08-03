#include<iostream>
using namespace std;
int main()
{
  int a[1010];
  int b[1010];
  int n;
  while(cin>>n,n)
  {
     if(n==1)
     {
       int h;
       while(cin>>h)
       {
         if(h)
         cout<<"Yes"<<endl;
         else
         {
           cout<<endl;
           break;
         }
       }
       continue;
     }      
     while(cin>>a[n-1],a[n-1])
     {
       int t=n,counta=0,lefta=t,countb=0,go=0;
       
       for(int i=t-2;i>=0;i--)
         cin>>a[i];
       
         
       while(1)
       {
         
         if(lefta==0&&go==t)
         {
           cout<<"Yes"<<endl;
           break;
         }
         else if(lefta==0&&go!=t)
         {
           cout<<"No"<<endl;
           break;
         }
         b[countb]=a[counta];
         
         while(b[countb]==t-go)
         {         
           countb--;
           go++;
           if(countb==-1)
           break;
         }  
         
         countb++;
         counta++;
         lefta--;
         
         
       }
     }
     cout<<endl;
   }
}     