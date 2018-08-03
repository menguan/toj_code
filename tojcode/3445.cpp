#include<iostream>
using namespace std;
int main()
{
    int e,f,c,left,sum=0;
    cin>>e>>f>>c;
    
        for(left=e+f;left>=c;)
            {  
              sum+=left/c;
              left=left%c+left/c;
            }  
        cout<<sum<<endl;
        
        return 0;
        
                
            
        
        
        
} 