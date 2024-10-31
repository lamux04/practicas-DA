CXX = c++
EXE = main
OBJS = main.o particion.o

all: $(EXE)

$(EXE) : $(OBJS)
	$(CXX) -o $@ $(LDFLAGS) $(LDLIBS) $^

main.o: main.cpp grafo.hpp grafo-ponderado.hpp particion.hpp cronometro.hpp
	$(CXX) -c $(CXXFLAGS) $<

particion.o: particion.cpp particion.hpp
	$(CXX) -c $(CXXFLAGS) $<

clean:
	$(RM) $(EXE) $(OBJS) core *~