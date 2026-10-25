class Solution {
public:
    int findNumbers(vector<int>& nums) {
       int n = nums.size();
       int ans= 0;
     
       for(int i = 0; i< n; i++){
        int a= nums[i];
         int count= 0;
        while(a!=0){
            int d=a% 10;
            count++;
            a= a/10;
            
        }
        if(count%2 == 0)
        ans++;
       } 
       return ans;
    }
};