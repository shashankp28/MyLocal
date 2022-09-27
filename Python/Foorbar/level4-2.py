from itertools import permutations

class BellmanFord:
    def __init__(self, dist, start):
        self.distance_matrix = dist
        self.N = len(dist)
        self.cost = [float('inf')]*self.N
        self.cost[start] = 0
    
    def neg_cycle(self):
        for i in range(self.N):
            for j in range(self.N):
                if self.cost[i] + self.distance_matrix[i][j] < self.cost[j]:
                    return True
        return False
    
    def solve(self):
        for n in range(self.N-1):
            for i in range(self.N):
                for j in range(self.N):
                    self.cost[j] = min(self.cost[j], self.cost[i]+self.distance_matrix[i][j])
        if self.neg_cycle(): return False
        return self.cost

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
    min_distances = []
    
    for i in range(len(times)):
        bellman_ford_i = BellmanFord(times, i)
        temp_min_distances = bellman_ford_i.solve()
        if not temp_min_distances: return [bunny-1 for bunny in bunnies]
        min_distances.append(temp_min_distances[:])
    
    for i in range(no_bunnies, 0, -1):
        path_permutations = list(permutations(bunnies, i))
        for path in path_permutations:
            path = list(path)
            cost = path_cost(min_distances, path[:])
            if cost<=times_limit:
                path.sort()
                return [num-1 for num in path]
    return []


print(solution([[0, 2, 2, 2, -1], [9, 0, 2, 2, -1], [9, 3, 0, 2, -1], [9, 3, 2, 0, -1], [9, 3, 2, 2, 0]], 1))