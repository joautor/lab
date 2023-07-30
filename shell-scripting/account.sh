#!/bin/bash

cur_password="hello world"
U_NAME="autorun"
auth="false"

counter=0
while [ "$auth" = "false" ]
do
    read -p "Enter username: " username 
    # echo "Enter password for ${username}: "
    read -s -p "Enter password for ${username}: " password

    if [[ $cur_password = $password && $U_NAME = $username ]]; then
        auth="true"
        counter=0
    else
        echo -e "\n\033[0;31mIncorrect password or username.\033[0m"
        counter=`expr $counter + 1`
    fi

    if [[ $counter -ge 3 ]]
    then
        echo -e "\033[0;31mOops!!! Reached Max number of failed attempts.\nExiting the program ...\033[0m"
        exit 1
    fi

done

echo -e "\n-------------------------------"
echo "Hi, ${U_NAME}!"
echo "Your password is: ${password}"
