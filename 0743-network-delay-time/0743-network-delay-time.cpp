class Solution {
public:
    vector<pair<int,int>> adj_list[105];
    int dis[105];

    void dijkstra(int src)
    {
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        dis[src] = 0;
        while(!pq.empty())
        {
            pair<int,int> par = pq.top();
            pq.pop();
            int par_node = par.second;
            int par_dis = par.first;
            for(auto child : adj_list[par_node])
            {
                int child_node = child.first;
                int child_dis = child.second;
                if(par_dis + child_dis < dis[child_node])
                {
                    dis[child_node] = par_dis + child_dis;
                    pq.push({dis[child_node], child_node});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
                for(auto v : times)
        {
            int a=v[0],b=v[1],c=v[2];
            adj_list[a].push_back({b,c});
        }
        for(int i=1;i<=n;i++)
            dis[i] = INT_MAX;
        dijkstra(k);
        int ans = -1;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INT_MAX) return -1;
            ans = max(dis[i],ans);
        }
        return ans;
    }
};