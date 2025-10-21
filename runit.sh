#!/bin/sh
in=$1
filepath=$2
[ -z "$filepath" ] && filepath=$in && in=input1
echo "RUNNING: ${filepath##**/} < $in"
in=${filepath%/*}/$in
case $filepath in
*.py) exec pypy3 "$filepath" < "$in" ;;
*.java|*.jav) exec java --source 21 -Dfile.encoding=UTF-8 -XX:+UseSerialGC -Xss64m "$filepath" < "$in" ;;
*.cpp) gcc -x c++ -g -O2 -std=gnu++20 -static "$filepath" && exec ./a.out < "$in" ;;
*) echo 'NOT FOUND'
esac
