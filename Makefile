COMPILER = c++ -fpermissive -w -D__VERBOSE__ -D__DEBUG__ -static -g
#COMPILER = c++ -fpermissive -w -D__USE_BOINC__ -D__VERBOSE__ -static
#COMPILER = c++ -fpermissive -w -D__VERBOSE__ -static

all: libdnstd.a

libdnstd.a: DNode.o DList.o DTree.o Binary.o Character.o Complex.o DArray.o DavidException.o DHashMap.o Double.o DRandom.o DStack.o DString.o StringTokenizer.o NumericalIntegration.o
	ar rcs $@ $^

clean:
	rm -f *.o *.exe *.out *stackdump* libdnstd.a


.cpp.o: 
	${COMPILER} -c $<
