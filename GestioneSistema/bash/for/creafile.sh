#!/bin/bash
for i in {1..100}
do
 # your-unix-command-here
 echo $i
 NOMEFILE=test_$i
 echo $NOMEFILE
        if [ -e "$NOMEFILE" ]
        then
                echo Il file $NOMEFILE esiste già!
        else
                echo Il file $NOMEFILE non esiste!
        fi
done
