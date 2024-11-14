CXX = c++
EXE = ejercicio1
OBJS = main.o matrices.o

all: $(EXE)

$(EXE) : $(OBJS)
	$(CXX) -o $@ $(LDFLAGS) $(LDLIBS) $^

main.o: main.cpp matrices.hpp cronometro.hpp
	$(CXX) -c $(CXXFLAGS) $<

matrices.o: matrices.cpp matrices.hpp
	$(CXX) -c $(CXXFLAGS) $<

clean:
	$(RM) $(EXE) $(OBJS) core *~