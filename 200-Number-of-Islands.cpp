class Solution {
    void dfs(vector<vector<char>>& grid,pair<int,int> s,vector<vector<bool>>& visited,int m,int n){
        stack<pair<int,int>> stk;
        stk.push(s);
        while(!stk.empty()){
            pair<int,int> t = stk.top();
            stk.pop();
            if(t.first-1 >=0 && (grid[t.first-1][t.second] - 48) && !visited[t.first-1][t.second]){
                visited[t.first-1][t.second] = true;
                stk.push({t.first-1,t.second});
            }
            if(t.second-1 >=0 && grid[t.first][t.second-1] - 48 && !visited[t.first][t.second-1]){
                visited[t.first][t.second-1] = true;
                stk.push({t.first,t.second-1});
            }
            if(t.second+1 < n && grid[t.first][t.second+1] - 48 && !visited[t.first][t.second+1]){
                visited[t.first][t.second+1] = true;
                stk.push({t.first,t.second+1});
            }
            if(t.first+1 < m && grid[t.first+1][t.second] - 48 && !visited[t.first+1][t.second]){
                visited[t.first+1][t.second] = true;
                stk.push({t.first+1,t.second});
            }  
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int count = 0;
        for(int i = 0;i<m;i++){
            for(int j= 0;j<n;j++){
                if(grid[i][j] - 48 && !visited[i][j]){
                    visited[i][j] = true;
                    dfs(grid,{i,j},visited,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};