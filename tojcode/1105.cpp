#include <iostream>
#include <stdio.h> 
#include <cstring>
using namespace std; 
int f[27], g[27][27]; 
void product_g()
{
  for(int i = 1; i < 27; i++) 
  { 
 for(int j = 2; j < 27; j++) 
  { 
  g[i][j]=0; 
  } 
  g[i][1]=1; 
  } 
for(int k = 1; k <= 26; k++) 
{
for(int i = 1; i <= 26; i++) 
{ 

for(int j = i + 1; j <= 26; j++) 
{ 
if(26 - j + 1 < k - 1) 
break; 

g[i][k] += g[j][k-1]; 
} 
}
}

} void product_f()
{ 
product_g(); 
for(int k = 1; k <= 26; k++) 
{ 
int sum = 0; 
for(int i = 1; i <= 26; i++) 
{ 
if(26 - i + 1 < k) 
break; 

sum += g[i][k]; 
} 
f[k] = sum; 

}
} int main()
{ 
char word[10]; 
int len, tmp, last; 
bool flag; 
product_f(); 
while(cin >> word) 
{ 
flag = true; 
len = strlen(word); 
for(int i = 0; i < len; i++) 
{ 
for(int j = i + 1; j < len; j++) 
if(word[i] >= word[j]) 
{ 
flag = false; 
break; 
}
} 
if(flag) 
{ 
int k, index = 0; 
if(len == 1)
index = word[0] - 'a' + 1; 
else 
{ 
for(k = 1; k < len; k++) 
index += f[k]; 
k = len; 
last = 0; 
for(int i = 0; i < len; i++) 
{ 
tmp = word[i] - 'a' + 1; 
for(int j = last + 1; j < tmp; j++) 
index += g[j][k]; 

k--; 
last=tmp; 
} 
index++; 
} 
cout << index << endl; 
} 
else 
cout << "0" << endl;
}

return 0;
}