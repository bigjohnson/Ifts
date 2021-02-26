#!/bin/bash
function controlla {
if [ $? == 0 ]
        then
                echo tutto bene
        else
                echo si sono verificati degli errori, codice errore: $?
                exit 1
        fi
}

./parametri.sh uno due
controlla

./parametri.sh uno due tre
controlla

mv pippo pluto
controlla

touch pippo
mv pippo pluto
controlla

exit 0
