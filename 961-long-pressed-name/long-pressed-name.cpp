class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0, nt = typed.size(), nn = name.size();
        int countN, countT;
        char charN, charT;
        while(i < nt && j < nn) {
            // Find counts of groups of chars
            countT = countN = 0;
            charT = typed[i];
            charN = name[j];
            
            if(charT != charN)
                return false;
            
            while(i < nt && typed[i] == charN) {
                countT++;
                i++;
            }
            
            while(j < nn && name[j] == charN) {
                countN++;
                j++;
            }
            
            if(countT < countN)
                return false;
        }
        
        return i == nt && j == nn && countT >= countN;
    }
};

/*
j
saeed
ssaaedd
i
*/