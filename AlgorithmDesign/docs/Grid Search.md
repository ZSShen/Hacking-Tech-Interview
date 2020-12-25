# Grid Search

## Flood and Fill
| Id      | Name                                        | Note               |
|---------|---------------------------------------------|--------------------|
| 1340     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/1254_Number_of_Closed_Islands.cpp" target="_blank">Number of Closed Islands</a>| DFS or BFS. DFS with more succinct code. |
| 305     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/305_Number_of_Islands_II.cpp" target="_blank">Number of Islands II</a>| Fill with disjoint set and union find. |


## Path Search
| Id      | Name                                        | Note               |
|---------|---------------------------------------------|--------------------|
| 1091     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/1091_Shortest_Path_in_Binary_Matrix.cpp" target="_blank">Shortest Path in Binary Matrix</a>| BFS. Need to explore 8 directions, instead of using greedy approach to reach the bottom right corner. |
| 1293     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/1293_Shortest_Path_in_a_Grid_with_Obstacles_Elimination.cpp" target="_blank">Shortest Path in a Grid with Obstacles Elimination</a>| BFS. Change `visit[i][j]` to `count[i][j]`, indicating the minimum number of obstacles need to be removed to reach the `cell[i][j]`. |
| 1559     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/1559_Detect_Cycles_in_2D_Grid.cpp" target="_blank">Detect Cycles in 2D Grid</a>| DFS. Must ignore trivial cycles. |
| 490     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/490_The_Maze.cpp" target="_blank">The Maze</a>| BFS or DFS. |
| 505     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/505_The_Maze_II.cpp" target="_blank">The Maze II</a>| BFS or DFS. Maintain a matrix to track the shortest path reaching each cell.|
| 499   |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/499_The_Maze_III.cpp" target="_blank">The Maze III</a>| DFS. Similar to part II but need to track path configurations, so prefer DFS. |
