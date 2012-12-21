
SOURCES:=$(wildcard test/*.cc)
OBJS:=$(SOURCES:.cc=.o)
DEPENDS:=$(SOURCES:.cc=.d)
TARGETS:=$(SOURCES:.cc=)

.PHONY : all test clean $(OBJS)
all : test

include $(DEPENDS)

%.d : %.cc
	set -e; rm -f $@; \
	$(CXX) -MT $(<:.cc=.o) -MM $(TEST_INCLUDE_FLAG) $(TEST_LIB_FLAG) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1 $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

% : %.cc
	$(CXX) $(TEST_INCLUDE_FLAG) $(TEST_LIB_FLAG) -o $@ $<
	$@

test : $(TARGETS)

clean : 
	rm -f $(TARGETS) $(DEPENDS)
