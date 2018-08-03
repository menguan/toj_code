#include<stdio.h> 
#include<cstring> 
#include<map> 
#include<string>
#include<iostream>
using namespace std; 
int main() 
{ 
    string s;
    double  cnt; 
    map<string, double>mapp; 
    map<string, double>::iterator it; 
    cnt=0; 
    while(getline(cin,s)) 
    { 
        mapp[s]+=1.0; 
        cnt+=1.0; 
    } 
    double dd; 
    for(it=mapp.begin(); it!=mapp.end(); it++ ) 
    { 
        dd=it->second*100.0/cnt;
        cout<<it->first<<" "; 
        printf("%.4lf\n", dd ); 
    }
    //while(1); 
}

