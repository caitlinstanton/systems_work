<h1>Projects from Systems</h1>
<h2>[Fall Term--Senior Year--2015]</h2>

<br>

<h2><a href="https://github.com/mks65/tunez">01-tunez</a></h2>
Write a program in C that implements a music library organizer. The data structure should consist of an array of 26 slots, one for each letter from 'a' to 'z' (you can convert everything to lower case to make comparisons easier). Each slot will contain a linked list of all the artists that have names with the corresponding letter. When you add a song, it should go on to a linked list at the appropriate array slot in the correct position alphabetically. Assume no duplicates..

You should start by making your linked lists work with the following functionality:
  - insert nodes at the front
  - insert nodes in order
  - print the entire list
  - find and return a pointer to an individual song based on song name
  - find and return a pointer to the first song of an artist based on artist name
  - Return a pointer to random element in the list.
  - remove a single node from the list
  - free the entire list

Then create your array of linked lists for the full program and have the following functions:
  - Add songs.
  - Search for a song.
  - Search for an artist.
  - Print out all the entries under a certain letter.
  - Print out all the songs of a certain artist
  - Print out the entire library.
  - Shuffle - print out a series of randomly chosen songs.
  - Delete a song
  - Delete all the nodes.
