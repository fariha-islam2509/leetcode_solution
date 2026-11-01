class Solution {
public:
    int level[105][105];
    int n;
    vector<pair<int,int>> d = {{-1,0},{0,-1},{1,0},{0,1},{-1,1},{1,-1},{-1,-1},{1,1}};

    bool valid(int i,int j)
    {
        return i>=0 && i<n && j>=0 && j<n;
    }

    void bfs(int si, int sj, vector<vector<int>>& grid)
    {
        queue<pair<int,int>> q;
        q.push({si,sj});
        level[si][sj] = 1;
        while(!q.empty())
        {
            pair<int,int> par = q.front();
            q.pop();
            int par_i = par.first;
            int par_j = par.second;
            for(int i=0;i<8;i++)
            {
                int ci = par_i + d[i].first;
                int cj = par_j + d[i].second;

                if(valid(ci,cj) && level[ci][cj] == -1 && grid[ci][cj] == 0)
                {
                    q.push({ci,cj});
                    level[ci][cj] = level[par_i][par_j] + 1;
                }
            }
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        memset(level,-1,sizeof(level));

        if(grid[0][0] == 0)
            bfs(0,0,grid);
        return level[n-1][n-1];
    }
};