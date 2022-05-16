#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int a[N];

int grp[N][N];
int cnt[N];

int n;
int ans;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

bool check(int ia, int ig) {
    for(int i = 1; i <= cnt[ig]; i++) {
        if(gcd(a[ia], grp[ig][i]) != 1) return false;
    }
    return true;
}

void dfs(int ia, int ig) {
    // printf("%d:%d\n",ia,ig);
    if(ig >= ans) return;
    if(ia == n + 1) {
        ans = ig;
        return;
    }
    for(int i = 1; i <= ig; i++) {
        if(check(ia, i)) {
            cnt[i]++;
            grp[i][cnt[i]] = a[ia];
            dfs(ia+1, ig);
            cnt[i]--;
        }
    } 
    cnt[ig+1] = 1;
    grp[ig+1][1] = a[ia];
    dfs(ia, ig + 1);
    cnt[ig+1] = 0;
}


int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    ans = n;
    dfs(1, 0);
    cout << ans;
    return 0;
}
