targetBin=pushBoxGame.out
obj=main.o map.o player.o
CXXFLAGS=-g -Wall -std=c++11

default: $(obj)
	$(CXX) -o $(targetBin) $^ $(CXXFLAGS)

%.o:%.c
	$(CXX) -c $< -o $@

clean:
	rm $(targetBin)
	rm *.o
