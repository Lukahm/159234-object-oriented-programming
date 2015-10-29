#include <iostream>

using namespace std;

class Media{
	private:
		int id;
	   string title;
	   int year;
	public:
		Media(int a = 0, string n = " ", int b = 0): id(a), title(n), year(b){}
		virtual ~Media(){}
		void changeID(int newID){
			id = newID;
		}
		virtual void print(){
			cout <<"ID " << id << " Title " << title << " ("<< year << ") "; 
		}
};
			
class DVD: public Media{
	private:
		string director;
	public:
		DVD(int a = 0, string n = " ", int b = 0, string m = " "): Media(a, n, b){
			director = m;
      }
		virtual ~DVD(){}
		virtual void print(){
			cout << "DVD: ";
			Media::print();
			if(director == " "){
				director = "unknown";
			}
			cout<< "Directed by " << director << endl;
			
		}
};
		
class Book: public Media{
	private:
		string author;
	   int numPages;
	public:
		Book(int a = 0, string n = " ", int b = 0, string m = " ", int c = 0): Media(a, n, b){
			author = m;
			numPages = c;
		}
		virtual ~Book(){}
		virtual void print(){
			cout << "Book: ";
			Media::print();
			if(author == " "){
				author = "unknown";
			}
			cout<< "By " << author << ", " << numPages << " pages" << endl;
		}
};

class Journal: public Media{
	private:
		int volume;
	   int number;
	public:
		Journal(int a = 0, string n = " ", int b = 0, int c = 0, int d = 0): Media(a, n, b){
			volume = c;
			number = d;
		}
		virtual ~Journal(){}
		virtual void print(){
			cout << "Journal: ";
			Media::print();
			cout << "Volume: " << volume << ", Number: " << number << endl;
		}
};


int main() {
   displayInfo();
   Media *ptr[10];
   ptr[0] = new DVD(352, "Remember The Alamo", 1945, "George Smith");
   ptr[1] = new DVD(831, "High School Blues", 1984);
   ptr[2] = new DVD(194, "Going For The Touchdown", 1984, "Frank Madden");
   ptr[3] = new DVD(576, "Martian Hairdresser", 1992, "Debbie Gold");
   ptr[4] = new Book(608,"How to Make Money", 1987, "Phil Barton", 324);
   ptr[5] = new Book(442,"Garden Projects At Home", 1998, "Mary Freeman", 164);
   ptr[6] = new Book(185,"The Haunted House Mystery", 1996, "Bert Morgan", 53);
   ptr[7] = new Journal(294, "ACM", 2009, 6, 8);
   ptr[8] = new Journal(521, "J of Logic", 2008, 23, 14);
   ptr[9] = new Journal(630, "J of AI", 2009, 35, 11);
   cout << "Printing 10 items..." << endl << endl;
   for (int i = 0; i < 10; ++i) {
      ptr[i]->print();
   }
   ptr[3]->changeID(707);
   ptr[5]->changeID(808);
   ptr[7]->changeID(909);
   cout << endl << "Printing again..." << endl << endl;
   ptr[3]->print();
   ptr[5]->print();
   ptr[7]->print();
}

