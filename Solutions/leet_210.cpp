#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
int max(int n,...) {va_list args;va_start(args, n);int ret = INT_MIN;FOR(i, 0, n-1)ret = max(ret, va_arg(args, int));va_end(args);return ret;}
int min(int n,...) {va_list args;va_start(args, n);int ret = INT_MAX;FOR(i, 0, n-1)ret = min(ret, va_arg(args, int));va_end(args);return ret;}
#define DEBUG // if debugging codes are contained, delete this line before submitting

class Solution {
public:
    int inD[2005] = {0};
    bool graph[2005][2005] = {0};
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> ans;
        for(auto e:pre) {
          graph[e[1]][e[0]] = 1;
          inD[e[0]]++;
        }
        queue<int> q;
        FOR(i, 0, numCourses-1) if(!inD[i]) q.push(i);
        while(!q.empty()) {
          int x = q.front();
          q.pop();
          ans.push_back(x);
          FOR(i, 0, numCourses-1) {
            if(graph[x][i]) {
              inD[i]--;
              if(!inD[i]) q.push(i);
            }
          }
        }
        return ans.size() == numCourses ? ans : vector<int>();
    }
};