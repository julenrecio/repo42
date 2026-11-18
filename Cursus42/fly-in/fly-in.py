import sys

map: str = sys.argv[1]
f = open(map, 'r')
content = f.read()
print(content)
f.close()