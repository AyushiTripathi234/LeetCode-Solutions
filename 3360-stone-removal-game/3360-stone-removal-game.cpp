class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10)
            return false;

        int stones = 10;
        bool alice = true;

        while(n >= stones) {
            n -= stones;
            stones--;

            alice = !alice;
        }

        return !alice;
    }
};