bool isValid(int x1, int y1, int x2, int y2, int n) {

    if (n == x1 || n == x2 || n == y1 || n == y2) {

        return false;

    }

    return true;

}

 

int greedyJewellerHelper(int x1, int y1, int x2, int n, vector<vector<int>> &mat, vector<vector<vector<int>>> &dp) {

 

    // Find the y coordinate of the second path.

    int y2 = x1 + y1 - x2;

 

    if (!isValid(x1, y1, x2, y2, n)) {

        return -99999;

    }

 

    int &ans = dp[x1][y1][x2];

 

    // Check if the current positions are already visited.

    if (ans != -99999) {

        return ans;

    }

 

    // Base Case.

    if (mat[x1][y1] == -1 || mat[x2][y2] == -1) {

        return -99999;

    }

 

    if (x1 == n - 1 and y1 == n - 1) {

        return mat[x1][y1];

    }

 

    // Check if gold is present at current position for first path.

    ans = mat[x1][y1];

 

    // Check if gold is present at current position for second path.

    if (y1 != y2) {

        ans += mat[x2][y2];

    }

 

    // Recursion call.

    ans += max({greedyJewellerHelper(x1, y1 + 1, x2 + 1, n, mat, dp), greedyJewellerHelper(x1 + 1, y1, x2 + 1, n, mat, dp), greedyJewellerHelper(x1, y1 + 1, x2, n, mat, dp), greedyJewellerHelper(x1 + 1, y1, x2, n, mat, dp)});

    return ans;

}

 

int greedyJeweller(int n, vector<vector<int>> &mat) {

 

    // Function call.

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -99999)));

    return max(0, greedyJewellerHelper(0, 0, 0, n, mat, dp));

}