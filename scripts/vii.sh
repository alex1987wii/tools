#!/bin/sh

if [ $# -eq 0 ] ; then
	vi
	exit 0
fi

if [ $# -ne 1 ] ; then
	echo "too many argment"
	exit 1
fi

if [ -e $1 ] ; then
test -f $1 && vi $1 && exit 0
echo "$1 already exist and is not a regular file"
exit 1
fi

suffix=${1#*.}
test $suffix = "c" && cp ~/tools/templates/template.c $1 && vi +10 $1 && exit 0
vi $1 && exit 0

