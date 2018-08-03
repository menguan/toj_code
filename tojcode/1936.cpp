#include<iostream>
#include<cstring>
using namespace std;
int nowmax;
int ans=0;
int nowlen;
int maxlen;
int main()
{
    int len,h,n;
    while(cin>>n,n)
    {
       maxlen=0;
       nowlen=0;
       ans=0;
       nowmax=0;
       while(cin>>len>>h)
       {
           if(len==-1&&h==-1)
           {
               ans+=nowmax;
               cout<<maxlen<<" x " <<ans<<endl;
               break;
           }      
           if(nowlen+len>n)
           {      
               ans+=nowmax;
               nowlen=len;
               nowmax=h; 
           }      
           else   
           {      
              nowlen+=len;
              if(nowmax<h)
                nowmax=h;
           }
           if(nowlen>maxlen)
             maxlen=nowlen;
       }
    }
}
             
                 
                  
                   
                                                                                
