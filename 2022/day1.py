caloriesArray = []
for entry in open("data.txt", "r").read().split("\n\n"):
  calories = 0
  for cal in entry.split("\n"):
    calories += (int(cal) if (len(entry) > 0) else 0)
  caloriesArray.append(calories)
caloriesArray.sort()
print("Part 1: " + str(caloriesArray[-1]) + "\nPart 2: " + str(sum(caloriesArray[-3:])))
