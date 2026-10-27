class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> Grid(m, string(n,'#')); 

        for(int i =0; i<m;i++){
            Grid[i][0]= '.';
        }
        for(int j =0; j<n;j++){
            Grid[m-1][j]= '.';
        }
        return Grid;
        
    }
};