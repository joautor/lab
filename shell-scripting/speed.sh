
Y=0
X=0
N=1000000

while [ "$X" -lt "$N" ]
do
    echo $X
    Y=`expr $Y + $X`
    X=`expr $X + 1`
done


