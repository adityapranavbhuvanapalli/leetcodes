class FrequencyTracker {
public:
    unordered_map<int, int> freq;       // stores (number, frequency)
    unordered_map<int, int> present;    // stores (frequency, countofFreq)
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        // Remove from present[freq[number]]
        if(freq[number] > 0)
            present[freq[number]]--;

        // Increase freq of number
        freq[number]++;

        // Add to present[new freq]
        present[freq[number]]++;
    }
    
    void deleteOne(int number) {
        if(freq[number] == 0)
            return;

        // Remove from present[freq[number]]
        present[freq[number]]--;

        // Decrease freq of number
        freq[number]--;


        // Add to present[new freq]
        if(freq[number] > 0)
            present[freq[number]]++;
    }
    
    bool hasFrequency(int frequency) {
        return present[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */