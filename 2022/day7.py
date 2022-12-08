data = open("data.txt", "r").read().split('\n')

part1answer = 0
part2answer = []

root = None
current = None

class Dir:

    def __init__(self, name, parent):
        print("new dir: " + name)
        self.name = name
        self.parent = parent
        self.children = []
        self.fileSizeSum = 0

    def __str__(self, level=0):
        ret = "\t"*level + self.name + ": " + str(self.fileSizeSum) + "\n"
        for child in self.children:
            ret += child.__str__(level+1)
        return ret

    def printEverySub100kDir(self):
        global part1answer
        if self.fileSizeSum <= 100000:
            print(self.name + ": " + str(self.fileSizeSum))
            part1answer += self.fileSizeSum
        
        for child in self.children:
            child.printEverySub100kDir()

    def findEveryDirThatFreesEnoughSpace(self):
        global part2answer
        global root
        totalDisk = 70000000
        needSpace = 30000000
        usedSpace = root.fileSizeSum
        freeSpace = totalDisk - usedSpace

        if (freeSpace + self.fileSizeSum) >= needSpace:
            part2answer.append(self.fileSizeSum)

        for child in self.children:
            child.findEveryDirThatFreesEnoughSpace()

#    def printEverySub100kDirButIgnoreDeeper(self):
#        global part1answer
#        if self.fileSizeSum <= 100000:
#            print(self.name + ": " + str(self.fileSizeSum))
#            part1answer += self.fileSizeSum
#        else:
#            for child in self.children:
#                child.printEverySub100kDirButIgnoreDeeper()

for line in data:
    vals = line.split(' ')
    # print(vals)
    if vals[0] == "$":
        # command
        if vals[1] == "cd":
            if vals[2] == "..":
                # go back one dir in path
                current = current.parent
            elif vals[2] != "/":
                node = Dir(vals[2], current)
                current.children.append(node)
                current = node
            else:
                root = Dir("root", None)
                current = root
        continue
    elif vals[0] == "dir":
        # directory (ignore really)
        continue
    elif len(vals[0]) > 0:
        # file
        print(line)
        ncur = current
        while ncur != None:
            ncur.fileSizeSum += int(vals[0])
            ncur = ncur.parent
        continue

# print(root)

# find directories smaller than 100_000
root.printEverySub100kDir()
print("Part 1: " + str(part1answer))

# part 2
root.findEveryDirThatFreesEnoughSpace()
print("Part 2: " + str(sorted(part2answer)))
