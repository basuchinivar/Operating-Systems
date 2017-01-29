
NAME		: Jayanth Sivakumar	
B-NUMBER	: B00615297
BMAIL		: jsivaku1@binghamton.edu



THE CODE IS BEING EXECUTED IN REMOTE MACHINE AND IS WORKING FINE WITHOUT ANY ERRORS, OUTPUT IS BEING GENERATED CORRECTLY WIHTOUT ANY PROBLEMS

STEPS TO INSTALL XV6 EMULATOR:
------------------------------

The xv6 in Remote Machine can be built by untaring the file in the path 
http://www.cs.binghamton.edu/˜zhangy/teaching/CS_550_16S/prj/cs550-16s-proj0-base.tar.gz.


After downloading the code, 
1. Two directory is created to untar the above downloaded file.
2. Untar to DIR_XV6_WORKING directory as well as DIR_XV6_BASE directory
3. Patch the file in the link http://www.cs.binghamton.edu/˜zhangy/teaching/CS_550_16S/prj/xv6-cs550-Makefile.patch to DIR_XV6_WORKING
4. On top of DIR_VX6_WORKING directory, build xv6 by typing "make qemu-nox"
5. Patch the file "proj0.jsivaku1.patch" to DIR_XV6_WORKING directory.
6. Now again  if you type make qemu-nox, you will see the output in the following format.

OUTPUT:
------
	cpu1: starting
	CS550 proj0 printing in kernel space
	cpu0: starting
	sb: size 1000 nblocks 941 ninodes 200 nlog 30 logstart 2 inodestart 32 bmap start 58
	init: starting sh

"CS550 proj0 printing in kernel space" is displayed in kernal space.

Later if you type ls to the xv6 emulator, the output looks like 

$ ls
.              1 1 512
..             1 1 512
README         2 2 1973
cat            2 3 13648
echo           2 4 12613
forktest       2 5 8213
grep           2 6 15560
init           2 7 13518
kill           2 8 12733
ln             2 9 12643
ls             2 10 15495
mkdir          2 11 12766
rm             2 12 12751
sh             2 13 25399
stressfs       2 14 13733
usertests      2 15 67244
wc             2 16 14258
zombie         2 17 12367
proj0          2 18 12702
console        3 19 0




You can notice the proj0 which is being created from the patching.

Now the output of proj0 is similar to echo, By typing like "proj0 Hello World", the output looks like this,



OUTPUT:
------

	$ proj0 Hello World
	CS550 proj0 print in user space: Hello World
	$ proj0 CS 550 Operating Systems Section 4
	CS550 proj0 print in user space: CS 550 Operating Systems Section 4
	$ proj0
	CS550 proj0 print in user space:


The above output is displayed in User space.

PATCH file with name proj0.jsivaku1.patch is submitted along with this README file. 
