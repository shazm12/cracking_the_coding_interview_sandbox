#include <bits/stdc++.h>
using namespace std;


void dfsRec(vector<vector<int>>& adj, vector<bool>& visited, int s, vector<int>& res) {
    visited[s] = true;
    res.push_back(s);
    
    for(int e: adj[s]) {
        if(!visited[e]) {
            dfsRec(adj,visited,e,res);
        }
    }
}

vector<int> dfs(vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(),false);
    vector<int> res;
    dfsRec(adj,visited,0,res);
    return res;
}



int main() {
    // Write C++ code here
    vector<vector<int>> adj = {{1,2}, {0,2,3}, {0,4}, {1,4}, {2,3}};

    vector<int> ans = dfs(adj);
    for(auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}
