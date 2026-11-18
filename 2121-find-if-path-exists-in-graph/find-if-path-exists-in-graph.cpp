class Solution {
public:

    vector<vector<int>> createGraph(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) {
            return true;
        }
        
        vector<vector<int>> adj = createGraph(n, edges);
        vector<bool> visited(n, false);
        queue<int> q;
        vector<int> res;

        q.push(source);
        visited[source] = true;

        while(!q.empty()) {
            int curr = q.front();
            res.push_back(curr);
            q.pop();
            for(int x : adj[curr]) {
                if(!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        return visited[destination] == true;
    }
};