# Käyttöjärjestelmät ja systeemiohjelmointi: project 1
Reverse - a part of my systems programming course project</br></br>
This program reads in the data from an input file and reverses it so that the last line is printed first and the first line is printed last. This repository includes a Makefile, and the program can be compiled by running "make" on the command line. 

## Running

The program can be invoked with 0, 1 or 2 command-line arguments. It should be invoked in one of the following ways:<br></br>

./reverse
./reverse input.txt
./reverse input.txt output.txt<br></br>

When invoked with no arguments, the program reads from stdin and writes to stdout. When invoked with 1 command, it reads from input file and writes to stdout. And finally, when invoked with 2 arguments, it reads from input file and writes to output file.<br></br>

If, for example, an input file looks like this:<br></br>

1st line  
2nd line  
3rd line  
4th line  

then output file will look like this:<br></br>

4th line  
3th line  
2nd line  
1st line  
