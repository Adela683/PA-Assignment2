#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("drumuri.in");
ofstream fout("drumuri.out");

const int MAXN = 100005;
const long long INF = 1e18;

struct Edge {
    int to;
    int cost;
};

// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
void Dijkstra(int start, vector<long long>& dist,
              const vector<vector<Edge>>& graph) {
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;

    dist[start] = 0;

    pq.push({0, start});

    while (!pq.empty()) {
        int node = pq.top().second;
        long long distance = pq.top().first;
        pq.pop();

        if (distance > dist[node]) {
            continue;
        }

        for (const Edge& edge : graph[node]) {
            long long newDistance = dist[node] + edge.cost;

            if (newDistance < dist[edge.to]) {
                dist[edge.to] = newDistance;

                pq.push({newDistance, edge.to});
            }
        }
    }
}

int main() {
    long long minCost = INF;
    int N, M, X, Y, Z, x, y, z;
    fin >> N >> M;

    vector<vector<Edge>> graph(MAXN);
    vector<vector<Edge>> reverseGraph(MAXN);

    for (int i = 0; i < M; i++) {
        fin >> x >> y >> z;
        graph[x].push_back({y, z});
        reverseGraph[y].push_back({x, z});
    }

    fin >> X >> Y >> Z;

    vector<long long> dist_x(MAXN, INF);
    vector<long long> dist_y(MAXN, INF);
    vector<long long> dist_z(MAXN, INF);

    Dijkstra(X, dist_x, graph);
    Dijkstra(Y, dist_y, graph);
    Dijkstra(Z, dist_z, reverseGraph);

    for (int i = 1; i <= N; i++) {
        minCost = min(minCost, dist_x[i] + dist_y[i] + dist_z[i]);
    }

    fout << minCost;

    return 0;
}
