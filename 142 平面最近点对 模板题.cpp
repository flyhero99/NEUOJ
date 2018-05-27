#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

const int maxn = 100005;

struct Point {
    double x, y;
};

Point p[maxn];
int n;

double getDistance(Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp(Point a, Point b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

double getDistance(int l, int r) {
    if(l >= r) return inf;
    if(l+1 == r) return getDistance(p[l], p[r]);
    int m = (l+r) >> 1;
    double d = min(getDistance(l, m), getDistance(m+1, r));
    for(int i = m; i >= l; i--) {
        for(int j = m+1; j <= r && p[j].x-p[i].x < d; j++) {
            double tmp = getDistance(p[i], p[j]);
            if(tmp < d) d = tmp;
        }
    }
    return d;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }
        sort(p, p+n, cmp);
        double ans = getDistance(0, n-1);
        printf("%.3lf\n", ans);
    }
    return 0;
}