*This project has been created as part of 42 curriculum by ktyu, cong.*

## Description

### Summary: Recreating a simple shell / or own bash.

Note: Limit yourself to the subject description. Anything not asked is not required. If you have any doubt about a requirement, take bash as a reference,

### Requirements:
1. Display a prompt when waiting for a new command.
2. Have a working history.
3. Search and launch the right executable (based on the PATH variable or using a relative or an absolute path).
4. Use at most one global variable to indicate a received signal. Consider the implications: this approach ensures that your signal handler will not access your main data structures. Important Note: This global variable must only store the signal number and must not provide any additional information or access to data. -> Cannot use "norm" type structure in the global scope.
5. Not interpret unclosed quotes or special characters which are not required by the subject such as \ (backslash) or ; (semicolon).
6. Handle ' (single quote) which should prevent the shell from interpreting the meta-characters in the quoted sequence.
7. Handle " (double quote) which should prevent the shell from interpreting the meta-characters in the quoted sequence except for $ (dollar sign).
8. Implement the following redirections (<, >, <<, >>)
9. Implement pipes (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
10. Handle environment variables ($ followed by a sequence of characters) which should expand to their values.
11. Handle $? which should expand to the exit status of the most recently executed foreground pipeline.
12. Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash. (In interactive mode: ctrl+C displays a new prompt on a new line. Ctrl+D exits the shell. Ctrl-\ does nothing.
13. Must Must be implemented bulti-in commands:
    - echo with option -n
    - cd with only a relative or absolute path
    - pwd with no options
    - export with no options
    - unset with no options
    - env with no options or arguments
    - exit with no options
Note: The readline() function may cause memory leaks, but you are not required to fix them. However, this does not mean your own code can have memory leaks.

### Planning

Minishell is like Read-Eval-Print Loop (REPL).

Bash (Bourne Again SHell) works as a command-line interpreter that acts as a textual bridge between you and your computer's operating system kernel. 

How bash works:
REPL (Read-Eval-Print-Loop), meaning it constantly waits for input, translates that input into actions the computer understands, displays the result, and loops back to wait for the next command.

Command Processing Cycle:


1. Read: takes the raw text string you typed into the terminal.
- Copy Environment: On program startup, clone envp into a custom linked list or array -> able to modify (export / unset) without memory issues.
- Setting up prompt signals: Setup sigaction for SIGINT (Ctrl+C) to clear line and reprint prompt, and SIGQUIT (Ctrl+\)
- Display Prompt: Call line = readline("minishell$ ")
- Check EOF (Ctrl+D): If line == NULL, print exit\n, free environment, and exit program
- Add History: If line is not empty, call add_history(line).


2. Lexer / Tokenize: Breaking up the string into pieces (tokens) separated by spaces to identify the core command and its argument.

Goal: Convert char *line into an array or linked list of t_token structs

3. Expansion: Processes the special symbols. Replaces variables (like $USER to your username), expands shortcuts (like ~ to your home directory), and evaluates wildcards.

4. Execution: Looks for the program. If built-in function, run it instantly. 

5. Print: Program sends its output back to Bash for display and shows a new prompt for next input. 

*Need to remember to clear mem use to prevent mem leak


Example of how everything comes together:

Step 1: readline() - raw input
gives you one long string.

char *line = "cat < input.txt | grep \"$USER\"";
Note: At this stage, the program don't know what cat, <, or | mean yet. These are just characters and words.

Step 2: Lexer / Tokenizer - splitting into Words

Lexer will slice the string into individual Tokens (words and operators). It will tag each piece so the shell knows what role it plays.

Note:
Enumerations (enum) creates a custom user-defined type whose values are restricted to a named set of integer constants.

We will need to use both enum and struct together.

struct: will hold the data for a token. it will hold different information such as the string value and a pointer to the next node.

enum: will assign a type or category to that token so that the code can quick identify what it is.



Output of Lexer (Token List):

1. [WORD] -> "cat"
2. [REDIR_IN] -> "<"
3. [WORD] -> "input.txt"
4. [PIPE] -> "|"
5. [WORD] -> "grep"
6. [WORD] -> "\"$USER\""

Note: Now, the program knows about the meaning behind each special characters like |, <, >, <<, >>) without searching through a single raw string over and over.

Example:

ktyu@LAPTOP-8K47KAAD:~/minishell_shared$ cc main.c lexer.c lexer_helper.c -o main -lreadline
ktyu@LAPTOP-8K47KAAD:~/minishell_shared$ ./main
minishell$ 1
Token: [1           ] Type: 0
minishell$ ls -l > cat.txt
Token: [ls          ] Type: 0
Token: [-l          ] Type: 0
Token: [>           ] Type: 3
Token: [cat.txt     ] Type: 0

Step 3: Expander - Variables and quotes
Note: Go token by token through the list created by Lexer and clean up the text

1. Look for the character $, replace $USER with ktyu

2. Strip outer quotes: "ktyu" to ktyu.

Output after expander:

1. [WORD] -> "cat"
2. [REDIR_IN] -> "<"
3. [WORD] -> "input.txt"
4. [PIPE] -> "|"
5. [WORD] -> "grep"
6. [WORD] -> "ktyu"

Step 4: Parser (Building the execution structure)

Parser will take those refined tokens and group them into t_cmd linked list separated by PIPE tokens.

// Node 1 (Before Pipe)
t_cmd Node 1:
    args   = ["cat", NULL]
    redirs = [type: REDIR_IN, file: "input.txt"]
    next   = Pointer to Node 2

// Node 2 (After Pipe)
t_cmd Node 2:
    args   = ["grep", "ktyu", NULL]
    redirs = NULL
    next   = NULL

Step 5: Executor 

Process the t_cmd list:

1. Sees Node 1 has a next node? -> Calls pipe().
2. Sees Node 1 has redirs? -> Opens input.txt and calls dup2() to redirect stdin.
3. Runs execve("/bin/cat", ["cat"], env).
4. Moves to Node 2 and executes grep ktyu.


## Instructions

current compilation:

cc main.c -o main -lreadline


## Resources

### Problem(s) faced:

Problem 1: issue with using readline() - meaning encountering the error "No such file or directory" even after including the 
#include <readline/readline.h>

Solution:
Fixed your OS by running:
1) sudo apt-get update
2) sudo apt-get install libreadline-dev
