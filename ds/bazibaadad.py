def divisors_sieve(limit):
    divisors = [[] for _ in range(limit)]
    for i in range(1, limit):
        for j in range(i, limit, i):
            divisors[j].append(i)
    return divisors
a, b = [int(x) for x in input().split()]
divisors = [j for j in divisors_sieve(b + 1)]
dp = [10e5] * (int(10e5))
dp[a] = 0
for i in range(a, b + 1):
    for d in divisors[i][1:-1]:
        dp[i + d] = min(dp[i + d], dp[i] + 1)
print("-1" if dp[b] == 10e5 else dp[b])