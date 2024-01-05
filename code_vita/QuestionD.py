def max_e( n, conflicts, expertise):
    max_expertise = 0 
    for mask in range(1 << n):
        valid_team = True
        expertise_sum= 0
        for i in range(n):
            if mask & (1 << i):
                expertise_sum += expertise[i]
                for j in range(n):
                    if mask & (1<<j) and conflicts[i][j]:
                        valid_team = False
                        break
                if not valid_team:
                    break
        if valid_team:
            max_expertise = max(max_expertise, expertise_sum)
    return max_expertise
n , c =  map(int, input().split())
conflicts = [[False] * n for _ in range(n)]

for _ in range(c):
    a, b = map(int, input().split())
    conflicts[a - 1][b - 1] = True
    conflicts[b - 1][a - 1] = True
expertise_levels = list(map(int , input().split()))
res = max_e(n , conflicts, expertise_levels)
print(res)