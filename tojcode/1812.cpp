#include <iostream>  
#include <stdio.h>  
#include <string>  
#include <cstring> 
#include <algorithm>  
#include <map>  
using namespace std;  
int main()  
{  

    char word[200];  
    string a;  
    map<string,int> m;  
    int maxn=1;  
    while(scanf(" %s",word)!=EOF)  
    {  
        a.clear();  
        int flag = 0;  

  
        for(int i=0; i<strlen(word); i++)  
        {  
            if(isalpha(word[i]) || (word[i]>='0' && word[i]<='9'))  
            {  
                flag = 1;  
                if(word[i]>='A' && word[i]<='Z')  
                {  
                    word[i] += 32;  
                }  
                a.push_back(word[i]);  
            }  
            else if(flag == 1)//没到头 有标点  
            {  
                if(m.find(a) == m.end())  
                {  
                    m.insert(make_pair(a,1));  
                }  
                else  
                {  
                    m[a]++;  
                    if(m[a]>maxn)  
                    {  
                        maxn = m[a];  
                    }  
                }  
                a.clear();  
                flag = 0;  
            }  
        }  
        if(flag == 1)  
        {  
            if(m.find(a) == m.end())  
            {  
                m.insert(make_pair(a,1));  
            }  
            else  
            {  
                m[a]++;  
                if(m[a]>maxn)  
                {  
                   maxn = m[a];  
                }  
            }  
        }  
    }  
    printf("%d occurrences\n",maxn);  
    for(map<string,int>::iterator i = m.begin();i!=m.end();i++)  
    {  
        if(i->second == maxn)  
        {  
            printf("%s\n",i->first.c_str());  
        }  

    }  
    return 0;  
}  