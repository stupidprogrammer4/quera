n, k = list(map(int, input().split()))
plane_ids = [input() for _ in range(n)]
q = int(input())
orders = [input() for _ in range(q)]

list_of_all_planes = {}

for p in plane_ids:
    list_of_all_planes[p] = 1


bounds = [0] * k
bounds_planes = ["1"] * k


def first_free() -> int:
    global bounds
    for i in range(k):
        if bounds[i] == 0:
            return i


def last_free() -> int:
    global bounds
    if 0 in bounds:
        return len(bounds) - 1 - bounds[::-1].index(0)
    else:
        return len(bounds) - 1

seen = [*plane_ids]


def make_actions(request: str):
    global list_of_all_planes, bounds
    request_type, request_id = request.split()

    if request_type == "TAKE-OFF":
        if request_id not in seen:
            list_of_all_planes[request_id] = 4
            print("YOU ARE NOT HERE")
            seen.append(request_id)
        elif list_of_all_planes[request_id] == 1 and 0 not in bounds:
            print("NO FREE BOUND")
        elif list_of_all_planes[request_id] == 1 and 0 in bounds:
            bounds_planes[first_free()] = request_id
            bounds[first_free()] = 1
            list_of_all_planes[request_id] = 2
        elif list_of_all_planes[request_id] == 2:
            print("YOU ARE TAKING OFF")
        elif list_of_all_planes[request_id] == 3:
            print("YOU ARE LANDING NOW")
        elif list_of_all_planes[request_id] == 4:
            print("YOU ARE NOT HERE")

    if request_type == "LANDING":
        if request_id not in seen:
            list_of_all_planes[request_id] = 4
            if 0 not in bounds:
                print("NO FREE BOUND")
            if 0 in bounds:
                bounds_planes[last_free()] = request_id
                bounds[last_free()] = 1
                list_of_all_planes[request_id] = 3
                seen.append(request_id)
        elif list_of_all_planes[request_id] == 1:
            print("YOU ARE HERE")
        elif list_of_all_planes[request_id] == 2:
            print("YOU ARE TAKING OFF")
        elif list_of_all_planes[request_id] == 3:
            print("YOU ARE LANDING NOW")
        elif list_of_all_planes[request_id] == 4 and 0 not in bounds:
            print("NO FREE BOUND")
        elif list_of_all_planes[request_id] == 4 and 0 in bounds:
            bounds_planes[last_free()] = request_id
            bounds[last_free()] = 1
            list_of_all_planes[request_id] = 3
    if request_type == "PLANE-STATUS":
        if request_id not in seen:
            print(4)
        else:
            print(list_of_all_planes[request_id])
    if request_type == "BAND-STATUS":
        if bounds[int(request_id) - 1] == 0:
            print("FREE")
        else:
            print(bounds_planes[int(request_id) - 1])


for o in orders:
    make_actions(o)