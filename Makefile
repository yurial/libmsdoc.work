BUILD = test
.PHONY: all $(BUILD) clean

test: main.o libmsdoc.so Makefile
	$(CXX) -L. main.o -lzip -lmsdoc -o test
	rm -f test.zip
	LD_LIBRARY_PATH="." ./test

all: $(BUILD)

clean:
	rm -rf *.o *.so

OBJ = czip.o cdoc.o cdocxlsx.o crelationships.o crelationship.o crelationshipobject.o ccontent.o cworkbook.o cworkbooklist.o cworkbooklistobject.o ccell.o ccellobject.o crow.o crowobject.o cformula.o csharedstrings.o csharedstring.o csharedstringobject.o cspreadsheets.o cspreadsheet.o cspreadsheetobject.o
CXXFLAGS = -g -fPIC

%.o: Makefile

%.so: Makefile ${OBJ} 
	$(CXX) ${CXXFLAGS} ${OBJ} -shared -o $@

