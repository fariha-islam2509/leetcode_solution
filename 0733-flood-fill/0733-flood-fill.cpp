class Solution {
public:
    int visited[55][55];
    int n,m;
    vector<pair<int,int>> direc = {{0,-1},{0,1},{-1,0},{1,0}};

    bool isValid(int i, int j)
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }

    void dfs(vector<vector<int>>& image, int i, int j,int val, int color)
    {
        if(!isValid(i,j))
            return;
        if(visited[i][j] || image[i][j] != val)
            return;

        image[i][j] = color;
        visited[i][j] = true;

        for(auto d:direc)
        {
            dfs(image,i+d.first, j+d.second, val, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        int val = image[sr][sc];
        dfs(image,sr,sc,val,color);
        return image;
    }
};