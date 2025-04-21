COMPILE.C 	= $(COMPILE.cc)
COMPILE.cc 	= $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
CXXFLAGS 	=-g3 -I headers 
CPPFLAGS 	= -Wall -Wextra -Wpedantic 
CXX 		= g++
OUTPUT_OPTION = -o $@

#Linking:
LINK.o 		= $(CC) $(LDFLAGS) $(TARGET_ARCH)
CC			= g++
#Libraries:

SMFL_LIBRARY = -lsfml-graphics -lsfml-window -lsfml-system

vpath %.cc sources
vpath %.h headers

#rules:

%: %.o 
	$(LINK.o) $(OUTPUT_OPTION) $<
%.o: %.c++
	$(COMPILE.C) $(OUTPUT_OPTION) $<

run: main
	./main

main: main.o game.o shot.o asteroid.o
	$(LINK.o) $(OUTPUT_OPTION) $^ $(SMFL_LIBRARY)

main.o: main.cc main.h 
shot.o: shot.cc shot.h
game.o: game.cc game.h
asteroid.o: asteroid.cc asteroid.h

.INTERMEDIATE: *.o

.PHONY: depend #Now the file will be updated each time it is called.
depend: c++.cc
	g++ -I headers -M $(CPPFLAGS) $^ > $@
	more depend

.PHONY:clean
clean:
	rm -rf *.o c++