/*
 * @Samaritan_infi
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 105;

inline int read()
{
    int x=0,t=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}

int a[maxn], t[maxn], m[maxn];

int dp[2000];

int main() {
    int kase = read();
    while(kase --) {
        int n = read(), V = read();
        for(int i = 0; i < n; i ++) {
            a[i] = read(), t[i] = read(), m[i] = read();
        }
        memset(dp, 0, sizeof dp);

        for(int j = 0; j < n; j ++) {
            for(int k = 1; k <= m[j]; k ++) {
                for(int i = V; i >= a[j]; i --) {
                    dp[i] = max(dp[i], dp[i - a[j] ] + t[j]);
                }
            }
        }
        printf("%d\n", dp[V]);
    }
    return 0;
}