class FreqStack {
public:
    int maxFreq;
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> freqStk;
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        freqStk[freq[val]].push(val);

        // cout<<val<<" > "<<freq[val]<<endl;
    }
    
    int pop() {
        int val = freqStk[maxFreq].top();
        freq[val]--;
        freqStk[maxFreq].pop();

        if(freqStk[maxFreq].size() == 0)
            maxFreq--;
        
        // cout<<"Popped: "<<val<<endl;
        return val;
    }
};

/*
1 - 4   0   9   3   2   
2 - 4

4   6   1
*/

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */