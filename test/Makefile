
SOURCES:=$(wildcard test/*.cc)
OBJS:=$(SOURCES:.cc=.o)
DEPENDS:=$(SOURCES:.cc=.d)
DEBUG_INFO:=$(SOURCES:.cc=.dSYM)
TARGETS:=$(SOURCES:.cc=)
UNITTESTS:=$(SOURCES:.cc=.unittest)

.PHONY : all test clean $(OBJS)
all : test

include $(DEPENDS)

%.d : %.cc
	set -e; rm -f $@; \
	$(CXX) $(CXX_FLAG) -MT $(<:.cc=.o) -MM $(TEST_INCLUDE_FLAG) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.unittest $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

%.unittest : %.cc
	@set -e
	$(CXX) $(CXX_FLAG) $(TEST_INCLUDE_FLAG) $(TEST_LIB_FLAG) -o $(<:.cc=) $<
	touch $@
	$(VALGRIND) $(<:.cc=)

test : $(UNITTESTS)

clean : 
	rm -rf $(shell find test/* -maxdepth 0 | grep -v .cc | grep -v Makefile)
