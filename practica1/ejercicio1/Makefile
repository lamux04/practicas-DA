CXX = c++
EXE = ejercicio1
OBJS = main.o fajos.o

all: $(EXE)

$(EXE) : $(OBJS)
	$(CXX) -o $@ $(LDFLAGS) $(LDLIBS) $^

fajos.o: fajos.cpp fajos.hpp
	$(CXX) -c $(CXXFLAGS) $<

main.o: main.cpp fajos.hpp
	$(CXX) -c $(CXXFLAGS) $<


clean:
	$(RM) $(EXE) $(OBJS) core *~