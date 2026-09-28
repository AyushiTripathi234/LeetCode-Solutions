class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int counter=0;
        int maxCounter=0;
        for(int i= 0; i< n; i++){
            if(s[i]=='('){
                counter++;
            }
            else if(s[i]==')'){
                counter--;
            }
            maxCounter= max(maxCounter,counter);
        }
        return maxCounter;
    }
};