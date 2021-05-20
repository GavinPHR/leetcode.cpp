class Solution {
public:
    double radius, x_center, y_center;
    Solution(double radius, double x_center, double y_center) 
    : radius(radius), x_center(x_center), y_center(y_center)
    {
    }
    
    vector<double> randPoint() {
        // generate in the unit circle
        double x, y;
        auto gen = [&]() {
            x = (((double) rand()) / RAND_MAX) * 2 - 1;
            y = (((double) rand()) / RAND_MAX) * 2 - 1;
        };
        gen();
        while (x * x + y * y > 1) gen();
        x = x * radius + x_center;
        y = y * radius + y_center;
        return vector<double>{x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */