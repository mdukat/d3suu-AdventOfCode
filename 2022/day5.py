file = open("data.txt", "r").read()

dataBlocks = file.split("\n\n")
#print(dataBlocks[0])

## print line by line
#for line in dataBlocks[0].split('\n'):
#    print(line)
#
#    c = 1
#    for a in range(1, len(line), 4):
#        print(str(c) + ": " + line[a])
#        c += 1

stacks = []
stackLines = dataBlocks[0].split('\n')

# make arrays for each stack
for a in range(1, len(stackLines[0]), 4):
    stacks.append([])
print(stacks)

# print from bottom
for a in reversed(range(0, len(stackLines))):

    # Don't print (add to stack) the stack numbers
    if a == len(stackLines) - 1:
        continue
    print(stackLines[a])
    # print each "box" (crate)
    c = 1
    for boxIndex in range(1, len(stackLines[a]), 4):
        letter = stackLines[a][boxIndex]
        if letter != ' ':
            #print(str(c) + ": " + letter)
            stacks[c-1].append(letter)
        c += 1
        
# Stacks should now have array for each stack, in format: last = top
print(stacks)

# Move crates between stacks
for line in dataBlocks[1].split('\n'):
    line = line.replace("move ", "").replace(" from ", ",").replace(" to ", ",").split(',')
    moveDataLine = [int(w) for w in line]
    #print(moveDataLine)

    cratesToMove = moveDataLine[0]
    moveFrom = moveDataLine[1]-1
    moveTo = moveDataLine[2]-1
    for numberOfCrates in range(0, cratesToMove):
        stacks[moveTo].append(stacks[moveFrom].pop())

print(stacks)

# Part 1 answer
partOneAnswer = ""
for stack in stacks:
    partOneAnswer += stack.pop()

print("Part 1: " + partOneAnswer)

######################################## PART 2

stacks = []
stackLines = dataBlocks[0].split('\n')

# make arrays for each stack
for a in range(1, len(stackLines[0]), 4):
    stacks.append([])
print(stacks)

# print from bottom
for a in reversed(range(0, len(stackLines))):

    # Don't print (add to stack) the stack numbers
    if a == len(stackLines) - 1:
        continue
    print(stackLines[a])
    # print each "box" (crate)
    c = 1
    for boxIndex in range(1, len(stackLines[a]), 4):
        letter = stackLines[a][boxIndex]
        if letter != ' ':
            #print(str(c) + ": " + letter)
            stacks[c-1].append(letter)
        c += 1
        
# Stacks should now have array for each stack, in format: last = top
print(stacks)

# Move crates between stacks
for line in dataBlocks[1].split('\n'):
    line = line.replace("move ", "").replace(" from ", ",").replace(" to ", ",").split(',')
    moveDataLine = [int(w) for w in line]
    #print(moveDataLine)

    cratesToMove = moveDataLine[0]
    moveFrom = moveDataLine[1]-1
    moveTo = moveDataLine[2]-1
    # For crate in correct order from top
    for a in stacks[moveFrom][cratesToMove * -1:].copy():
        stacks[moveTo].append(a)  # Append to destination
        stacks[moveFrom].pop()  # Remove from source
        print(a)

print(stacks)

# Part 2 answer
partTwoAnswer = ""
for stack in stacks:
    partTwoAnswer += stack.pop()

print("Part 2: " + partTwoAnswer)
