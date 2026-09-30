class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        if(num<=9){
            return num;
        }
        else if(num % 9!=0){
            int d= num % 9;
            return d;
        }
        else{
            return 9;
        }
   
    }
};