class Solution {
public:   
    int rev(int x) {
        int ans = 0;
        while(x > 0) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long count = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < nums.size(); i++) {
            int diff = nums[i] - rev(nums[i]);

            count = (count + mp[diff]) % mod;
            mp[diff]++;
        }

        return count;
    }
};
