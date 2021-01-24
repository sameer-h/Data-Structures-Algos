
all: Collection.o Stress_ball.o main.o
	g++ -std=c++11 Collection.o Stress_ball.o main.o -o test

Stress_ball.o: Stress_ball.cpp Stress_ball.h
	g++ -std=c++11 -c -g Stress_ball.cpp

Collection.o: Collection.cpp Collection.h
	g++ -std=c++11 -c -g Collection.cpp

main.o: main.cpp Collection.h Stress_ball.h
	g++ -std=c++11 -c -g main.cpp

clean:
	rm *.o test

run: test
	./test