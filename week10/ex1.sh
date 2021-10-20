touch _ex1.txt
echo "damir" > _ex1.txt
touch _ex1_1.txt
touch _ex1_2.txt
ln _ex1.txt _ex1_1.txt
ln _ex1.txt _ex1_2.txt
touch ex1.txt
ls -i _ex1.txt| awk '{print $1}' >> ex1.txt
ls -i _ex1_1.txt | awk '{print $1}' >> ex1.txt
ls -i _ex1_2.txt | awk '{print $1}' >> ex1.txt

