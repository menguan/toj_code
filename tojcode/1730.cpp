#include<iostream>
using namespace std;
bool f(int a)
{
    bool o=0;
    if(a>1000)
    {
       for(int i=a-36;i<a;i++)
       {
           if(i<1000)
           {
               int j=i;
               int sum=0;
               sum+=j;
               sum+=j/100;
               j-=(j/100)*100;
               sum+=j/10;
               j-=(j/10)*10;
               sum+=j;
               if(sum==a)
               {
                   o= 1;
               }    
           }
           else
           {
               int j=i;
               int sum=0;
               sum+=j;
               sum+=j/1000;
               j-=(j/1000)*1000;
               sum+=j/100;
               j-=(j/100)*100;
               sum+=j/10;
               j-=(j/10)*10;
               sum+=j;
               if(sum==a)
               {
                   o= 1;
               }     
           }
       }
     }
     else if(a>100)
     {
         for(int i=a-27;i<a;i++)
         {
           if(i>=100)
           {
               int j=i;
               int sum=0;
               sum+=j;
               sum+=j/100;
               j-=(j/100)*100;
               sum+=j/10;
               j-=(j/10)*10;
               sum+=j;
               if(sum==a)
               {
                   o= 1;
               }    
           }
           else
           {
               int j=i;
               int sum=0;
               sum+=j;               
               sum+=j/10;
               j-=(j/10)*10;
               sum+=j;
               if(sum==a)
               {
                   o= 1;
               }     
           }
       }
    }
    else if(a>10)
    {
        for(int i=a-18;i<a;i++)
         {
           if(i<10&&i>0)
           {
               int j=i;
               int sum=0;
               sum+=j;
               sum+=j;               
               if(sum==a)
               {
                   o= 1;
               }    
           }
           else if(i>=10)
           {
               int j=i;
               int sum=0;
               sum+=j;               
               sum+=j/10;
               j-=(j/10)*10;
               sum+=j;
               if(sum==a)
               {
                   o= 1;
               }     
           }
       } 
    }
    else if(a==2||a==4||a==6||a==8||a==10)
      o=1;
      
    return o;
}                                                                            
int main()
{
    for(int i=1;i<10000;i++)
    {
        if(f(i)==0)
        cout<<i<<endl;
    }
    
    return 0;
}