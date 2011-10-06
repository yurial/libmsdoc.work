CXXFLAGS = -O9 -fPIC -Wall
BUILD = test

.PHONY: all $(BUILD) clean
all: $(BUILD)
$(BUILD): depend $(BUILD:=.o) $(OBJ) Makefile

OBJ = czip.o cdate.o cdoc.o cdocxlsx.o crelationships.o crelationship.o crelationshipobject.o cbaserelationshipobject.o ccontent.o cworkbook.o cworkbooklist.o cworkbooklistobject.o ccell.o ccellobject.o ccellvalue.o ccelltype.o crow.o crowobject.o cformula.o csharedstrings.o csharedstring.o csharedstringobject.o cspreadsheets.o cspreadsheet.o cspreadsheetobject.o cstylesheet.o cfontflags.o cfonts.o cfontobject.o cfont.o cxf.o ccellxfs.o ccellxf.o ccellxfobject.o cfills.o cfill.o cfillobject.o cpatternfill.o cgradientfill.o ccolor.o cborders.o cborder.o cborderobject.o cborderline.o calignment.o cnumfmts.o cnumfmt.o cnumfmtobject.o

include $(wildcard *.d)

DEPS=$(OBJ:%.o=%.d)
depend: Makefile $(DEPS)

%.d: %.cpp
	echo -n "$@ " > $@
	($(CXX) -MM $< || rm $@) |tr -d '\\\n' >>$@

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

${OBJ}: Makefile

%.so: Makefile ${OBJ} 
	$(CXX) ${CXXFLAGS} ${OBJ} -shared -o $@

test: libmsdoc.so
	$(CXX) -L. test.o -lzip -lmsdoc -o test
	rm -f test.zip
	LD_LIBRARY_PATH="." ./test


clean:
	rm -rf *.d *.o *.so
