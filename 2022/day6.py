def charactersBeforeStartOfPacketMarker(inputData):  # Made for first part
    for i in range(0, len(inputData)-4):
        marker = inputData[i:i+4]
        statusBuffer = 0
        for j in range(0,4):
            # For each character in marker
            char = marker[j]
            markerCopy = marker.replace(char, "", 1)
            if not (char in markerCopy):
                statusBuffer += 1
        if statusBuffer == 4:
            return i+4


def charactersBeforeStartOfNDifferentCharactersMarker(inputData, N):  # Made to work with first and second part (needs longer name)
    for i in range(0, len(inputData)-N):
        marker = inputData[i:i+N]
        statusBuffer = 0
        for j in range(0,N):  # For each character in marker
            char = marker[j]  # Get that character
            markerCopy = marker.replace(char, "", 1)  # Remove single instance of that character from marker
            if not (char in markerCopy):  # Check if character is still in marker
                statusBuffer += 1
        if statusBuffer == N:  # If every character is different, return
            return i+N


# Data
data = open("data.txt", "r").read()

# Sanity tests
assert(charactersBeforeStartOfPacketMarker("mjqjpqmgbljsphdztnvjfqwrcgsmlb") == 7)
assert(charactersBeforeStartOfPacketMarker("bvwbjplbgvbhsrlpgdmjqwftvncz") == 5)
assert(charactersBeforeStartOfPacketMarker("nppdvjthqldpwncqszvftbrmjlhg") == 6)
assert(charactersBeforeStartOfPacketMarker("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg") == 10)
assert(charactersBeforeStartOfPacketMarker("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw") == 11)

print("Part 1: " + str(charactersBeforeStartOfPacketMarker(data)))

# Sanity tests
assert(charactersBeforeStartOfNDifferentCharactersMarker("mjqjpqmgbljsphdztnvjfqwrcgsmlb", 14) == 19)
assert(charactersBeforeStartOfNDifferentCharactersMarker("bvwbjplbgvbhsrlpgdmjqwftvncz", 14) == 23)
assert(charactersBeforeStartOfNDifferentCharactersMarker("nppdvjthqldpwncqszvftbrmjlhg", 14) == 23)
assert(charactersBeforeStartOfNDifferentCharactersMarker("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg", 14) == 29)
assert(charactersBeforeStartOfNDifferentCharactersMarker("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw", 14) == 26)

print("Part 2: " + str(charactersBeforeStartOfNDifferentCharactersMarker(data, 14)))
