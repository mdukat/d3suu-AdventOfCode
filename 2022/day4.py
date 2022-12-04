data = []

for line in open("data.txt", "r").readlines():
    line = line.replace('\n', '')
    if len(line) == 0:
        continue

    print(line.split(','))
    pairArray = []
    for pair in line.split(','):
        pairArray.append([int(p) for p in pair.split('-')])

    print(pairArray)
    data.append(pairArray.copy())

print(data)

### Ready data

containPairs = 0

for pair in data:
    aMin = pair[0][0]
    aMax = pair[0][1]
    bMin = pair[1][0]
    bMax = pair[1][1]

    if aMin >= bMin and aMax <= bMax:  # If A in B
        containPairs += 1
    elif bMin >= aMin and bMax <= aMax:  # If B in A
        containPairs += 1

print("Part 1: " + str(containPairs))

### Part 2

overlapPairs = 0

for pair in data:
    aMin = pair[0][0]
    aMax = pair[0][1]
    bMin = pair[1][0]
    bMax = pair[1][1]

    for a in range(aMin, aMax+1):
        # print(str(aMin) + " " + str(aMax) + " = " + str(a))
        if a in range(bMin, bMax+1):
            overlapPairs += 1
            break

print("Part 2: " + str(overlapPairs))
