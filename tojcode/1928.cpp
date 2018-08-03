#include<iostream> 
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[500000],num,minute,second,speed,inclination,b[3];

bool isStart(int pos) {
    if ((a[pos] == 4 || a[pos] == 5) && (a[pos+1] == 4 || a[pos+1] == 5)
     && (a[pos+2] == 0 || a[pos+2] == 1) && (a[pos+3] == 8 || a[pos+3] == 9))
        return true;
    else return false;
}

void get(int pos) {//每次读取六个数 
    for (int i = 0; i < 3; i++){
        if (a[pos] == 4 || a[pos] == 5)
            b[i] = 0;
        else b[i] = 1;
        pos += 2;
    }
}

void solve(int pos) {
    minute = (pos / 3 / 60);//There will be three samples per second
    second = (pos / 3 % 60);
    if (minute < 10)
        cout << "0" << minute;
    else cout << minute;
    cout << ":";
    if (second < 10)
        cout << "0" << second;
    else cout << second;
    pos += 4;
    get(pos);
    pos += 6;
    speed = b[2] * 4 + b[1] * 2 + b[0];
    get(pos);
    inclination = b[2] * 4 + b[1] * 2 +b[0];
    cout << " Speed " << speed << " Inclination " << inclination << endl;
}

int main() {
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cout << "Program " << i << endl;
        for (num = 0; ;) {
            cin >> a[num];
            if (a[num] == 10)
                break;
            else num++;
        }
        for (j = 0; j < num - 15;)
            if (isStart(j)) {
                solve(j);
                j += 16;
            }
            else j++;
    }
}
