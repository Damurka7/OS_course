file='file.txt'
line=$(cat "$file")
last=${line: -1}
echo "$line" > file.txt
echo -n "$last" >> file.txt
