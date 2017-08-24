/* CSC300 - Mike Benton
   Requirements: Your program should start each round by asking the first question stored 
   at the top (root) of the tree. Depending on the answer, it moves 
   left or right until it reaches a leaf node. Once a leaf node is reached, 
   it must make a guess. If the guess is not correct, it asks the user 
   for the name of a new character and a yes or no question that distinguishes 
   the wrong guess from the new character. It should then add a node to the 
   tree with the new question and the new character.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class CharacterTree
{

private:

	vector<string> vectorTree; 

public:

	CharacterTree();  //CONSTRUCTOR
	void insert(string s, int index);
	string retrieve(int index);
	void resizeTree(int index);

}; //END CLASS

//-----CLASS FUNCTIONS--------------------
CharacterTree::CharacterTree() //CONSTRUCTOR
{
	// INITIALIZE WITH 3 NODES
	vectorTree = vector<string>(3,"");
	
	//INITIALIZE FIRST NODE TO "CAPTAIN AMERICA" 
	vectorTree[0] = "Captain America";
}

void CharacterTree::insert(string s, int index)
{
	if( index * 2 > vectorTree.size() ) 
	{
		cout << "vectorTreeSize is : " << vectorTree.size() << endl;
		//ADD INDICES TO VECTOR SO NOT OUT OF BOUNDS
		//THIS WILL ADD 2 "NULL" INDICES TO THE NEXT 2 NODES AFTER THE INDICES FOR SEARCHING/TRAVERSING
		vectorTree.resize( index * 2  , "");                     
		cout << "resize was called" << "for index: " << index << endl; 
		cout << "        vectorSize is "  << vectorTree.size() << endl;  
	}
	vectorTree[index] = s;
	cout << "(index " << index << " =" << vectorTree.at(index) << ")" << endl;                               
}

string CharacterTree::retrieve(int index)
{
	if(index < vectorTree.size() ){
		return vectorTree.at(index); 
	}
	else{
		return "";
	}
	
}

void CharacterTree::resizeTree(int index)
{
	if( index * 2 > vectorTree.size() ) 
	{
		cout << "vectorTreeSize is : " << vectorTree.size() << endl;
		//ADD INDICES TO VECTOR SO NOT OUT OF BOUNDS
		//THIS WILL ADD 2 "NULL" INDICES TO THE NEXT 2 NODES AFTER THE INDICES FOR SEARCHING/TRAVERSING
		vectorTree.resize( index * 2  , "");   //vectorTree.resize(vectorTree.size() * 2, "");                    
		cout << "resize was called" << "for index: " << index << endl; 
		cout << "        vectorSize is "  << vectorTree.size() << endl;  
	}
}


int main( int argc, char **argv)
{
	
	CharacterTree myTree = CharacterTree(); //INITIALZE TREE OBJECT FOR GAME
	string answer = "y";                    //INITIALIZE THE ANSWER TO ENTER WHILE LOOP
	string yesOrNo;                         //STRING TO HOLD YES OR NO RESPONSE IN GAME
	string characterName;                   //STRING TO HOLD THE NAME OF CHARACTER
	string characterQuestion;               //STRING TO HOLD DISTINGUISHING QUESTION

	while(answer == "y")
	{	
		int treeIndex = 0; //INITIALIZE TO ZERO TO START AT ROOT

		cout << endl;
		cout << "Are you thinking of your favorite superhero character? (Enter y or n) ";
		getline (cin,answer);
		cout << endl;

		//CHECK USER INPUT
		while( (answer != "y") && (answer != "n")  ){
			cout << "Please enter y or n" << endl;
			cout << "Are you thinking of your favorite superhero character? (Enter y or n) ";
			getline (cin,answer);
		}
		
		if(answer == "n")
		{
			//CONTINUE BACK TO TOP TO END PROGRAM IF NO
			continue; 
		}

		//WHILE LEFT CHILD IS NOT A LEAF NODE 
		while(myTree.retrieve( (2*treeIndex) + 1) != "" )
		{
			//ASK QUESTION STORED IN VECTOR INDEX
			cout << myTree.retrieve(treeIndex) << " (Enter y or n) ";
			getline (cin,yesOrNo);

			while( (yesOrNo != "y") && (yesOrNo != "n") ){
				cout << "Please enter again: " << myTree.retrieve(treeIndex) << " (Enter y or n) ";
				getline (cin,yesOrNo);
			}

			if(yesOrNo == "y")
			{
				treeIndex = (2 * treeIndex) + 2; //GO TO THE RIGHT CHILD
			}
			else
			{
				treeIndex = (2 * treeIndex) + 1; //GO TO THE LEFT CHILD
			}

		}
		
		//MAKE A GUESS USING THE CURRENT NODE
		cout << "Is it " << myTree.retrieve(treeIndex) << "? (Enter y or n)";
		getline (cin,yesOrNo);  

		while( (yesOrNo != "y") && (yesOrNo != "n") ){
				cout << "Please enter again: Is it " << myTree.retrieve(treeIndex) << " (Enter y or n) ";
				getline (cin,yesOrNo);
		}  

		if(yesOrNo == "y")
		{
			cout << "I got it!" << endl << endl;  //TELL USER CORRECT GUESS 
			continue;                           //MOVE TO NEXT ITERATION OF LOOP
		}

		//PROMPT USER FOR NEW CHARACTERS NAME
		cout << "What is the character's name? ";	
		getline (cin, characterName);	

		//PROMPT USER FOR QUESTION THAT DISTINGUISHES NEW CHARACTER
		cout << "What yes or no question would distinguish " << characterName << " from " << myTree.retrieve(treeIndex) << "? ";
		cout << endl;
		getline (cin, characterQuestion);

		//NEED A TEMPORARY VARIABLE TO HOLD THE CURRENT NODE 
		string temp;  
		temp = myTree.retrieve(treeIndex);
		
		//INSERT QUESTION INTO CURRENT NODE
		myTree.insert(characterQuestion, treeIndex);

		//PROMPT USER FOR WHAT ANSWER TO QUESTION WOULD BE FOR THE CURRENT CHARACTER
		cout << "If the character were " << characterName << ", what would the answer be? (Enter y or n)";
		getline (cin,yesOrNo); 
		cout << endl;  

		while((yesOrNo != "y") && (yesOrNo != "n") ){
				cout << "Please enter again: what would the answer be? (Enter y or n) ";
				getline (cin,yesOrNo);
			}

		if(yesOrNo == "y")
		{
			//SET THE LEFT CHILD EQUAL TO THE GUESS
			myTree.insert(temp, (2 * treeIndex) + 1);
			//SET THE RIGHT CHILD EQUAL TO CHARACTER
			myTree.insert(characterName, (2 * treeIndex) + 2);
		}
		else
		{
			//SET THE LEFT CHILD EQUAL TO THE CHARACTER
			myTree.insert(characterName, (2 * treeIndex) + 1);
			//SET THE RIGHT CHILD EQUAL TO GUESS
			myTree.insert(temp, (2 * treeIndex) + 2);	
		}

	}//END OF WHILE
	
	cout << "Thanks for playing!" << endl;
	return 0;

}



