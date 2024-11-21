CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
EXE = prueba
OBJS = prueba.o matriz.o

${EXE}: ${OBJS}
	${CXX} -o $@ ${LDFLAGS} $^ ${LDLIBS}

${OBJS}: matriz.hpp matriz-inline.hpp cronometro.hpp

clean:
	${RM} ${EXE} ${OBJS} *~
