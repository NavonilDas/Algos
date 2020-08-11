class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 12 hour = 360 degree
        // shift in hour due to minute clock
        // minute * 30 / 60 
        // this comes from 60 min = 1 hour
        double h = hour*30.0 + (double)minutes / 2.0;
        // 60 minute = 360 degree
        double m = minutes * 6.0;
        // angle between them
        double ang = abs(m - h);
        // if angle is greater than 180 then choose the half angle
        if(ang > 180) ang = 360 - ang;
        return ang;
    }
};