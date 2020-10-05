# pathsInMap

## Problem Statement
Given a map of continental USA find all the descending points to Atlantic and Pacific

## Brainstorming/Discussion
* You can use any representation of the map that you want
* Not interested in the path. Interested in the points
* It must be descending always
* Is level considered descending (Yes)
* Observation: Highest point could be on the left side and lowest on right or vice versa. 

+ To keep it simple for understanding, I can use a Matrix whre the value of each element represents the altitude.
  - Assuming pacific is on the left side and atlantic is on the right side of this matrix representation
  - I can use -ive for descending from current point and +ive for ascending from current point
    - Actually that's not needed. Simply any values can be used. 
    - Let's keep only positive values and 0 would be mean the level
- Whereever I start, the points that I follow for the path must be in descending order always
    - Length of the path can be anything
- Hitting a leaf would mean I reached atlantic/pacific. Left side of a tree can be atlantic and right as pacific. But wait a minute
    - Since the start point is not given, so tree it not a proper representation of this
- It must a graph
    - There can be circles to keep descending path (I should avoid those. Does it matter? Can I simply just stop if I don't find next descending point?)
    - So, Graph is the way to go. I would need to represent the map using grpah and then do DFS.
    - I can go in any direction (Hint: To keep it simple assume you can go in 4 directions only E/W/N/S)
- Assuming just 4 directions only helps works on the matrix representation for graph
    - We don't even need an explicit matrix with graph representation

### Hints
    - Focus on points
    - 2D representation and 4 directions are sufficient

### Initial solution
    - focused on implementing the graph with Node struct with random values for nodes
    - search just discussed but not implemented. DFS, with each node as the start node and then keep recording the points.

## Afterthoughts based upon hints
    - While going graph and then doing DFS is apparently OK, that will require doing doulbe traversals i.e. first DFS (or BFS) for treating each node as root and then send DFS for finding the set of nodes leading to Atlantic/Pacific.
    - How will Atlantic or pacific be represented.
        - It would help if I use 0 on each side of the matrix (first and last column) for representing pacific and atlantic
        - I didn't use them in my example to understand and I think they are not needed. They can be assumed based upon hitting first or the last column
        - Rather they should not be in the matrix as 0 can be a place which at sea level in the middle somewhere

    + Do we have to create the graph explicitly or can we just have it implicit by implementing acustom traversal using recursion, where instead of having edges to 4 adjacent nodes in each direction, we just check the values of the adjacent elements in Matrix and then go to the minimum one.
        - where at each point we decide which way to go based upon the lowest value of the 4 directions.
        - we keep on recording the points

### Let's try this matrix based solution
