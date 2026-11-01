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

    void dfs(int si, int sj, vector<vector<char>>& board)
    {
        vis[si][sj] = true;
        for(int i=0;i<4;i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && board[ci][cj]=='X')
                dfs(ci,cj,board);
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        int cnt = 0;
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!vis[i][j] && board[i][j]=='X')
                {
                    dfs(i,j,board);
                    cnt++;
                }
        return cnt;
    }
};