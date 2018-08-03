#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int k, t;
int beat[52][52];
int vis[52];
int use[52];
const char pai[52][3] = {
  "2C", "2D", "2S", "2H",
  "3C", "3D", "3S", "3H",
  "4C", "4D", "4S", "4H",
  "5C", "5D", "5S", "5H",
  "6C", "6D", "6S", "6H",
  "7C", "7D", "7S", "7H",
  "8C", "8D", "8S", "8H",
  "9C", "9D", "9S", "9H",
  "TC", "TD", "TS", "TH",
  "JC", "JD", "JS", "JH",
  "QC", "QD", "QS", "QH",
  "KC", "KD", "KS", "KH",
  "AC", "AD", "AS", "AH"};

int getNum(char *str) {
  for(int i = 0; i < 52; i++) {
    if(strcmp(pai[i], str) == 0)
      return i;
  }
  return -1;
}

int find(int a) {
  for(int i = 0; i < 52; i++) {
    if(beat[a][i] && vis[i] == 0) {
      vis[i] = 1;
      if(use[i] == -1 || find(use[i])) {
        use[i] = a;
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  cin>>t;
  while(t--) {
    cin>>k;
    char adam[26][3];
    char eve[26][3];
    for(int i = 0; i < k; i++)
      cin>>adam[i];
    for(int i = 0; i < k; i++)
      cin>>eve[i];
    memset(beat, 0, sizeof(beat));
    for(int i = 0; i < k; i++) {
      for(int j = 0; j < k; j++) {
        int p1 = getNum(adam[i]);
        int p2 = getNum(eve[j]);
        if(p1 < p2)
          beat[p1][p2] = 1;
      }
    }
    memset(use, -1, sizeof(use));
    int ans = 0;
    for(int i = 0; i < 52; i++) {
      memset(vis, 0, sizeof(vis));
      ans += find(i);
    }
    cout<<ans<<endl;
  }
}
