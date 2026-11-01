class Solution {
public:
    bool has_parent[100005];
    vector<int> ans;
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        for(auto v : edges)
            has_parent[v[1]] = true;
        
        for(int i=0;i<n;i++)
            if(!has_parent[i])
                ans.push_back(i);
                
        return ans;
    }
};