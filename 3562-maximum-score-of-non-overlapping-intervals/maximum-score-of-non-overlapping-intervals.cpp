class Solution {
public:


    struct Node {
        long long score;
        vector<int> indices;
    };

    // Returns true if a is better than b.
    // Higher score is better.
    // If scores are equal, lexicographically smaller indices are better.
    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return lexicographical_compare(
            a.indices.begin(), a.indices.end(),
            b.indices.begin(), b.indices.end()
        );
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
       
   
           int n = intervals.size();

        // Store: {left, right, weight, original_index}
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by left endpoint.
        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[0] != y[0])
                return x[0] < y[0];

            return x[1] < y[1];
        });

        // next[i] = first index j such that a[j][0] > a[i][1]
        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            next[i] = lo;
        }

        // dp[i][k]:
        // best answer considering intervals [i ... n-1]
        // and choosing at most k intervals.
        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        // Base case: choosing 0 intervals gives score 0.
        for (int i = 0; i <= n; i++) {
            for (int k = 0; k <= 4; k++) {
                dp[i][k] = {0, {}};
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Option 1: skip this interval.
                Node skip = dp[i + 1][k];

                // Option 2: take this interval.
                Node take = dp[next[i]][k - 1];

                take.score += a[i][2];
                take.indices.push_back(a[i][3]);

                // The indices need to be sorted because the final answer
                // must be compared lexicographically.
                sort(take.indices.begin(), take.indices.end());

                // Pick the better option.
                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[0][4].indices;
    }
};

  