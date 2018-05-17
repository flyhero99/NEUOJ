#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 10000000+5;

int n;
int a[maxn] = {0, 1, 2, 4, 8, 16, 23, 46, 29, 58, 116, 223, 446,
               289, 578, 1156, 1223, 2446, 2489, 4789, 5789, 11578,
               12356, 12247, 24449, 48889, 77789, 155578, 111356, 122227, 244445};

int main() {
    int t; scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++) {
        scanf("%d", &n);
        printf("Case #%d: ", cas);
        if(n <= 30) printf("%d\n", a[n]);
        else {
            n -= 24;
            if(n%6 == 0) printf("%d\n", a[30]);
            else printf("%d\n", a[n%6+24]);
        }
    }
    return 0;
}