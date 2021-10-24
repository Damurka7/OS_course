mkdir tmp
cd tmp
touch file1.txt
touch file2.txt
ln file1.txt link1.txt
cd ..
gcc ex4.c -o ex4
./ex4 > ex4.txt
cat ex4.txt
