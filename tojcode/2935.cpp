#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
char a[10010][12];
int i,j;
int cmp(const void*a,const void*b)
{
     return strcmp((char*)a,(char*)b);
     }
int main()
{
    int t;
    int n;
    cin>>t;
    while(t--)
    {
       cin>>n;
       for(i=0;i<n;i++)
       {
            cin>>a[i];
            }                  
      qsort(a,n,sizeof(char)*12,cmp);
      int len1,len2;bool flag=0;
      for(i=1;i<n;i++)
      {
          len1=strlen(a[i-1]);
          len2=strlen(a[i]);
          j=0;
          if(len1<=len2)
          {
             while(a[i-1][j]==a[i][j]&&j<len1)
              j++;
            if(j==len1)
              flag=1;
              }
              if(flag)
                break;
       }
       if(flag)
         cout<<"NO"<<endl;
       else
         cout<<"YES"<<endl;
    }
    return 0;
}        
     
                             
                         
