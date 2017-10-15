#!/bin/bash

basepath=$(cd `dirname $0`; pwd)

function show_problem {
    cd $basepath/code

    status=`git status | grep ".cpp" | sed -e 's/^[ \t]*//g'`

    if [ -z "$status" ]
    then
        problemNo=`cat ../README.md | grep "\d*/\d*" | awk '{print $2}'`
        problemNo=$[${problemNo%/*}+1]
        leetcode show ${problemNo} -gxl cpp
        problem=`ls | grep ${problemNo}.*.cpp`
        vim ${problem}
    else
        problem=${status}
        vim ${problem}
    fi
}

function do_test {
    cd $basepath/code

    problem=`git status | grep ".cpp" | sed -e 's/^[ \t]*//g'`

    if [ -z "$problem" ]
    then
        echo "Nothing for test."
    else
        leetcode test ${problem} -t $OPTARG
    fi
}

function submit_problem {
    cd $basepath/code

    problem=`git status | grep ".cpp" | sed -e 's/^[ \t]*//g'`

    if [ -z "$problem" ]
    then
        echo "Nothing for submit."
    else
        leetcode submit ${problem}
    fi
}

function git_commit {
    cd $basepath

    str=`git status | grep ".cpp"`
    str=${str#*/}
    target=${str%%.*}
    sedflag='s/'$[${target}-1]'\//'${target}'\//g'

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
    -t      do test
    -s      submit
    -c      git commit
    -h      show_help
EOF
}

if [ -z "$1" ]
then
    show_problem
    exit
fi

while getopts 'tsch' arg
do
    case $arg in
        t) do_test ;;
        s) submit_problem ;;
        c) git_commit ;;
        h) show_help ;;
        *) show_help ;;
    esac
done
