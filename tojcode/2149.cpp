#include<iostream>
#include<string>
//#include<cstring>
using namespace std;//最后还是看了网上的代码 
//char s1[150],s2[150],s3[150]; 
string addtion(string &str1, string& str2)
{      
    int len = (str1.size() > str2.size()) ? str1.size() : str2.size();
    string a = string(len-str1.size(), '0') + str1,
   b = string(len-str2.size(), '0') + str2,
   c = string(len+1, '0');

    int i;
    for(i = len-1; i >= 0; --i) {
        c[i+1] += (a[i]-'0'+b[i]-'0');               
    }
    for(i = c.size()-1; i >= 1; --i) {
        if(c[i] == '2'){
            c[i] = '0';
            c[i-1] += 1;
        }
        if(c[i] == '3'){
            c[i] = '1';
            c[i-1] += 1;    
        }
    }

    while(c[0] == '0') {
   c = c.substr(1);
}
if (c == "") 
{
   return "0";
}
    return c;
}
int main()
{
    int n;
cin>>n;

    string a, b;    
    for(int i = 1; i <= n; ++i)
    {
        cin>>a>>b;
        cout<<i<<" "<<addtion(a, b)<<endl;   
    }   
    return 0;
}
     
/* int main()
{
    int n;
cin>>n;

    
    for(int i = 1; i <= n; ++i)
    {
        cin>>s1>>s2;
        cout<<i<<" "<<addtion(a, b)<<endl;   
    }   
    return 0;
}*/             
                    
     