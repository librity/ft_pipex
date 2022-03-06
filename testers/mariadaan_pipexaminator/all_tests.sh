#!/bin/bash

bold=$(tput bold)
normal=$(tput sgr0)

PINK="\033[38;2;255;105;180m"
GREEN="\033[38;2;57;181;74m"
RED="\033[38;2;222;56;43m"
RESET="\033[0m"

printf "$PINK"
echo -e "${bold}\nWELCOME TO THE PIPEXAMINATOR! LET'S TEST YOUR PIPEX!"
printf "$GREEN"
echo -e "

  ███                                                              ███
  ███                                                              ███
||███|████████████████████████████████████████████████████████████|███||
||███|████████       ██   ███       ██       ███   ████   ████████|███||
||███|████████   █   ██   ███   █   ██   ████████   ██   █████████|███||
||███|████████       ██   ███       ██       ██████    ███████████|███||
||███|████████   ██████   ███   ██████   ████████   ██   █████████|███||
||███|████████   ██████   ███   ██████       ███   ████   ████████|███||
||███|████████████████████████████████████████████████████████████|███||
  ███                                                              ███
  ███                                                              ███
\n"
sleep 1

# valid arguments
printf "$PINK"
echo "${bold}TEST 1"
echo "valid arguments${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "cat -e" "grep gewoon" files_out/res_mine
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

# valid arguments
printf "$PINK"
echo "${bold}TEST 2"
echo "valid arguments${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "cat -t" "grep FANTASTISCH" files_out/res_mine
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

# valid arguments
printf "$PINK"
echo "${bold}TEST 3"
echo "valid arguments${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "ls -a" "grep pipex" files_out/res_mine
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

# valid arguments
printf "$PINK"
echo "${bold}TEST 4"
echo "valid arguments${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "ls -l" "wc -l" files_out/res_mine
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

# valid arguments
printf "$PINK"
echo "${bold}TEST 4"
echo "valid arguments${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "ls -l" "wc" files_out/res_mine
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

# input file does not exist
printf "$PINK"
echo "${bold}TEST 6"
echo "input file does not exist${normal}"
printf "$RESET"
bash single_test.sh fiwefcen/fileewe_in "cat -e" "grep gewoon" files_out/res_mine
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

# first command does not exist, second command doesnt need input
printf "$PINK"
echo "${bold}TEST 7"
echo "first command does not exist, second command doesnt need input${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "whateverrr" "ls" files_out/res_mine
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

# both commands do not exist
printf "$PINK"
echo "${bold}TEST 8"
echo "both commands do not exist${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "whateverrr" "nothing" files_out/res_mine
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

# first command does not need input, second command does not exist
printf "$PINK"
echo "${bold}TEST 9"
echo "first command does not need input, second command does not exist${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "ls" "nopeee" files_out/res_mine
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

# incorrect number of arguments ( 1 arg )
printf "$PINK"
echo "${bold}TEST 10"
echo "incorrect number of arguments ( 1 arg, input file only )${normal}"
printf "$RESET"
touch files_out/res_mine
bash single_test.sh files_in/file_in
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

# incorrect number of arguments ( 2 args, input file and first command only )
printf "$PINK"
echo "${bold}TEST 11"
echo "incorrect number of arguments ( 2 args, input file and first command only )${normal}"
printf "$RESET"
touch files_out/res_mine
bash single_test.sh files_in/file_in cat
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

# incorrect number of arguments ( 3 args, input file and two commands )
printf "$PINK"
echo "${bold}TEST 12"
echo "incorrect number of arguments ( 3 args, input file and two commands )${normal}"
printf "$RESET"
touch files_out/res_mine
bash single_test.sh files_in/file_in "cat" "grep gewoon"
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

# non-existing flag command 1
printf "$PINK"
echo "${bold}TEST 13"
echo "non-existing flag command 1${normal}"
printf "$RESET"
touch files_out/res_mine
bash single_test.sh files_in/file_in "cat -bestaatniet" "grep FANTASTISCH" files_out/res_mine
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

# non-existing flag command 2
printf "$PINK"
echo "${bold}TEST 14"
echo "non-existing flag command 2${normal}"
printf "$RESET"
touch files_out/res_mine
bash single_test.sh files_in/file_in "cat -t" "cat -bestaatniet FANTASTISCH" files_out/res_mine
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

# non-existing flag command 2
printf "$PINK"
echo "${bold}TEST 15"
echo "non-existing flag command 2${normal}"
printf "$RESET"
touch files_out/res_mine
bash single_test.sh files_in/file_in "cat -t" "grep -bestaatniet FANTASTISCH" files_out/res_mine
EXIT_CODE=$?
EXIT_CODE_TOTAL=$((EXIT_CODE_TOTAL+EXIT_CODE))
sleep 0.1

if [ $EXIT_CODE_TOTAL -eq 0 ]; then
  printf "$GREEN"
  echo "${bold}========================================= PASS =========================================${normal}"
  printf "$RESET"
  echo "Congrats, you passed all tests!"
else
  printf "$RED"
  echo "${bold}========================================= FAIL =========================================${normal}"
  printf "$RESET"
  echo "$EXIT_CODE_TOTAL out of 15 tests have not given the correct output or exitcode. Check terminal output
for more information on which tests have failed."
fi

echo -e "\nMake sure to check whether error messages are the same, this tester does not check those.
Some error messages may look weird because of the shell script information. Run the
'my command' and the 'real command' of those tests in your terminal to check whether the
error messages are the same."

echo -e "\n"
rm -f files_out/res_real
rm -f files_out/res_mine