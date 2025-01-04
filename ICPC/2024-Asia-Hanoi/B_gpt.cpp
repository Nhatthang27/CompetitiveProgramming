#include <bits/stdc++.h>
using namespace std;

class BulletTrainSolver
{
private:
    int n, k, m;
    vector<vector<int>> dist;
    vector<pair<int, int>> important_pairs;

    // Calculate cost of a route
    int getRouteCost(const vector<int> &route)
    {
        int cost = 0;
        for (int i = 0; i < route.size() - 1; i++)
        {
            cost += dist[route[i] - 1][route[i + 1] - 1];
        }
        return cost;
    }

    // Check if a route covers a pair of cities
    bool routeCoversPair(const vector<int> &route, int u, int v)
    {
        bool hasU = false, hasV = false;
        for (int city : route)
        {
            if (city == u)
                hasU = true;
            if (city == v)
                hasV = true;
            if (hasU && hasV)
                return true;
        }
        return false;
    }

    // Check which pairs are covered by a route
    vector<bool> getCoveredPairs(const vector<int> &route)
    {
        vector<bool> covered(m, false);
        for (int i = 0; i < m; i++)
        {
            auto [u, v] = important_pairs[i];
            if (routeCoversPair(route, u, v))
            {
                covered[i] = true;
            }
        }
        return covered;
    }

    // Generate all possible routes starting from a city
    void generateRoutes(int start, int len, vector<int> &current, vector<bool> &used,
                        vector<vector<int>> &routes)
    {
        if (len > k)
            return;

        if (len >= 2)
        {
            // Consider completing the cycle back to start
            vector<int> cycle = current;
            cycle.push_back(start);
            if (cycle.size() <= k)
            {
                routes.push_back(cycle);
            }
        }

        if (len == k)
            return;

        for (int next = 1; next <= n; next++)
        {
            if (!used[next])
            {
                used[next] = true;
                current.push_back(next);
                generateRoutes(start, len + 1, current, used, routes);
                current.pop_back();
                used[next] = false;
            }
        }
    }

public:
    void solve()
    {
        // Read input
        cin >> n >> k >> m;

        // Read distance matrix
        dist.assign(n, vector<int>(n));
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                cin >> dist[i][j];
                dist[j][i] = dist[i][j];
            }
        }

        // Read important pairs
        important_pairs.resize(m);
        for (int i = 0; i < m; i++)
        {
            cin >> important_pairs[i].first >> important_pairs[i].second;
        }

        // Generate all possible cyclic routes
        vector<vector<int>> all_routes;
        for (int start = 1; start <= n; start++)
        {
            vector<int> current = {start};
            vector<bool> used(n + 1, false);
            used[start] = true;
            generateRoutes(start, 1, current, used, all_routes);
        }

        // Find optimal combination of routes
        int best_cost = INT_MAX;
        vector<vector<int>> best_solution;

        int max_routes = m; // We won't need more routes than pairs
        vector<bool> global_covered(m, false);
        vector<vector<int>> current_solution;

        function<void(int, int)> search = [&](int current_cost, int route_idx)
        {
            // Check if we have a valid solution
            bool all_covered = true;
            for (bool covered : global_covered)
            {
                if (!covered)
                {
                    all_covered = false;
                    break;
                }
            }

            if (all_covered && current_cost < best_cost)
            {
                best_cost = current_cost;
                best_solution = current_solution;
                return;
            }

            if (current_cost >= best_cost || current_solution.size() >= max_routes)
            {
                return;
            }

            // Try adding each possible route
            for (int i = route_idx; i < all_routes.size(); i++)
            {
                const auto &route = all_routes[i];
                vector<bool> new_covered = getCoveredPairs(route);

                // Check if this route adds any new coverage
                bool adds_coverage = false;
                for (int j = 0; j < m; j++)
                {
                    if (!global_covered[j] && new_covered[j])
                    {
                        adds_coverage = true;
                        break;
                    }
                }

                if (!adds_coverage)
                    continue;

                // Add route
                int route_cost = getRouteCost(route);
                current_solution.push_back(route);
                vector<bool> old_covered = global_covered;

                // Update coverage
                for (int j = 0; j < m; j++)
                {
                    global_covered[j] = global_covered[j] | new_covered[j];
                }

                // Recurse
                search(current_cost + route_cost, i + 1);

                // Backtrack
                current_solution.pop_back();
                global_covered = old_covered;
            }
        };

        search(0, 0);

        // Output solution
        cout << best_cost << " " << best_solution.size() << "\n";
        for (const auto &route : best_solution)
        {
            cout << route.size();
            for (int city : route)
            {
                cout << " " << city;
            }
            cout << "\n";
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    BulletTrainSolver solver;
    while (test_cases--)
    {
        solver.solve();
    }

    return 0;
}