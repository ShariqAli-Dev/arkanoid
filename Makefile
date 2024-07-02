build:
	@g++ main.cc -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o arkanoid
run: build
	@./arkanoid