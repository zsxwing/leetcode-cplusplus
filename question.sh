#!/bin/bash

if [[ $# -eq 0 ]] ; then
	echo "Need the question argument."; exit 1
fi

args=""
for arg in "$@" ; do
    if [[ -z "${args}" ]] ; then
        args=${arg}
    else
        args=${args}_${arg}
    fi
done 

question=$( echo ${args} | tr [A-Z] [a-z] )
touch src/${question}.h
if [[ ! -e "test/${question}_test.cc" ]]; then
    echo "#include \"common.h\"" >> test/${question}_test.cc && \
      echo "#include \"${question}.h\"" >> test/${question}_test.cc && \
      echo "#include <gtest/gtest.h>" >> test/${question}_test.cc && \
      echo "" >> test/${question}_test.cc
fi
