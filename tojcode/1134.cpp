#include<iostream>
#include<algorithm>
using namespace std;
int a[20];
int main()
{
   int k;
   int flag=0;
   while(cin>>k,k)
   {
     if(flag)
       cout<<endl;
     flag=1;  
     for(int i=0;i<k;i++)
     {
       cin>>a[i];
     }
     
     sort(a,a+k);
     for(int i1=0;i1<=k-6;i1++)
     {
       for(int i2=i1+1;i2<=k-5;i2++)
       {
         for(int i3=i2+1;i3<=k-4;i3++)
         {
           for(int i4=i3+1;i4<=k-3;i4++)
           {
             for(int i5=i4+1;i5<=k-2;i5++)
             {
               for(int i6=i5+1;i6<=k-1;i6++)
               {
                 cout<<a[i1]<<" "<<a[i2]<<" " <<a[i3]<<" "<<a[i4]<<" "<<a[i5]<<" "<<a[i6]<<endl;
               }
             }
           }
         }
       }
     }
   }
 }   