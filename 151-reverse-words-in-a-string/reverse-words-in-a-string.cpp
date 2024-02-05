class Solution {
public:
    string reverseWords(string s) {
        string res = "", part = "";

        s += " ";
        for(const auto& ch: s) {
            if(ch != ' ') {
                part += ch;
                continue;
            }

            if(part == "")
                continue;

            res = part + " " + res;
            part = "";
        }

        return res.substr(0, res.size() - 1);
    }
};

/*
sky 
res = the 


eulb si yks eht
blue is sky the
*/