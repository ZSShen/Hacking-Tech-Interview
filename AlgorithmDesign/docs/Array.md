# Array

## Subarray and Prefix Sum
| Id      | Name                                        | Note               |
|---------|---------------------------------------------|--------------------|
| 325     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/325_Maximum_Size_Subarray_Sum_Equals_k.cpp" target="_blank">Maximum Size Subarray Sum Equals k</a>| Track prefix sums and their ending indexes. |
| 525     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/525_Contiguous_Array.cpp" target="_blank">Contiguous Array</a>| Convert 0 to -1. Track prefix sums and their ending indexes. |
| 560     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/560_Subarray_Sum_Equals_K.cpp" target="_blank">Subarray Sum Equals K</a>| Count the number of subarrays. Group prefix sums by sum. |
| 523     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/523_Continuous_Subarray_Sum.cpp" target="_blank">Continuous Subarray Sum</a>| Count the number of subarrays. Group prefix sums by remainder. |
| 974     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/974_Subarray_Sums_Divisible_by_K.cpp" target="_blank">Subarray Sum Divisible by K</a>| Count the number of subarrays. Group prefix sums by remainder. |
| 1498    |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/1498_Number_of_Subsequences_That_Satisfy_the_Given_Sum_Condition.cpp" target="_blank">Number of Subsequences That Satisfy the Given Sum Condition</a>| Two pointer and sandwitch scan. should handle integer overflow with pre-calculated power array. |
| 53      |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/53_Maximum_Subarray.cpp" target="_blank">Maximum Subarray</a>| Maintain a running sum. Cut it off and initiate a new one once the sum is negative. |
| 152     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/152_Maximum_Product_Subarray.cpp" target="_blank">Maximum Product Subarray</a>| Maintain two running products, `min_sofar` and `max_sofar`. |
| 238      |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/238_Product_of_Array_Except_Self.cpp" target="_blank">Product of Array Except Self</a>| Maintain two running products `l_prod` and `r_prod`. Reuse the answer vector to achieve O(1) space complexity. |


## Sliding Window
| Id      | Name                                        | Note               |
|---------|---------------------------------------------|--------------------|
| 209     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/209_Minimum_Size_Subarray_Sum.cpp" target="_blank">Minimum Size Subarray Sum</a>| Use two pointers, `L` and `R`, to locate legitimate subarrays. Among them, pick the shortest one.|
| 713     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/713_Subarray_Product_Less_Than_K.cpp" target="_blank">Subarray Product Less Than K</a>| Use two pointers, `L` and `R`, to locate legitimate subarrays. Among them, pick the shortest one.|
| 76      |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/76_Minimum_Window_Substring.cpp" target="_blank">Minimum Window Substring</a>| Use two pointers, `L` and `R`, to locate legitimate subarrays. Among them, pick the shortest one.|
| 340     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/340_Longest_Substring_with_At_Most_K_Distinct_Characters.cpp" target="_blank">Longest Substring with At Most K Distinct Characters</a>| Use two pointers, `L` and `R`, to locate legitimate subarrays. Among them, pick the longest one.|


## Sandwitch (Reversed Two Pointers)
| Id      | Name                                        | Note               |
|---------|---------------------------------------------|--------------------|
| 15     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/15_3Sum.cpp" target="_blank">3Sum</a>| Use two pointers, `L` and `R`, to locate legal triplets. Be sure to dedulicate using `while (++l < r && nums[l] == nums[l - 1])` and `while (l < --r && nums[r] == nums[r + 1])`.|
| 18     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/18_4Sum.cpp" target="_blank">4Sum</a>| Same as 3Sum, but need to define a 2-layer driver loop outside of the 2Sum subroutine. |
| 16     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/16_3Sum_Closest.cpp" target="_blank">3Sum Closest</a>| Use two pointers, `L` and `R`, to locate legal triplets.|
| 259     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/259_3Sum_Smaller.cpp" target="_blank">3Sum Smaller</a>| Use two pointers, `L` and `R`, to locate legal triplets.|


## Two Non-Overlapping Subarrays
| Id      | Name                                        | Note               |
|---------|---------------------------------------------|--------------------|
| 123     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/123_Best_Time_to_Buy_and_Sell_Stock_III.cpp" target="_blank">Best Time to Buy and Sell Stock III</a>| Use a rod to seperate two transactions. Also, keep the lowest buying price on the left and keep the highest selling price on the right. |
| 1031    |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/1031_Maximum_Sum_of_Two_Non-Overlapping_Subarrays.cpp" target="_blank">Maximum Sum of Two Non-Overlapping Subarrays</a>| Use a rod to seperate subarrays with size L and M. |
| 689     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/689_Maximum_Sum_of_3_Non-Overlapping_Subarrays.cpp" target="_blank">Maximum Sum of 3 Non-Overlapping Subarrays</a>| Use a block to seperate the input array to 3 partitions. |


## Element Partition
| Id      | Name                                        | Note               |
|---------|---------------------------------------------|--------------------|
| 283     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/283_Move_Zeroes.cpp" target="_blank">Move Zeroes</a>| Use two pointers `L` and `R`. Once seeing a non-zero element, increase `L` and swap it with the element pointed by `L`. |
| 75     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/75_Sort_Colors.cpp" target="_blank">Sort Colors</a>| Use three pointers `0`, `1`, and `2`. When swapping a 2 to the right end and acquiring an unknown element, do not advance `1` but postpone to the next iteration to make decision. |
