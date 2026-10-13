class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
    int n= nums.size();
    long long ans=0;
    vector<int> square(n);
    for(int i = 0; i < n; i++){
        square[i]= nums[i]*nums[i];
    } 
    sort(square.begin(), square.end());
    for (int i = 0; i < n; i++) {
            if (i <(n / 2)) {
                ans -= square[i];
            }
             else {
                ans += square[i];
            }
        }
    return ans;
    }
};