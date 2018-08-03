#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;
bool jud(int h,int m,int s)
{
     double hh=h*30.0+(m/12)*6;
     
     double mm=m*6;
     
     double ss=s*6;
     //cout<<hh<<" "<<mm<<" "<<ss<<endl;
     
     double h1=hh-mm;if(h1<0) h1+=360;
     double h2=hh-ss;if(h2<0) h2+=360;
     double m1=mm-ss;if(m1<0) m1+=360;
     double m2=mm-hh;if(m2<0) m2+=360;
     double s1=ss-mm;if(s1<0) s1+=360;
     double s2=ss-hh;if(s2<0) s2+=360;
     //cout<<h1<<" "<<h2<<" "<<m1<<" "<<m2<<" "<<s1<<" "<<s2<<endl;
     if(fabs(h1-s2)<eps||fabs(h2-m2)<eps||fabs(m1-h1)<eps)
       return 1;
     if(fabs(m2-s1)<eps||fabs(s1-h2)<eps||fabs(s2-m1)<eps)
       return 1;  
     
     return 0;
}  
int main()
{
    //jud(11,53,26);
    //system("pause");
    for(int i=0;i<12;i++)
    {
       for(int j=0;j<60;j++)
       {
           for(int k=0;k<60;k++)
           {
               if(jud(i,j,k))
               {
                   if(i<10)
                     cout<<"0";
                   cout<<i<<":";
                   if(j<10)
                     cout<<"0";
                   cout<<j<<":";
                   if(k<10)
                     cout<<"0";
                   cout<<k<<endl;
                   //system("pause");
               }
           }
       }
    }
   // while(1);
}  
                       
                     
                                 
                            
    
