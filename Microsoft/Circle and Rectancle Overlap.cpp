// LC -1401

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        int x = max(x1, min(xCenter,x2));  //find the closest x point on or in the rectangle from the circle
        int y = max(y1, min(yCenter,y2));  ////find the closest y point on or in the rectangle from the circle

        int dx = x-xCenter;  //calculating  x distance from the center of the circle
        int dy = y-yCenter;  //calculating  y distance from the center of the circle

        if((dx*dx + dy*dy)<=radius*radius){
            return true;
        }else{                                    // if the distance is less than equal to the radius it means circle is intersecting or inside the rectangle
            return false;
        }

       
        
    }
};
