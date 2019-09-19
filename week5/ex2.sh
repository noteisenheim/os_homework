# the first race condition occured on 38'th number
# the number was output 2 times
# one program reads last line, then before it writes the second program also reads the last line
# then both programs write the same number to the file

i=0

while true
do
	tempfile=$(mktemp ./lock.XXXX)
	lockfile=./lockfile

	if ln $tempfile $lockfile ; then
		read -r line < <(tail -n1 ex2.txt)
		echo "$(($line + 1))" >> ex2.txt
		((i++))
		if [[ "$i" == '200' ]]; then
			rm $lockfile
			rm $tempfile
			break
		fi
		rm $lockfile
	fi
	rm $tempfile
done

echo "all done"