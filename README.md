# Project - Longest Common Subsequence
## Background

The longest common subsequence (LCS) problem is a common problem that arises (e.g.) in computational biology.  
*Given two sequences of numbers, letters, genes, etc., x[1..m] and y[1..n], find a longest subsequence that is common to both of them.*  
Usually no single, unique answer, but rather several possible answers exist. As we know, the brute force algorithm is **O(n*2m)** whereas the dynamic programming version is **O(m*n).** However, as we also know, the basic dynamic programming solution requires **O(2*n*m)** space.

## Program Descriptions

Assume that we are implementing a program to help us study similarity among organisms based upon comparison of gene sequences. In order to do this, we will implement the dynamic programming version of the LCS algorithm in two different ways in one program.
### Part 1:
The first part will:
- read a file containing a pair of character strings corresponding to the gene sequences 
- compute the LCS 
- and display the original strings and the longest subsequence of characters.  
This version of the problem will utilize the entire "c" array, but NO "b" array. You must reconstruct the sequence itself from the "c" array for full credit.  
Strings could be up to 1000 characters in length. The file name you should use is twoStrings.txt. 
Obviously, you will not be able to hand-check for LCS in strings of such length, so you should run tests with shorter strings to confirm correctness of your program.
### Part 2:

The second part will not make any attempt to recount the actual subsequence. It will **calculate measures of similarity (which I made up) among an arbitrary number of character strings in a file.** This second program will utilize an approach of keeping only the 2xM entries needed to compute the LCS value.

It will produce as output, a table that will look like this:
```
      01 02 03 04 05 06 07

01  -  H  M  D  M  L  D

02  -  -  H  H  D  D  H

03  -  -  -  L  M  D  M

04  -  -  -  -  M  L  M

05  -  -  -  -  -  M  L

06  -  -  -  -  -  -  M

07  -  -  -  -  -  -  -
```
Obviously, the 01, 02, 03, ... are labels for the strings, and the upper triangle holds a measure of similarity between pairs of strings {01,02}, {01,03}, {01,04}...

The possible entries in the table are:

H = high similarity between the strings

M = medium similarity between the strings

L = low similarity between the strings

D = the two strings are dissimilar

### Determining similarity:

High similarity exists if ***the length of the shorter string is within 10% of the length of the longer string and the longest common subsequence is at least 90% of the length of the shorter string.***

Medium similarity exists if ***the criteria for High similarity is not met but the length of the shorter string is within 20% of the longer string and the longest common subsequence is 80% of the length of the shorter string.***

Low similarity exists if ***the criteria for Medium similarity is not met but the length of the shorter string is within 40% of the longer string and the longest common subsequence is 50% of the length of the shorter string.***

Dissimilar strings are any that meet none of the above criteria.

The file of strings will: 
- first, contain an integer that indicates how many strings are in the file
- followed by that number of character strings.  
Strings will be terminated in the file by newlines.  

Recognize that you can end up with memory problems in a real-world version of this problem and you should not try to read all the strings into RAM at once. This is an obvious place to use a **direct access file.**  
We are already economizing on the amount of ram by not using the O(2*m*n) space. The reason for this is that these will be long strings and in a real-world solution, there might be a lot of them. For our purposes, you can assume there will be 20 strings or fewer. The file name you should use is multiStrings.txt
