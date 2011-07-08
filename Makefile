BUILD = test
.PHONY: all $(BUILD) clean

test: main.o libmsdoc.so
	$(CXX) -L. main.o -lmsdoc -o test
	LD_LIBRARY_PATH="/disk/projects/libmsdoc" ./test

all: $(BUILD)

clean:
	rm -rf *.o *.so

OBJ = csharedstrings.o csharedstring.o csharedstringobject.o cspreadsheets.o cspreadsheet.o cspreadsheetobject.o
CXXFLAGS = -g -fPIC

%.so: ${OBJ}
	$(CXX) ${CXXFLAGS} ${OBJ} -shared -o $@

