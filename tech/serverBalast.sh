#!/bin/bash
flag="true"
while [ "$flag" = "true" ]
do
    status_code=$(curl -s -o dev/null -w "%{http_code}" $1)
    echo "ret is: [$status_code]"
    if [ $status_code = 200 ]
    then
        flag="false"
    fi
done
