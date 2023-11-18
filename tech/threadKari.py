from threading import Thread
import functions


def run(func):
    threads = []
    for i in range(len(func)):
        threads.append(Thread(target=func[i], name=i+1))
    for t in threads:
        t.start()
    for t in threads:
        t.join()


def solve():
    run(functions.f)
    run(functions.g)
    run(functions.h)
