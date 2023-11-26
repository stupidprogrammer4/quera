n = int(input())
key = input()
rotors = [input() for _ in range(n)]
s = 0
for i in range(n):
    if rotors[i].index(key[i]) <= len(rotors[i]) // 2:
        s += rotors[i].index(key[i])
    else:
        s += len(rotors[i]) - rotors[i].index(key[i])
print(s)