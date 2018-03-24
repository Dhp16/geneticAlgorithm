# script to read and plot the fitness

import matplotlib.pyplot as plt

## Import Data ##
fitness = []
with open("results/Fitness.txt") as file:
    for line in file:
        line = line.strip() 
        fitness.append(line)

n_elements = len(fitness)

## Plot ##
fig1 = plt.figure()
ax1 = fig1.add_subplot(111)
ax1.plot(fitness, '-o')

plt.title('Fitness evolution')
ax1.set_ylabel('fitness [-]')
ax1.set_xlabel('generation [-]')
ax1.legend(loc=4)
fig1.patch.set_facecolor('white')

plt.show()
