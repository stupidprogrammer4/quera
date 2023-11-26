import numpy as np
n, m, k = [int(x) for x in input().split()]
tab = [[int(x) for x in input().split()] for _ in range(n)]
def is_prime(num: int) -> bool:  # NOQA
    if num <= 1:
        return False
    else:
        for d in range(2, int(num ** 0.5) + 1):
            if num % d == 0:
                return False
        else:
            return True
i = 1
j = 1
while k != 0:
    if is_prime(tab[i - 1][j - 1]):
        i -= 1
        j -= 1
        coordinates = [[(i, j) for j in range(m)] for i in range(n)]
        matrix = np.array(coordinates)
        new_matrix = np.fliplr(np.flipud(matrix))  # flip left-right and flip up-down
        new_matrix = new_matrix.tolist()
        i, j = new_matrix[i][j]
        i += 1
        j += 1
        k -= 1
        continue
    else:
        if tab[i - 1][j - 1] % 4 == 0:
            i -= 1
            j -= 1
            if j + 1 < m:
                j += 1
            else:
                j = 0
            i += 1
            j += 1
            k -= 1
            continue
        if tab[i - 1][j - 1] % 4 == 1:
            i -= 1
            j -= 1
            if i + 1 < n:
                i += 1
            else:
                i = 0
            i += 1
            j += 1
            k -= 1
            continue
        if tab[i - 1][j - 1] % 4 == 2:
            i -= 1
            j -= 1
            if j - 1 >= 0:
                j -= 1
            else:
                j = m - 1
            i += 1
            j += 1
            k -= 1
            continue
        if tab[i - 1][j - 1] % 4 == 3:
            i -= 1
            j -= 1
            if i - 1 >= 0:
                i -= 1
            else:
                i = n - 1
            i += 1
            j += 1
            k -= 1
            continue
print(i, j)