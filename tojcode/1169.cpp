#include<iostream>
using namespace std;
int kk(int k)
{
    if(k%2==0)
    return 1;
    else 
    return 0;
}    
    
int main()
{
    int a;
    while(cin>>a,a)
    {
        short m[a][a];
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<a;j++)
            {
                cin>>m[i][j];
            }
        }
        
        int sum1[a],sum2[a];
        for(int i=0;i<a;i++)
        {
            sum1[i]=0;
            sum2[i]=0;
        }    
        int sum11=0,sum22=0;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<a;j++)
            {
                sum1[i]+=m[i][j];
                sum2[j]+=m[i][j];
            }
        }
        int b1,b2;
        for(int i=0;i<a;i++)
        {
            if(kk(sum1[i])==1)
            sum11+=kk(sum1[i]);
            else
            b1=i+1;
            
        }
        for(int i=0;i<a;i++)
        {
            if(kk(sum2[i])==1)
            sum22+=kk(sum2[i]);
            else
            b2=i+1;
            
        }
        
        if(sum11==a&&sum22==a)
        cout<<"OK"<<endl;
        else if(sum11==a-1&&sum22==a-1)
        cout<<"Change bit ("<<b1<<","<<b2<<")"<<endl;
        else
        cout<<"Corrupt"<<endl;
        

        
                    
                        
    }
    return 0;
}    
   