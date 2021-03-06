CC=g++
CXXFLAGS= -std=c++1z
INC = 
LIBS = 
CURLLIB=
TARGET=bin
OBJ=main.cpp Individual.cpp Population.cpp FitnessCalculation.cpp Algorithm.cpp HyperparameterSet.cpp HyperparameterSearch.cpp

default: $(TARGET)
all: $(TARGET)

$(TARGET): $(OBJ)
	 $(CC) $(INC) $(OBJ) $(CXXFLAGS) -o $(TARGET) $(LIBS) $(CURLLIB) 

run:$(TARGET)
	./$(TARGET)
	python3 ./python/sensitivityPlots.py