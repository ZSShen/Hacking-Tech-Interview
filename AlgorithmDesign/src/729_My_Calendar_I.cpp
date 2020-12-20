class MyCalendar {
public:
    MyCalendar() {

    }

    bool book(int start, int end) {

        /**
            TC: O(nlogn)
            SC: O(n)

            case 1: Check upper bound

                input
                s1 |---------| e1

                  s2 |---------| e2

                s2 < e1 => overlap with the upper bound.

            case 2: Check lower bound

                intput
                s1 |---------| e1

              s2 |---------| e2

                s1 < e2 => overlap with the lower bound.
        */

        // Check the upper bound.
        auto it = map.lower_bound(start);
        if (it != map.end() && it->first < end) {
            return false;
        }

        // Check the lower bound.
        if (it != map.begin() && (--it)->second > start) {
            return false;
        }

        map[start] = end;
        return true;
    }

private:
    map<int, int> map;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */