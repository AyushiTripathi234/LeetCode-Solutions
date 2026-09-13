class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
       
        int n = img1.size();

        vector<pair<int, int>> a, b;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j])
                    a.push_back({i, j});

                if (img2[i][j])
                    b.push_back({i, j});
            }
        }

        unordered_map<long long, int> freq;

        int ans = 0;

        for (auto [r1, c1] : a) {
            for (auto [r2, c2] : b) {
                int dr = r2 - r1;
                int dc = c2 - c1;

                // Encode (dr, dc) into one long long
                long long key = ((long long)dr << 32) ^ (unsigned int)dc;

                ans = max(ans, ++freq[key]);
            }
        }

        return ans;
    }
};

  