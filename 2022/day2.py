dataFile = open("data.txt", "r")
dataString = dataFile.read()
dataArray = dataString.split("\n")

ROCK = ['A', 'X']
PAPER = ['B', 'Y']
SCISSORS = ['C', 'Z']

ROCKv = 1
PAPERv = 2
SCISSORSv = 3

LOSS = 0
DRAW = 3
WIN = 6

score = 0

for data in dataArray:
    if len(data) == 0:
        continue

    data = data.split(' ')

    if data[1] in ROCK:
        if data[0] in ROCK:
            score += DRAW + ROCKv
        elif data[0] in PAPER:
            score += LOSS + ROCKv
        elif data[0] in SCISSORS:
            score += WIN + ROCKv
    elif data[1] in PAPER:
        if data[0] in ROCK:
            score += WIN + PAPERv
        elif data[0] in PAPER:
            score += DRAW + PAPERv
        elif data[0] in SCISSORS:
            score += LOSS + PAPERv
    elif data[1] in SCISSORS:
        if data[0] in ROCK:
            score += LOSS + SCISSORSv
        elif data[0] in PAPER:
            score += WIN + SCISSORSv
        elif data[0] in SCISSORS:
            score += DRAW + SCISSORSv

print("Part 1: " + str(score))

################################## PART 2 ##########################################

NLOSS = 'X'
NDRAW = 'Y'
NWIN = 'Z'

score = 0

for data in dataArray:
    if len(data) == 0:
        continue

    data = data.split(' ')

    if data[1] == NWIN:
        if data[0] in ROCK:
            score += WIN + PAPERv
        elif data[0] in PAPER:
            score += WIN + SCISSORSv
        elif data[0] in SCISSORS:
            score += WIN + ROCKv
    elif data[1] == NDRAW:
        if data[0] in ROCK:
            score += DRAW + ROCKv
        elif data[0] in PAPER:
            score += DRAW + PAPERv
        elif data[0] in SCISSORS:
            score += DRAW + SCISSORSv
    elif data[1] == NLOSS:
        if data[0] in ROCK:
            score += LOSS + SCISSORSv
        elif data[0] in PAPER:
            score += LOSS + ROCKv
        elif data[0] in SCISSORS:
            score += LOSS + PAPERv

print("Part 2: " + str(score))
