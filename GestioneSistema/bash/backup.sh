#!/bin/bash
BACKUPDIR=${HOME:?Manca la variabile HOME}/backup
if [ ! -d "$BACKUPDIR" ]
then
        mkdir "$BACKUPDIR"
fi

if [ ! -d "$BACKUPDIR" ]
then
        echo ERRORE: non posso creare la directory di backup!
        exit 1
fi

OGGI=$(date +%Y%m%d%H%M%S)
#echo $OGGI
if tar --exclude="$BACKUPDIR" -cf "$BACKUPDIR/$OGGI.tar" "$HOME" &> /dev/null
then
        #echo Backup terminato correttamente.
        exit 0
else
        echo Errore nel backup.
        exit 2
fi