#!/bin/bash

PIPEXPATH="../pipex"

TESTPATH="../pipexfasttest"
OUTPATH="../pipexfasttest/outs"

cd $PIPEXPATH && make

cd $PIPEXPATH && ./pipex $TESTPATH/infile "ls -l" "wc -l" $OUTPATH/out1
cd $PIPEXPATH && ./pipex $TESTPATH/infile "grep a" "wc -w" $OUTPATH/out2
cd $PIPEXPATH && ./pipex $TESTPATH/infile "ls -slslksdfow" "wc -cmlw" $OUTPATH/out3
cd $PIPEXPATH && ./pipex $TESTPATH/infile "grep -i North" "echo Star" $OUTPATH/out4
cd $PIPEXPATH && ./pipex $TESTPATH/infile "who -b" "grep -v Reprogramme" $OUTPATH/out5

echo -------------------------------------
echo Test1
echo Pipex out:
cat $OUTPATH/out1
echo System out:
< $TESTPATH/infile ls -l | wc -l
echo -------------------------------------

echo Test2
echo Pipex out:
cat $OUTPATH/out2
echo System out:
< $TESTPATH/infile grep a | wc -w
echo -------------------------------------

echo Test3
echo Pipex out:
cat $OUTPATH/out3
echo System out:
< $TESTPATH/infile ls -slslksdfow| wc -cmlw
echo -------------------------------------

echo Test4
echo Pipex out:
cat $OUTPATH/out4
echo System out:
< $TESTPATH/infile grep -i North | echo Star
echo -------------------------------------

echo Test5
echo Pipex out:
cat $OUTPATH/out5
echo System out:
< $TESTPATH/infile  who -b | grep -v Reprogramme
echo -------------------------------------

echo

echo ------------------
echo '|' Error handling '|'
echo ------------------
echo
echo Error 1: Wrong number of arguments
cd $PIPEXPATH && ./pipex $TESTPATH/infile "wc -w" "ls -a" 
echo -------------------------------------

echo
echo Error 2: Wrong keys
cd $PIPEXPATH && ./pipex $TESTPATH/infile "" "ls -abdsnj" $OUTPATH/out6
cat $OUTPATH/out6
echo -------------------------------------

echo
echo Error 3: Wrong input file
cd $PIPEXPATH && ./pipex $TESTPATH/ouch "grep -v ouch" "ls -a" $OUTPATH/out7
echo -------------------------------------

echo
echo Error 4: Wrong command
cd $PIPEXPATH && ./pipex $TESTPATH/infile "weewee" "wc -w" $OUTPATH/out6
echo -------------------------------------
