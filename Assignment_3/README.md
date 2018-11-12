<pre>
  The pseudo-code below, behaves like a simple shell for interpreting simple bash scripts, that
consist of a few lines. Each line is made of a single shell command with or without arguments.
  Write a C program that uses only Unix input/outputs system calls to open the script file and
to read each line until the end of the file. Each line consists of a command, except lines that
start with # or that are empty, that should be ignored. Your program uses fork() and exec() to
execute the commands.

Synopsis: myShell < myScriptFile >

Pseudo-code:
-----------
Open Scriptfile
// use perror() in case of error
while(1){
  readLine from myScriptFile
  if (read-error or end-of-file) // use perror() in case of error
    quit
  if (line is a comment or empty)
    skip iteration (continue in C)
extract command and arguments from line and store them in
a NULL-terminated array of strings, call it myCommand

duplicate current process
parent process waits for its child to terminate
child should exec to the new program using myCommand
}</pre>
