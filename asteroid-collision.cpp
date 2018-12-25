// O(n)
// each negative asteroid will make positive asteroids with less size explode until it meet a larger positive asteroid
// it is monotonous stack

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> idx;
        for (int i = 0; i < asteroids.size(); i ++) {
            while (!idx.empty() && 
                   idx.top() > 0 && asteroids[i] < 0 && 
                   idx.top() < -asteroids[i]) idx.pop();
            if (!idx.empty() && idx.top() > 0 && asteroids[i] < 0) {
                if (idx.top() == -asteroids[i]) idx.pop();
            } else idx.push(asteroids[i]);
        }
        
        vector<int> res;
        while (!idx.empty()) {
            res.push_back(idx.top());
            idx.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};