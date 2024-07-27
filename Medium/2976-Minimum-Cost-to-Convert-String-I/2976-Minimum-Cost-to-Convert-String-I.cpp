#include <bits/stdc++.h>
using namespace std;

class Solution {
// private:
//     long long shortestPath(char src, char dest, map<char, vector<pair<char, int>>> graph,
//      long long cost, long long& minCost, set<char>& vis,
//      int maxDepth, int depth){
        
//         if(vis.find(src) != vis.end() || depth > maxDepth){
//             return LLONG_MAX;
//         }

//         if(src == dest){
//             minCost = min(minCost, cost);
//             vis.erase(src);
//             return minCost;
//         }

//         for(auto it : graph[src]){
//             cost = cost+it.second;
//             shortestPath(it.first, dest, graph, cost, minCost, vis, maxDepth, depth+1);
//             cost = cost-it.second;
//         }
        
//         vis.erase(src);

//         return minCost;
//     }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        if(source.size() != target.size())
            return -1;
        map<char, vector<pair<char, int>>> graph;
        set<char> nodes;
        for(char ch: source)
            nodes.insert(ch);
        for(char ch: target)
            nodes.insert(ch);
        
        for(int i=0; i<original.size(); i++){
            char src = original[i];
            char dest = changed[i];
            nodes.insert(src);
            graph[src].push_back({dest, cost[i]});
        }

        long long ans = 0;
        unordered_map<string, long long> mpp;
        int maxDepth = source.size();
        for(int i=0; i<source.size(); i++){
            char src = source[i];
            char dest = target[i];
            string s = src + string("->")+dest;
            if(src != dest){
                if(mpp.find(s) != mpp.end())
                    ans += mpp[s];
                else{
                    //dikstra's algorithm
                    map<char, long long> minDist;
                    for (auto& node : nodes) {
                        minDist[node] = LLONG_MAX;
                    }
                    priority_queue<pair<long long, char>, vector<pair<long long, char>>, greater<pair<long long, char>>> pq;
                    pq.push({0, src});
                    minDist[src] = 0;
                    while(!pq.empty()){
                        auto [currentDist, currentNode] = pq.top();
                        pq.pop();
                        if(currentNode == dest)
                            break;
                        for(auto& neighbor:graph[currentNode]){
                            char nextNode = neighbor.first;
                            int edgeCost = neighbor.second;
                            if (minDist[currentNode] + edgeCost < minDist[nextNode]) {
                                minDist[nextNode] = minDist[currentNode] + edgeCost;
                                pq.push({minDist[nextNode], nextNode});
                            }
                        }
                    }
                    if (minDist[dest] == LLONG_MAX) {
                        return -1;
                    }
                    ans += minDist[dest];
                    mpp[s] = minDist[dest];
                }
            }
        }

        return ans;
    }
};