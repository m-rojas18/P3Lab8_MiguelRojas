all:
	g++ main.cpp \
	-lncurses -o ventanas
clean:
	rm ventanas