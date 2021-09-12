
output: paddle.o ball.o main.o
	g++ paddle.o ball.o main.o -o breakout -L src/lib -l sfml-graphics -l sfml-window -l sfml-system

paddle.o: src/paddle.cpp src/paddle.h
	g++ -I src/include -c src/paddle.cpp

ball.o: src/ball.cpp src/ball.h
	g++ -I src/include -c src/ball.cpp

main.o: src/main.cpp
	g++ -I src/include -c src/main.cpp
