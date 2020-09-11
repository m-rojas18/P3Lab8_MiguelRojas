all:
	g++ main.cpp \
	-lncurses -o run
clean:
	rm run