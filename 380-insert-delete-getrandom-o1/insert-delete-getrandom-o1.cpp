class RandomizedSet {
public:
    unordered_map<int, int> index;
    vector<int> randomSet;
    int top = 0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(index.count(val) == 1 && index[val] != -1)
            return false;

        if(top < randomSet.size())
            randomSet[top] = val;
        else
            randomSet.push_back(val);

        index[val] = top;

        top++;
        return true;
    }
    
    bool remove(int val) {
        if(index.count(val) == 0 || index[val] == -1)
            return false;

        int valIdx = index[val];
        int lastIdx = top - 1, lastVal = randomSet[top - 1];

        swap(randomSet[valIdx], randomSet[lastIdx]);
        index[lastVal] = valIdx;
        index[val] = -1;
        
        top--;
        return true;
    }
    
    int getRandom() {
        int random = rand() % top;
        return randomSet[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */