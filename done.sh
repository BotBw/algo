# !/bin/bash

cp luogu.cpp ${1}.cpp
mv ${1}.cpp codes/
git add codes/${1}.cpp
cp template.cpp luogu.cpp