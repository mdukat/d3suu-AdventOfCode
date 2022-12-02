dataFile = open("data.txt", "r")
dataString = dataFile.read()
dataArray = dataString.split("\n")

ROCK = ['A', 'X']
PAPER = ['B', 'Y']
SCISSORS = ['C', 'Z']

ROCK_VALUE = 1
PAPER_VALUE = 2
SCISSORS_VALUE = 3

LOSS_VALUE = 0
DRAW_VALUE = 3
WIN_VALUE = 6

score = 0

for data in dataArray:
    if len(data) == 0:
        continue

    OPPONENT_HAND, MY_HAND = data.split(' ')

    if MY_HAND in ROCK:
        if OPPONENT_HAND in ROCK:
            score += DRAW_VALUE
        elif OPPONENT_HAND in PAPER:
            score += LOSS_VALUE
        elif OPPONENT_HAND in SCISSORS:
            score += WIN_VALUE
        score += ROCK_VALUE

    elif MY_HAND in PAPER:
        if OPPONENT_HAND in ROCK:
            score += WIN_VALUE
        elif OPPONENT_HAND in PAPER:
            score += DRAW_VALUE
        elif OPPONENT_HAND in SCISSORS:
            score += LOSS_VALUE
        score += PAPER_VALUE

    elif MY_HAND in SCISSORS:
        if OPPONENT_HAND in ROCK:
            score += LOSS_VALUE
        elif OPPONENT_HAND in PAPER:
            score += WIN_VALUE
        elif OPPONENT_HAND in SCISSORS:
            score += DRAW_VALUE
        score += SCISSORS_VALUE

print("Part 1: " + str(score))

################################## PART 2 ##########################################

NLOSS = 'X'
NDRAW = 'Y'
NWIN = 'Z'

score = 0

for data in dataArray:
    if len(data) == 0:
        continue

    OPPONENT_HAND, SITUATION = data.split(' ')

    if SITUATION == NWIN:
        if OPPONENT_HAND in ROCK:
            score += PAPER_VALUE
        elif OPPONENT_HAND in PAPER:
            score += SCISSORS_VALUE
        elif OPPONENT_HAND in SCISSORS:
            score += ROCK_VALUE
        score += WIN_VALUE

    elif SITUATION == NDRAW:
        if OPPONENT_HAND in ROCK:
            score += ROCK_VALUE
        elif OPPONENT_HAND in PAPER:
            score += PAPER_VALUE
        elif OPPONENT_HAND in SCISSORS:
            score += SCISSORS_VALUE
        score += DRAW_VALUE

    elif SITUATION == NLOSS:
        if OPPONENT_HAND in ROCK:
            score += SCISSORS_VALUE
        elif OPPONENT_HAND in PAPER:
            score += ROCK_VALUE
        elif OPPONENT_HAND in SCISSORS:
            score += PAPER_VALUE
        score += LOSS_VALUE

print("Part 2: " + str(score))
