CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Ofast
EXE = main
OBJS = main.o damas.o

${EXE}: ${OBJS}
	${CXX} -o $@ ${LDFLAGS} $^ ${LDLIBS}

${OBJS}: damas.hpp

clean:
	${RM} ${EXE} ${OBJS} *~
