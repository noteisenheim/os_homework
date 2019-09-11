gcc ex2_1.c -o ex2_1.out
./ex2_1.out &
echo "first"
pstree $!
sleep 5
echo "second"
pstree $!
sleep 8
echo "third"
pstree $!