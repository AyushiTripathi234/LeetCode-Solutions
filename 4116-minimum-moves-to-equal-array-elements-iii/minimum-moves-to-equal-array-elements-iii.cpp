class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
       int maxi = nums[0];

    for(int i = 1; i < n; i++) {
        if(nums[i] > maxi) {
            maxi = nums[i];
        }
    }
      int count = 0;
      for(int i =0; i< nums.size(); i++){
        while(nums[i] <maxi) {
            nums[i]++;
            count++;
        }
      }
      return count;
    }
};