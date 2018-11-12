<pre>Lab#6: ~~~  process control



Write a C program to simulate the following scenario:

1- The parent creates a child process.

2- The parent goes inside an infinite loop.

3- The parent opens the file "temp.txt" for reading(using fopen()).
   if successful, the parent closes the file, sleeps for 1 seconds then  
   opens the file "temp.txt" for reading again until nonsuccessful(file 
   not existant). This can be done using the loop below:

      while(f=fopen("temp.txt", "r")){
        fclose(f);
        sleep(1);  
      }

4- The parent reads two numbers and an operator(+, -, * or /) from the user.

5- The parent creates the file "temp.txt" and saves the data in the file.
   This can be done using -fprintf(f, "%f %f %c\n", a, b, op);- 
   The parent closes the file afterwards.

6- The parent will sleep for three seconds.

7- The child goes in an infinite loop

8- The child opens the file "temp.txt" for reading (using fopen()).
   if not successful, the child sleeps for 1 seconds then tries again 
   until success. This can be done using the loop below:

      while(!(f=fopen("temp.txt", "r")))
        sleep(1);  

9- The child reads two numbers and the operator from "temp.txt", closes
   the file, deletes it using the system call unlink("temp.txt").
   Then performs the appropriate operation and prints the results on the screen.

10- The child sleeps for 1 second.</pre>
