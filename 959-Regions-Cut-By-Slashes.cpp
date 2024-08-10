class Solution {
    void bfs(vector<vector<bool>>& graph,int i,int j,int n){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            q.pop();
            if(i-1 >= 0 && !graph[i-1][j]){
                graph[i-1][j] = 1;
                q.push({i-1,j});
            }
            if(j-1 >= 0 && !graph[i][j-1]){
                graph[i][j-1] = 1;
                q.push({i,j-1});
            }
            if(i+1 < n && !graph[i+1][j]){
                graph[i+1][j] = 1;
                q.push({i+1,j});
            }
            if(j+1 < n && !graph[i][j+1]){
                graph[i][j+1] = 1;
                q.push({i,j+1});
            }
                
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size()*3;
        vector<vector<bool>> graph(n,vector<bool>(n,0));
        int i = 0;
        for(auto& row : grid){
            int j = 0;
            for(char c : row){
                if(c == '/'){
                    graph[i][j+2] = graph[i+1][j+1] = graph[i+2][j] = 1;
                }
                else if(c == '\\'){
                    graph[i][j] = graph[i+1][j+1] = graph[i+2][j+2] = 1;    
                }
                j+=3;
            }
            i+=3;
        }
        int res = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(!graph[i][j]){
                    bfs(graph,i,j,n);
                    res++;
                }
            }
        }
        return res;
    }
};