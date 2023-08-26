
## Description
This project about implementing a simple interpreter for interpret high level language like "python programming" using the application of stack & queue Data structure. The implementation focuses on implementing stack and queue functionalities using  linked list data structure using C programming language. The primary goal of the project is to create a command-line application named "monty" that simulates an interpreter for a high-level programming language by executing Monty ByteCodes files.

## Table of Contents
- The Monty Language
- Project Concepts
- Compilation and Output
- Usage
- Implemented Functions
- Examples
- Notes

### The Monty Language
Monty 0.98 is a scripting language compiled into Monty ByteCodes files. These files have a .m extension and contain opcode instructions. Comments start with the '#' character.

### Project Concepts
In this project, we delve into the following concepts:
- LIFO (Last In, First Out) and FIFO (First In, First Out) structures
- Stack and queue implementations using a doubly linked lists

### Compilation and Output
To compile the "monty" application, use the following command:

```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
All output generated by the program will be printed on stdout and errors will printed on stderr.


### Usage
```
$ ./monty file
```
Replace file with the path to the Monty ByteCodes file.

### Implemented_instructions
This project involves implementing the following opcode functions:

1. push  
   push an element to the top of stack  

2. pall  
   prints all elements in the stack

3. pint  
   print the top element in the stack  

4. pop  
   remove the top element of the stack  
   
5. swap  
   swap the top two elements in the stack
   
6. add  
   add the the top element with it's previous and remove the top
   
7. nop  
   does'nt do any thing  
   
8. sub  
   subtract the the second top element from it's next and remove the top  
   
9. div  
   divide the the second top element by it's next and remove the top  
   
10. mul  
    maltiply the the second top element by it's next and remove the top  
   
11. mod  
    mod the the second top element by it's next and remove the top  
    
12. pchar  
    convert the top element to char according to it ascii value and print it  
    if not in ascii range will raise an error

13. handle comments      

14. rotl  
The top element of the stack becomes the last one,   
and the second top element of the stack becomes the first one



### Examples
1. push, 2. pall
```
$ cat -e bytecodes/00.m  
push 1$  
push 2$  
push 3$  
pall$  
$ ./monty bytecodes/00.m  
3  
2  
1  
$
```
---

3. pint
```
$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
$ ./monty bytecodes/06.m 
1
2
3
$
```
---

4. pop
```
$ cat bytecodes/07.m  
push 1  
push 2   
push 3  
pall  
pop  
pall  
pop  
pall  
pop  
pall  
$ ./monty bytecodes/07.m 
3
2
1
2
1
1
$ 
```
-------------------------------------------------------

5. swap  
```
$ cat bytecodes/09.m   
push 1  
push 2  
push 3  
pall  
swap  
pall  
$ ./monty bytecodes/09.m   
3  
2  
1  
2  
3  
1  
$ 
```
---
6. add
```
$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

$ ./monty bytecodes/12.m 
3
2
1
5
1
$
```
- all math (add, sub, mul, div, mod) instructions do the same thing
---

12. comments 13. pchar
---
```
$ cat bytecodes/28.m 
# this is comment
push 72
pchar
$ ./monty bytecodes/28.m 
H
$
```
---
14. rotl

```
$ cat bytecodes/35.m 
push 1
push 2
push 3
push 4
push 5
push 6
push 7
push 8
push 9
push 0
pall
rotl
pall
$ ./monty bytecodes/35.m 
0
9
8
7
6
5
4
3
2
1
9
8
7
6
5
4
3
2
1
0
$ 
```
### Notes
Invalid opcode instructions will be reported with an error message.
The program handles division by zero scenarios.
