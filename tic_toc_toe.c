//copyright from github and edited
//Ds projrct in c

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define WIDTH 3
#define SIZE WIDTH *WIDTH
#define MOVE_COUNT 8


//const char *DIVIDOR= "\n---+---+---\n";
const char *NUM_STR= "123456789";

const char EMPTY=' ';
const char PLAYER1='x';
const char PLAYER2='o';

/*
-->The container of all the positional that
must be ocupaied by a player to score a win
*/

const size_t WINNING_MOVES[MOVE_COUNT][3]={
	//horizontal streaks
	{0,1,2},
	{3,4,5},
	{6,7,8},
	//vertical streaks
	{0,3,6},
	{1,4,7},
	{2,5,8},
	//diagonal streaks
	{0,4,8},
	{2,4,6}
};

typedef struct tic_toc_toe
{
   char values[SIZE];
   struct tic_toc_toe *right;
}node;

/*
-->Return a new state with all blanks and navigation
cleared
*/

node *new_ptr(){
	node *ptr;
	ptr=malloc(sizeof(node));
	for (int i = 0; i < SIZE; ++i)
	{
		ptr->values[i]=EMPTY;
	}
	ptr->right=NULL;
}

/*
parameter ptr the parent node.
parameter index the free position to mark
parameter player the player which sill mark the cell
return a new state from a parent with the request
position marked by the given player mark
*/
node *derive(node *ptr, size_t index, char player){
ptr->right=new_ptr();
//copy values
for (size_t i = 0; i < SIZE; ++i)
{
	ptr->right->values[i]=ptr->values[i];
	/* code */
}
ptr=ptr->right;
ptr->values[index]=player;

return ptr;
}

/*
frees the space occupied by the given node and its successors
parameter pre ptr to deallocate
*/

void free_ptr(node *ptr){
	if(ptr==NULL)
		return;
	free(ptr->values);
	free(ptr->right);
	ptr->right=NULL;
	free(ptr);
}

/*
pretty prints the given ptr with evenly spaced
symbols and dividers and indicaes in place of blanks
parameter ptr the state to be pretty-printted
*/

void print_ptr(node *ptr){
	for(size_t row =0; row<WIDTH; ++row){
		if (row!=0)
			printf("\n---+---+---\n");
		for(size_t col=0; col<WIDTH; ++col){
         if(col!=0)
             printf("|");
		int index=row*WIDTH+col;
		char value =ptr->values[index];
		printf("%c",(value==EMPTY?NUM_STR[index]:value));
        }
    }
    printf("\n\n");
}


/*
parameter player the player who's win to check
parameter ptr the ptr to check for win in
return if the player has won
*/

bool if_won(char player,node *ptr){
	for(size_t move=0; move<MOVE_COUNT; ++move){
		int count=0;
		for(size_t index=0;index<WIDTH;++index){
			size_t move_idx=WINNING_MOVES[move][index];
			if(ptr->values[move_idx]==player){
				count++;
			}
			else{
                //no point is checking any further for this move
                break;
			}
		}
		if(count==WIDTH){
			print_ptr(ptr);
			printf("\n%c WINS!!\n",player);
			return true;
		}
	}
	return false;
}

/*
create a new state from the given state using input
provide by the human player

parameter current the current ptr to move from

return a new based on the input given by the human player
*/

node *take_input(char player, node *current){
	printf("***%c*** Your Turn ---->\n",player);
	print_ptr(current);
	printf("\nENTER YOUR POSITION:");
	size_t index;
	scanf("%ld",&index);//nolint
	while(index<1 || index>SIZE || current->values[index-1]!=EMPTY){
		printf("***INVALID POSITION !! ***\n***TRY AGAIN***:");
		scanf("%ld",&index);//nolint
	}
	return derive(current,index-1,player);
}

int main(){
	node *ptr=new_ptr();
	node *head=ptr;
	char player=PLAYER1;
	while(!if_won(PLAYER1,ptr) && !if_won(PLAYER2,ptr)){
		ptr=take_input(player,ptr);
		//change player
		player=player==PLAYER1?PLAYER2:PLAYER1;
	}
	free_ptr(head);
	return 0;
}