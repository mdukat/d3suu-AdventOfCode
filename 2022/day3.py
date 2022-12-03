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
            print(firstCompartment + " " + secondCompartment + " = " + item + " (" + str(itemToPriority(item)) + ")")
            break  # Only one item per line, ignore rest

print(prioritiesSum)
