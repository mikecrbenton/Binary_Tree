# Binary_Tree
CSC 300 // C++ program building a decision tree using a Vector&lt;> implementation

## Assignment Overview:
This assignment will use trees to build a program that is capable of guessing what a user is thinking. In
this example, you will ask the user to think of their favorite superhero character.The program will 
attempt to guess what they are thinking by asking a series of questions. The program will use the answers 
to these questions to build out a decision tree and eventually be capable of guessing correctly.

#### The Program:
The program starts each round by asking the first question stored at the top (root) of the tree. Depending 
on the answer, it moves left or right until it reaches a leaf node. Once a leaf node is reached, it must 
make a guess. If the guess is not correct, it asks the user for the name of the new character and a question 
that distinguishes the wrong guess from the new character. It then adds a node to the tree with the new question 
and the new character.

#### Here is some pseudo code:
While the user is thinking of a character:

* Start at root

  * While left child is not a leaf node:
    * If user responds yes to question in current node:
      * Follow right child
    * Else:
      * Follow left child
      
   * Make a guess using current node
   
   * If guess is correct:
     * Tell the user correct
     * Move to next iteration of loop
     
   * Prompt user for new character’s name
   * Prompt user for question that distinguishes new character
   
   * Insert question into current node
   
   * Prompt user what answer to question would be for current character
   
   * If answer is yes:
     * Set left child equal to guess
     * Set right child equal to character
   * Else:
     * Set left child equal to character
     * Set right child equal to guess
     
#### Requirements:
Write a class called CharacterTree that handles building and accessing your decision tree. 
The only requirement of this class is that it uses some sort of linear or dynamic array to 
store the tree itself. DO NOT USE STRUCTS. Refer to lecture on heaps for more information on 
representing a binary tree using an array.
Suggestions:
* #include string
* #include vector
* getline( cin, … );
* void CharacterTree::insert( string s, int index ){}
* string CharacterTree::retrieve( int index ){}
