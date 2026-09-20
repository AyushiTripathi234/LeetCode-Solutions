class Solution {
public:
    int reverseDegree(string s) {
        
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
           
            // a -> 26, b -> 25, ..., z -> 1
            int reversePos = 'z' - s[i] + 1;

            // String position is 1-indexed
            int position = i + 1;

            ans += reversePos * position;
        }

        return ans;
    }
};

        

 
    