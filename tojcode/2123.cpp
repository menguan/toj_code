#include<iostream>
using namespace std;
int main()
{ 
    int a;
       while(cin>>a,a)    
       {
           
           int m=0,j=0;
           for(int i=0;i<a;i++)
           {   
               int y;
               cin>>y;
               if(y==0)
               m++;
               else
               j++;
           }
           cout<<"Mary won "<<m<<" times and John won "<<j<<" times"<<endl;
       }    
    return 0;
}