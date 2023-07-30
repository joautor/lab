#!/bin/bash

# the set of characters above of is called "shebang"

echo "Hello World! Enter your name: "
read NAME
echo "Hi, $NAME"

read -p "Enter password: " psword
echo "You entered \"$psword\""

# defining variables (azAZ_)
# by convention capitalized

VAR_1="This is var1"
readonly VAR_2=2       # it's like const
# or
readonly VAR_1

VAR_3="to be unset"
unset VAR_3        #remove the varialble from the list that shell tracks; you cannot access it na; cannot unset "readonly" variables

echo $VAR_1 $VAR_2 $VAR_3

# VARIABLE TYPES

# LOCAL VARIABLES - present within the current instance of the shell; not available to programs that are not started by the shell; are set at the command prompt

# ENVIRONMENT VARIABLES - available to any child process of the shell; are needed by some programs inorder to function properly; usually, a shell script defines only those e.v. that re needed by the programs that it runs.

# SHELL VARIABLES - a special varialbe that is set by the sell and is required by the shell in order to function correctly. These variables can be local or enviroment variables


### SPECIAL VARIABLES ####

echo $$		# the PID of the current shell 
echo $0		# the filename of the current script
echo $1		# the first argument, 2, 3 and so on...
echo $#		# the number of agurments supplied to a script
echo $*		# all the arguments are doubled qouted. If the script receives two arguments, $* is equivalent to $1 $2
echo $@		# all the arguments are individualy double qouted. If a script receives two arguments, $@ is equivalent to $1 $2
echo $? 	# the exit stus of the last command executed
echo $!		# the process number of the last background command ( 0 - successful, 1 - unsuccessful)


echo "Using the s*"
for TOKEN in $*
do
    echo $TOKEN
done

echo "Using the s@"
for TOKEN2 in $@
do
    echo $TOKEN2
done

# Arrays

ARR[0]=0
ARR[1]=2
ARR[2]=4
echo ${ARR[*]}

for R in ${ARR[*]}
do
    echo $R
done

ARR_2=(1 2 3 4 5 6 7)
echo ${ARR_2[@]}

for R2 in ${ARR_2[@]}
do
    echo $R2
done



# Arithmetic opeatiors

a=7
b=11

echo `expr $a + $b`
echo `expr $a - $b`
echo `expr $a \* $b`
echo `expr $a / $b`
echo `expr $a % $b`
c=$b
echo [ $a == $b ]
echo [ $a != $b ]

#NOTE: all conditional expressions should be inside squire braces with spaces around them
#NOTE: all the arithmetical calculations are done using long integers

if [ $a != $b ] ; then
    echo "hello it's true"
fi


# Relational Operators
# - works only on number as a 7 and 11, or strings with numeric value like "7" and "11", and NOT "seven" and "eleven"


# -eq, -ne, -gt, -lt, -ge, -le (equal, not equal, greater than, less than, greater than or equal , less than or equal)
# example: [ $a -eq $b ]



# BOOLEAN OPERATORS

# ! 	negation
# -o	logical OR   example: [ true -o false ]
# -a	logical AND  example: [ true -a false ]


# STRING OPERATORS
# = 	equal
# != 	not equal
# -z	true if length is zero; example: [ -z $MY_STR ]
# -n	ture if lenght is not zero; example: [ -n $MY_STR ]
# str	false if string is empty; example: [ $MY_STR ]


#  FILE TEST OPERATORS

# -b file 	check if block special file
# -c file	check if charachter special file
# -d file 	check if it is a directory
# -f file	check if it is an ordinary file
# -g file	check if the has its Set Groud ID (SGID) bit set
# -k file	check if the file has its sticky file set
# -p file	check if it is a named pipe
# -t file	check if file descriptor is open and associated with a terminal
# -u file	check if the file has its Set User ID (SUID) bit set
# -r file	check if file is readable
# -w file	check if file is writable
# -x file	check if file is executable
# -s file	check if file size is greater than zero
# -e file	check if it exists

