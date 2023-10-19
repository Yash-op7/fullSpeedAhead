/*
    Time complexity: O(N * M * (2^N))
    Space complexity: O(N * (2^N))

    Where 'N' is the number of cities and 'M' is the number of roads.
*/
#include <bits/stdc++.h>
using namespace std;

long long ml, N;

// Set bits in mask 'm1' represents the subset of cities visited.
// Unset bits in mask 'm2' represents the subset of cities to be visited.
long long get(vector<vector<int>> &g, long long m1,

              long long m2, map<pair<long long, long long>, long long> dp)
{

    // All cities are visited, which can be done in this way.
    // So return 1.
    if (m2 == ml)
    {

        return 1ll;
    }

    // Value of this masks is already computed.
    if (dp.find({m1, m2}) != dp.end())
    {

        return dp[{m1, m2}];
    }

    // Calculate values for new masks using already computed values.
    else
    {

        long long ans = 0;

        // Travel the cities one by one and recur for remaining cities.
        for (int i = 0; i < N; i++)
        {

            // If i-th bit of mask m1 is set but i-th bit of mask m2 is unset.
            if (m1 & (1 << i) && !(m2 & (1 << i)))
            {

                // Set i-th bit of mask 'm2'. i.e, When we include this city.
                m2 ^= (1 << i);

                long long cc = m1;

                for (auto j : g[i])
                {

                    // Available cities to start from.
                    cc |= (1 << j);
                }

                // Recur with updated masks
                ans += get(g, cc, m2, dp);
                ans %= 1000000007;

                // Backtrack. Unset i-th bit of mask 'm2'
                m2 ^= (1 << i);
            }
        }

        // We solved this subproblem so return answer.
        return dp[{m1, m2}] = ans;
    }
}

int numWays(int n, vector<vector<int>> &cities, int m)
{

    N = n;
    vector<vector<int>> g(N);

    // Set all N bits. i.e, Mask representing all cities as visited.
    ml = (1 << N) - 1;

    map<pair<long long, long long>, long long> dp;

    // Create graph
    for (int i = 0; i < m; i++)
    {

        int t1 = cities[i][0], t2 = cities[i][1];
        t1--;
        t2--;

        // Roads are bidirectional so, add reverse edge too.
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    long long ans = 0;

    // Iterate i in 0 to N i.e, from city 0 to city n.
    for (int i = 0; i < N; i++)
    {

        // Get the number of ways starting from this city
        // (1 << i) set the i-th bit. Denoting the current city.
        // 0 denotes the subset of cities to be visited. As all the cities are yet to be visited
        // so not element in this subset.
        ans += get(g, 1 << i, 0, dp);
        ans %= 1000000007;
    }

    // Finally, return answer.
    return (int)ans;
}
