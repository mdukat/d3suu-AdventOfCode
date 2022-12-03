prioritiesSum = 0


def itemToPriority(itemInput):
    # From ascii table, calculate priority value
    priority = ord(itemInput) - ord('a') + 1
    if priority <= 0:  # Big char
        priority += 58

    return priority


for rucksack in open("data.txt", "r").readlines():
    rucksack = rucksack.replace('\n', '')
    halfRucksack = int(len(rucksack) / 2)
    # print(rucksack + " = " + rucksack[0:halfRucksack] + " " + rucksack[halfRucksack:])

    firstCompartment = rucksack[0:halfRucksack]
    secondCompartment = rucksack[halfRucksack:]

    for item in firstCompartment:
        if item in secondCompartment:
            prioritiesSum += itemToPriority(item)
            # print(firstCompartment + " " + secondCompartment + " = " + item + " (" + str(itemToPriority(item)) + ")")
            break  # Only one item per line, ignore rest

print("Part 1: " + str(prioritiesSum))

#################################### PART 2 #########################################

# Split rucksack list into 3s
rucksackGroups = []
prioritiesSum = 0

data = open("data.txt", "r").readlines()

for i in range(0, len(data), 3):
    rucksackGroups.append(data[i:i+3])

for rucksackGroup in rucksackGroups:  # For each group of 3 rucksacks
    for item in rucksackGroup[0].replace('\n', ''):  # Fixme: replace for each string in group
        if item in rucksackGroup[1].replace('\n', '') and item in rucksackGroup[2].replace('\n', ''):  # If any item in first rucksack is in second and third
            prioritiesSum += itemToPriority(item)  # Add this items priority value
            break  # Go to next group of 3s

print("Part 2: " + str(prioritiesSum))
