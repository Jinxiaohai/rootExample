# Created  by  xiaohai
EXE=main.exe
OBJS=main.o
CC=g++
CFLAGE= -Wall -g -std=c++11

$(EXE):$(OBJS)
	$(CC) $(OBJS) -o $(EXE)

$(OBJS):main.cpp
	$(CC) $(CFLAGE) -c main.cpp

.PHONY:clean
clean:
	-rm $(OBJS) $(EXE)
