class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min_ang = abs( ((minutes * 0.5) + (hour * 30)) - (minutes * 6) );
        return min(min_ang, 360 - min_ang);;
    }
};