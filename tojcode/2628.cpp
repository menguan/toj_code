#include<iostream>
#include<string>
using namespace std;
int main()
{
        int hhh;
        cin>>hhh;
        while(hhh--)
        {
        
        
        string a,b,o;
        cin>>b>>a;
    
        int aa=a.length();
        int bb=b.length();
        
        int c=0;
        int d=0;
        int e=0;
        int f=0;
        
        for(int i=0,j=aa-1;i<=aa-1;i++,j--)
        {
             o[i]=a[j];
             
        }
                   
        for(int j=0;j<aa;j++)
        {
            for(int i=d;i<bb;i++)
            {
                if(b[i]==a[j])
                {   
                    d=i+1;
                    c++;
                    break;
                }
            }
        }
        for(int j=0;j<aa;j++)
        {
            for(int i=f;i<bb;i++)
            {
                if(b[i]==o[j])
                {   
                    f=i+1;
                    e++;
                    break;
                }
            }
        }
        if(c==aa||e==aa)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        }
    
    return 0;
}