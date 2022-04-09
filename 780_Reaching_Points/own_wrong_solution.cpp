class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) {
            return true;
        }
        if (sx > tx || sy > ty) {
            return false;
        }
        if (sx == tx && sy != ty) {
            return false or reachingPoints(sx, sx + sy, tx, ty);
        }
        if (sx != tx && sy == ty) {
            return false or reachingPoints(sx + sy, sy, tx, ty);
        }
        return reachingPoints(sx, sx + sy, tx, ty) or reachingPoints(sx + sy, sy, tx, ty);
    }
};