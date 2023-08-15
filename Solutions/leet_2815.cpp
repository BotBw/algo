class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int mx = -1;
        for(int i = 0; i < n; i++) {
            int ai = nums[i];
            int mxi = 0;
            while(ai) {
                mxi = max(mxi, ai % 10);
                ai /= 10;
            }
            for(int j = i + 1; j < n; j++) {
                int aj = nums[j];
                int mxj = 0;
                while(aj) {
                    mxj = max(mxj, aj % 10);
                    aj /= 10;
                }
                if(mxi == mxj) {
                    mx = max(mx, nums[i] + nums[j]);
                }
            }
        }
        return mx;
    }
};
