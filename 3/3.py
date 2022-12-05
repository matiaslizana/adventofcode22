sacks = open("3/sacks.txt", "r").read().splitlines()

total = 0
for s in sacks:
    num = 0
    for lpivot in range(int(len(s)/2)):
        for rpivot in range(int(len(s)/2), len(s)):
            if s[lpivot] == s[rpivot]:
                num = ord(s[lpivot]) - 38 if s[lpivot].isupper() else ord(s[lpivot]) - 96
                break
        if num != 0:
            total = total + num
            break
print(total)