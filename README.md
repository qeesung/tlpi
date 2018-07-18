# The Linux Programming Interface 

## How to setup env

Download the tlpi source code.

```bash
wget "http://man7.org/tlpi/code/download/tlpi-161214-dist.tar.gz"
```

Unzip the source code, and compile.

```bash
tar -zxvf tlpi-161214-dist.tar.gz
cd tlpi-dist/
make -j
```

Copy the header files to the system include directory.

```bash
cd lib/
sudo cp tlpi_hdr.h /usr/local/include/
sudo cp get_num.h /usr/local/include/
sudo cp error_functions.h /usr/local/include/
sudo cp ename.c.inc /usr/local/include/
```

Make a static shared library.

```bash
g++ -c get_num.c error_functions.c
ar -crv libtlpi.a get_num.o error_functions.o
sudo cp libtlpi.a /usr/local/lib
```


## How to compile a c file and run it

```bash
g++ <filename> -ltlpi -o <exec_file>
./<exec_file>
```
