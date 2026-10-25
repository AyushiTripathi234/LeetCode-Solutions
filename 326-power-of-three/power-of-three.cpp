class Solution {
public:
    bool isPowerOfThree(int n) {
        //3^19 = 1162261467
        if(n > 0 && 1162261467 % n == 0){
            return true;
        }
        return false;
    }
};