#!/bin/bash

if [ ! -d ../testcases ]
then
	exit
fi

if [ -d ../output ]
then
	rm -r ../output
fi
mkdir ../output

if [ -d ../execs ]
then
	rm -r ../execs
fi
mkdir ../execs

if [ -d ../data ]
then
	rm -r ../data
fi
mkdir ../data

for curr_fil in `ls *.c`
do
	filename=`echo $curr_fil|cut -f1 -d.`
	out_file=$filename.out

	echo -e "\033[1mCompiling $curr_fil\033[0m" > /dev/tty
	gcc -w -o ../execs/$out_file $curr_fil -lm

	part=`echo $curr_fil|cut -f4 -d\_|cut -d. -f1`
	question=`echo $part|cut -c 1`

	if [ -f ../execs/$out_file ]
	then	
		ls -1 ../testcases/??????$part?.tsc ../testcases/?????$part?.tsc | while read test_fil
		do
			if [ `echo $test_fil|grep Main` ] && [ `echo $curr_fil|cut -f1 -d\_|cut -c 2-|grep A` ]
			then
				continue
			elif [ `echo $test_fil|grep Adv` ] && [ ! `echo $curr_fil|cut -f1 -d\_|cut -c 2-|grep A` ]
			then
				continue
			fi

			test_filname=`echo $test_fil|cut -f3 -d\/|cut -f1 -d.`
			echo "-------------- Running test case $test_filname" > /dev/tty
			echo +--------+
			if [[ `echo $test_fil|grep Main` ]]
			then
				echo \|\ `echo $test_filname|cut -c 3-`\ \|
			else
				echo \|\ `echo $test_filname|cut -c 3-`\ \ \|
			fi
			echo +--------+

			../execs/$out_file ../data/`echo $test_filname`.DAT < $test_fil > ../output/tmp.out_log & # > ../testoutputs/`echo $test_filname`.op &

			run_pid=$!
			counter=0
			sleep 0.1
			kill -0 $run_pid 2> /dev/null
			while [[ $? == 0 ]]
			do
				((counter++))
				if [[ $counter == 20 ]]
				then
					kill $run_pid
					break
				fi
				sleep 0.1
				kill -0 $run_pid 2> /dev/null
			done

			out_size=`cat ../output/tmp.out_log | wc -c`
			if [[ $out_size -lt 1000000 ]]
			then
				cat ../output/tmp.out_log

				for tscfile in ../testoutputs/$test_filname*
				do
					diff -B -b -w -i <(cat ../output/tmp.out_log|cut -d: -f2|tr -d '\n') <(cat $tscfile|tr -d '\n') > /dev/null
					if [[ $? -eq 0 ]]
					then
						touch ../output/match.tmp
						break
					fi
				done
				
				if [[ -f ../output/match.tmp ]]
				then
					echo -e "\033[1;32mExpected output obtained!\033[0m" > /dev/tty
				elif [[ `cat ../testoutputs/$test_filname.op|grep -i invalid` && `cat ../output/tmp.out_log|grep -i 'valid\|wrong\|correct'` ]]
				then
					echo -e "\033[1;32mExpected output obtained!\033[0m" > /dev/tty
				else
					echo -e "\033[1;31mOutput mismatch, please verify the corresponding out_log.\033[0m" > /dev/tty
				fi
				rm -f ../output/match.tmp
			else
				echo -e "\033[1mPossible infinite loop detected; please verify manually.\033[0m" > /dev/tty
			fi

			echo
			echo
			echo > /dev/tty
		done > ../output/$filename.out_log
	fi 2> /dev/null
done

rm -f ../output/tmp.out_log
