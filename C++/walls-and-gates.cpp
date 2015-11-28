// BFS
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if(m == 0) return;
        int n = rooms[0].size();
        queue<pair<int, int> > q;
        vector<pair<int, int> > dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(rooms[i][j] == 0)
                    q.push(make_pair(i,j));
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(pair<int, int>& dir: dirs){
                int x = i + dir.first;
                int y = j + dir.second;
                if(x >= 0 && x < m && y >= 0 && y < n && rooms[x][y] > 0)
                    if(rooms[x][y] > rooms[i][j] + 1){
                        rooms[x][y] = rooms[i][j] + 1;
                        q.push(make_pair(x,y));
                    }
            }
        }
    }
};



// Time:  O(m * n)
// Space: O(g)

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int INF = numeric_limits<int>::max();
        queue<pair<int, int>> q;
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[0].size(); ++j) {
                if (rooms[i][j] == 0) {
                    q.emplace(make_pair(i, j));
                }
            }
        }
        while (!q.empty()) {
            int i, j;
            tie(i, j) = q.front();
            q.pop();
            for (const pair<int, int>& d :
                 vector<pair<int, int>>{{i + 1, j}, {i - 1, j},
                                        {i, j + 1}, {i, j - 1}}) {
                int I, J;
                tie(I, J) = d;
                if (I >= 0 && I < rooms.size() &&
                    J >= 0 && J < rooms[0].size() &&
                    rooms[I][J] == INF) {
                    rooms[I][J] = rooms[i][j] + 1;
                    q.emplace(make_pair(I, J));
                }
            }
        }
    }
};
