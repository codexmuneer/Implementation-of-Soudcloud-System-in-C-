#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

//Music Metadata DataBase (A doubly linked list)
class MMD
{
	public:
		//data members
		int mbid;
		AD* album;

		//connections
		MMD* next;
		MMD* previous;
};

//Author Metadata DataBase (A circular linked list)
class AMD
{
	public:
		//data members
		int aid;
		AD* albums;
		ADP* adp;

		//connections
		AMD* next;
};

//Tracks (A singly linked list)
class Tracks
{
	public:
		//data members
		int trackNumber;
		MMD* trackRef;

		//connections
		Tracks* next;
};

//Album DataBase (A circular linked list)
class AD
{
	public:
		//data members
		int abid;
		AMD* author;
		Tracks* tracks;
		ADP* adp;

		//connections
		AD* next;
};

//Albums (A singly linked list)
class Albums
{
	public:
		//data members
		int year;
		AD* albumRef;

		//connections
		Albums* next;
};

//Author Discography Playlist (A circular linked list)
class ADP
{
	public:
		//data members
		int did;
		AMD* author;
		Albums* albums;

		//connections
		ADP* next;
};

MMD* Create_MMD(string path)
{
	MMD * head;
	MMD* newNode;
	MMD *temp;
	head=NULL;
	temp = head;
	string str;

	ifstream fin ("Music.csv"); //name of the file it is supposed to read
	if (fin.is_open())
	{
		while ( getline (fin, str) )
		{
					///cout<<str<<endl;
			newNode = new MMD();
			fin >> newNode->mbid;
			getline (fin, str, ',');
			fin >> newNode->album->tracks ;
			getline (fin, str, ',');
			fin >> album->author;
			getline (fin, str, ',');
			fin >> album->tracks->trackNumber;
			newNode->next = NULL;
			newNode->previous = NULL;
			if (head == NULL) 
		 	{
				head = temp = newNode;
			}
			else 
			{
		
				temp->next = newNode;
				newNode->previous = temp;
				temp = newNode;
			}				
		}
			}
			fin.close();
	
	return head;

}

AMD* Create_AMD(string path)
	{
		
	    AMD* head;
		AMD* newNode;
		AMD* temp;
	    head=NULL;
		temp = head;
	    string str;

		ifstream fin ("Authors.csv"); //name of the file it is supposed to read
		if (fin.is_open())
		{
			while ( getline (fin, str) )
			{
				//cout<<str<<endl;
				newNode = new AMD();
				
				fin >> newNode->aid;
				newNode->next = NULL;
				

					if (head == NULL) {

						head = temp = newNode;
					}
					else {

						temp->next = newNode;
						temp = newNode;
					}
					temp->next=head;
			}
		
		}
		return head;
		}

AD* Create_AD(string path)
	{
		
	    AD* head;
		AD* newNode;
		AD* temp;
	    head=NULL;
		temp = head;
	    string str;

		ifstream fin ("Albums.csv"); //name of the file it is supposed to read
		if (fin.is_open())
		{
			while ( getline (fin, str) )
			{
				//cout<<str<<endl;
				newNode = new AD();
				
				fin >> newNode->aid;
				newNode->next = NULL;
				

					if (head == NULL) {

						head = temp = newNode;
					}
					else {

						temp->next = newNode;
						temp = newNode;
					}
					temp->next=head;
			}
		
		}
		return head;
		}

ADP* Create_ADP(string path)
	{
		
	    ADP* head;
		ADP* newNode;
		ADP* temp;
	    head=NULL;
		temp = head;
	    string str;

		ifstream fin ("Discography.csv"); //name of the file it is supposed to read
		if (fin.is_open())
		{
			while ( getline (fin, str) )
			{
				//cout<<str<<endl;
				newNode = new ADP();
				
				fin >> newNode->aid;
				newNode->next = NULL;
				

					if (head == NULL) {

						head = temp = newNode;
					}
					else {

						temp->next = newNode;
						temp = newNode;
					}
					temp->next=head;
			}
		
		}
		return head;
		}























//Functions Prototypes
// AMD* Create_AMD(string path); //should return head of the AMD linkedlist
// AD* Create_AD(string path); //should return head of the AD linkedlist
// ADP* Create_ADP(string path); //should return head of the ADP linkedlist
// MMD* Search_Music(int MBID); //should return pointer to track having mbid = MBID
// AMD* Search_Author(int AID); //should return pointer to author having aid = AID
// AD* Search_Album(int ABID); //should return pointer to album having abid = ABID
// ADP* Search_Discography(int DID); //should return pointer to discography having did = DID
// Tracks* Search_Music_By_Album(int ABID); //should return singly linklist of "Tracks" in given album
// Albums* Search_Music_By_Author(int DID); //should return singly linklist of "Albums" in given discography

