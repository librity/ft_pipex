#!/bin/bash
<<com
USAGE

create pipex executable first, then run this program.

run command in following format:
bash single_test.sh file_in cmd1 cmd2 file_out

example:
bash single_test.sh files_in/file_in "cat -e" "grep gewoon" files_out/res_mine
com

GREEN="\033[38;2;57;181;74m"
RED="\033[38;2;222;56;43m"
RESET="\033[0m"
BLUE="\033[38;2;34;183;235m"
RETURN_VALUE=0

RES_REAL="files_out/res_real"
DIFF_FILE="files_out/diff.txt"

rm -f "files_out/res_mine"
rm -f $RES_REAL
rm -f $DIFF_FILE

if [ -z "$4" ]; then
  unset -v RES_REAL
fi

ARG2=$2
echo ""
echo "my command:   "../pipex $1 \"$2\" \"$3\" $4
echo "real command: <" $1 $2 "|" $3 ">" $RES_REAL
echo ""

printf "$BLUE"
echo "your error message:"
printf "$RESET"
../pipex $1 "$2" "$3" $4
MY_EXITCODE=$?
echo ""

printf "$BLUE"
echo "real error message:"
printf "$RESET"
< $1 $2 | $3 > $RES_REAL
REAL_EXITCODE=$?

echo ""

if cmp --silent -- "$4" "$RES_REAL"; then
  printf "$GREEN"
  echo "###    SUCCESS: Output Files Are Identical!    ###"
  printf "$RESET"
elif [ -z "$4" ]; then
  printf "$GREEN"
  echo "###    SUCCESS: Output Files Are Not Made!    ###"
  printf "$RESET"
else
  printf "$RED"
  echo "###    ERROR:   Output Files Are Different!   ###"
  RETURN_VALUE=1
  printf "$RESET"
fi

if [ $MY_EXITCODE -eq $REAL_EXITCODE ]; then
  printf "$GREEN"
  echo "###    SUCCESS: Exit Codes Are Identical!      ###"
else
  printf "$RED"
  RETURN_VALUE=1
  echo "###    ERROR:   Exit Codes Are Different!     ###"
fi

echo -n "your exit code: "
echo $MY_EXITCODE
echo -n "real exit code: "
echo $REAL_EXITCODE
printf "$RESET"
echo ""
echo ""
exit $RETURN_VALUE