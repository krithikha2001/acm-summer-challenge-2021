#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	string s;
	cin >> s;										// Reading input from STDIN
	long long step = 0;
    long long carry = 0;

    long long r = 0;
        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back();
            } else {
                int c = 1;
                int j = s.size() - 2;
                s[j + 1] = '0';
                while ((j >= 0) && (c > 0)) {
                    int x = s[j] - '0' + c;
                    c = x / 2;
                    s[j] = (x % 2 == 0) ? '0' : '1';
                    j --;
                }
                if (c > 0) {
                    s = '1' + s;
                }
            }
            r ++;
        }
        cout<<r;
}
