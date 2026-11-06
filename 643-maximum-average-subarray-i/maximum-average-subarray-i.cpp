class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       int n = nums.size();
       int low=0;
       int high = k-1;
       double sum = 0.0;
       double res = INT_MIN;
       for(int i= low; i<= high ; i++){
       sum= sum + nums[i];
       } 
       double avg = sum/k;
       res = avg;

       while(high<n){
       
        high++;
        low++;
        sum = sum - nums[low-1];
        if(high == n)
        break;
        sum= sum+ nums[high];
        avg= sum/k;
         res= max(res,avg);
       }
       return res;
    }
};