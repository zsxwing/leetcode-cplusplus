
SOURCES:=$(wildcard test/*.cc)
OBJS:=$(SOURCES:.cc=.o)
DEPENDS:=$(SOURCES:.cc=.d)
DEBUG_INFO:=$(SOURCES:.cc=.dSYM)
TARGETS:=$(SOURCES:.cc=)

.PHONY : all test clean $(OBJS)
all : test

include $(DEPENDS)

%.d : %.cc
	set -e; rm -f $@; \
	$(CXX) -MT $(<:.cc=.o) -MM $(TEST_INCLUDE_FLAG) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1 $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

% : %.cc
	@set -e
	$(CXX) -ggdb $(TEST_INCLUDE_FLAG) $(TEST_LIB_FLAG) -o $@ $<
	$(VALGRIND) $@

test : $(TARGETS)

clean : 
	rm -rf $(shell find test/* -maxdepth 0 | grep -v .cc | grep -v Makefile)
