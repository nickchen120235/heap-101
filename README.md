# Demonstration Code for Heap 101 Presentation

Presentation: https://docs.google.com/presentation/d/1faxIZOY48M7vc0DuuRHa4elljE8ACEi695fAHYEbkx0/edit?usp=sharing

All code are tested on Ubuntu Server 22.04 with glibc 2.35

### What

`fastbin.c`, `tcache.c`, `double-free.c` are demonstrative code.

`uaf.c`, `overflow.c` are little pwning challenge, the solutions are under the `solution` folder if you're stuck.

### How

You'll need `make` and `gcc`, on Ubuntu-based OS `build-essential` is enough.

You can `make` to compile all examples, or `make <target>` to compile specific example.

Good luck solving heap-based CTF challenges!
