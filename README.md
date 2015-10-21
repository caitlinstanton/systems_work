<h1>Assignments and Other Work from Systems</h1>
<h2>[Fall Term--Senior Year--2015]</h2>

<br>

<h2><a href="https://github.com/mks65/euler">01-euler</a></h2>
1. Look at the problems here: http://projecteuler.net/index.php?section=problems
2. They are all math problems of some sort, pick two and write a c program to solve it.
    - Finished early? pick a third, a fourth, a fifth...
3. Remember, c syntax is the same as java, so all your old friends (if, while, else, for...) are around.
4. Use scanf if you need user input (we'll talk about it tomorrow, but you can do man scanf to get info on it)

<br>

<h2><a href="https://github.com/mks65/stringy">02-stringy</a></h2>
First, acquaint yourself with the basic string functions: strlen, strcpy, strcat, strncat and strncpy. You can look at the man pages for each if you are unclear as to their uses. I encourage you to play around with each so you are comfortable with how to use them. Then write your own versions of the following four:
  - Required: 
    - strlen
    - strcpy/strncpy (choose one)
    - strcat/strncat (choose one)
    - strcmp
    - strchr
    - strstr
    - You must test every function you write, you will not get full credit for an untested functions
    - You do not need to write 8 functions, only 6, but you need to write 1 or the "n" versions. (So if you do strcpy then you have to do strncat)
  - Extra
    - The other strn/str version of the functions you wrote above
Remember you should call them something other than the regular names (like, mystrlen...). 

<br>

<h2><a href="https://github.com/mks65/list">03-list</a></h2>
Write a simple linked list program. You will need a define a node struct with the following data members:
  - A piece of data (your choice, but make it a primitive data type)
  - A pointer to the next node
Create the following functions:
  - print_list
    - Should take a pointer to a node struct and print out all of the data in the list
  - insert_front
    - Should take a pointer to the existing list and the data to be added, create a new node, put it at the beginning of the list and return a pointer to the beginning of the list.
  - free_list
    - Should take a pointer to a list as a parameter and then go through the entire list freeing each node and return a pointer to the beginning of the list (which should be NULL by then).                
Don't forget to test out these various functions to ensure they work correctly. (Just to be clear, when you run the program and get "Segmentation fault" that means it's not working.)
