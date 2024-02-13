class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> line, res;
        int i = 0, n = words.size(), sum;

        while(i < n) {
            line.clear();
            sum = 0;
            while(i < n && sum + words[i].size() + line.size() <= maxWidth) {
                sum += words[i].size();
                line.push_back(words[i]);
                i++;
            }

            if(i == n)
                break;

            // Transform line into appropriate justified string
            res.push_back(transform(line, maxWidth, sum));
        }

        // Last line should be left aligned
        res.push_back("");
        string& last = res.back();
        for(int i=0; i<line.size() - 1; i++) {
            last += line[i] + " ";
        }
        last += line.back();
        while(last.size() < maxWidth)
            last += " ";

        return res;
    }

    string transform(vector<string>& line, int maxWidth, int sum) {
        int n = line.size(), spaces = maxWidth - sum;
        string res = "";

        if(n == 1) {
            res = line[0];
            res += string(maxWidth - sum, ' ');
            return res;
        }

        int spacePerWord = spaces / (n - 1);
        int extraSpaces = spaces % (n - 1);

        for(int i=0; i<n-1; i++) {
            res += line[i];
            res += string(spacePerWord, ' ');
            if(extraSpaces > 0) {
                res += ' ';
                extraSpaces--;
            } 
        }
        res += line[n-1];

        return res;
    }
};

/*
maxWidth = 16

sum += word.size() + lines.back().size() - 1 
*/