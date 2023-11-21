n = int(input())
lines = [input() for _ in range(n)]
def run(l: str, local_vars: dict):  # NOQA
    if ":=" in l:
        l = l.replace(":=", "=")
        exec(l, local_vars)
    elif l.startswith("print"):
        _, content = l.split(maxsplit=1)
        print(eval(content, local_vars))
local_variables = {}  # Dictionary to store local variables
for line in lines:
    run(line, local_variables)