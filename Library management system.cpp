//Library management system:
//****************************************************

#include<iostream>
#include<sstream>
using namespace std;

//Note: Eaeh row in the arrays has Interconnected information!!!

class myLibrary{
	public:
		int b_borrowed;
        int user=11;
        int books=20;
        int choice;
        string user_ID;
        string user_name,password,name;
        
        //TO CONVERT 'int' TO 'string'....
        string int_to_string(int user){
	        stringstream ss;
	        ss<<user;
	        string myuser=ss.str();
	        return myuser;
        }
        //Array of books including: book name , author name , status and Category.....
        string Book[20][4]={
	        {"The Power of Now" ,"Eckhart Tolle" , "Available","Self-help"},
	        {"The Four Agreements","Don Miguel Ruiz" , "Borrowed","Self-help"},
	        {"Atomic Habits" , " James Clear","Borrowed" ,"Self-help"},
	        {"Mindset: The New Psychology of Success" ,"Carol S. Dweck" ,"Available" ,"Self-help"},
	        {"A passage to India" ,"E,M.Forster" ,"Available" ,"Novel"},
	        {"Invisible man" ,"Unknown" ,"Borrowed","Novel" },
	        {"Mrs.Dalloway" ,"virginia woolf" ,"Available","Novel" },
	        {"Jane eyre" ,"Charlotte Bronte" ,"Borrowed","Novel" },
	        {"Odd John" ,"Olaf Stapledon" ,"Available","Science fiction" },
	        {"Brave new world" ,"Aldous Huxely" ,"Available","Science fiction" },
	        {"Foundation" ,"Isaac Asimov" ,"Borrowed","Science fiction" },
	        {"Earth Abides" ,"George" ,"Available","Science fiction" },
	        {"The blue zone kitchen" ,"Dan Buehener" ,"Available","Health" },
	        {"The telomer effect" ,"Elissa Epel" ,"Available","Health" },
	        {"How not to die" ,"Michael Greger" ,"Borrowed","Health" },
	        {"Changing my mind" ,"Margret Trudeau" ,"Available","Health" },
	        {"The scarlet Fig" ,"Avram Davidson" ,"Borrowed","Fantasy" },
	        {"The sea of trolls" ,"Nancy Famer" ,"Borrowed","Fantasy" },
	        {"Shrek!" ,"William Steig" ,"Available","Fantasy" },
	        {"The stand" ,"Stephin King" ,"Available","Fantasy" }
        };
        //Metaphor Array including : book name and statuse(borrowed).....
        string Metaphor[8][2]={
	        {"The sea of trolls" ,"Borrowed" },
	        {"The scarlet Fig" ,"Borrowed" },
	        {"How not to die" ,"Borrowed" },
	        {"Foundation" ,"Borrowed" },
	        {"Jane eyre" ,"Borrowed" },
	        {"Invisible man" ,"Borrowed" },
	        {"Atomic Habits" ,"Borrowed" },
	        {"The Four Agreements" ,"Borrowed" }
        };       
};

class Readers: public myLibrary{
	public:
		//Array of Users including: User ID , User name and Password.....(private)
        string Users[11][3]={
	        {"0" ,"Emad", "9898"},//the admin!!!
	        {"1" ,"Ali" ,"2222" },
	        {"2" ,"Ahmad" ,"4562" },
	        {"3" ,"Sameer" ,"6566" },
	        {"4" ,"Alaa" ,"5565" },
	        {"5" ,"Sara" ,"4846" },
	        {"6" ,"Ameer" ,"7895" },
	        {"7" ,"Reem" ,"8956" },
	        {"8" ,"Ameera" ,"4562" },
	        {"9" ,"Kareem" ,"2154" },
	        {"10" ,"Hala" ,"1235" },
        };
 
		
		//TO SIGN UP ON THE SYSTEM....
        void sign_up( string Array[][3]){
	        cout<<"We are happy to have you in our family :) \n please fill the info ....\n";
	        cout<<"Name: ";
	        cin>>user_name;
	        for(int j=0 ; j<user ; j++){
		        cout<<"Password : ";
		        cin>>password;
		        for(int i=0 ; i<user ; i++){
			        if(Array[i][2]==password){
				        cout<<"this password is not available...plz enter another one :)\n";
			        }else{
				        user++;
				        Array[j][0]=int_to_string(j+1);
				        Array[j][1]=user_name;
				        Array[j][2]=password;
			        }
		        }
	        }
	        cout<<"You are one of the family now...we are happy to have you here :):)\n";
        }
        
    //ADD USER TO THE SYSTEM....
    void Add_user(string Array[][3] , int &user){
	    user++;
	    cout<<"Name: ";
	    cin>>user_name;
	    for(int j=0 ; j<user ; j++){
		    cout<<"Password : ";
		    cin>>password;
		    for(int i=0 ; i<user ; i++){
			    if(Array[i][2]==password){
				    cout<<"this password is not available...plz enter another one :)\n";
			    }else{
				    user++;
				    Array[j][0]=int_to_string(j+1);
				    Array[j][1]=user_name;
				    Array[j][2]=password;
				    
			    }
		    }
	    }
	    cout<<"He\She is one of the family :):)\n";
    }     
	
    //DELETE USER...
    void Delete_user(string Array[][3], int& user) {
        cout << "Enter the user ID to delete: ";
        cin >> user_ID;

        bool found = false;
            for (int i = 0; i < user; i++) {
                if (Array[i][0] == user_ID) {
                    found = true;
                    for (int k = i; k < user - 1; k++) {
                        for (int j = 0; j < 3; j++) {
                            Array[k][j] = Array[k + 1][j];
                        }
                    }
                    break;
                }
            }

        if (found) {
            --user; // ????? ??? ????????
            cout << "User has been deleted successfully." << endl;
        } else {
            cout << "User not found." << endl;
        }
    }
    //ADD BOOK....
    void Add_book(string Array[][4] , int &books){
	    books++;
	    cout<<"Enter : the book name , author , status and Category...in the order...\n ";
	    for(int i=0 ; i<4 ; i++){
		    cin>>Array[books][i];
	    }
	    cout<<"Done !!!!"<<endl;
    }
            
    //REPORT....
    void Report(string Array[][4] , int &books){
	    int num_of_borrowed_books=0;
	    for(int j=0 ; j<books ; j++){
		    if(Book[j][2]=="Borrowed"){
			    num_of_borrowed_books++;
		    }
	    }
	    for(int i=0 ; i<books ; i++){
		    cout<<"the book : "<<Array[i][0] <<" is "<<Array[i][2]<<endl;
	    }
	    cout<<"the number of borrowed books is = "<<num_of_borrowed_books<<endl;
	    cout<<"the number of available books is = "<<(books-num_of_borrowed_books)<<endl;
    } 
    
    //BOOKS INFO.....
    void Book_info(string Array[][4] , int &books){
	    for(int i=0 ; i<books ; i++){
		    for(int j=0 ; j<4 ; j++){
			    cout<<Array[i][j]<<" --------> ";
		    }
		    cout<<endl;
	    }
    }
	
    //ADMIN INTERFACE.....
    void Admin(string Users[][3], int user) {
        cout << "Welcome Admin to the system....\nWhich process do you want to do?\n";
        cout << "1) Add User.\n";
        cout << "2) Delete User.\n";
        cout << "3) Add a book.\n";
        cout << "4) Books info.\n";
        cout << "5) Reports.\n";
        cout << "6) Exit.\n";
        cin >> choice;
        switch (choice) {
            case 1:
                Add_user(Users, user);
                break;
            case 2:
                Delete_user(Users, user);
                break;
            case 3:
                Add_book(Book, books);
                break;
            case 4:
                Report(Book, books);
                break;
            case 5:
                Book_info(Book, books);
                break;
            case 6:
                cout << "Thank you for visiting us...take care:):)\n";
                break;
            default:
                cout << "Invalid choice! Please try again.";
        }
    }

    //TO SIGN IN INTO THE SYSTEM....
   void sign_in(string Array[][3]){
    bool loggedIn = false; 
    cout << "We are happy to see you again :)\n Name: ";
    cin >> user_name;
    cout << "Password: ";
    cin >> password;
    if (password == "9898"){
        Admin(Users, user);
        loggedIn = true; 
    }
    for (int i = 0; !loggedIn && i < user; i++){ 
        if ((user_name == Array[i][1]) && (password == Array[i][2])){
            cout << "Welcome to the system ...\n";
            loggedIn = true; 
        }
    }
    if (!loggedIn) { 
        cout << "One of the inputs is wrong:(\nPlease try again ...\n";
        sign_in(Array);
    }
}
		//TO BORROW FROM THE LIBRARY....
        void Borrow(string Metaphor[][2] , string Book[][4]){
	        cout<<"Enter the book name that you want to borrow >> ";
	        cin>>name; 
	        for(int i=0 ; i<books ; i++){
		        if(Book[i][0]==name){
			        if(Book[i][2]=="Borrowed"){
				    cout<<"Not available...choose another book.\n";
				    cin>>name;
			    }else{
				    cout<<"Done:):)\n";
			    }
		        }
	        }
	        b_borrowed++;
	        Metaphor[b_borrowed][0]=name;
	        Metaphor[b_borrowed][1]="Borroed";
        }

    //TO RETURN A BOOK...
    void Return(string Metaphor[][2], string Book[][4]){
        cout<<"enter the book name that you want to return .... ";
        cin>>name;
        int i;
        for(i=0 ; i<books ; i++){
            if(Book[i][0]==name){
                Book[i][2] = "Available";
            }
        }
        for(int j=0 ; j<b_borrowed ; j++){
            if(Metaphor[j][0]==name){
                for(int k=0 ; k<2 ; k++){
                    Metaphor[j][k] = Metaphor[j+1][k];
                }
            }
        }
        --b_borrowed; 
        --i; 
    }

        //TO SEARCH FOR A BOOK....
        void Search(string Book[][4] ){
	        string standard;
	        cout<<"enter the standard to search for a book ....";
	        cin>>standard;
	        for(int i=0 ; i<books ; i++){
		        for(int j=0 ; j<4 ;j++){
			        if(Book[i][j]==standard){
				        cout<<"the book : "<<Book[i][0]<<"is "<<Book[i][2]<<endl;
			        }
		        }
	        }
        }

        //TO SEE THE DETAILS....
        void Show(string Book[][4]){
	        for(int i=0 ; i<books ; i++){
		        cout<<"the book : "<<Book[i][0]<<" is "<<Book[i][2]<<endl;
	        }
        }   
};

class Textbook : public myLibrary{
	private:
		//array of the data including:book name , user name , user ID , borrow date and return date..... (private)
        string Data[20][5]={
	        {"The power of now","Ali","1","23/1","20/2"},
	        {"Atomic habits","Ahmad","2","23/2","28/2"},
	        {"The four agreement","Sara","5","23/1","15/2"},
	        {"A passage to India","Sameer","3","23/3","20/4"},
	        {"Invisible man","Ali","1","5/1","20/1"},
	        {"Mrs.Dalloway","Alaa","4","23/1","12/2"},
	        {"Jane eyre","Ameer","6","23/5","1/7"},
	        {"Invisible man","Reem","7","1/1","20/1"},
	        {"Atomic habits","Ameera","8","6/5","5/6"},
	        {"The power of now","Alaa","4","2/11","20/11"},
	        {"Mrs.Dalloway","Kareem","9","23/1","1/2"},
	        {"The blue zone kithen","Sameer","3","15/8","20/8"},
	        {"The tellomer effect","Kareem","9","1/1","30/1"},
	        {"How not to die","Reem","7","20/10","20/11"},
	        {"Changing my mind","Hala","10","5/5","25/5"},
	        {"The scallet Fig","Ahmad","2","15/3","23/3"},
	        {"The sea of trolls","Ameera","8","3/3","30/3"},
	        {"Shrek!","Sara","5","30/6","15/7"},
	        {"The stand","Alaa","4","20/6","2/7"},
	        {"The power of now","Hala","10","26/5","18/6"}
        };
        
    public:
    	void setData(string Array1[][5]){
    		for(int i=0 ; i<books ; i++){
    			for(int j=0 ; j<5 ; j++){
    				Data[i][j]=Array1[i][j];
				}
			}
		}
		
		string getData(){
			return Data[books][5];
		}
};


int main(){
    Readers myuser1;
    Readers myuser2;
    Readers myuser3;
    Readers myuser4;
    Readers myuser;
    
    myLibrary myitem;

	int choice;
	
	cout<<"Welcome to our library....we are happy to see you here :):)\n If you are a member enter: 1(sign in) \n If you want to join to our family enter : 2(sign up)\n";
	cin>>choice;
	if(choice ==1 ){
		myuser.sign_in(myuser.Users);
	}else{
		myuser.sign_up(myuser.Users);
		myuser.sign_in(myuser.Users);
	}
	cout<<"As a member of the family you can do these things :):):) Once you choose one you will be able to do the choice that you have choosen!!!\n";
	
	cout<<"Tell us what you want to do...\n";
	cout<<"1)Borrow a book. \n";
	cout<<"2)Return a book. \n";
	cout<<"3)Search for a book. \n";
	cout<<"4)Books details(borrowed and available books). \n";
	cout<<"5)Exit. \n";
	cin>>choice;
	switch(choice){
		case 1:
			myuser1.Borrow(myitem.Metaphor , myitem.Book);
			break;
		case 2:
			myuser2.Return(myitem.Metaphor,myitem.Book); 
			break;
		case 3:
			myuser3.Search(myitem.Book); 
			break;
		case 4:
			myuser4.Show(myitem.Book); 
			break;
		case 5:
			cout<<"Thank you for visiting us ...take care:):)\n";
			break;
	}
	

	return 0;
}

