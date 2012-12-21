#!/bin/sh

question=$1
if [ "" = "$question" ]; then
	echo "Need the question argument."; exit 1
fi


touch src/${question}.cc && \
echo "#include \"common.h\"" >> test/${question}_test.cc && \
echo "#include \"${question}.cc\"" >> test/${question}_test.cc && \
echo "#include <gtest/gtest.h>" >> test/${question}_test.cc && \
echo "" >> test/${question}_test.cc

