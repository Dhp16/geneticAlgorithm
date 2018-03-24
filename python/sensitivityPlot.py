#script to read and plot the time taken vs different hyperparameters
import matplotlib.pyplot as plt


def createListFrom(list, subElementIndex):
    newList = []
    for i in list:
        newList.append(i[subElementIndex])
    return newList

## Import Data ##
tests = []

with open("../results/hyperparametersTested.txt") as file:
    for line in file:
        parameters = line.split()
        parameters[-1] = parameters[-1].rstrip()
        for i in range(0, len(parameters)):
            if(i < 2 or i == 4 or i == 5):
                parameters[i] = int(parameters[i])
            else:
                parameters[i] = float(parameters[i])

        tests.append(parameters)

length = tests[0][0];
tests.pop(0)

# order of the parameters: population size, 
# tournament size, 
# uniform rate, 
# mutation rate, 
# elitism, 
# time

## All lists ##
allPopulations = createListFrom(tests, 0)
allTournamentSizes = createListFrom(tests, 1)
allUniformRates = createListFrom(tests, 2)
allMutationRates = createListFrom(tests, 3)
allGenerationCounts = createListFrom(tests, 5)
allTimes = createListFrom(tests, 6)


withElitism = [] 
withoutElitism = []

for parameterSet in tests:
    if(parameterSet[4] == 1):
        withElitism.append(parameterSet)
    else:
        withoutElitism.append(parameterSet)

timeWithElitism = createListFrom(withElitism, 6)
timeWithoutElitism = createListFrom(withoutElitism, 6)

title = "Sensitivity to different hyperparameters for solution of length " + str(length)

figure1 = plt.figure()
plt.suptitle(title, fontsize=16)

graph1 = figure1.add_subplot(231)
graph1.plot(timeWithElitism, 'o', label='elitism')
graph1.plot(timeWithoutElitism, '*', label='no elitism')

graph1.set_xlabel('iteration number [-]')
graph1.set_ylabel('time (s)')

figure1.patch.set_facecolor('white')
graph1.legend(loc=1)

### plot 2 ###
graph2 = figure1.add_subplot(232)
graph2.plot(allPopulations, allTimes, 'o')

graph2.set_xlabel('Population size [-]')
graph2.set_ylabel('time (s)')

### plot 3 ###
graph3 = figure1.add_subplot(233)
graph3.plot(allTournamentSizes, allTimes, 'o')

graph3.set_xlabel('TournamentSize size [-]')
graph3.set_ylabel('time (s)')

### plot 4 ###
graph4 = figure1.add_subplot(234)
graph4.plot(allUniformRates, allTimes, 'o')

graph4.set_xlabel('Uniform Rate [-]')
graph4.set_ylabel('time (s)')

### plot 5 ###
graph5 = figure1.add_subplot(235)
graph5.plot(allMutationRates, allTimes, 'o')

graph5.set_xlabel('Mutation Rate [-]')
graph5.set_ylabel('time (s)')

### plot 6 ###
graph6 = figure1.add_subplot(236)
graph6.plot(allGenerationCounts, allTimes, 'o')

graph6.set_xlabel('Generation Count [-]')
graph6.set_ylabel('time (s)')


plt.show()


