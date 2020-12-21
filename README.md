# The Monty language
## 0x19. C - Stacks, Queues - LIFO, FIFO

![Cover of Monty](https://semanticadigital.com/wp-content/uploads/2017/01/cover-monty.png)

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Description

This project is a about:
- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables

## Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument

```
~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
~/monty$
```

# Usage
## Compilation & Output

Your code will be compiled this way
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

Usage: `monty file`

Example
**Example of Use**
![monty](https://semanticadigital.com/wp-content/uploads/2017/01/lvsf.gif)

```
~/monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
~/monty$ ./monty bytecodes/09.m 
3
2
1
2
3
1
~/monty$ 
```
## Monty Bytecode Commands
`push <int>` : The opcode push pushes an element to the stack.

## flowcharts
**Main flowchart**



## Authors

* David Alzate² <[Illker](https://github.com/illker)>
* Soren Acevedo <[SorenAcevedo](https://twitter.com/AcevedoSoren)>

![authors](https://semanticadigital.com/wp-content/uploads/2017/01/footerd.gif)
