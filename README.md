*This project has been created as part of 42 curriculum by ktyu, cong.*

## Description

Summary: Recreating a simple shell / or own bash.

Note: Limit yourself to the subject description. Anything not asked is not required. If you have any doubt about a requirement, take bash as a reference,

Requirements:
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




## Instructions

## Resources
