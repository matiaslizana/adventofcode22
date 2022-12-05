sacks = open("3/sacks.txt", "r").read().splitlines()

total = 0
i = 0
while i < len(sacks):
    num = 0
    for pivot1 in range(len(sacks[i])):
        for pivot2 in range(len(sacks[i + 1])):
            s1 = sacks[i][pivot1]
            s2 = sacks[i + 1][pivot2]
            if s1 == s2:
                for pivot3 in range(len(sacks[i + 2])):
                    s3 = sacks[i + 2][pivot3]
                    if s2 == s3 and num == 0:
                        num = ord(s3) - 38 if s3.isupper() else ord(s3) - 96
                        total = total + num
    i = i + 3
print(total)