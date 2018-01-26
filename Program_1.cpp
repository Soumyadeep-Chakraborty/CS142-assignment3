//program to make a doubly linked list
#include <iostream>
using namespace std;
//declaring node as a datatype using classes
class node
{
public:
int data;
node *next;
node *prev;

node() {
//constructor to initialize the components of a node (not necessary)
    data = 0;
    next = nullptr;
    prev = nullptr;
}
};
//declaring linked_list as a datatype using classes
class linked_list
{
public:
node *head, *tail;
//using class constructor to initialize linked lists
linked_list() 

{
head = NULL;
tail = NULL;
}
//declaring the functions in the linked list
void insert(int data);
void display();
int countItems();
void Delete();
void insertAt(int p,int e);
void deleteAt(int p);
};
/*definition of each function
function to insert node*/
void linked_list::insert (int data){//inserting nodes
node *tmp = new node;
tmp->data = data;
tmp->next = NULL;
tmp->prev = NULL;
if(head == NULL)
{
head = tmp;
tail = tmp;
}
else
{
tail->next = tmp;
tmp->prev = tail; //making the previous pointer of new node point to the tail node
tail = tail->next;
}
cout << "Node With Data " << data << " Successfully Added." << endl;
}
//function to display data
void linked_list::display (void){
    node *tmp = head; 
    while(tmp !=NULL){ 
        cout<<(tmp->data)<<" -> "; 
        tmp = tmp->next; //traversing linked list
         } 
         cout<<"NULL\n";
          }
//function to count the number of node in the linked list
int linked_list::countItems (void){
    node *tmp = head;
    int c=0;
    while(tmp !=NULL){
        tmp = tmp->next; //traversing linked list
        c++;
    }
    return c;
}
//function to delete elements from the linked list
void linked_list::Delete () {
    int d = linked_list::countItems();
    if (d == 1)
        head = NULL;
    else if (d == 2)
        head->next=NULL;
    else if (d == 0) // checking if list exists
        cout << "No list exists";
    else {
        node *i = head;
        for ( ; i->next->next != NULL ; i = i->next); //traversing linked list

        i->next = nullptr; //making node i tail
        tail = i;
    }
    cout<<"Last Node Removed\n";
}
//function to insert elements at a particular position in the linked list
void linked_list::insertAt(int p,int e){
    node *i = head, *tmp = new node;
    tmp->data = e;

    if(p == 0 ||p > linked_list::countItems()){
        cout<<"Not Possible\n";//checking incosistencies
        return;
    }

    int c = 1;
    for ( ; i ; i = i->next, c++)
        if (c == p-1)//traversing list
            break;

    tmp->next = i->next;
    tmp->prev = i;
    i->next = tmp;//linking previous node to present and present to next node
    cout<<"node of data"<<e<<"added at"<<p<<endl;  
}
//function to delete elements at a particular position in the linked list
void linked_list::deleteAt(int p){
    node *tmp =head;
    if(p == 0 ||p > linked_list::countItems()){
        cout<<"Not Possible\n"; //checking for inconsistencies
        return;
    }
    for(int c=1;c<(p-1);c++){
        tmp=tmp->next; //moving through list
        }
    tmp->next=tmp->next->next;
    tmp->next->prev=tmp;//linking previous node to next and deleting present
    cout<<"Node removed at "<<p<<"\n";
}

int main(){
    int a=0;
    linked_list ll1;
    cout<<"Linked list has no nodes\n";
    cout<<"in infinite loop\n";
    while(true){ //user interface
        cout<<"Please make a choice : \n"<<" insert: 1 \n delete: 2 \n count items: 3\n insert at: 4\n delete at: 5\n display: 6\n exit: 7\n";
        cin>>a;
        if(a==1){
            int b;
            cout<<"Enter Data : ";
            cin>>b;
            ll1.insert(b);
        }
        else if(a==2){
            ll1.Delete();
        }
        else if(a==3){
            cout <<"Total number of items ="<< ll1.countItems() << endl;
        }
        else if(a==4){
            int c,b;
            cout<<"Enter Position : ";
            cin>>c;
            cout<<"Enter Data : ";
            cin>>b;
            ll1.insertAt(c,b);
        }
        else if(a==5){
            int c;
            cout<<"Enter Position : ";
            cin>>c;
            ll1.deleteAt(c);
        }
        else if(a==6){
            ll1.display();
        }
        else if(a==7){
            return 0;
        }
    }
}


