<h3 align="center">42 São Paulo - Pipex</h3>

<div align="center">

![42 São Paulo](https://img.shields.io/badge/42-SP-1E2952)
![License](https://img.shields.io/github/license/librity/ft_pipex?color=yellow)
![Code size in bytes](https://img.shields.io/github/languages/code-size/librity/ft_pipex?color=blue)
![Lines of code](https://img.shields.io/tokei/lines/github/librity/ft_pipex?color=blueviolet)
![Top language](https://img.shields.io/github/languages/top/librity/ft_pipex?color=ff69b4)
![Last commit](https://img.shields.io/github/last-commit/librity/ft_pipex?color=orange)

</div>

<div align="center">

[![Build](https://github.com/librity/ft_pipex/actions/workflows/build.yml/badge.svg)](https://github.com/librity/ft_pipex/actions/workflows/build.yml)
[![Norminette v3](https://github.com/librity/ft_pipex/actions/workflows/norminette_v3.yml/badge.svg)](https://github.com/librity/ft_pipex/actions/workflows/norminette_v3.yml)
[![denisgodoy_pipex-tester](https://github.com/librity/ft_pipex/actions/workflows/denisgodoy_pipex-tester.yml/badge.svg)](https://github.com/librity/ft_pipex/actions/workflows/denisgodoy_pipex-tester.yml)
[![gsilva-v_pipextester](https://github.com/librity/ft_pipex/actions/workflows/gsilva-v_pipextester.yml/badge.svg)](https://github.com/librity/ft_pipex/actions/workflows/gsilva-v_pipextester.yml)
[![vfurmane_pipex-tester](https://github.com/librity/ft_pipex/actions/workflows/vfurmane_pipex-tester.yml/badge.svg)](https://github.com/librity/ft_pipex/actions/workflows/vfurmane_pipex-tester.yml)
[![yoo0lh_pipex_tester_42](https://github.com/librity/ft_pipex/actions/workflows/yoo0lh_pipex_tester_42.yml/badge.svg)](https://github.com/librity/ft_pipex/actions/workflows/yoo0lh_pipex_tester_42.yml)

</div>

<p align="center"> A simple implementation of UNIX <code>|</code>, <code><</code>, <code><<</code>, <code>></code> and <code>>></code> in pure C.
  <br>
</p>

---

## 📜 Table of Contents

- [About](#about)
- [Checklist](#checklist)
- [Getting Started](#getting_started)
- [Notes](#notes)
- [42 São Paulo](#ft_sp)
- [Resources](#resources)

## 🧐 About <a name = "about"></a>

In this projects we implement UNIX pipes and redirections, namely
`|`, `<`, `<<`, `>` and `>>`.
These mechanisms allow us to link commands and files together,
where the output of one serves as the input of the next.

This _toolbox philosophy_ is one of the reasons why
UNIX is still popular after 40 years:
it encourages developers to create programs that do one thing well,
and that work well with other programs.
It's also extremely modular and versatile.

I learned about child processes, filesystem interfaces
and the internals of `bash`, the target of our emulation.
Since I did both bonuses I'm pretty confident about
the next big challenge in the 42 curriculum: `minishell`.
It's basically this with a parser and dynamic environment variables.

## ✅ Checklist <a name = "checklist"></a>

### Mandatory

- [x] DONT TURN IN LIBS AS SUBMODULES
- [x] MAKEFILE EXPLICIT SOURCE FILES (`echo M_SOURCES`)
- [x] Make must compile without relinking
  - [x] SHOOULDNT RECOMPILE/REARCHIVE OBJECTS WITH MAKE ALL
    - [x] Add `.keep` to object dirs
    - [x] Remove `initialize` from `all` /build
    - [x] Create non-phony rule for each lib archive
- [x] `.linux` file (42 Workspaces)
- [x] Test in workspaces
- [x] Follows `norminette 3.3.51`
- [x] Turn in `Makefile`, `*.h`, `*.c` , `.linux` , `.gitignore`
- [x] Makefile rules: `$(NAME)` `all` `clean` `fclean` `re`
- [x] Program name `pipex`
- [x] Compiles with `-Wall -Wextra -Werror`
- [x] Should not quit unexpectedly (segmentation fault, bus error, double
      free, etc.)
- [x] All allocated heap memory properly freed, no memory leaks.
  - [x] Check memory leaks with `valgrind`
- [x] Allowed functions:
  - [x] `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`
  - [x] `libft` allowed
  - [x] Your `ft_printf` (may be modified)
    - [x] No `printf` from `stdio.h`
- [x] Handle arguments `file1 cmd1 cmd2 file2`
  - [x] Wrong number of arguments exits with help message
- [x] Behaves exactly like `< file1 cmd1 | cmd2 > file2`
  1. `< file1 cmd1`: `< file1` read `file1` and pipes it to `cmd1`’s `STDIN`
  2. `cmd1 | cmd2`: `cmd1`’s `STDOUT` is piped to `cmd2`’s `STDIN`
  3. `cmd2 > file2`: `cmd2`’s `STDOUT` is piped to `file2`, overwriting the file
- [x] Handle errors exactly like `< file1 cmd1 | cmd2 > file2`
- [x] Handle input errors (in order):
  - [x] `argc != 5` , return `0`
  - [x] No `infile`, return `0`
  - [x] No `cmd1` , return `0`
  - [x] No `cmd2` , return `127`
  - [x] `cmd1` bad arguments, return `0`
  - [x] `cmd2` bad arguments, return `1`
- [x] Pass all testers
  - [x] [https://github.com/denisgodoy/pipex-tester](https://github.com/denisgodoy/pipex-tester)
  - [x] [https://github.com/gsilva-v/PipexTester](https://github.com/gsilva-v/PipexTester)
  - [x] [https://github.com/vfurmane/pipex-tester](https://github.com/vfurmane/pipex-tester)
  - [x] [https://github.com/Yoo0lh/pipex_tester_42](https://github.com/Yoo0lh/pipex_tester_42)

### Bonus

- [x] Handle multiple pipes:
  - `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`
  - `./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`
- [x] Support `«` and `»` when the first parameter is "here_doc":
  - `./pipex here_doc LIMITER cmd cmd1 file`
  - `cmd << LIMITER | cmd1 >> file`

## 🏁 Getting Started <a name = "getting_started"></a>

### 🖥️ Installing

Clone the repo and build with `make`:

```bash
$ git clone --recurse-submodules https://github.com/librity/ft_pipex.git
$ cd ft_pipex
$ make
```

It works exactly like `< infile cmd1 | cmd2 > outfile`:

```bash
./pipex infile "ls" "wc" outfile

./pipex infile "ls -l" "wc -l" outfile
./pipex infile "grep a1" "wc -w" outfile

./pipex .gitignore "tr a b" "tr b c" outfile
./pipex EOF "tr a b" "tr b c" outfile
./pipex .gitignore "ping 8.8.8.8" "grep ms" outfile
```

### Bonus

You can also compile the bonus implementation:

```bash
$ make bonus
```

It handles multiple pipes `< infile cmd1 | cmd2 | cmd3 | ... | cmdn > outfile`:

```bash
./pipex infile "grep a" "grep d" "grep s" outfile
./pipex infile "ls -l" "grep a" "wc -l" outfile
./pipex infile "cat" "tr a b" "tr b a" "tr a b" "tr b a" outfile
```

It also takes a heredoc as input `cmd1 << LIMITER | cmd2 >> file`:

```bash
./pipex here_doc l "grep a" "grep d" "grep s" outfile
./pipex here_doc l "grep a" "wc -l" outfile
./pipex here_doc x "cat" "tr a b" "tr c d"  outfile
```

## 📝 Notes <a name = "notes"></a>

### `< infile cmd`

Redirect `infile` ’s contents to `cmd` ’s `STDIN`

```bash
python hello.py < foo.txt      # feed foo.txt to stdin for python
diff <(ls -r) <(ls)            # Compare two stdout without files
```

### `cmd1 | cmd2`

Redirects previous `cmd1`'s `STDOUT` to `cmd2` ’s `STDIN`

```bash
ls -la | wc -l
```

### `cmd > outfile`

Truncates `outfile` with `cmd` ’s `STDOUT`

```bash
python hello.py > output.txt   # stdout to (file)
python hello.py >> output.txt  # stdout to (file), append
python hello.py 2> error.log   # stderr to (file)
python hello.py 2>&1           # stderr to stdout
python hello.py 2>/dev/null    # stderr to (null)
python hello.py &>/dev/null    # stdout and stderr to (null)
```

### `perror`

- [https://www.man7.org/linux/man-pages/man3/perror.3.html](https://www.man7.org/linux/man-pages/man3/perror.3.html)

### `errno`

- [https://www.man7.org/linux/man-pages/man3/errno.3.html](https://www.man7.org/linux/man-pages/man3/errno.3.html)

```bash
# GET ALL ERRNO CODES
$ sudo apt install moreutils
$ errno -l
```

### **`strerror`**

- [https://linux.die.net/man/3/strerror](https://linux.die.net/man/3/strerror)
- [https://www.geeksforgeeks.org/error-handling-c-programs/](https://www.geeksforgeeks.org/error-handling-c-programs/)

### `open`

- [https://www.man7.org/linux/man-pages/man2/open.2.html](https://www.man7.org/linux/man-pages/man2/open.2.html)
- [https://jameshfisher.com/2017/02/24/what-is-mode_t/](https://jameshfisher.com/2017/02/24/what-is-mode_t/)

### `close`

- [https://www.man7.org/linux/man-pages/man2/close.2.html](https://www.man7.org/linux/man-pages/man2/close.2.html)

### **`access`**

Checks if the calling process can access a specific file

- [https://www.man7.org/linux/man-pages/man2/access.2.html](https://www.man7.org/linux/man-pages/man2/access.2.html)

### **`dup` & `dup2`**

Adjust file descriptors so they reference the same file.

- [https://www.man7.org/linux/man-pages/man2/dup.2.html](https://www.man7.org/linux/man-pages/man2/dup.2.html)
- [https://www.geeksforgeeks.org/dup-dup2-linux-system-call/](https://www.geeksforgeeks.org/dup-dup2-linux-system-call/)

### **`execve`**

Replaces the current process with a system call.

- [https://jameshfisher.com/2017/02/05/how-do-i-use-execve-in-c/](https://jameshfisher.com/2017/02/05/how-do-i-use-execve-in-c/)
- [https://stackoverflow.com/questions/29615540/using-execve-in-c](https://stackoverflow.com/questions/29615540/using-execve-in-c)
- [https://www.tutorialspoint.com/unix_system_calls/execve.htm](https://www.tutorialspoint.com/unix_system_calls/execve.htm)
- [https://www.man7.org/linux/man-pages/man2/execve.2.html](https://www.man7.org/linux/man-pages/man2/execve.2.html)
- [https://stackoverflow.com/questions/5429141/what-happens-to-malloced-memory-after-exec-changes-the-program-image/5429592#5429592](https://stackoverflow.com/questions/5429141/what-happens-to-malloced-memory-after-exec-changes-the-program-image/5429592#5429592)

### **`fork`**

Forks the parent process, creating a child process.
The child process is almost identical to its parent,
with a copy of its memory space at the time of fork.

- [https://www.man7.org/linux/man-pages/man2/fork.2.html](https://www.man7.org/linux/man-pages/man2/fork.2.html)
- [https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY](https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)

### **`pipe`**

Creates a pipe: a data channel through which processes can communicate.
Emitting processes can write to`pipefd[1]`,
and receiving ones can read from `pipefd[0]`.

- [https://www.man7.org/linux/man-pages/man2/pipe.2.html](https://www.man7.org/linux/man-pages/man2/pipe.2.html)
- [https://man7.org/linux/man-pages/man7/pipe.7.html](https://man7.org/linux/man-pages/man7/pipe.7.html)
- [https://www.programacaoprogressiva.net/2014/09/Pipes-em-C-Comunicao-entre-Processos-IPC-Interprocess-Communication.html](https://www.programacaoprogressiva.net/2014/09/Pipes-em-C-Comunicao-entre-Processos-IPC-Interprocess-Communication.html)

### **`unlink`**

- [https://linux.die.net/man/2/unlink](https://linux.die.net/man/2/unlink)

### **`wait` & `waitpid`**

Wait for a process to change state.

- [https://man7.org/linux/man-pages/man2/wait.2.html](https://man7.org/linux/man-pages/man2/wait.2.html)
- [https://www.man7.org/linux/man-pages/man3/waitpid.3p.html](https://www.man7.org/linux/man-pages/man3/waitpid.3p.html)

### `char **envp`

A string array with all the environment variables of the parent shell.

- [https://www.geeksforgeeks.org/c-program-print-environment-variables/](https://www.geeksforgeeks.org/c-program-print-environment-variables/)
- [https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)
- [https://stackoverflow.com/questions/54723587/what-does-envp-stand-for](https://stackoverflow.com/questions/54723587/what-does-envp-stand-for)

### Processes vs Threads

- Threads are lighter: easier to create and destroy
- Processes don’t share memory

### `lalloc` - Listed Memory Allocation

A linked list in the control structure with all the allocated memory pointers.
The interface function `ft_lalloc` allocates memory and adds the pointer to the list.
The interface function `ft_free_lalloc` frees all pointers and the list.

## 🛸 42 São Paulo <a name = "ft_sp"></a>

Part of the larger [42 Network](https://www.42.fr/42-network/),
[42 São Paulo](https://www.42sp.org.br/) is a software engineering school
that offers a healthy alternative to traditional education:

- It doesn't have any teachers and classes.
- Students learn by cooperating
  and correcting each other's work (peer-to-peer learning).
- Its focus is as much on social skills as it is on technical skills.
- It's completely free to anyone that passes its selection process -
  [**The Piscine**](https://42.fr/en/admissions/42-piscine/)

It's an amazing school, and I'm grateful for the opportunity.

## 📚 Resources <a name = "resources"></a>

### Bash Pipes

- [https://wikiless.org/wiki/Pipeline\_(Unix)?lang=en](<https://wikiless.org/wiki/Pipeline_(Unix)?lang=en>)
- [https://wikiless.org/wiki/Unix_philosophy?lang=en](https://wikiless.org/wiki/Unix_philosophy?lang=en)
- [https://devhints.io/bash](https://devhints.io/bash)
- [https://stackoverflow.com/questions/9834086/what-is-a-simple-explanation-for-how-pipes-work-in-bash](https://stackoverflow.com/questions/9834086/what-is-a-simple-explanation-for-how-pipes-work-in-bash)
- [https://stackoverflow.com/questions/21287848/function-to-find-the-maximum-number-of-pipes](https://stackoverflow.com/questions/21287848/function-to-find-the-maximum-number-of-pipes)
- [https://linuxconfig.org/introduction-to-named-pipes-on-bash-shell](https://linuxconfig.org/introduction-to-named-pipes-on-bash-shell)
- [https://linuxhint.com/bash_pipe_tutorial/](https://linuxhint.com/bash_pipe_tutorial/)
- [https://www.delftstack.com/howto/linux/pipes-in-bash/](https://www.delftstack.com/howto/linux/pipes-in-bash/)
- [https://devdocs.io/bash/](https://devdocs.io/bash/)

### Pipe Order

- [https://www.gnu.org/software/bash/manual/html_node/Pipelines.html](https://www.gnu.org/software/bash/manual/html_node/Pipelines.html)
- [https://www.gnu.org/software/bash/manual/html_node/Lists.html](https://www.gnu.org/software/bash/manual/html_node/Lists.html)
- [https://stackoverflow.com/questions/66511243/bash-pipe-execution-order](https://stackoverflow.com/questions/66511243/bash-pipe-execution-order)
- [https://unix.stackexchange.com/questions/37508/in-what-order-do-piped-commands-run](https://unix.stackexchange.com/questions/37508/in-what-order-do-piped-commands-run)
- [https://linuxhint.com/bash_pipe_tutorial/](https://linuxhint.com/bash_pipe_tutorial/)

### `nm -un`

- [https://www.howtoforge.com/linux-nm-command/](https://www.howtoforge.com/linux-nm-command/)
- [https://www.tutorialspoint.com/unix_commands/nm.htm](https://www.tutorialspoint.com/unix_commands/nm.htm)

### CS 61

- [https://cs61.seas.harvard.edu/site/2021/](https://cs61.seas.harvard.edu/site/2021/)
- [https://cs61.seas.harvard.edu/site/2021/ProcessControl/](https://cs61.seas.harvard.edu/site/2021/ProcessControl/)
- [https://cs61.seas.harvard.edu/site/2021/Section11/](https://cs61.seas.harvard.edu/site/2021/Section11/)

### File Descriptors

- [https://www.youtube.com/watch?v=6SA6S9Ca5-U](https://www.youtube.com/watch?v=6SA6S9Ca5-U)

### FORBIDDEN! `execlp`

A more convenient version of `execve`.

- [https://linux.die.net/man/3/execlp](https://linux.die.net/man/3/execlp)

### Valgrind Child Leaks

- [https://stackoverflow.com/questions/16847385/valgrind-to-detect-memory-leak-in-child-process](https://stackoverflow.com/questions/16847385/valgrind-to-detect-memory-leak-in-child-process)

### Testers

- [https://github.com/denisgodoy/pipex-tester](https://github.com/denisgodoy/pipex-tester)
- [https://github.com/vfurmane/pipex-tester](https://github.com/vfurmane/pipex-tester)
- [https://github.com/Yoo0lh/pipex_tester_42](https://github.com/Yoo0lh/pipex_tester_42)
- [https://github.com/HEADLIGHTER/pipexfasttest](https://github.com/HEADLIGHTER/pipexfasttest)
- [https://github.com/gmarcha/pipexMedic](https://github.com/gmarcha/pipexMedic)
- [https://github.com/gsilva-v/PipexTester](https://github.com/gsilva-v/PipexTester)
- [https://github.com/mariadaan/PIPEXaminator](https://github.com/mariadaan/PIPEXaminator)

### Parsing Tokens

- [https://towardsdatascience.com/why-are-there-so-many-tokenization-methods-for-transformers-a340e493b3a8](https://towardsdatascience.com/why-are-there-so-many-tokenization-methods-for-transformers-a340e493b3a8)
- [https://nlp.stanford.edu/IR-book/html/htmledition/tokenization-1.html](https://nlp.stanford.edu/IR-book/html/htmledition/tokenization-1.html)

### C Quirks

- [https://stackoverflow.com/questions/2407605/c-warning-missing-sentinel-in-function-call](https://stackoverflow.com/questions/2407605/c-warning-missing-sentinel-in-function-call)

### Should I `free` before exiting?

- [https://stackoverflow.com/questions/36584062/should-i-free-memory-before-exit](https://stackoverflow.com/questions/36584062/should-i-free-memory-before-exit)
- [https://newbedev.com/should-i-free-memory-before-exit](https://newbedev.com/should-i-free-memory-before-exit)
- [https://cboard.cprogramming.com/c-programming/75239-freeing-memory-before-exit.html](https://cboard.cprogramming.com/c-programming/75239-freeing-memory-before-exit.html)
- [http://c-faq.com/malloc/freeb4exit.html](http://c-faq.com/malloc/freeb4exit.html)
- [https://www.linuxquestions.org/questions/programming-9/to-free-or-not-to-free-before-an-exit-458107/](https://www.linuxquestions.org/questions/programming-9/to-free-or-not-to-free-before-an-exit-458107/)
- [https://stackoverflow.com/questions/654754/what-really-happens-when-you-dont-free-after-malloc-before-program-termination](https://stackoverflow.com/questions/654754/what-really-happens-when-you-dont-free-after-malloc-before-program-termination)
- [https://stackoverflow.com/questions/2975831/is-leaked-memory-freed-up-when-the-program-exits](https://stackoverflow.com/questions/2975831/is-leaked-memory-freed-up-when-the-program-exits)

### Git `submodule`

- `git clone --recurse-submodule REMOTE_REPO`
- `git submodule add REMOTE_REPO`
- `git submodule foreach git pull`
- `git submodule update --init --recursive`
- [https://stackoverflow.com/questions/33714063/how-to-update-submodules-in-git](https://stackoverflow.com/questions/33714063/how-to-update-submodules-in-git)
- [https://stackoverflow.com/questions/59271919/how-to-clone-public-submodule-in-github-actions](https://stackoverflow.com/questions/59271919/how-to-clone-public-submodule-in-github-actions)
- [https://stackoverflow.com/questions/50254184/git-submodule-and-fetch](https://stackoverflow.com/questions/50254184/git-submodule-and-fetch)
- [https://www.w3docs.com/snippets/git/how-to-add-a-submodule-in-git.html](https://www.w3docs.com/snippets/git/how-to-add-a-submodule-in-git.html)
- [https://stackoverflow.com/questions/1260748/how-do-i-remove-a-submodule#1260982](https://stackoverflow.com/questions/1260748/how-do-i-remove-a-submodule#1260982)
- [https://stackoverflow.com/questions/2006172/git-how-to-reset-a-remote-git-repository-to-remove-all-commits](https://stackoverflow.com/questions/2006172/git-how-to-reset-a-remote-git-repository-to-remove-all-commits)

### Bash Quirks

- [https://linuxize.com/post/bash-shebang/](https://linuxize.com/post/bash-shebang/)
- [https://stackoverflow.com/questions/18219262/evaluating-variables-in-a-string](https://stackoverflow.com/questions/18219262/evaluating-variables-in-a-string)
- [https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux](https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux)
- [https://stackoverflow.com/questions/1951742/how-can-i-symlink-a-file-in-linux](https://stackoverflow.com/questions/1951742/how-can-i-symlink-a-file-in-linux)
- [https://stackoverflow.com/questions/9452935/unix-create-path-of-folders-and-file](https://stackoverflow.com/questions/9452935/unix-create-path-of-folders-and-file)

### Videos

- [https://www.youtube.com/watch?v=6xbLgZpOBi8](https://www.youtube.com/watch?v=6xbLgZpOBi8)
- [https://www.youtube.com/playlist?list=PLFAC320731F539902](https://www.youtube.com/playlist?list=PLFAC320731F539902)
- [https://www.youtube.com/results?search_query=c+pipe+fork+wait](https://www.youtube.com/results?search_query=c+pipe+fork+wait)
- [https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
