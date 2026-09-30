class Solution {
public:
    int climbStairs(int n) {
        int a=1, b=2;
        if(n==1 || n==2)
        return n;
       else{
       for(int i=3; i<=n; i++){
        int next= a+b;
        a=b;
        b=next;
       }
       return b;
      }
    }
   
};