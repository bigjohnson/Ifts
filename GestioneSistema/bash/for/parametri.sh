#!/bin/bash
if [ -R $3 ]
then
        echo Inserire almeno tre parametri.
        exit 1
fi

ERRORE=true
PRIMOPARAMETRO="uno due tre quattro"

for PARAMETRO in $PRIMOPARAMETRO
do
        echo $PARAMETRO
        if [ $PARAMETRO == $1 ]
        then
                ERRORE=false
        fi
done

if [ $ERRORE == true ]
then
        echo il primo parametro non è corretto deve essere $PRIMOPARAMETRO
        exit 2
fi

echo nome programma: $0
echo primo parametro: $1
echo secondo parametro: $2
echo terzo parametro: $3
exit 0
