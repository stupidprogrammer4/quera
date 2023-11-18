import os

def combet(type1, type2, path):
    t1 = 0
    t2 = 0
    file_count = {}
    for dir in os.walk(path):
        for file in dir[2]:
            name, ext = os.path.splitext(file)
            if not file_count.get(name):
                file_count[name] = [0, 0]
            file_count[name][0] += 1 
            if ext[1:].lower() == type1.lower(): 
                t1 += 1
                file_count[name][1] += 1
            elif ext[1:].lower() == type2.lower(): 
                t2 += 1
                file_count[name][0] -= 1
    if t2 > t1: 
        return 'Win! Normally!'
    for k, v in file_count.items():
        if t2 + v[0] > t1 - v[1]:
            return f"Win! you can win if you cheat on '{k}'!"
    return "Lose! you can't win this game!"
