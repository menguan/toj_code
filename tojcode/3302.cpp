#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#define eps 1e-9
using namespace std;
//double s4[400];
//double s3[400];
int s1[800],s2[800];
int main()
{
    double u,v;
    
    int n;
    while(scanf("%d",&n)!=EOF)
    {
       for(int i=0;i<n;i++)
       {
           scanf("%d%d",&s1[2*i],&s1[2*i+1]);
       }
       //for(int i=1;i<n;i++)
       //{
       //   ba[i]=hypot(s1[i]-s1[i-1],s2[i]-s2[i-1]);
       //}
       //ba[0]=hypot(s1[0]-s1[n-1],s2[0]-s2[n-1]);
       for(int i=0;i<n;i++)
       {
           scanf("%d%d",&s2[2*i],&s2[2*i+1]);
       }
       double temp;
       for(int i=0;i<2*n;i++)
       {
          if(s1[i]&&s2[i])
            { temp=s1[i]*0.1/s2[i];
              break;}
       }            
       //for(int i=1;i<n;i++)
       //{
       //   bb[i]=hypot(s1[i]-s1[i-1],s2[i]-s2[i-1]);
       //}
       //bb[0]=hypot(s1[0]-s1[n-1],s2[0]-s2[n-1]);
       //sort(ba,ba+n);
       //sort(bb,bb+n);
      // double temp=ba[0]/bb[0];
       bool flag=1;
       for(int i=0;i<2*n;i++)
       {
          if(s1[i]&&s2[i])
            { 
              if(fabs(s1[i]*0.1/s2[i]-temp)>eps)
              {
                  flag=0;                                
              break;} 
            }   
       }             
   //    for(int i=1;i<n;i++)            
   //    {
   //         if(fabs(temp*bb[i]-ba[i])>eps)
   //           {flag=0;break;}
  //     }
       if(flag)
         puts("Yes");
       else 
         puts("No");
    }
}                                     
    
