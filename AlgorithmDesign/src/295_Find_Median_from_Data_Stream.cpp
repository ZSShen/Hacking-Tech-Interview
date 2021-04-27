class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder()
    { }

    void addNum(int num) {

        /**
         * https://leetcode.com/problems/find-median-from-data-stream/
         *
         * TC: O(NlogN)
         * SC: O(N)
         */

        if (max_q.empty()) {
            max_q.emplace(num);
            return;
        }

        insert(num);
        rebalance();
    }

    double findMedian() {

        if (max_q.size() == min_q.size()) {
            return static_cast<double>(max_q.top() + min_q.top()) / 2;
        } else {
            return max_q.size() > min_q.size() ? max_q.top() : min_q.top();
        }
    }

private:
    void insert(int num) {

        if (num <= max_q.top()) {
            max_q.emplace(num);
        } else {
            min_q.emplace(num);
        }
    }

    void rebalance() {

        if (max_q.size() > min_q.size() + 1) {
            min_q.emplace(max_q.top());
            max_q.pop();
        }

        if (min_q.size() > max_q.size() + 1) {
            max_q.emplace(min_q.top());
            min_q.pop();
        }
    }

    priority_queue<int, vector<int>, less<int>> max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */