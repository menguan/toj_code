#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        int aa=a.length();
        int bb=b.length();
        int c=0;
        int d=0;
        
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
        
        if(c==aa)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
    
    return 0;
} 