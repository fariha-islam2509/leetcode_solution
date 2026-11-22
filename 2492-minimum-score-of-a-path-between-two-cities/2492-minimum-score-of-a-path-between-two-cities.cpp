class Solution {
public:
    int mn = INT_MAX;
    vector<pair<int,int>> adj_list[100005];
    bool vis[100005];

    void dfs(int src)
    {
        vis[src] = true;
        for(auto child : adj_list[src])
        {
            mn = min(mn,child.second);
            if(!vis[child.first])
                dfs(child.first);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        for(auto v : roads)
        {
            int a = v[0], b = v[1], c = v[2];
            adj_list[a].push_back({b,c});
            adj_list[b].push_back({a,c});
        }
        memset(vis,false,sizeof(vis));
        dfs(1);
        return mn;
    }
};