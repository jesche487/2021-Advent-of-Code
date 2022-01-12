Final answer is received by running the program and subtracting 5 times part 1 answer

REASONING:
special node 1 paths = old + new1
special node 2 paths = old + new2
special node 3 paths = old + new3
special node 4 paths = old + new4
special node 5 paths = old + new5
special node 6 paths = old + new6

Total: 6*old + new(1-6)
 so take total - 5*old to take out overcounting

Main thing with DFS is that you want to reset the state to the OG before it was called
