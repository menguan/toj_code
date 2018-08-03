#include<iostream>
using namespace std;
int f(int a)
{
    int i;
    if(a>10000)
    {
       for(i=a-45;i<a;i++)
       {
           if(i>=10000)
           {
               int j=i;
               int sum=0;
               sum+=j;
               sum+=j/10000;
               j-=(j/10000)*10000;
               sum+=j/1000;
               j-=(j/1000)*1000;
               sum+=j/100;
               j-=(j/100)*100;
               sum+=j/10;
               j-=(j/10)*10;
               sum+=j;
               if(sum==a)
               {
                   break;
               }    
           }
           else if(i<10000)
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
                   break;
               }     
           }
       }
     }
    else if(a>1000)
    {
       for(i=a-36;i<a;i++)
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
                   break;
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
                   break;
               }     
           }
       }
     }
     else if(a>100)
     {
         for(i=a-27;i<a;i++)
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
                   break;
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
                   break;
               }     
           }
       }
    }
    else if(a>10)
    {
        for(i=a-18;i<a;i++)
         {
           if(i<10&&i>0)
           {
               int j=i;
               int sum=0;
               sum+=j;
               sum+=j;               
               if(sum==a)
               {
                   break;
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
                   break;
               }     
           }
       } 
    }
    else if(a==2) 
      i=1;
    else if(a==4) 
      i=2;
    else if(a==6) 
      i=3;
    else if(a==8) 
      i=4;
    else if(a==10) 
      i=5;
    else
      i=a;    
    return i;
} 
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        int b;
        cin>>b;
        
        if(b==1)
          cout<<0<<endl;
        else if(b==2)
          cout<<1<<endl;
        else if(f(b)==b)
          cout<<0<<endl;
        else
          cout<<f(b)<<endl;
    }
    return 0;
}            
   