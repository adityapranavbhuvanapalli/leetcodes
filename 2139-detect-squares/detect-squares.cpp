class DetectSquares {
public:
    map<vector<int>, int> points;
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        points[point]++;
    }
    
    int count(vector<int> point) {
        int squares = 0;

        for(const auto& [k, v]: points) {
            if(point[1] == k[1] || point[0] == k[0] || abs(point[0] - k[0]) != abs(point[1] - k[1]))
                continue;
            
            squares += points[{k[0], point[1]}] * points[{point[0], k[1]}] * points[{k[0], k[1]}];
        }

        return squares;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */