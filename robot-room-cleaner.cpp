// O(width*length)

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    set<pair<int, int>> vis; // relative coordinate
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    void cleanRoom(Robot& robot) {
        dfs(0, 0, 0, robot);
    }
    
    void dfs(int x, int y, int d, Robot &robot) {
        if (!vis.count(make_pair(x, y))) {
            vis.insert(make_pair(x, y));
            robot.clean();

            for (int i = 0; i < 4; i ++) {
                bool fg = robot.move();
                if (fg) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    dfs(nx, ny, d, robot);
                    robot.turnLeft();
                } else {
                    robot.turnRight();
                }
                d = (d + 1) % 4;
            }
        }
        
        // turn around and move back
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
    }
};