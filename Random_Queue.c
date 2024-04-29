#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct kisi{
    
    int sirano;
    
    struct kisi *next;
    
};

struct kisi *head= NULL;
struct kisi *tail= NULL;


void addend(int sirano){
    
    if(head==NULL){

        struct kisi *new = (struct kisi *)malloc(sizeof(struct kisi));
        
        new->sirano=sirano;
        
        new->next=NULL;
        head=tail=new;
    }
 
    else{
            
        struct kisi *new = (struct kisi *)malloc(sizeof(struct kisi));
       
        new->sirano=sirano;
        new->next=NULL;
            
        tail->next=new;
        tail=new;
    }
    
}

void addfirst(int sirano){
    
    if(head==NULL){

        struct kisi *new = (struct kisi *)malloc(sizeof(struct kisi));
        
        new->sirano=sirano;
        
        new->next=NULL;
        head=tail=new;
    }
 
    else{
            
        struct kisi *new = (struct kisi *)malloc(sizeof(struct kisi));
       
        new->sirano=sirano;
        
        new->next=head;
        head=new;
    }
    
}

void insertNodeAtMiddle(int sirano, int position){
    int j;
    struct kisi *newNode, *temp;

    newNode = (struct kisi*)malloc(sizeof(struct kisi));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->sirano = sirano; 
        newNode->next = NULL;

        temp = head;

        
         
        for(j=2; j<=position-1; j++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {
            
            newNode->next = temp->next; 

            
            temp->next = newNode;

            
        }
        else
        {
            printf(" ");
        }
    }
}

void print(){
        
        struct kisi *index = head;
        
        while(index!=NULL){
            
            printf("  %d  ",index->sirano);
            index=index->next;
        }
    }


int main()
{
   srand(time(0));
   int randomnumber[9];
   int n=0;
   for(int i=0; i<10; i++){
       
    randomnumber[i] = rand() %3 +1;
    int position;
    
    
    if(randomnumber[i]==3){
       
        addfirst(randomnumber[i]);
        
    }
    
    else if(randomnumber[i]==2){
        addend(randomnumber[i]);
        n++;
    }
    
    else if(randomnumber[i]==1){
        if(n>=3){
        n=n-2;
        position=i-n+1;
        insertNodeAtMiddle(randomnumber[i],position);
        }
        else{
        addend(randomnumber[i]);
        n=0;
    }}
    
    
   }
   printf("\ngelen musteri\t\t");
   for(int j=0; j<10; j++){
       printf("  %d  ", randomnumber[j]);
   }
   printf("\n\n");
   printf("kuyruktaki siralamasi   ");
   print();
   
   
   
   
    return 0;
}