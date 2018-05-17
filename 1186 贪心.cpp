#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1000+5;

int n;
int a[maxn], cnt[maxn];
vector<int> vec;

int main() {
    while(scanf("%d", &n) != EOF) {
        vec.clear();
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n; i++) scanf("%d", &cnt[i]);
        for(int i = 0; i < n; i++) while(cnt[i]--) vec.push_back(a[i]);
        sort(vec.begin(), vec.end());
        ll sum = 0;
        int j;
        for(j = vec.size() - 1; j >= 0; j--) {
            sum += vec[j];
            if(sum < 0) break;
        }
        j++;
        sum = 0;
        for(int i = j, d = 1; i < vec.size(); i++, d++) sum += vec[i]*d;
        cout << sum << endl;
    }
    return 0;
}