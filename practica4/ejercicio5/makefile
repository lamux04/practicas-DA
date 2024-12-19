CXX = g++
CXXFLAGS = -O3
EXE = main
OBJS = main.o damas.o

${EXE}: ${OBJS}
	${CXX} -o $@ ${LDFLAGS} $^ ${LDLIBS}

${OBJS}: damas.hpp

clean:
	${RM} ${EXE} ${OBJS} *~
