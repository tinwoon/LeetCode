#define MTZ(a,b) ( (a - b) > 0 )
#define WIDE(a,b,c,d) ( (a - b) * (c - d) )

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int ans = (ax2 - ax1) * (ay2 - ay1);
        ans += (bx2 - bx1) * (by2 - by1);

        int x_overlap = std::min(ax2, bx2) - std::max(ax1, bx1);
        int y_overlap = std::min(ay2, by2) - std::max(ay1, by1);

        if(x_overlap > 0 && y_overlap > 0){
            ans -= x_overlap * y_overlap;
        }

        return ans;
    }
};