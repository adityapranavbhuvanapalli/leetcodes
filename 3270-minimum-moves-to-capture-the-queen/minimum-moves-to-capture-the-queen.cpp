class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int colorB = (c + d) % 2, colorQ = (e + f) % 2;
        int bishop = INT_MAX, rook = INT_MAX;
        
        // Bishop
        if(colorB == colorQ) {
            if(abs(d - f) != abs(c - e)) {
                bishop = 2;
            } else if((d - f) * (c - a) == (d - b) * (c - e)) {
                double distBQ = sqrt((c - e) * (c - e) + (d - f) * (d - f));
                double distRQ = sqrt((a - e) * (a - e) + (b - f) * (b - f));
                double distRB = sqrt((a - c) * (a - c) + (b - d) * (b - d));
                
                bishop = (distBQ > distRB && distBQ > distRQ) ? 2 : 1; 
            } else {
                bishop = 1;
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
};