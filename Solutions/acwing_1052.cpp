#ifndef FREQ_H
#define FREQ_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)

#endif
#include <bits/stdc++.h>
using namespace std;

const int N = 55, mod = 1e9 + 7;

int dp[N][N], n, ne[N];

char str[N];

int main(){
    cin >> n >> str;
    int m = strlen(str);

    for(int i = 0, j = 1; j < n; j++){
        while(i && str[i] != str[j]) i = ne[i - 1];
        if(str[i] == str[j]) ++i;
        ne[j] = i;
    }

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 'a'; k <= 'z'; k++){
                int u = j;
                while(u && k != str[u]) u = ne[u - 1];
                if(k == str[u]) ++u;
                dp[i][u] = (dp[i][u] + dp[i - 1][j]) % mod;
            }

    int ans = 0;
    for(int i = 0; i < m; i++)  ans = (ans + dp[n][i]) % mod;
    cout << ans;
}
