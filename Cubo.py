import multiprocessing as mp
import random
import string


def cube(x):
    return x**3


pool = mp.Pool(processes=4)
results = [pool.apply(cube, args=(x,)) for x in range(1,17)]
print(results)

#OOOOOO It could be

results = pool.map(cube, range(1,17))
print(results)

#asincrono

pool = mp.Pool(processes=4)
results = [pool.apply_async(cube, args=(x,)) for x in range(1,17)]
output = [p.get() for p in results]
print(output)
