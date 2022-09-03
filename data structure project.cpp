#include <iostream>
#include <string>
using namespace std;

struct Node{                   //structure node
     
     Node *next; 
	 int playerid;
	 float playerscore;
	 string playername;

};

 void startgame(Node *head){             //INITIALIZE LINKED LIST    start game
 	head=NULL;
 }


 void insert(Node *&head , int x){

 Node *temp = new Node();
 temp->playerid = x; 
 temp->next =NULL; 

 if(head == NULL){
 	 head = temp;
 	 return;

 }
    Node *p=head;
    while(p->next !=NULL){
    	p=p->next;

	}
		p->next=temp;
}


void swap (Node* p , Node* q){
    float t1 = p->playerscore;
    string t2 = p->playername;
    int t3 = p->playerid;

    p->playerscore = q->playerscore;
    p->playername = q->playername;
    p->playerid = q->playerid;


    q->playerscore = t1;
    q->playername = t2;
    q->playerid = t3;
}



void sort_ll(Node* head) {
    if(head == NULL)
        return;  // base case
    else
    {
        Node* p = head->next; // moving pointer

        while(p != NULL)  //find max value and store it into max_ptr
        {
            if(p->playerscore > head->playerscore) {
            swap(p, head);
            }

            p = p->next;
        }
        sort_ll(head->next);  //call function again
    }
}

void print(Node* head){
  Node* p = head;
  while(p != NULL){
  printf("%.3f\n" , p->playerscore);
  p = p->next;

  }

}


void update_score(Node *head,	int playerid, int newscore){
      if(head==NULL){
      	printf("Not found");
      	return;
	  }
    Node *q = head;
    while(q != NULL && q->playerid !=playerid){
    	q = q->next;
	}

	 if(q != NULL && q->playerid == playerid){

	     q->playerscore = newscore;
	}
     else
     printf("not found");
}


void search(Node *head,	int playerid){      
      if(head==NULL){
      	printf("Not found"); 
      	return;
	  }
	  Node *q = head;
    while(q != NULL && q->playerid !=playerid){ 
    	q = q->next;
	}

	 if(q != NULL && q->playerid == playerid){ 

	     printf("%.3f\n" , q->playerscore); 
	}
     else
     printf("not found");
}

 int playerMax(Node *head){       //MAX
 	if(head==NULL){
 		return 0;
	 }
	 int max = head->playerscore;
	 Node *r = head;
	 while(r != NULL){
	 	if(r->playerscore > max){
	 		max = r->playerscore;   // xxx the new max is r->playerscore
		 }
		 r =r->next;
	 }
	 return max;
 }


     void destroy (Node *&head , int playerid){    
     	if (head == NULL){
     		printf("Not fount");
     		return;
		 }

		if (head->playerid == playerid){ 
            head = head->next;
            return;
		}


     	Node *q = head , *p = q->next; 
     	while (p !=NULL && p->playerid != playerid){
     		q = p; // xxx q=p (move q one step)
     		p = p->next;

        }

		 if(p == NULL){ 
		 	printf("Not found");
		 	return;
		 }


     	q->next = p->next;
     	delete p;

 }




 float getAvg(Node *head){          //calculate Avg
	if(head==NULL){
		return 0;
	}

	int sum = 0;
	int count =0;
	Node *q = head;
	while(q!=NULL){
		sum += q->playerscore; 
		count++;
		q=q->next;
	}

	return (float)sum/count;
}





 int main(){
 	Node *game = NULL;

 	insert(game,1); // xxx pass by reference the head

    insert(game,2);
 	insert(game,3);
 	insert(game,4);
 	insert(game,5);

    update_score(game,1,100);
    update_score(game,2,200);
    update_score(game,3,300);
    update_score(game,4,400);
    update_score(game,5,500);


    search(game,1);
    search(game,2);
    search(game,3);
    search(game,4);
    search(game,5);

    printf("-------------------------\n");

    sort_ll(game);
    print(game);




   printf("game\n");   
   printf("Max: %d\n", playerMax(game)); 

   printf( "REMOVE PLAYER BY ID\n");
   destroy(game,4);  
   search(game,4);



return 0;


}



















