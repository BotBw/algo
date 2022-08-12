#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10;

bool mmap[maxn][maxn];

int m, n;

bool vis[maxn][maxn];

int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

void dfs(int i, int j) {
    vis[i][j] = 1;
    for(int k = 0; k < 8; k++) {
        int ii = i + dx[k];
        int jj = j + dy[k];
        if(mmap[ii][jj] && !vis[ii][jj]) {
            dfs(ii, jj);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++) {
            mmap[i][j] = (s[j-1] == 'W');
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if (mmap[i][j] && !vis[i][j]) {
                ans ++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}