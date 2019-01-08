// polar coordinates are quite tricky, pay attention to sqrt(z)!!
// another method without thinking too much is rejection sampling

# define PI 3.14159265358979323846

class Solution {
public:
    double x, y, r;
    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }
    
    vector<double> randPoint() {
        double f = (double)rand() / RAND_MAX;
        double z = (double)rand() / RAND_MAX;
        double nx = x + r * sqrt(z) * cos(f * PI * 2);
        double ny = y + r * sqrt(z) * sin(f * PI * 2);
        return vector<double>({nx, ny});
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */