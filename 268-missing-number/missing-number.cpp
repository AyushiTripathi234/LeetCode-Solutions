class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int d=0;
        for(int i= 1; i<=n; i++){
          d=d^ (i^nums[i-1]);
        }
        return d;
    }
};