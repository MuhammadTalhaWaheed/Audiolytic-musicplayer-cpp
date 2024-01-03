#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<string>
#include<windows.h>
#include <list>
using namespace std;
class node{
	public:
    char song[100];
    node *next;
    node *prev;
 
	node(){   
    	next = NULL;
    	prev = NULL;
	}

}*top,*temp,*top1;

class MusicPlayer{
	public:
		void tofile(string a){
    		fstream f1;
    		f1.open("playlist.txt",ios::out|ios::app);
    		f1<<a<<endl;
    		f1.close();
		}

void add_node(node *first)
    {
	//system("COLOR 40");
	char a[100];
	while(first->next!=NULL)
    {
        first=first->next;
    }
    first->next= new node();
    first->prev=first;
    first=first->next;
    cout<<"\n\a\a\a\aEnter Song name-  ";
    cin>>a;
    
    strcpy(first->song,a);
    tofile(a);
    first->next=NULL;
}
	void add_node_file(node *first,string a){
    	node *n=new node;
		if(first==NULL){
            first=n;
            first->next=NULL;
        }
        else{
            first=n;
            n->next=first;
        }
        strcpy(first->song,a.c_str());
        
		
		while(first->next!=NULL){
        	first=first->next;
    	}

    first->next=new node();

    first->prev=first;

    first=first->next;

    strcpy(first->song,a.c_str());
	
    first->next=NULL;

}
void delete_file(char a[])
{

    fstream f1,f2;

    string line;

    int x=0;

    f1.open("playlist.txt",ios::in|ios::out);

    f2.open("temp.txt",ios::in|ios::out);

    while(!f1.eof())

    {

        getline(f1,line);

        if(strcmp(a,line.c_str())!=0)

        f2<<line<<endl;

        else if (strcmp(a,line.c_str())==0)

        x=1;

    }

    f1.close();

    f2.close();

    //remove("playlist.txt");

    //rename("temp.txt","playlist.txt");

    if(x==0)

        {

        cout << "There is no song with name you entered." << endl;

        }

    else

        {

        cout << "Song has been deleted." << endl;

        }

    }

void del_node(node *first)

{

    while((first->next)->next!=NULL)

    {

        first=first->next;

    }

    node *temp;

    temp=(first->next)->next;

    first->next=NULL;

    delete temp;

   cout<<"Deleted"<<endl;

}



void printlist(node *first)

{

    cout<<"\nPlaylist Name- ";
	int i[100];
	//for(int j=0;j<100;j++)
	//i[j]=static_cast<int> (first->song);
    while(first!=NULL)

    {
    	//for(int j=0;j<100;j++)
		//i= stoi (first->song);
//		i[0]=int(first->song);
//		if(i[0]>=97&&i[0]<=122)
        cout<<first->song<<endl;

        first=first->next;

    }

    //cout<<first->song<<endl;

}

void count_nodes(node *first)

{

    int i=0;

    while (first->next!=NULL)

    {

        first=first->next;

        i++;

    }

    i++;

    cout<<"\nTotal songs-  "<<i-1<<endl;

}



node  *del_pos(node *pointer, int pos)

{

	node *n1,*prev1,*temp;

	prev1 = new node();

    temp= new node();

    int i=0;

		if(pos==1)

           {

                temp=pointer;

                delete_file(temp->song);

                pointer=pointer->next;

                pointer->prev = NULL;

                delete temp;

                cout<<"\nThe list is updated\nUse the display function to check\n";

                return pointer;

           }

           while(i<pos-1)

           {

               prev1=pointer;

               pointer=pointer->next;

               i++; 

            }

            if(pointer->next==NULL)

            {

            temp=pointer;

            delete_file(temp->song);

            prev1->next->prev=NULL;

            prev1->next=NULL;

            delete temp;

            cout<<"\nThe list is updated\nUse the display function to check\n";

          }

            else

            {

            temp=pointer;

            delete_file(temp->song);

            prev1->next=temp->next;

            temp->next->prev=prev1;

            delete temp;

            cout<<"\nThe list is updated\nUse the display function to check\n";

            }

}

void search1(node *first)

{

    char song[100];

    cout<<"\n\a\a\a\aEnter song To be Searched- ";

    cin>>song;

    int flag=0;

    while(first!=NULL)

    {

        if(strcmp(first->song,song)==0)

        {

            cout<<"\n\a\a\a\a#Song Found"<<endl;

            flag++;

            return;

        }

        else

        {

            first=first->next;

        }

    }

    if(flag==0)

    {

        cout<<"\n\a\a\a\a#Song Not found"<<endl;

    }

}

void create()

{

    top = NULL;

}

void push(char data[])

{

    if (top == NULL)

    {

        top = new node();

        top->next = NULL;

        strcpy(top->song,data);

    }

    else if (strcmp(top->song,data)!=0)

    {

        temp =new node();

        temp->next = top;

        strcpy(temp->song,data);

        top = temp;

    }

}

void display()

{

    top1 = top;

    if (top1 == NULL)

    {

        cout<<"\n\a\a\a\a=>NO recently played tracks.\n";

        return;

    }

    cout<<"\n\a\a\a\a#Recently played tracks-\n";

    while (top1 != NULL)

    {
		if(top1!=NULL)
		{
			cout<<top1->song;

        cout<<"\n";

		}
        
        top1 = top1->next;

    }

 }



void play(node *first)

{

    char song[100];

    printlist(first);

    cout<<"\n\a\a\a\aChoose song you wish to play- ";

    cin>>song;

    int flag=0;
    while(first!=NULL)

    {

        if(strcmp(first->song,song)==0)

        {

            cout<<"\n\a\a\a\a=>Now Playing......"<<song<<endl;

            flag++;

            push (song);

            break;

        }

        else

        {

            first=first->next;

        }

    }

    if(flag==0)

    {

        cout<<"\n\a\a\a\a#Song Not found"<<endl;

    }

}

void playlist()
{
   int song;

   	cout<<"\nPLAYLIST: \n1. Cantina Band\n2. Star Wars\n3. Documentary\n";

    cout<<"\n\a\a\a\aChoose song you wish to play- ";

    cin>>song;

    int flag=0;
	if(song==1)
	{
		PlaySound(TEXT("CantinaBand3.wav"),NULL, SND_SYNC);	
		flag++;
	}
	else if(song==3)
	{
		PlaySound(TEXT("gettysburg10.wav"),NULL, SND_SYNC);	
		flag++;
	}
	else if(song==2)
	{
		PlaySound(TEXT("StarWars3"),NULL, SND_SYNC);	
		flag++;
	}
    if(flag==0)
    {
        cout<<"\n\a\a\a\a#Song Not found"<<endl;
    }
}

void recent()

{

display();

}
void topelement()
{

    top1=top;

    if(top1==NULL)

    {

        cout<<"\n\a\a\a\a#NO last played tracks.\n";

        return;

    }

    cout<<"\n=>Last Played Song - "<<top->song<<endl;

}
void sort( node *&pointer)

{
 node *a = NULL;

 node *b = NULL;

 node *c = NULL;

 node *e = NULL;

 node *tmp = NULL;

while(e != pointer->next)

{

    c = a = pointer;

    b = a->next;

    while(a != e)

        {

            if(strcmp(a->song,a->song))

            {

                if(a == pointer)

                {

                    tmp = b -> next;

                    b->next = a;

                    a->next = tmp;

                    pointer = b;

                    c = b;

                }

            else

            {

                tmp = b->next;

                b->next = a;

                a->next = tmp;

                c->next = b;

                c = b;

            }

        }

        else

        {

            c = a;

            a = a->next;

        }

        b = a->next;

        if(b == e)

            e = a;

        }

    }

}

void del_search(node *start){
	char song[100];
    printlist(start);
    cout<<"\n\a\a\a\aChoose song you wish to delete- ";
    cin>>song;
    int flag=0;
    node *temp1=start;
    while(temp1!=NULL){
        if(strcmp(temp1->song,song)==0){
            cout<<"\n\a\a\a\a#Song Found"<<endl;
//            node *temp;
//            temp= new node();
//            temp=start;
            delete_file(temp1->song);
            if(start==temp1){
            	start=start->next;
			}
			else{
				node *n=temp1->next;
				node *p=temp1->prev;
				if(temp1->next==NULL){
					temp1->prev->next=NULL;
				}
				else{
					p->next=n;
					n->prev=p;
				}
//            	temp1->prev->next=temp1->next;
//            	temp1->next->prev=temp1->prev;
            }
            for(int i=0; i<100; i++)
            {
            	temp1->song[i]=' ';
			}
			temp1= NULL;
            delete temp1;
            
            flag++;
			printlist(start);
        	return;
        }
        else{
            temp1=temp1->next;
        }
    }
    if(flag==0){
        cout<<"\n\a\a\a\a#Song Not found"<<endl;
    }
    
}

void deletemenu(node *start)
{

    int c;

    cout<<"Which type of delete do you want?\n1.By Search\n2.By Position"<<endl;

    cin>>c;

    switch(c)

    {

    case 1:del_search(start);

    break;

    case 2:int pos;

            cout<<"\nEnter the pos of the song : ";

            cin>>pos;

            del_pos(start,pos-1);

    break;

    }

}
};
int main(){
    int choice,loc;
    MusicPlayer m;
    string song;
    node *start,*hold;
    start=new node();
    cout<<"\t\t\t\a\a\a\a**WELCOME TO AUDIOLYTIC**"<<endl;
    cout<<"\n\n\a\a\a\aEnter your playlist name-  ";
    cin.getline(start->song,100);
    start->next=NULL;
    hold=start;
    m.create();
    do{
        cout<<"\n1.Add New Song\n2.Delete Song\n3.Display Entered Playlist\n4.Total Songs\n5.End the Music File\n6.Play Song\n7.Recently Played List\n8.Last Played\n9.Search Song\n10. Sorted playlist\n11. Builtin Playlist\n12. Exit"<<endl;
        cout<<("\n\a\a\a\aEnter your choice- ");
        cin>>choice;
		if(choice>0 && choice<=12){
		switch(choice)
        {
            case 1:m.add_node(start);

            break;

            case 2:m.del_search(start);

            break;

            case 3:m.printlist(start);

            break;

            case 4:m.count_nodes(hold);

            break;

            case 5:cout<<"Stopped the Music!";
            
            case 6:m.play(start);

            break;

            case 7:m.recent();

            break;

            case 8:m.topelement();

            break;
			case 9:m.search1(start);

            break;

            case 10:m.sort(start->next);

            m.printlist(start);

            break;

            case 11:
					m.playlist();

            break;
            case 12:exit(0);

            break;

        }
		}

    }while(choice!=12);

}
