import os
import re

with open('input.txt') as f:
	lines = f.readlines()

i = 0
curdir = None
dirs = {}
subdirs = {}
for line in lines:
	if len(line.strip()) == 0: continue
	if line[0] == '$':
		c, cmd, *args = line.split()
		if cmd == 'cd':
			path ,= args
			if path[0] == '/':
				curdir = path
			else:
				curdir = os.path.normpath(os.path.join(curdir, path))

			if curdir not in dirs:
				dirs[curdir] = 0
				subdirs[curdir] = []

	else:
		sz, fname = line.split()
		if sz != 'dir':
			dirs[curdir] += int(sz)
		else:
			subdirs[curdir].append(os.path.normpath(os.path.join(curdir, fname)))

dirsizes = {}
def dirsize(dirname):
	dsize = dirs[dirname]
	for i in subdirs[dirname]:
		if i in dirs:
			dsize += dirsize(i)
	return dsize

totsize = 0

for d in dirs:
	dsize = dirsize(d)
	if dsize <= 100000:
		totsize+=dsize

print("Part one: ",totsize)

totsize = dirsize('/')
unused = 70000000 - totsize
ms = None
for d in dirs:
	ds = dirsize(d)
	if unused + ds >= 30000000:
		if ms is None or ms > ds:
			ms = ds
print("Part two: ",ms)