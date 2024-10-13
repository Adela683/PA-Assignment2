#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

ifstream fin("numarare.in");
ofstream fout("numarare.out");
const int MOD = 1e9 + 7;

// https://www.geeksforgeeks.org/topological-sorting/
void topologicalSort(int n,
                     const vector<vector<int>>& graph, vector<int>& order) {
    vector<int> inDegree(n, 0);

    for (int i = 1; i <= n; ++i) {
        for (int neigh : graph[i]) {
            inDegree[neigh]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int neigh : graph[node]) {
            --inDegree[neigh];
            if (inDegree[neigh] == 0) {
                q.push(neigh);
            }
        }
    }
}

int main() {
    int N, M;
    fin >> N >> M;

    vector<vector<int>> graph1(N + 1);
    vector<vector<int>> graph2(N + 1);

    for (int i = 0; i < M; i++) {
        int x, y;
        fin >> x >> y;
        graph1[x].push_back(y);
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        fin >> x >> y;
        graph2[x].push_back(y);
    }

    vector<unordered_set<int>> graph2_set(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int v : graph2[i]) {
            graph2_set[i].insert(v);
        }
    }

    vector<int> order;
    topologicalSort(N, graph1, order);

    vector<long long> dp(N + 1, 0);
    dp[N] = 1;

    for (int i = order.size() - 1; i >= 0; --i) {
        int currNode = order[i];
        for (int neigh : graph1[currNode]) {
            if (graph2_set[currNode].count(neigh)) {
                dp[currNode] = (dp[currNode] + dp[neigh]) % MOD;
            }
        }
    }

    fout << dp[1] << '\n';
    return 0;
}
