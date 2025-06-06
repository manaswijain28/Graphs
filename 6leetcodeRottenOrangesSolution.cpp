class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int minutes = 0;
        int numberOfOrangesNotRotten = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    numberOfOrangesNotRotten++;
                }
            }
        }


        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty()) {

            if(numberOfOrangesNotRotten == 0){
                break;
            }
            int levelNodes = q.size();
            minutes++;
            for (int i = 0; i < levelNodes; i++) {
                pair<int, int> node = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int x = node.first+dx[j];
                    int y = node.second+dy[j];

                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x,y});
                        numberOfOrangesNotRotten--;
                        
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return minutes;
    }
};
