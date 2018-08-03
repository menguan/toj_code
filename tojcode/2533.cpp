#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    char a[100];
    char b[100];
    char c[100];
    while(cin>>a)
    {
        int len=strlen(a);
        strcpy(c,a);
        strcpy(b,a);
        int tt=-1;
        for(int i=0;i<10;i++)
        {
            next_permutation(b,b+len);
            int ma=1010101010;
            for(int i=0;i<len-1;i++)
                ma=min(ma,abs(b[i]-b[i+1]));
            if((tt<ma)||(tt<=ma&&strcmp(c,b)>0)){strcpy(c,b);tt=ma;}
        }
        strcpy(b,a);
        for(int i=0;i<10;i++)
        {
            prev_permutation(b,b+len);
            int ma=1010101010;
            for(int i=0;i<len-1;i++)
                ma=min(ma,abs(b[i]-b[i+1]));
            if((tt<ma)||(tt<=ma&&strcmp(c,b)>0)){strcpy(c,b);tt=ma;}
        }
        cout<<c<<tt<<endl;
    }
}
