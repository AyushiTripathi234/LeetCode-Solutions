class Solution {
public:
    int maxVowels(string s, int k) {
    
      int low = 0;
      int n = s.size();
      int res= INT_MIN;
      int count =0;
      int high= 0;
      for(high =0 ; high < n; high++){

       if(s[high]=='a' || s[high]=='e' || s[high]=='i' || s[high]=='o' || s[high]=='u')
      count++;
    
        if(high - low + 1 > k) {
                if(s[low]=='a' || s[low]=='e' ||
                   s[low]=='i' || s[low]=='o' ||
                   s[low]=='u') {
                    count--;
                }
                low++;
            }
        
     
       
       if(high -low +1==k){
        res= max(res,count);
       }
      }
      return res;
    }
};