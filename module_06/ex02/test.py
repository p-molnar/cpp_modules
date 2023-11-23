import sys

l = []

for line in sys.stdin:
	l.append(line.strip())
 
l_bool = [l[0] == el for el in l]

if not all(l_bool):
    print("test failed")
    print(l)
else:
    print("test passed")
    