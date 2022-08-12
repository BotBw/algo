#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
int max(int n,...) {va_list args;va_start(args, n);int ret = INT_MIN;FOR(i, 0, n-1)ret = max(ret, va_arg(args, int));va_end(args);return ret;}
int min(int n,...) {va_list args;va_start(args, n);int ret = INT_MAX;FOR(i, 0, n-1)ret = min(ret, va_arg(args, int));va_end(args);return ret;}

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 1) continue;
            int pre = i == 0 ? i : i-1;
            int nxt = i == flowerbed.size()-1 ? i : i+1;
            if(flowerbed[pre] == 0 && flowerbed[nxt] == 0) {
                n--;
                flowerbed[i] = 1;
            }
        }
        return n <= 0;
    }
};

int main() {

    return 0;
}
