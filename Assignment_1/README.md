shell can handle the following commands:-
Internal commands:
1. cd - change the current working directroy
   
2. pwd - print the name of working directroy

3. echo - print the input text
	-n - do not print the newline
	-E - ingnore the blckslash escapes
	--help - print --help
External commands:
1. ls - list the given directories/directory contents (which do not start with .)
	-a - do not ignore entries starting with .
	-d - list directories themselves, not their contents
2. date - print system date and time
	-u - print or set Coordinated Universal Time (UTC)
	-R - output date and time in RFC 5322 format
3. cat - print the files content
	-E - display $ at end of each line
	-n - number all output lines
4. mkdir - make directories
	-v - print message for created directory
	-m - set given file mode(-m=444 is allowed -m=rax is not allowed)
5. rm - remove files
	-v - print message for deleted files
	-i - prompt before every removal
6. exit - close/terminate the shell



// create some files for test
touch file1 file2 file3
// also write in these files before testing(for cat command) 

test cases:

make
date
date -u
date -R
cat file1
cat -E file2
cat -n file3
mkdir dir1
mkdir -m=321 dir2
mkdir -v dir3 dir4
rm file1
rm -v file2
rm -i file3
ls
ls ..
ls -a
ls -d
echo ankit
echo --help
echo -n noline
pwd
pwd -L
pwd -P
cd .
cd -L .
cd -P .

some error handled:
wrong command
wrong option
wrong directory name
wrong path name
file not exist

