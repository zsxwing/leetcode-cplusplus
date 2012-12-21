

SOURCES := $(wildcard test/*.cc)
TARGETS := $(patsubst %.cc,%,$(SOURCES))

.PHONY : all test clean
all : test

test : $(TARGETS)

% : %.cc
	$(CC) $(TEST_INCLUDE_FLAG) $(TEST_LIB_FLAG) -o $@ $^
	$@

clean : 
	rm -f $(TARGETS)
