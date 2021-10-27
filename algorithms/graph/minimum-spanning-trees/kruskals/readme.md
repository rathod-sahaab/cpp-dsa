# Kruskal's algorithm
Kruskal's algorithm is used to find minimum spanning tree in a weighted graph.

**Algorithm**
1. Sort all edges according to weight in increasing order
2. For all edges, if adding the edge doesn't create a cycle add edge to MST set.

**Required:**
- Number of nodes
- Edges {source, destination, weight}

**Complexities:**
Time: **ElogV**
Space: **E + V**
