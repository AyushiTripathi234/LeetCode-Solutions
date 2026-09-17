class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        vector<int> best(n, INT_MAX);

        unordered_map<long long, int> mp;
        mp[0] = -1;

        long long sum = 0;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (i > 0)
                best[i] = best[i - 1];

            if (mp.count(sum - target)) {
                int j = mp[sum - target];
                int len = i - j;

                if (j >= 0 && best[j] != INT_MAX) {
                    ans = min(ans, len + best[j]);
                }

                best[i] = min(best[i], len);
            }

           
            mp[sum] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

   
  