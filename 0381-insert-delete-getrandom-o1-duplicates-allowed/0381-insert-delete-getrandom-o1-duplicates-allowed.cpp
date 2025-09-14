class RandomizedCollection {
    vector<int> v;
    map<int, set<int>> m;
public:
    RandomizedCollection() {
    }
    
    bool insert(int val) {
        bool isPresent = (m.find(val) ==m.end() || m[val].empty());
        m[val].insert(v.size());
        v.push_back(val);
        return isPresent;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end() || m[val].empty())
            return false;

        int removeIdx = *m[val].begin();
        m[val].erase(removeIdx);

        int lastVal = v.back();
        v[removeIdx] = lastVal;

        m[lastVal].insert(removeIdx);
        m[lastVal].erase(v.size() - 1);

        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */