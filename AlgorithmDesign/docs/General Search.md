# General Search

## Graph Problem Abstraction
| Id      | Name                                        | Note               |
|---------|---------------------------------------------|--------------------|
| 322     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/332_Reconstruct_Itinerary.cpp" target="_blank">Reconstruct Itinerary</a>| Find a Euler path. |
| 753     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/753_Cracking_the_Safe.cpp" target="_blank">Cracking the Safe</a>| Find a Hamiltonian path with optimal starting node generation. |
| 127     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/127_Word_Ladder.cpp" target="_blank">Word Ladder</a>| Find a shortest path with BFS. |
| 126     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/126_Word_Ladder_II.cpp" target="_blank">Word Ladder II</a>| 1. Do not remove a dictionary word once it is discovered. Instead, use a map to record the discovery time of each word. Also, for a visited word, we should not push it into the BFS queue.  2. In the second pace, we run DFS to find all the paths. To ensure correct node order of each path, we should apply the discovery time map created above to examine the neighbors of each node. |


## Backtracking
| Id      | Name                                        | Note               |
|---------|---------------------------------------------|--------------------|
| 140     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/140_Word_Break_II.cpp" target="_blank">Word Break II</a>| Ａvoid re-visiting same subproblems with a memo cache. |
| 291     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/291_Word_Pattern_II.cpp" target="_blank">Word Pattern II</a>|  |


## Topological Sort
| Id      | Name                                        | Note               |
|---------|---------------------------------------------|--------------------|
| 269     |  <a href="https://github.com/ZSShen/Hacking-Tech-Interview/blob/main/AlgorithmDesign/src/269_Alien_Dictionary.cpp" target="_blank">Alien Dictionary</a>| Build a graph by examining pairs of words and then run the topological sort on the graph to figure out the legal character order. |
