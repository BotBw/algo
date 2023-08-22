class Solution {
public:
    int longestEqualSubarray(vector<int>& a, int k) {
        unordered_map<int, deque<int>> pre;
        int n = a.size();
        int ans = 1;
        for(int i = 0; i < n; i++) {
            if(pre.count(a[i])) {
                auto &q = pre[a[i]];
                while(q.size() && i - q.front() - q.size() > k) q.pop_front();
                if(q.size()) ans = max(ans, (int)q.size() + 1);
            }
            pre[a[i]].push_back(i);
        }
        return ans;
    }
};
