<pre>Write a Bash script to back up a list of files with some given extensions. Basically the files are copied into a
folder created in the target directory, named the current date. The name is a string obtained from date command,
but blanks and : are removed, using tr command. E.g., WedSep19112241EDT2018 is a valid name, obtained
using date and tr. Then, all files are archived using tar utility then, the original files (the ones just copied) are
removed. The name of the archive should be archive.tar</pre>
