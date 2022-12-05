f = open("1/calories.txt", "r")
calories = f.read().splitlines()
maxCalories = 0
elfCalories = 0
for c in calories:
    if c == "":
        if elfCalories > maxCalories:
            maxCalories = elfCalories
        elfCalories = 0
    else:
        elfCalories = elfCalories + int(c)
print(maxCalories)
