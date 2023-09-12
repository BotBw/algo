class Solution {
public:
    // 3 2 4 mod=2, k = 1
    // 1 0 0
    // 1 1 1
    // 0: 0 0 0
    // 1: 1 1 
    
    
    // 3 1 9 6 mod=3 k=0
    // 1 0 1 1
    // 1 1 2 3
    // 
    int mod(int a, int b) {
        a = a % b;
        if(a < 0) a += b;
        return a;
    }
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> cnt;
        int n = nums.size();
        int cur = 0;
        long long ans = 0;
        cnt[0] = 1;
        for(int i = 0; i < n; i++) {
            cur += (nums[i] % modulo) == k;
            cur %= modulo;
            ans += cnt[mod(cur - k, modulo)];
            cnt[cur] += 1;
        }
        return ans;
    }
};
