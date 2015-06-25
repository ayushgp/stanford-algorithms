import collections
"""
G is an object of class Graph from package NetworkX 
"""
def path_exists(node1, node2, G):
    """
    This function checks whether a path exists between two nodes (node1, node2) in graph G.
    """
    discovered=[]
    q=collections.deque()
    q.append(node1)
    discovered.append(node1)
    while len(q)!=0:
        node1=q.popleft()
        for i in G.neighbors(node1):
            if i not in discovered:
                q.append(i)
                discovered.append(i)
    if node2 in discovered:
        return True
    else:
        return False
