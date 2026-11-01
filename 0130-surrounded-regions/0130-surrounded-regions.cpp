class Solution {
public:
    bool vis[205][205];
    vector<pair<int,int>> d =  {{0,-1},{0,1},{-1,0},{1,0}};
    int n,m;

    bool valid(int i, int j)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }

    void dfs(int si, int sj, vector<vector<char>>& grid)
    {
        vis[si][sj] = true;
        for(int i=0;i<4;i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]=='O')
                dfs(ci,cj,grid);
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        memset(vis,false,sizeof(vis));

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='O' && (i==0 || j==0 || i==n-1 || j==m-1))
                {
                    dfs(i,j,board);
                }
            }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j]=='O' && !vis[i][j])
                    board[i][j] = 'X';
    }
};