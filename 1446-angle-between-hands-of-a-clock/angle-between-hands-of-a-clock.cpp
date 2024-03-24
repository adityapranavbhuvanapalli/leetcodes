class Solution {
public:
    double angleClock(int hour, int minutes) {
        double extra = minutes / 2.0;
        double angleHour = (hour % 12) * 30 + extra;
        double angleMinute = minutes * 6;

        return min({
            abs(angleHour - angleMinute), 
            abs(360 - angleHour + angleMinute), 
            abs(360 - angleMinute + angleHour)
        });
    }
};

/*
12:30

60  - 30
*/