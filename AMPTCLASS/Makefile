##########################################################
##                 Created  by  xiaohai                 ##
##                 Telphone : 18501781924               ##
##            E-mail : jinxiaohai@sinap.ac.cn           ##
##            E-mail : xiaohaijin@outlook.com           ##
##   Address : Shanghai Institute of Applied Physics    ##
##########################################################

EXE=main.exe
OBJS=main.o
CC=g++
CFLAGE= -Wall -g -std=c++11

$(EXE):$(OBJS)
	$(CC) $(OBJS) -o $(EXE)

$(OBJS):main.cpp	;	$(CC) $(CFLAGE) -c main.cpp

.PHONY:clean
clean:
	-rm $(OBJS) $(EXE)
