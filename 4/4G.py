assignments = open("4/assignments.txt", "r").read().splitlines()
count = 0
for a in assignments:
    pairs = a.split(",")
    found = False
    for i in range(len(pairs)):
        for j in range(len(pairs)):
            if i == j or found:
                continue
            A = pairs[i].split("-")
            B = pairs[j].split("-")
            if int(A[1]) < int(B[0]) or int(A[0]) > int(B[1]):
                continue
            found = True
            count = count + 1
print(count)