// deque for snake, queue for food

class SnakeGame {
public:
    typedef pair<int, int> pr; // <x, y>
    deque<pr> snake;
    int n, m;
    int score;
    queue<pr> food;
    vector<vector<bool>> used;
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        snake.push_back({0, 0});
        n = height;
        m = width;
        for (pr& f : food) this->food.push(f);
        score = 0;
        used.resize(n, vector<bool>(m, false));
        used[0][0] = true;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int dx, dy;
        if (direction[0] == 'U') dx = -1, dy = 0;
        else if (direction[0] == 'L') dx = 0, dy = -1;
        else if (direction[0] == 'R') dx = 0, dy = 1;
        else dx = 1, dy = 0;
        int nx = snake.back().first + dx;
        int ny = snake.back().second + dy;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) return -1;
        
        // cout << nx << " " << ny << endl;
        // cout << food.front().first << " " << food.front().second << endl;
        // cout << endl;
        
        if (!food.empty() && nx == food.front().first && ny == food.front().second) {
            snake.push_back({nx, ny});
            if (used[nx][ny]) return -1;
            used[nx][ny] = true;
            food.pop();
            score ++;
        } else {
            used[snake.front().first][snake.front().second] = false;
            snake.pop_front();
            
            snake.push_back({nx, ny});
            if (used[nx][ny]) return -1;
            used[nx][ny] = true;
        }
        
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */