class RLEIterator {
public:
    int idx = 0;
    vector<int> RLE;
    RLEIterator(vector<int>& encoding) {
        RLE = encoding;
    }
    
    int next(int n) {
        // cout<<n<<": ";
        while(idx < RLE.size() && n > RLE[idx]) {
            n -= RLE[idx];
            idx += 2;
        }

        if(idx >= RLE.size()) {
            // cout<<-1<<endl;
            return -1;
        }

        RLE[idx] -= n;
        // for(const auto& r: RLE)
        //     cout<<r<<" ";
        // cout<<" : "<<idx<<" -> "<<RLE[idx + 1]<<endl;

        return RLE[idx + 1];
    }
};

/*
3   8   0   9   2   5
1   8   0   9   2   5
*/

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */