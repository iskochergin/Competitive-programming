import random
from collections import defaultdict, deque


def generate_tree(n, root=None, weighted=False, min_weight=1, max_weight=100):
    """
    Generates a random tree with n nodes.

    Arguments:
    n -- the number of nodes
    root -- the root node of the tree (default is randomly chosen)
    weighted -- if True, the tree will have weights on edges
    min_weight -- the minimum weight of edges if weighted
    max_weight -- the maximum weight of edges if weighted

    Returns:
    A string representing the tree with an adjacency list.
    """
    if root is None:
        root = random.randint(1, n)
    elif root < 1 or root > n:
        raise ValueError("Root must be a node between 1 and n")

    edges = []
    nodes = list(range(1, n + 1))
    nodes.remove(root)
    random.shuffle(nodes)
    parent = {root: None}

    for i in range(n - 1):
        u = random.choice(list(parent.keys()))
        v = nodes[i]
        parent[v] = u
        if weighted:
            weight = random.randint(min_weight, max_weight)
            edges.append((u, v, weight))
        else:
            edges.append((u, v))

    result = f"{n}\n"
    for edge in edges:
        if weighted:
            result += f"{edge[0]} {edge[1]} {edge[2]}\n"
        else:
            result += f"{edge[0]} {edge[1]}\n"

    return result


def is_connected_graph(n, edges, oriented=False):
    """
    Checks if the graph with n nodes and given edges is connected.
    """
    adjacency_list = defaultdict(list)
    for edge in edges:
        u, v = edge[:2]
        adjacency_list[u].append(v)
        if not oriented:
            adjacency_list[v].append(u)

    visited = set()
    queue = deque([1])

    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.add(node)
            for neighbor in adjacency_list[node]:
                if neighbor not in visited:
                    queue.append(neighbor)

    return len(visited) == n


def generate_graph(n, m, oriented=False, weighted=False, cyclical=False, min_weight=1, max_weight=100):
    """
    Generates a random graph with n nodes and m edges.

    Arguments:
    n -- the number of nodes
    m -- the number of edges
    oriented -- if True, the graph will be oriented
    weighted -- if True, the graph will have weights on edges
    cyclical -- if True, the graph will be cyclical, otherwise acyclic
    min_weight -- the minimum weight of edges if weighted
    max_weight -- the maximum weight of edges if weighted

    Returns:
    A string representing the graph with an adjacency list.
    """
    edges = set()
    while len(edges) < m:
        u = random.randint(1, n)
        v = random.randint(1, n)
        if u != v:
            if not oriented and (v, u) in edges:
                continue
            if oriented and (u, v) in edges:
                continue
            if weighted:
                weight = random.randint(min_weight, max_weight)
                edges.add((u, v, weight))
            else:
                edges.add((u, v))

    if not is_connected_graph(n, edges, oriented):
        return generate_graph(n, m, oriented, weighted, cyclical, min_weight, max_weight)

    result = f"{n} {m}\n"
    for edge in edges:
        if weighted:
            result += f"{edge[0]} {edge[1]} {edge[2]}\n"
        else:
            result += f"{edge[0]} {edge[1]}\n"

    return result


def generate_array(n, min_value, max_value):
    """
    Generates a random array of size n with elements ranging from min_value to max_value.

    Arguments:
    n -- the size of the array
    min_value -- the minimum value of elements in the array
    max_value -- the maximum value of elements in the array

    Returns:
    A string representing the array.
    """
    array = [random.randint(min_value, max_value) for _ in range(n)]
    return ' '.join(map(str, array))


if __name__ == '__main__':
    pass
