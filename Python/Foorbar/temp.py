from itertools import permutations

def BellmanFord(times):
    N = len(times)
    min_distances = []
    for n in range(N):
        min_distance = [float('inf')]*N
        min_distance[n] = 0
        
        # Relax Edges for N-1 interations
        for i in range(N-1):
            for u in range(N):
                for v in range(N):
                    min_distance[v] = min(min_distance[v], min_distance[u] + times[u][v])
        
        # Check for negative cycle.
        for u in range(N):
            for v in range(N):
                if min_distance[u] + times[u][v] < min_distance[v]:
                    return False
        
        min_distances.append(min_distance[:])
    return min_distances

def path_cost(distances, path):
    N = len(distances)
    path.insert(0, 0)
    path.append(N-1)
    cost = 0
    for i in range(len(path)-1):
        cost += distances[path[i]][path[i+1]]
    return cost

def solution(times, times_limit):
    no_bunnies = len(times) - 2
    bunnies = [x for x in range(1, no_bunnies+1)]
    
    distances = BellmanFord(times)
    
    if not distances: return [bunny-1 for bunny in bunnies]
    
    for n in range(no_bunnies, 0, -1):
        for path in list(permutations(bunnies, n)):
            path = list(path)
            current_path_cost = path_cost(distances, path[:])
            if current_path_cost<=times_limit:
                return [bunny-1 for bunny in path]
    return []

print(solution([[0, 1, 1, 1, 1], [1, 0, 1, 1, 1], [1, 1, 0, 1, 1], [1, 1, 1, 0, 1], [1, 1, 1, 1, 0]], 3))