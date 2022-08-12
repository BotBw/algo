#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
int max(int n,...) {va_list args;va_start(args, n);int ret = INT_MIN;FOR(i, 0, n-1)ret = max(ret, va_arg(args, int));va_end(args);return ret;}
int min(int n,...) {va_list args;va_start(args, n);int ret = INT_MAX;FOR(i, 0, n-1)ret = min(ret, va_arg(args, int));va_end(args);return ret;}

#ifdef LEET
class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i = 0; i < word.size(); i++) {
            if('a' <= word[i] && word[i] <= 'z') goto check2;
        }
        return true;
    check2:
        for(int i = 0; i < word.size(); i++) {
            if('A' <= word[i] && word[i] <= 'Z') goto check3;
        }
        return true;
    check3:
        if('a' <= word[0] && word[0] <= 'z') return false;
        for(int i = 1; i < word.size(); i++) {
            if('A' <= word[i] && word[i] <= 'Z') return false;
        }
        return true;
    }
};
#else
int main() {

    return 0;
}
#endif