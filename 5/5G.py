crates = open("5/crates.txt", "r").read().splitlines()
stacks = [[], [], [], [], [], [], [], [], []]
for c in reversed(crates[:8]):
    for i in range(9):
        si = i * 4 + 1
        if si > len(c):
            break
        if c[si] != " ":
            stacks[i].append(c[si])
for c in crates[10:]:
    orders = c.split(" ")
    elist = []
    for n in range(int(orders[1])):
        elist.append(stacks[int(orders[3]) - 1].pop())
    for e in reversed(elist):
        stacks[int(orders[5]) - 1].append(e)
for s in stacks:
    print(s.pop(), end="")
