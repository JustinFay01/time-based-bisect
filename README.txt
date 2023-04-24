This repository illustrates the use of git bisect to detect when a change was made that 
made the running time of some process exceed a threshold

Files:
sort.c:  this is the file that is actually contained in the repository        

base.c:      contains the main code that sets up a random array of integers of a given size
             and sorts it.  The value of SIZE isn't actually contained within this file

generate.pl: this script creates several revisions of sort.c, with a different value of 
             the SIZE constant defined at the beginning of the file, followed by the  
             contents of base.c.  Currently the maximum value of size will be 2^25

             It also generates a commit of that version of sort.c, with a commit message
             that indicates the value of SIZE used for that commit.

time.pl:    A Perl script that runs the executable a certain number of times, and computes 
            the average number of milliseconds it takes to run that version of the
            executable.

            This script takes a single command line argument representing a target value (in ms) for
            how long the sort can take to be considered a "good" run.

To demonstrate git bisect running for this application:

git log --oneline to see the list of revisions 
git bisect start HEAD `git log --pretty=%h | tail -1`     
git bisect run perl time.pl 1000

It should show the specific revision.  Can look at sort.c at that revision using 
git show bad:sort.c   (replace bad with the SHA-1 of the revision indicated by git bisect)

When done, execute "git bisect reset" to end the bisection process
