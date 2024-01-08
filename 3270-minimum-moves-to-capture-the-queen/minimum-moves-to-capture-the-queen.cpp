class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int colorB = getColor(c, d), colorQ = getColor(e, f);
        int bishop = INT_MAX, rook = INT_MAX;
        
        // Bishop
        if(colorB == colorQ) {
            if(abs(d - f) == abs(c - e)) {
                if((d - f) * (c - a) == (d - b) * (c - e)) {
                    double distBQ = (double)sqrt((c - e) * (c - e) + (d - f) * (d - f));
                    double distRQ = (double)sqrt((a - e) * (a - e) + (b - f) * (b - f));
                    double distRB = (double)sqrt((a - c) * (a - c) + (b - d) * (b - d));
                    
                    if(distBQ > distRB && distBQ > distRQ)
                        bishop = 2;
                    else
                        bishop = 1;
                } else {
                    bishop = 1;
                }
            } else {
                bishop = 2;
            }
        }

        // Rook
        if(a == c && a == e) {
            rook = (abs(b - d) + abs(d - f) == abs(b - f)) ? 2 : 1;
        } else if(b == d && b == f) {
            rook = (abs(a - c) + abs(c - e) == abs(a - e)) ? 2 : 1;
        } else {
            rook = (a == e || b == f) ? 1 : 2;
        }

        return min(bishop, rook);
    }

    int getColor(int x, int y) {
        return (x + y) % 2;
    }
};