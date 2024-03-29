class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long side = 0, apples = 0;
 
        while(apples + (long long)3 * side * side < neededApples){   
            apples += (long long) 3 * side * side; 
            side += 2;
        }

        return 4 * side;
    }
};
/*
        |
        |
        |
-------------------
        |
        |
        |

     6543456
     5432345
     4321234
     3210123
     4321234
     5432345
     6543456

for side = 2,                           2*4 + 1*4   = 12 = (3^ 2^2)
for side = 4,             4*4 +  3*8 +  2*8 + 1*4   = 60 = 12 + (3 * 4^2)
for side = 6, 6*4 + 5*8 + 4*12 + 3*12 + 2*8 + 1*4   = 168 = 60 + (3 * 6^2)

24+40+48+36+16+4
*/