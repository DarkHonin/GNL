rm *bytes.txt*
make FILE='main.c'
read -n 1 -s
./main.c.bin
for i in *bytes.txt; do
    echo "Checking $i"
    diff $i $i.out
done