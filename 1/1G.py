from queue import Queue

f = open("1/calories.txt", "r")
calories = f.read().splitlines()
maxCalories = []
numElf = 0
elfCalories = 0
for c in calories:
    if c == "":
        if len(maxCalories) < 3:
            maxCalories.append(elfCalories)
            if len(maxCalories) == 3:
                maxCalories.sort()
        else:
            numElf = 0
            for m in maxCalories:
                if elfCalories > m:
                    maxCalories[numElf] = elfCalories
                    break
                numElf = numElf + 1
        elfCalories = 0
        maxCalories.sort()
    else:
        elfCalories = elfCalories + int(c)

print(sum(maxCalories))