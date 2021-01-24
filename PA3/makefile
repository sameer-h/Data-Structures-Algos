all: Stress_ball.o Stress_ball_test.o Jeans.o Jeans_test.o Collection-test.o
	g++ -std=c++11 Stress_ball.o Stress_ball_test.o Collection-test.o Jeans.o Jeans_test.o -o test
Stress_ball.o: Stress_ball.cpp Stress_ball.h
	g++ -std=c++11 -c Stress_ball.cpp
Stress_ball_test.o: Stress_ball_test.cpp	
	g++ -std=c++11 -c Stress_ball_test.cpp
Jeans.o: Jeans.cpp Jeans.h
	g++ -std=c++11 -c Jeans.cpp
Jeans_test.o: Jeans_test.cpp
	g++ -std=c++11 -c Jeans_test.cpp
Collection-test.o: Collection-test.cpp
	g++ -std=c++11 -c Collection-test.cpp
clean:
	rm -f *.o test
run: test
	./test