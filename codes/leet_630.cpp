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
class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
        
    int scheduleCourse(vector<vector<int>>& a) {
        int n = a.size();
        
        sort(a.begin(), a.end(), cmp);
        
        priority_queue<int> q;
        
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            q.push(a[i][0]);
            sum += a[i][0];
            if(sum > a[i][1]) {
                sum -= q.top();
                q.pop();
            }
        }
        
        return q.size();
    }
};
