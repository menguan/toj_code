#include <stdio.h>//懒得自己写了 
#include <iostream>
#include <string>
#include <cstring>
using namespace std; 
int main()
{
 int i, j;
 int nKey;
 char pcSource[1000];
 char pcDest[1000];
 int nLength;
 int nTemp;
 
 while (cin>>nKey)
 {
  if (nKey == 0)
  {
   break;
  }
  cin>>pcDest;
  nLength = strlen(pcDest);
  for (i=0; i<nLength; i++)
  { 
   if (pcDest[i] == '_')
   {
    nTemp = 0;
   }
   else if (pcDest[i] == '.')
   {
    nTemp = 27;
   }
   else
   {
    nTemp = pcDest[i] + 1 - 'a';
   }
   nTemp = (nTemp+i)%28;
   if (nTemp == 0)
   {
    pcSource[(nKey*i)%nLength] = '_';
   }
   else if (nTemp == 27)
   {
    pcSource[(nKey*i)%nLength] = '.';
   }
   else
   {
    pcSource[(nKey*i)%nLength] = 'a'+nTemp-1;
   }
  }
  pcSource[nLength] = '\0';
  cout<<pcSource<<endl;
 }
 return 0;
}
