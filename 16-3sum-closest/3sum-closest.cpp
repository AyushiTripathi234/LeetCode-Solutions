class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int max_diff = INT_MAX;
        int result_sum;
       for(int i=0 ;i<n-2; i++) {
        int right = n-1;
         int left = i+1;
         while(left < right){
         int sum = nums[i] + nums[left]+ nums[right];
         int diff= abs(sum- target);
         if(diff < max_diff){
         max_diff= diff;
         result_sum = sum;
         }
        if(sum<target)
         left++;
         else if(sum > target)
         right--;
         else
         return sum;
       }
       }
       return result_sum;
    }
};