#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int mod = 20140413;
const int maxn = 105;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll x = 1;
        for(int i = 1; i < n; i++) {
            x = x*2%mod;
        }
        cout << x << endl;
    }
    return 0;
}