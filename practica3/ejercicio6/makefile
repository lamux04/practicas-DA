CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Ofast
EXE = main
OBJS = main.o

${EXE}: ${OBJS}
	${CXX} -o $@ ${LDFLAGS} $^ ${LDLIBS}

${OBJS}: ordenacion.hpp cronometro.hpp

clean:
	${RM} ${EXE} ${OBJS} *~
