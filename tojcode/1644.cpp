#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

int main()
{
    int n;
    char word[1111111];
    cin>>n;
    getchar();
    while(n--){
        gets(word);
        int kk=strlen(word);
        for(int i=kk-1;i>=0;i--)
            {
            cout<<word[i];
            }
            cout<<endl;
        }
    return 0;
}