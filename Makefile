build:
	@g++ main.cc -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o space-invaders
run: build
	@./space-invaders
