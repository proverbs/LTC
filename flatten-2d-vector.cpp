class Vector2D {
public:
    int nx, ny;
    vector<vector<int>>& vec;
    Vector2D(vector<vector<int>>& vec2d) : vec(vec2d) {
        nx = 0;
        ny = 0;
        while (nx < vec.size()) {
            if (!vec[nx].size()) nx ++, ny = 0;
            else break;
        }
    }

    int next() {
        int res = vec[nx][ny];
        if (ny + 1 < vec[nx].size()) ny ++;
        else {
            ny ++;
            while (nx < vec.size()) {
                if (ny == vec[nx].size()) nx ++, ny = 0;
                else break;
            }
        }
        
        return res;
    }

    bool hasNext() {
        return nx < vec.size() && ny < vec[nx].size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */