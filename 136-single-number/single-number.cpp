class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int n= nums.size();
      int d=0;
      for(int i=0; i<n; i++){
          d= d^nums[i];
         } 
         return d; 
    }
};