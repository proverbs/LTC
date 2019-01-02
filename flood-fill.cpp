class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor) dfs(image, sr, sc, newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor) {
        static int dx[4] = {0, 0, -1, 1};
        static int dy[4] = {1, -1, 0, 0};
        int org = image[sr][sc];
        image[sr][sc] = newColor;
        for (int i = 0; i < 4; i ++) {
            int nx = sr + dx[i];
            int ny = sc + dy[i];
            if (nx < 0 || ny < 0 || nx >= image.size() || ny >= image[0].size()) continue;
            if (image[nx][ny] == org) dfs(image, nx, ny, newColor);
        }
    }
};