#include <climits>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

ifstream fin("trenuri.in");
ofstream fout("trenuri.out");

int longestPathInDAG(string start, string destination,
                     vector<pair<string, string>> trains) {
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> inDegree;
    unordered_map<string, int> Distance;
    unordered_set<string> cities;

    for (auto tren : trains) {
        graph[tren.first].push_back(tren.second);
        inDegree[tren.second]++;
        if (inDegree.find(tren.first) == inDegree.end()) {
            inDegree[tren.first] = 0;
        }
        cities.insert(tren.first);
        cities.insert(tren.second);
    }

    queue<string> q;
    for (auto city : cities) {
        if (inDegree[city] == 0) {
            q.push(city);
        }
    }

    vector<string> topologicalOrder;
    while (!q.empty()) {
        string currentCity = q.front();
        q.pop();
        topologicalOrder.push_back(currentCity);

        for (auto neighbour : graph[currentCity]) {
            inDegree[neighbour]--;
            if (inDegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    for (auto city : cities) {
        Distance[city] = INT_MIN;
    }
    Distance[start] = 0;

    for (auto city : topologicalOrder) {
        for (auto neighbour : graph[city]) {
            if (Distance[city] + 1 > Distance[neighbour]) {
                Distance[neighbour] = Distance[city] + 1;
            }
        }
    }

    return Distance[destination] + 1;
}

int main() {
    string start, destination;
    int M;
    vector<pair<string, string>> trains;

    fin >> start >> destination;
    fin >> M;
    trains.resize(M);

    for (int i = 0; i < M; i++) {
        fin >> trains[i].first >> trains[i].second;
    }

    fout << longestPathInDAG(start, destination, trains);

    return 0;
}
