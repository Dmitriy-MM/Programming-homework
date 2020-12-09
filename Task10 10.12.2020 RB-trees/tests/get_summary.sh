grep "./a.out : " $1 > ___tmp.txt
sed -E -e "s/Elapsed = [0-9]*\.[0-9]*//g" -e "/a.out [0-9]/d" ___tmp.txt > $2
rm ___tmp.txt
