class RandomizedSet {
public:
    int top = 0;
    unordered_map<int, int> index;
    vector<int> v;
    RandomizedSet() {}

    bool insert(int val) {
        if (index.count(val))
            return false;

        v.push_back(val);
        index[val] = top++;
        return true;
    }

    bool remove(int val) {
        if (index.count(val) == 0)
            return false;

        int pos = index[val];
        index[v[top - 1]] = pos;
        index.erase(val);
        swap(v.back(), v[pos]);
        v.pop_back();
        top--;

        return true;
    }

    int getRandom() { return v[rand() % v.size()]; }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */