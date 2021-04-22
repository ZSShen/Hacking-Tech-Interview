class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

        /**
         * https://leetcode.com/problems/insert-delete-getrandom-o1/
         *
         * TC: O(1)
         * SC: O(N)
         */
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {

        if (map.count(val) == 1) {
            return false;
        }

        vec.emplace_back(val);
        map[val] = vec.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {

        if (map.count(val) == 0) {
            return false;
        }

        int index = map[val];
        swap(vec[index], vec.back());

        int last = vec[index];
        map[last] = index;

        vec.pop_back();
        map.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % vec.size();
        return vec[index];
    }


private:
    vector<int> vec;
    unordered_map<int, int> map;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */