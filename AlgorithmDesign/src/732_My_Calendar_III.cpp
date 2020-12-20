class MyCalendarThree {
public:
    MyCalendarThree() {

    }

    int book(int start, int end) {

        /**
            TC: O(n^2)
            SC: O(n)

            |---|

            |-------|      |------------|

                |---------------|

                |------|            |------|

            ----------------------------------
            5  10  15  20  25  40  50  55  60

        */

        ++map[start];
        --map[end];

        int ans = 0;
        int count = 0;
        for (const auto& pair : map) {
            count += pair.second;
            ans = max(ans, count);
        }
        return ans;
    }

private:
    map<int, int> map;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */