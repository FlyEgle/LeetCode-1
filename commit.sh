#!//bin/bash

cd ~/github/LeetCode

str=`git status | grep ".cpp"`
str=${str#*/}
target=${str%%.*}
sedflag='s/'$[${target}-1]'\//'${target}'\//g'

sed -i ${sedflag} ./README.md

gitflag=`cat ./README.md | grep "\d*/\d*" | awk '{print $2}'`

git add --all
git commit -m ${gitflag}
