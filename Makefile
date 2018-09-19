CPPFLAGS = --std=c++14 -Wall -Wextra
INCLUDES = -I E:\Code\mingw_dev_libs\include
LINK = -L E:\Code\mingw_dev_libs\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

LIB_CPPS = GlobalLib.cpp
HPPS = GlobalLib.hpp

.PHONY: all
all: main.exe

%.exe: %.cpp $(LIB_CPPS) $(HPPS)
	g++ $< $(LIB_CPPS) $(INCLUDES) $(CPPFLAGS) $(LINK) -o $@

.PHONY: clean
clean:
	rm -rf *.exe