// Grpah DFS
class Solution {
    vector<pair<int, int> > directions{{0, -1}, {0, 1},
                                       {-1, 0}, {1, 0}};
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid.size() == 0)
            return 0;
        int num = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == '1'){
                    explore(grid, i, j);
                    num++;
                }
        return num;
    }
    
    void explore(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = 'x';
        for(pair<int, int>& direction : directions){
            int x = direction.first;
            int y = direction.second;
            if(i + x >= 0 && i + x < grid.size() && j + y >= 0 && j + y < grid[0].size() &&
               grid[i+x][j+y] == '1')
                explore(grid, i+x, j+y);
        }
    }
};
