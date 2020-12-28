class StockSpanner {
public:
    StockSpanner()
        : index(0)
    { }

    int next(int price) {

        /**
         * TC: O(n)
         * SC: O(n)
         */

        // Maintain a monotonous decreasing stack.
        while (!stk.empty() && price >= stk.top().second) {
            stk.pop();
        }

        int span = index - (stk.empty() ? -1 : stk.top().first);
        stk.push({index++, price});
        return span;
    }

private:
    int index;
    stack<pair<int, int>> stk;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */