n = int(input())
tab = [[int(x) for x in input().split()] for _ in range(n)]
cnt = 0
for i in range(n):
    for j in range(len(tab[0])):
        neighbors = [tab[i][j]]
        if j + 1 < n:
            neighbors.append(tab[i][j + 1])
        if j - 1 >= 0:
            neighbors.append(tab[i][j - 1])
        if i + 1 < n:
            neighbors.append(tab[i + 1][j])
        if i - 1 >= 0:
            neighbors.append(tab[i - 1][j])
        if min(neighbors) == tab[i][j]:
            cnt += 1
print(cnt)