mkdir week01
cd week01
touch _ex2.txt
touch file.txt
printf "damir" > file.txt
cd ..
mkdir week10
cd week10
link ~/Desktop/My\ Courses/Operating\ Systems/labs/lab/week01/file.txt _ex2.txt
ls -i _ex2.txt > ex2.txt
find ~/Desktop/My\ Courses/Operating\ Systems/labs/lab/week01/file.txt -inum 40781 >> ex2.txt
find ~/Desktop/My\ Courses/Operating\ Systems/labs/lab/week01/file.txt -inum 40781 -exec rm {} \; >> ex2.txt
