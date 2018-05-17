#include<iostream>
using namespace std;

const int maxn = 50000+5;

struct jj {
    int pos, x;
}a[maxn];

int main() {
    int n, i, i1, x, top, ans;
    while(scanf("%d", &n) != EOF) {
        int top = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            if(top == 0 || a[top-1].x > x) { // 当前元素小于栈顶则入栈
                a[top].x = x;
                a[top].pos = i;
                top++;
            }
            else { // 依次和栈中元素计算相对距离且取最长的那个
                for(int j = top-1; j >= 0 && a[j].x <= x; j--) {
                    ans = max(ans, i-a[j].pos);
                }
            }
        }
        printf("%d\n", ans);
    }
}