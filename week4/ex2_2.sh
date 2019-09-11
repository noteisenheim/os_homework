gcc ex2_2.c -o ex2_2.out
./ex2_2.out &
sleep 2
echo "first"
pstree $!
sleep 3
echo "second"
pstree $!
sleep 3
echo "third"
pstree $!
sleep 3
echo "fourth"
pstree $!
sleep 3
echo "fifth"
pstree $!