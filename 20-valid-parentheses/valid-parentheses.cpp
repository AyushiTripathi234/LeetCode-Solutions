class Solution {
public:
    bool isValid(string s) {
        int n= s.size();

        stack<char> Stack;
        for(int i= 0; i<n ; i++ ){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
          Stack.push(s[i]);
         }

        else{
        if(Stack.empty()){
            return false;
        }

          else
            if ((s[i] == ')' && Stack.top() != '(') ||
              (s[i] == ']' && Stack.top() != '[') ||
                (s[i] == '}' && Stack.top() != '{')) {
                    return false;
            }
            Stack.pop();
        }
            
          }
         return Stack.empty();
        }
    
};