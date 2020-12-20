# Intervals

## Interval Foundamental
| Id      | Name                                        | Note               |
|---------|---------------------------------------------|--------------------|
| 435     | <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/435_Non-overlapping_Intervals.cpp" target="_blank">Non-overlapping Intervals</a> | Greedy sort and pick. Similar to #452. |
| 452     | <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/452_Minimum_Number_of_Arrows_to_Burst_Balloons.cpp" target="_blank">Minimum Number of Arrows to Burst Balloons</a> | Greedy sort and pick. Similar to #435. |


## Interval Scheduling with Sweep Line
| Id      | Name                                        | Note               |
|---------|---------------------------------------------|--------------------|
| 759     | <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/759_Employee_Free_Time.cpp" target="_blank">Employee Free Time</a> | Count free intervals. The idea is similar to meeting rooms II. |
| 1229    | <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/1229_Meeting_Scheduler.cpp" target="_blank">Meeting Scheduler</a> | Two pointers. Check `max(s1, s2) < min(e1, e2)` |
| 729     | <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/729_My_Calendar_I.cpp" target="_blank">My Calendar I</a> | Use OrderedMap to maintain intervals. Speed up with lower and upper bound checks. |
| 731     | <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/731_My_Calendar_II.cpp" target="_blank">My Calendar II</a> | Use OrderedMap to maintain intervals. Count the number of meetings at any moment. |
| 732     | <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/732_My_Calendar_III.cpp" target="_blank">My Calendar III</a> | Use OrderedMap to maintain intervals. Count the number of meetings at any moment. |