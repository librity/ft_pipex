<h3 align="center">42 São Paulo - Pipex</h3>

<div align="center">

[![Norminette v3](https://github.com/librity/ft_pipex/actions/workflows/norminette_v3.yml/badge.svg)](https://github.com/librity/ft_pipex/actions/workflows/norminette_v3.yml)
![42 São Paulo](https://img.shields.io/badge/42-SP-1E2952)
![License](https://img.shields.io/github/license/librity/ft_pipex?color=yellow)
![Code size in bytes](https://img.shields.io/github/languages/code-size/librity/ft_pipex?color=blue)
![Lines of code](https://img.shields.io/tokei/lines/github/librity/ft_pipex?color=blueviolet)
![Top language](https://img.shields.io/github/languages/top/librity/ft_pipex?color=ff69b4)
![Last commit](https://img.shields.io/github/last-commit/librity/ft_pipex?color=orange)

</div>

<p align="center"> A simple implementation of UNIX <code>|</code>, <code><</code> and <code>></code> in pure C.
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

## ✅ Checklist <a name = "checklist"></a>

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

## 📝 Notes <a name = "notes"></a>

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
