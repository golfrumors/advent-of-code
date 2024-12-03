import re
import functools
import itertools
import collections
from collections import defaultdict
from collections import Counter
import sys
from heapq import heappush, heappop

def diff(head, tail):
        return abs(head[0] - tail[0]) + abs(head[1] - tail[1])

ll = [x for x in open('input.txt').read().strip().split('\n')]
rope = [[0, 4] for z in range(10)]
h = [0, 4]
t = [0, 4]
p1 = ['0 4']
p2 = ['0 4']

for line in ll:
        spl = line.split(" ")
        direction = spl[0]
        mag = int(spl[1])
        dd = (0, 0)

        if(direction == 'R'):
                dd = (1, 0)
        if(direction == 'U'):
                dd = (0, -1)
        if(direction == 'D'):
                dd = (0, 1)
        if(direction == 'L'):
                dd = (-1, 0)

        for i in range(0, mag):

                h[0] += dd[0]
                h[1] += dd[1]
                rope[0][0] += dd[0]
                rope[0][1] += dd[1]

                if(abs(h[0] - t[0]) == 2 and h[1] == t[1]):
                        t[0] += (1 if h[0] > t[0] else -1)

                elif(abs(h[1] - t[1]) == 2 and h[0] == t[0]):
                        t[1] += (1 if h[1] > t[1] else -1)

                elif(h[0] != t[0] and h[1] != t[1] and diff(h, t) > 2):
                        t[0] += (1 if h[0] > t[0] else -1)
                        t[1] += (1 if h[1] > t[1] else -1)


                for j in range(1, 10):
                        head = rope[j - 1]
                        tail = rope[j]
                        if(abs(head[0] - tail[0]) == 2 and head[1] == tail[1]):
                                tail[0] += (1 if head[0] > tail[0] else -1)

                        elif(abs(head[1] - tail[1]) == 2 and head[0] == tail[0]):
                                tail[1] += (1 if head[1] > tail[1] else -1)

                        elif(head[0] != tail[0] and head[1] != tail[1] and diff(head, tail) > 2):
                                tail[0] += (1 if head[0] > tail[0] else -1)
                                tail[1] += (1 if head[1] > tail[1] else -1)


                ty = [str(z) for z in t]
                p1.append(' '.join(ty))
                ts = [str(z) for z in rope[9]]
                p2.append(' '.join(ts))

print('P1', len(set(p1)))
print('P2', len(set(p2)))