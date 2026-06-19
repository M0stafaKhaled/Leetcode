class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes * 6;
        double hourAngle = (hour * 30) % 360 + minutes * 0.5;

        double diff = abs(minuteAngle - hourAngle);
        double ans = min(diff, 360 - diff);

        return ans;
    }
};