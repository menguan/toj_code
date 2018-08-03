#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{    
    double t[1001];
    int a,b;
    cin>>a;
    while(a--)
    {
        
        double kk=0,ave=0,sum=0;
        cin>>b;
        int c=b;
        while(1)
        {
            cin>>t[b];
            sum+=t[b];
            b--;
            if(b==0)
            break;
        }
        ave=sum/c;
        
        for(int i=c;i>0;i--)
        {
            if(t[i]>ave)
            kk+=1;
        }
        
        double u=kk/c*100;
        printf("%.3f%c",u,'%');
        
        
        cout<<endl; 
     }
return 0;
}  