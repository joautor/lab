BRANCH_ROOT="default"

function seroot {
    echo "$# ($1)"
    if [ $# -gt 0 ] && [ -d $1 ]; then
        BRANCH_ROOT=$1
    else
        echo "${BRANCH_ROOT} here is pwd!"
        BRANCH_ROOT=`pwd`
    fi
    echo "BRANCH_ROOT set to ${BRANCH_ROOT}"
    #local testing="tisting"
}

function groot {
    cd ${BRANCH_ROOT}
}

#testing

seroot
seroot ~/Desktop/work
groot
pwd
seroot
pwd
echo "tryi..(${testing}).."
