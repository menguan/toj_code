#include<iostream>
#include<cmath>
using namespace std;
int main()
{  
   int a; 
   while(cin>>a)
   {
       int n[a];
       int b[a];
       bool k=1;
       for(int i=1;i<a;i++)
           b[i]=0;
       for(int i=0;i<a;i++)
       {
           cin>>n[i];
       }
       for(int i=0;i<a-1;i++)
       { 
          int o= abs(n[i+1]-n[i]);       
          b[o]=1;
       }   
       for(int i=1;i<a;i++)
       {
           if(b[i]==0)
             k=0;
       }
       if(k==0)
       {
           cout<<"Not jolly"<<endl;
       }
       else if(k==1)
       {
           cout<<"Jolly"<<endl;
       }
    }
    return 0;
} 