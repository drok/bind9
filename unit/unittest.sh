#!/bin/sh

PATH="/home/radu/proj/bind9/unit/atf/bin:${PATH}"
export PATH

status=0
if [ -n "/home/radu/proj/bind9/unit/atf/bin" -a -f Atffile ]
then
	echo "I: unit tests"
	atf-run > atf.out
	status=$?

        # | cat is there to force non-fancy output
	atf-report < atf.out | cat

	if [ $status -eq 0 ]
	then
		rm -f atf.out
		echo R:PASS
	else
		echo R:FAIL
	fi
fi
exit $status
