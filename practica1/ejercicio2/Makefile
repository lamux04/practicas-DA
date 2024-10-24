CXX = c++
EXE = ejercicio2
OBJS = main.o fajos.o

all: $(EXE)

$(EXE) : $(OBJS)
	$(CXX) -o $@ $(LDFLAGS) $(LDLIBS) $^

particion.o: particion.cpp particion.hpp
	$(CXX) -c $(CXXFLAGS) $<

clean:
	$(RM) $(EXE) $(OBJS) core *~