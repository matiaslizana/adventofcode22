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
            if int(A[0]) - int(B[0]) >= 0 and int(A[1]) - int(B[1]) <= 0:
                found = True
                count = count + 1
print(count)