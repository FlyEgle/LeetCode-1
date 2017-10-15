#!/bin/bash

basepath=$(cd `dirname $0`; pwd)
problemstr=`git status | grep ".cpp" | sed -e 's/^[ \t]*//g'`
problem=${problemstr#*/}
problemNo=${problem%%.*}
testcase=""

function show_problem {
    cd $basepath/code

    if [ -z "$problem" ]
    then
        leetcode show ${problemNo} -gxl cpp
    fi
    vim ${problem}
}

function do_test {
    cd $basepath/code

    if [ -z "$problem" ]
    then
        echo "Nothing for test."
    else
        leetcode test ${problem}
    fi
}

function do_my_test {
    cd $basepath/code

    if [ -z "$problem" ]
    then
        echo "Nothing for test."
    else
        leetcode test ${problem} -t $testcase
    fi
}

function submit_problem {
    cd $basepath/code

    if [ -z "$problem" ]
    then
        echo "Nothing for submit."
    else
        leetcode submit ${problem}
    fi
}

function git_commit {
    cd $basepath

    sedflag='s/'$[${problemNo}-1]'\//'${problemNo}'\//g'
    sed -i ${sedflag} ./README.md

    gitflag=`cat ./README.md | grep "\d*/\d*" | awk '{print $2}'`
    git add --all
    git commit -m ${gitflag}
}

function show_help {
    cat << "EOF"
SYNOPSIS
    auto.sh [OPTION]

DESCRIPTION
    [none]  show problem
    -t                  do test
    --t 'testcase'      do test with test cases
    -s                  submit
    -c                  git commit
    -h                  show_help
EOF
}

if [ -z "$1" ]
then
    show_problem
    exit
fi

ARGS=`getopt -o tsch --long t: -- "$@"`
if [ $? != 0 ]
then
    echo "Parameter error."
    exit 1
fi

eval set -- "${ARGS}"

while [ -n "$1" ]
do
    case $1 in
        -t) do_test ;;
        --t) testcase=$2
            do_my_test ;;
        -s) submit_problem ;;
        -c) git_commit ;;
        -h) show_help ;;

        --) shift
            break ;;
        *) show_help ;;
    esac
    shift
done
