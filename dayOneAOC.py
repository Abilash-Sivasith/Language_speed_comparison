import time

"""
Idea:
- put LHS into lhsList
- put RHS into rhsDict
- sort lhsList
- go threw lhsList and multiple the lhsList[i] * rhsMap.at(lhsList[i]) 
"""

def main(filename):
    start_time = time.time()
    lhsList = list()
    rhsDict = dict()

    with open(filename, "r") as file:
        for line in file:
            lhs, rhs = line.split()
            lhsList.append(int(lhs))
            if int(rhs) not in rhsDict:
                rhsDict[int(rhs)] = 1
            else:
                rhsDict[int(rhs)] += 1
        
        lhsList.sort()
        running_sum = 0
        for i in range(len(lhsList)):
            if lhsList[i]  in rhsDict.keys():
                running_sum += (lhsList[i] * rhsDict[lhsList[i]])
        
        print(running_sum)
        end_time = time.time()
        elapsed_time = end_time - start_time
        print(f"Elapsed time: {elapsed_time:.15f} seconds")
            
            
main("testing2.txt")