CXX = c++
EXE = ejercicio1
OBJS = main.o mochila.o

all: $(EXE)

$(EXE) : $(OBJS)
	$(CXX) -o $@ $(LDFLAGS) $(LDLIBS) $^

main.o: main.cpp mochila.hpp
	$(CXX) -c $(CXXFLAGS) $<

mochila.o: mochila.cpp mochila.hpp
	$(CXX) -c $(CXXFLAGS) $<

clean:
	$(RM) $(EXE) $(OBJS) core *~