#!/bin/bash

DGEN=./perm.out
PROG=./binaryTreeLongestConsecutiveSequenceII.out
DO_CLEAN='rm -rf b.txt dot LCP*'

if [ "$1" == "clean" ]; then
	$DO_CLEAN
	exit
fi

if [ -e b.txt ]; then
	$DO_CLEAN
fi

i=1;

mkdir dot
$DGEN $1 > b.txt
for line in `cat b.txt`; do
	echo $PROG \'$line\' \| dot -Tpng -otree$i.png
	$PROG "$line" > dot/$i.dot

    lcp=`tail -n 1 dot/$i.dot | cut -d' ' -f2`
    echo LCP $lcp
	if [ ! -e LCP$lcp ]; then
		mkdir LCP$lcp
	fi

	dot -T png -o LCP${lcp}/tree$i.png dot/$i.dot
	i=`expr $i + 1`
done

