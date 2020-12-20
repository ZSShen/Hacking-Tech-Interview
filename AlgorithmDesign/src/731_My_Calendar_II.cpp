class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {

        /**
            TC: O(n^2)
            SC: O(n)

            |--|        |-----------------|

               |-----------------|

               |----|                  |----|

            ----------------------------------
            5 10 15 20 25 30 35 40 45 50 55 60

        */

        // Check potential conflict.
        ++map[start];
        --map[end];

        int count = 0;
        int max_count = 0;

        for (const auto& pair : map) {
            count += pair.second;
            max_count = max(max_count, count);
            if (max_count > 2) {
                --map[start];
                ++map[end];
                return false;
            }
        }

        return true;
    }

private:
    map<int, int> map;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */