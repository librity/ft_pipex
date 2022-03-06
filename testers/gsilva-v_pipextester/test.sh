#Recompilando
printf "\033[36mCOMPILING PROGRAM\n\033[0m"
make -C ../ all
cp ../pipex ./

printf "\n"
printf "Invalid Tests: Invalid input\n" 
printf "./pipex inf \"grep a\" \"wc -l\" outfile\n"
./pipex inf "grep a" "wc -l" ./results/testinvinput/outputs/outfile
echo $? > ./results/testinvinput/exitcodes/resulprog
<inf grep a | wc -l > ./results/testinvinput/outputs/outpipe
echo $? > ./results/testinvinput/exitcodes/resulpipe
printf "\033[33m[Verifying results!]\n\033[0m"
sleep 1
printf "Output check: "
if diff ./results/testinvinput/outputs/outpipe ./results/testinvinput/outputs/outfile;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n";
fi
printf "Exit check: "
if diff ./results/testinvinput/exitcodes/resulpipe ./results/testinvinput/exitcodes/resulprog;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n"; 
fi
printf "\n"

sleep 1

printf "Invalid Tests: Invalid command " 
echo  " ./pipex infile \"catt\" \"wcc -l\" outfile "
./pipex infile "catt" "wcc -l" ./results/testinvcommand/outputs/outfile
echo $? > ./results/testinvcommand/exitcodes/resulprog
<infile catt | wcc -l> ./results/testinvcommand/outputs/outpipe
echo $? > ./results/testinvcommand/exitcodes/resulpipe
printf "\033[33m[Verifying results!]\n\033[0m"
sleep 1
printf "Output check: "
if  diff ./results/testinvcommand/outputs/outpipe ./results/testinvcommand/outputs/outfile;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n";
fi
printf "Exit check: "
if diff ./results/testinvcommand/exitcodes/resulpipe ./results/testinvcommand/exitcodes/resulprog;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n"; 
fi
printf "\n"
sleep 1

printf "Invalid Tests: Invalid args " 
echo  " ./pipex infile  outfile "
./pipex infile ./results/testinvargs/outputs/outfile
echo $? > ./results/testinvargs/exitcodes/resulprog
<infile > ./results/testinvargs/outputs/outpipe
echo $? > ./results/testinvargs/exitcodes/resulpipe
printf "\033[33m[Verifying results!]\n\033[0m"
sleep 1
printf "Output check: "
if  diff ./results/testinvargs/outputs/outpipe ./results/testinvargs/outputs/outfile;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n";
fi
printf "Exit check: "
if diff ./results/testinvargs/exitcodes/resulpipe ./results/testinvargs/exitcodes/resulprog;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n"; 
fi
printf "\n"

sleep 1

printf "Test 1:" 
echo  " ./pipex infile \"tr a b\" \"tr b c\" outfile "
./pipex infile2 "tr a b" "tr b c" ./results/test1/outputs/outfile
echo $? > ./results/test1/exitcodes/resulprog
<infile2 tr a b | tr b c> ./results/test1/outputs/outpipe
echo $? > ./results/test1/exitcodes/resulpipe
printf "\033[33m[Verifying results!]\n\033[0m"
sleep 1
printf "Output check: "
if  diff ./results/test1/outputs/outpipe ./results/test1/outputs/outfile;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n";
fi
printf "Exit check: "
if  diff ./results/test1/exitcodes/resulpipe ./results/test1/exitcodes/resulprog;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n";
fi
printf "\n"

sleep 1

printf "Test 2:" 
echo  " ./pipex infile \"cat\" \"wc -l\" outfile "
./pipex infile "cat" "wc -l" ./results/test2/outputs/outfile
echo $? > ./results/test2/exitcodes/resulprog
<infile cat | wc -l > ./results/test2/outputs/outpipe 
echo $? > ./results/test2/exitcodes/resulpipe
printf "\033[33m[Verifying results!]\n\033[0m"
sleep 1
printf "Output check: "
if  diff ./results/test2/outputs/outpipe ./results/test2/outputs/outfile;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n";
fi
printf "Exit check: "
if  diff ./results/test2/exitcodes/resulpipe ./results/test2/exitcodes/resulprog;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n";
fi
printf "\n"

sleep 1

printf "Test 3:  " 
echo  " ./pipex infile \"ls -la\" \"wc -l\" outfile "
./pipex infile "ls -la" "wc -l"  ./results/test3/outputs/outfile
echo $? > ./results/test3/exitcodes/resulprog
<infile ls -la | wc -l >  ./results/test3/outputs/outpipe
echo $? > ./results/test3/exitcodes/resulpipe
printf "\033[33m[Verifying results!]\n\033[0m"
sleep 1
printf "Output check: "
if  diff ./results/test3/outputs/outpipe ./results/test3/outputs/outfile;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n";
fi
printf "Exit check: "
if diff ./results/test3/exitcodes/resulpipe ./results/test3/exitcodes/resulprog;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n"; 
fi
printf "\n"


sleep 1


printf "Test 4:  " 
echo  " ./pipex infile \"grep a\" \"wc -l\" outfile "
./pipex infile "grep a" "wc -l" ./results/test4/outputs/outfile
echo $? > ./results/test4/exitcodes/resulprog
<infile grep a | wc -l > ./results/test4/outputs/outpipe
echo $? > ./results/test4/exitcodes/resulpipe
printf "\033[33m[Verifying results!]\n\033[0m"
sleep 1
printf "Output check: "
if  diff ./results/test4/outputs/outpipe ./results/test4/outputs/outfile;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n";
fi
printf "Exit check: "
if diff ./results/test4/exitcodes/resulpipe ./results/test4/exitcodes/resulprog;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n"; 
fi
printf "\n"


sleep 1

printf "Test 5:  " 
echo  " ./pipex infile2 \"pwd\" \" tr o b\" outfile "
./pipex infile2 "pwd" "tr o b" ./results/test5/outputs/outfile
echo $? > ./results/test5/exitcodes/resulprog
<infile2 pwd | tr o b > ./results/test5/outputs/outpipe 
echo $? > ./results/test5/exitcodes/resulpipe
printf "\033[33m[Verifying results!]\n\033[0m"
sleep 1
printf "Output check: "
if  diff ./results/test5/outputs/outpipe ./results/test5/outputs/outfile;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n";
fi
printf "Exit check: "
if diff ./results/test5/exitcodes/resulpipe ./results/test5/exitcodes/resulprog;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n"; 
fi
printf "\n"



sleep 1
printf "Test 6:" 
echo  " ./pipex infile \"tr a ' '\" \"tr ' ' x\" outfile "
./pipex infile2 "tr a ' '" "tr ' ' x" ./results/test6/outputs/outfile 
echo $? > ./results/test6/exitcodes/resulprog
<infile2 tr a  ' ' | tr ' ' x > ./results/test6/outputs/outpipe 
echo $? > ./results/test6/exitcodes/resulpipe
printf "\033[33m[Verifying results!]\n\033[0m"
sleep 1
printf "Output check: "
if  diff ./results/test6/outputs/outpipe ./results/test6/outputs/outfile;
    then printf "\033[32m[OK]\033[0m\n";
else printf "\033[31m[KO]\033[0m\n";
fi
printf "Exit check: "
if diff ./results/test6/exitcodes/resulpipe ./results/test6/exitcodes/resulprog;
    then printf "\033[32m[OK]\033[0m\n" ;
else printf "\033[31m[KO]\033[0m\n";
fi
printf "\n"
