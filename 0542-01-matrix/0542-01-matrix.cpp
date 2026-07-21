class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        // Push all 0's into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // Directions: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};