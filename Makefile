CPPFLAGS = --std=c++14 -Wall -Wextra

.PHONY: all
all: main.exe

%.exe: %.cpp
	g++ -o $@ $(CPPFLAGS) $<

.PHONY: clean
clean:
	rm -rf *.exe