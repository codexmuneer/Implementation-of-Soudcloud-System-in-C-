#include <iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

struct Music {
	string song;
	string writer;
	float length;

};

struct ald {
	int abid;
	string albumName;
	int AID;
	string publisher;
	int numberofTracks;

};

//Music Metadata DataBase (A doubly linked list)
class MMD
{
public:

	MMD() {
		next = NULL;
		previous = NULL;
	}
	//data members
	int mbid;
	Music music;
	ald* album;

	//connections
	MMD* next;
	MMD* previous;
};

//Author Metadata DataBase (A circular linked list)
class AMD
{
public:
	AMD() {
		next = NULL;
	}
	//data members
	int aid;
	//AD* albums;
	//ADP* adp;

	string Name;
	string Band;
	string Gender;
	int DateOfBirth;
	int startDate;
	string Genre;

	//connections
	AMD* next;
};

//Tracks (A singly linked list)
class Tracks
{
public:
	Tracks() {
		trackRef = new MMD;
	}
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
	AD() {
		author = new AMD;
		tracks = new Tracks;
	}

	//data members
	int abid;
	string albumName;
	string publisher;
	float totalDuration;
	int numOFtracks;
	AMD* author;
	Tracks* tracks;
	//ADP* adp;


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

//Functions Prototypes
MMD* Create_MMD(string path); //should return head of the MMD linkedlist
AMD* Create_AMD(string path); //should return head of the AMD linkedlist
AD* Create_AD(string path); //should return head of the AD linkedlist
ADP* Create_ADP(string path); //should return head of the ADP linkedlist
//MMD* Search_Music(int MBID); //should return pointer to track having mbid = MBID
//AMD* Search_Author(int AID); //should return pointer to author having aid = AID
//AD* Search_Album(int ABID); //should return pointer to album having abid = ABID
//ADP* Search_Discography(int DID); //should return pointer to discography having did = DID
//Tracks* Search_Music_By_Album(int ABID); //should return singly linklist of "Tracks" in given album
//Albums* Search_Music_By_Author(int DID); //should return singly linklist of "Albums" in given discography


MMD* Create_MMD(string path) {
	MMD* head;  // making head 
	MMD* temp;
	MMD* prev;
	fstream file;  // file name 
	int counter = 4;
	file.open(path, ios::in);

	head = new MMD;  // making a node 
	temp = head;    // pointing 
	string line;
	string second;
	getline(file, line, ',');
	getline(file, line, ',');
	getline(file, line, ',');
	getline(file, line); // getting rid of the headers
	line = "";
	while (file.good())
	{
		counter++;
		if (counter % 4 == 1)
		{
			getline(file, line, ',');
			temp->mbid = (atoi(line.c_str()));

		}
		if (counter % 4 == 2)
		{
			getline(file, line, ',');
			temp->music.song = line;
		}
		if (counter % 4 == 3)
		{
			getline(file, line, ',');
			temp->music.writer = line;
		}
		if (counter % 4 == 0)
		{
			getline(file, line);
			temp->music.length = (atof(line.c_str()));
			prev = temp;
			temp = temp->next;
			temp = NULL;
			temp = new MMD; // making new node
			temp->previous = prev;
			prev->next = temp; // setting links	
		}
		line = "";
	}
	file.close();

	return head;


}
MMD* Search_Music(int MBID)
{
	MMD* head;
	head = Create_MMD("../Music.csv");

	MMD* temp;
	temp = head;
	while (temp != NULL)
	{
		if (temp->mbid == MBID)
		{
			return temp;
		}
		temp = temp->next;
	}


	return NULL;
}


AMD* Create_AMD(string path) // 
{
	AMD* head;
	AMD* temp;
	AMD* prev;



	fstream file_amd;

	int counter = 7;
	file_amd.open(path, ios::in);

	head = new AMD;

	temp = head;
	string line;
	string second;
	getline(file_amd, line, ',');
	getline(file_amd, line, ',');
	getline(file_amd, line, ',');
	getline(file_amd, line, ',');
	getline(file_amd, line, ',');
	getline(file_amd, line, ',');
	getline(file_amd, line);
	line = "";


	while (file_amd.good())
	{
		counter++;
		if (counter % 7 == 1)
		{
			getline(file_amd, line, ',');
			temp->aid = (atoi(line.c_str()));
		}
		if (counter % 7 == 2)
		{
			getline(file_amd, line, ',');
			temp->Name = line;
		}
		if (counter % 7 == 3)
		{
			getline(file_amd, line, ',');
			temp->Band = (line);
		}
		if (counter % 7 == 4)
		{
			getline(file_amd, line, ',');
			temp->Gender = (line);
		}
		if (counter % 7 == 5)
		{
			getline(file_amd, line, ',');
			temp->DateOfBirth = (atoi(line.c_str()));
		}
		if (counter % 7 == 6)
		{
			getline(file_amd, line, ',');
			temp->startDate = (atoi(line.c_str()));
		}
		if (counter % 7 == 0)
		{
			getline(file_amd, line);
			temp->Genre = (line);
			prev = temp;
			temp->next = new AMD;  // making new node 
			temp = temp->next;   //moving to next !!!!!!!
		}
		line = "";
	}
	prev->next = head;
	file_amd.close();
	return head;
}
AMD* Search_Author(int AID)
{
	AMD* head;
	head = Create_AMD("../Authors.csv");

	AMD* temp;
	temp = head;
	while (temp != NULL)
	{
		if (temp->aid == AID)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;

}

AD* Create_AD(string path)// circular link list
{
	AD* head;
	AD* temp;
	AD* prev;

	Tracks* trackHead = new Tracks;
	Tracks* prevTrack;
	Tracks* tempTrack = new Tracks;

	fstream file_ad;

	int counter = 8, prevAbid = 1, prevAid = 1, colstarter = 1;
	file_ad.open(path, ios::in);

	head = new AD;
	temp = head;
	string line;
	getline(file_ad, line, ',');
	getline(file_ad, line, ',');
	getline(file_ad, line, ',');
	getline(file_ad, line, ',');
	getline(file_ad, line, ',');
	getline(file_ad, line, ',');
	getline(file_ad, line, ',');
	getline(file_ad, line);
	line = "";
	bool newAlbum = true;
	while (file_ad.good())
	{
		counter++;
		if (counter % 8 == 1)
		{
			getline(file_ad, line, ',');
			if (atoi(line.c_str()) != prevAbid && atoi(line.c_str()) != 0) {
				prev = temp;
				temp->next = (new AD);  // making new node 
				temp = temp->next;
				prev->tracks = trackHead;

				prev->author->next = temp->author;
				prevAbid = atoi(line.c_str());
				newAlbum = true;
			}
			else {
				colstarter = 1;
			}
			temp->abid = (atoi(line.c_str()));
		}
		if (newAlbum) {
			colstarter++;
		}
		if (counter % 8 == 2)
		{
			getline(file_ad, line, ',');
			temp->albumName = (line);
		}
		if (counter % 8 == 3)
		{
			getline(file_ad, line, ',');
			if (atoi(line.c_str()) != prevAid && atoi(line.c_str()) != 0) {
				temp->author->next = (new AMD);  // making new node 
				temp->author = temp->author->next;
				prevAid = atoi(line.c_str());
			}
			temp->author = (Search_Author(atoi(line.c_str())));
		}
		if (counter % 8 == 4)
		{
			getline(file_ad, line, ',');
			temp->publisher = (line);
		}
		if (counter % 8 == 5)
		{
			getline(file_ad, line, ',');
			temp->numOFtracks = (atoi(line.c_str()));
		}
		if (counter % 8 == 6)
		{
			getline(file_ad, line, ',');
			temp->totalDuration = (atof(line.c_str()));
		}
		if (counter % 8 == 7)
		{
			getline(file_ad, line, ',');
			temp->tracks->trackNumber = (atoi(line.c_str()));
		}
		if (colstarter == 8) {
			newAlbum = true;
		}
		if (counter % 8 == 0)
		{
			getline(file_ad, line);
			if (newAlbum) {
				tempTrack = temp->tracks;
				trackHead = temp->tracks;
				newAlbum = false;
			}
			temp->tracks->trackRef = (Search_Music(atoi(line.c_str())));
			//tempTrack->trackRef = (Search_Music(atoi(line.c_str())));
			temp->tracks->next = new Tracks;
			//tempTrack->next = new Tracks;
			prevTrack = temp->tracks;
			//prevTrack = tempTrack;
			temp->tracks = temp->tracks->next;

		}
		line = "";
	}
	file_ad.close();
	temp->next = (head);

	AD* check = head;
	check = check;
	return head;
}




ADP* Create_ADP(string path)
{
	ADP* head;
	ADP* temp;
	ADP* prev;




	int  prevAbid = 1, prevAid = 1, colstarter = 1;
	int num;
	fstream file_adp;
	int counter = 4;
	file_adp.open(path, ios::in);


	head = new ADP;
	temp = head;

	string line;

	getline(file_adp, line, ',');
	getline(file_adp, line, ',');
	getline(file_adp, line, ',');
	getline(file_adp, line);
	line = "";
	bool newAlbum = true;
	while (file_adp.good())
	{

		counter++;
		if (counter % 4 == 1)
		{
			getline(file_adp, line, ',');
			temp->did = (atoi(line.c_str()));

		}

		if (counter % 4 == 2)
		{
			getline(file_adp, line, ',');
			temp->author->aid = (atoi(line.c_str()));
		}

		if (counter % 4 == 3)
		{
			getline(file_adp, line, ',');
			temp->albums->albumRef->abid = (atoi(line.c_str()));
		}

		if (counter % 4 == 0)
		{
			getline(file_adp, line, ',');
			temp->albums->year = (atoi(line.c_str()));

			temp->next = (new ADP);  // making new node 
			temp = temp->next;
		}
		line = "";
	}
	file_adp.close();
	temp->next = (head);

	return head;
}







AD* Search_Album(int ABID)//should return pointer to album having abid = ABID
{
	AD* head;
	head = Create_AD("../Albums.csv");

	AD* temp;
	temp = head;
	while (temp != head)
	{
		if (temp->abid == ABID)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
