for i in $(seq 1 1000)
do

./gen $i > a.in
./brute < a.in > a.out
./main < a.in > b.out

diff -bwq a.out b.out || break
echo "TEST $i - AC"

done