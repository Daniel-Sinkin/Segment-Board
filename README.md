# Segment-Board
In the scope of learning how to programm in C I've created this program that parses an inputstring representing different commands that can be sent to a segment board.

For a full run that parses `+ACG-A~+F+A+G+B-A-F~+A` see `output.txt`.
## Printing Predefined Characters
```
Printing 'E'.
      12345
      |||||
   +--+++++--
   |  
1 -|   ### 
2 -|  #    
3 -|  #    
4 -|  #    
5 -|   ### 
6 -|  #    
7 -|  #    
8 -|  #    
9 -|   ###
```
## Adding segments.
```
Adding Segment 'A'
      12345
      |||||
   +--+++++--
   |  
1 -|   ### 
2 -|       
3 -|       
4 -|       
5 -|       
6 -|       
7 -|       
8 -|       
9 -|    
```
## Implemented Functionality
* Adding (via prefix `+` or just writing the letter) and removing (via prefix `-`) 7 different segment pieces, labels A, ..., F inspired by [ElectronicsTutorials](https://www.electronics-tutorials.ws/blog/7-segment-display-tutorial.html).
* Clearing / Resetting the board.
* Compilation and saving of information via a shell script.

## Where could we go from here
* Print the steps one after the other, as a type of "animation", either waiting for a fixed time or for user input between each step.
* Allow user input into the console instead of just reading a string, either as a chain of steps or an individual command.
* Add support for multiple segment boards to be able to wrint entire words.

## Bugs and RFI (Room for Improvement)
* There is absolutely no input validation on the input string.
* There should be a way to save the output to a different file, or just have it print.

# Sources and References
* [ElectronicsTutorials](https://www.electronics-tutorials.ws/blog/7-segment-display-tutorial.html)
