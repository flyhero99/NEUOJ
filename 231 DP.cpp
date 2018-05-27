/*
 * @Samaritan_infi
 */

#include<bits/stdc++.h>
using namespace std;

const int maxn = 2005;

inline int read() {
    int x = 0, t = 1; char ch = getchar();
    while((ch<'0' || ch>'9') && ch != '-') ch = getchar();
    if(ch == '-') t = -1, ch = getchar();
    while(ch<='9' && ch>='0') x=x*10+ch-48, ch=getchar();
    return x*t;
}

int pic[maxn][maxn];
int h[maxn][maxn];
int ll[maxn][maxn], rr[maxn][maxn];

void show(int a[][maxn], int n, int m) {
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++) {
            cout << a[i][j] << " ";
        }cout << endl;
    }
}

int main() {
    //int kase = read();
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        memset(h, 0, sizeof(h));
        memset(ll, 0, sizeof(ll));
        memset(rr, 0, sizeof(rr));
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                scanf("%d", &pic[i][j]);
                ll[i][j] = j;
                rr[i][j] = j;
            }
        }
        for(int i = 0; i < m; i ++) if(pic[n - 1][i]) h[n - 1][i] = 1;

        for(int i = n - 2; i >= 0; i --) {
            for(int j = 0; j < m; j ++) {
                if(! pic[i][j]) h[i][j] = 0;
                else h[i][j] = h[i + 1][j] + 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(! pic[i][j]) continue;
                int l = j, r = j;
                while(l >= 0 && h[i][l] >= h[i][j]) {
                    l = ll[i][l];
                    if(l == ll[i][l]) l --;
                    //cout << l << " >" << endl;
                }
                l ++;
                ll[i][j] = l;

                while(r < m && h[i][r] >= h[i][j]) {
                    r = rr[i][r];
                    if(r == rr[i][r]) r ++;
                    //cout << r << endl;
                }
                r --;
                rr[i][j] = r;
                ans = max(ans, (r - l + 1) * h[i][j]);

            }
        }
//        show(ll, n, m);
//        cout << endl;
//        show(rr, n, m);
        printf("%d\n", ans==0 ? -1 : ans);
    }
    return 0;
}
/*
4 4
1 1 1 1
0 1 1 0
0 1 1 0
0 1 0 0
4 5
0 0 1 1 0
1 1 0 0 1
1 1 0 0 1
1 1 0 0 1
*/