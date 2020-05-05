make re > /dev/null
gcc tests/main.c -o bin_tests

echo "-------------------------" > out.txt
echo "       TESTS ASM		   " >> out.txt
echo "-------------------------" >> out.txt
LD_PRELOAD=$PWD/libasm.so ./bin_tests >> out.txt

echo "-------------------------" > ref.txt
echo "       TESTS LIBC		   " >> ref.txt
echo "-------------------------" >> ref.txt
./bin_tests >> ref.txt

if [ $# -eq 0 ]
  then
  	diff out.txt ref.txt -a
  else
	cat out.txt
fi

rm out.txt
rm ref.txt
rm bin_tests
make fclean > /dev/null