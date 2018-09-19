CPPFLAGS = --std=c++14 -Wall -Wextra
INCLUDES = -I E:\Code\mingw_dev_libs\include
LINK = -L E:\Code\mingw_dev_libs\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

.PHONY: all
all: main.exe

%.exe: %.cpp
	g++ $(LINK) $(INCLUDES) $(CPPFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -rf *.exe