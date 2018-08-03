/*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa  aaa  aaaaa                 aaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaa  aaaaaa 
aaaaa    aaaaa    aaaaaaaaaaaaaaaaaaaa   aaaaaaaa
aaaaa aaaaa          aaaaaaaaaaaaaaa   aaaaaaaaaa
aaaaa aaaaaaaa   aaaaaaaaaaaaaaaaa   aaaaaaaaaaaa
aaaaa    aaaaa     aaaaaaaaaaaa    aaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaa   aaaaaaaaaaaaaaaaa
aaaaaa a aaaaa   aa  aaaaaa   aaaaaaaaaaaaaaaaaaa
aaaaaaa  aaaaa  aaaaa aaaaa                aaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string>
using namespace std;
int a[300010];
bool ms[300010];int temp;
void init()
{
     memset(ms,0,sizeof(ms));
     temp=0;
     ms[1]=1;
     for(int i=2;i<=300000;i++)
     {
         if(i%7==1||i%7==6)
         {
            a[temp++]=i;
            ms[i]=1;
         }    
     }
     for(int i=0;i<temp;i++)
     {
       for(int j=0;j<temp;j++)
       {
             if(a[i]*a[j]>300000)
               break;
             ms[a[i]*a[j]]=0;
       }
     }
     temp=0;
     for(int i=1;i<=300000;i++)
     {
         if(ms[i]==1)
           a[temp++]=i;
     }
}             
         
int main()
{
    int t;
    init();
    while(cin>>t)
    {
       if(t==1)
         break;
       cout<<t<<":";
       for(int i=1;i<temp;i++)
       {
          if(t%a[i]==0)
            cout<<" "<<a[i];
          }     
       cout<<endl;
    }
}                 
