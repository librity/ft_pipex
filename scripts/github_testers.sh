# CLONE AND BUILD PROJECT
cd ~
git clone --recurse-submodule https://github.com/librity/ft_pipex
# git clone 42_INTRA_REPO_ADDRESS ft_pipex
cd ft_pipex
# norminette
make norm
make re

# CLONE ALL GITHUB TESTERS
git clone https://github.com/denisgodoy/pipex-tester tt_1
git clone https://github.com/gsilva-v/PipexTester tt_2
git clone https://github.com/Yoo0lh/pipex_tester_42 tt_3
git clone https://github.com/vfurmane/pipex-tester tt_4
chmod 777 */*.sh

# RUN tt_1
cd tt_1
make
cd ..

# RUN tt_2
cd tt_2
./test.sh
cd ..

# RUN tt_3
cd tt_3
./pipex_tester.sh a
cd ..

# ATENCAO: NAO FUNCIONA NO WORKSPACE (NAO DA PARA INSTALAR PING)
# RUN tt_4
cd tt_4
./run.sh
cd ..
