#include<iostream>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string temp;
    int n;
    cin>>n;
    getline(cin,temp);
    while(n--)
    {
         vector<int>digit;
         getline(cin,temp);
         for(int i=0;i<temp.size();i+=2)
           digit.push_back(temp[i]-'0');
         if(digit.size()==2)
         {  
           cout<<digit[1]-digit[0]<<endl;
           continue;
         }
         if(digit.size()%2==0)
         {
           int minn=1010101010;
           for(int i=0;i+1<digit.size();i++)
           {
               if(digit[i]!=0&&digit[i+1]-digit[i]<minn)
               {
                      minn=digit[i+1]-digit[i];
               }
           }
         
         int minnn=10101010;
         for(int i=0;i+1<digit.size();i++)
         {
              if(digit[i]!=0&&digit[i+1]-digit[i]==minn)
              {
                  vector<int>left;
                  vector<int>right;
                  left.push_back(digit[i]);
                  right.push_back(digit[i+1]);
                  for(int j=0,k=digit.size()-1;j<k;j++,k--)
                  {
                      if(j==i||j==i+1)
                      {
                         k++;
                         continue;
                      }
                      if(k==i||k==i+1)
                      {
                         j--;
                         continue;
                      }
                      left.push_back(digit[k]);
                      right.push_back(digit[j]);
                  }
                  int a=0,b=0;
                  for(int j=0;j<left.size();j++)
                  {
                      a=10*a+left[j];
                  }
                  for(int j=0;j<right.size();j++)
                  {
                      b=b*10+right[j];
                  }
                  if(minnn>b-a)
                    minnn=b-a;
              }
         } 
         cout<<minnn<<endl;
         }
         else
         {
             vector<int>left;
             vector<int>right;
             int i;
             if(digit[0]==0)
             {
                i=1;
                right.push_back(digit[1]);
             }
             else
             {
                i=0;
                right.push_back(digit[0]);
             }
             for(int j=0,k=digit.size()-1;j<k;j++,k--)
                  {
                      if(j==i)
                      {
                         k++;
                         continue;
                      }
                      if(k==i)
                      {
                         j--;
                         continue;
                      }
                      left.push_back(digit[k]);
                      right.push_back(digit[j]);
                  }
                  int a=0,b=0;
                  for(int j=0;j<left.size();j++)
                  {
                      a=10*a+left[j];
                  }
                  for(int j=0;j<right.size();j++)
                  {
                      b=b*10+right[j];
                  }
                  cout<<b-a<<endl;
             }
         }
    }   
                 
                                                                                                                                                      
                  
