#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
 
class shopdetails{
   public:
      string title;
      string author;
      string publisher;
      int stock;
      int cost;
      shopdetails(){
      string *title=new string;
      string *author=new string;
      string *publisher=new string;
      int *stock=new int;
      int *cost=new int;
      }
      
      void accept()
      {
         cout<<"\nEnter the name of book author:\t";
         cin>>author;
         cout<<"\nEnter the title of book:\t";
         cin>>title;
         cout<<"\nEnter the cost of the book:\t";
         cin>>cost;
         cout<<"\nEnter the name of publisher:\t";
         cin>>publisher;
         cout<<"\nEnter the stock:\t";
         cin>>stock;
          
      }
      void display() {
        cout <<setw(20)<<left<<author
                <<setw(20)<<left<<title
                <<setw(20)<<left<<publisher
                <<setw(10)<<right<<cost
                <<setw(10)<<right<<stock<<endl;
        
      }
      static void search(int n, int i, shopdetails obj[]){
        int flag=0,s_stock; 
        string s_title;
        string s_author;
        cout << "\nEnter the title of book:\t";
        cin >> s_title;
        cout << "\nEnter the author of book:\t";
        cin >> s_author;
       /* cout << "\nEnter the quantity of book:\t";
        cin >> s_stock;*/
        for (i = 0; i < n; i++) {
            if (obj[i].title== s_title && obj[i].author== s_author /*&& obj[i].stock>=s_stock*/) {
                cout <<setw(20)<<left<<"Author"
                <<setw(20)<<left<<"Title"
                <<setw(20)<<left<<"Publisher"
                <<setw(10)<<right<<"Cost"
                <<setw(10)<<right<<"Stock"<<endl;
                cout<< setfill('-')<<setw(80)<<""<<setfill(' ')<<endl;
                cout <<setw(20)<<left<<obj[i].author
                <<setw(20)<<left<<obj[i].title
                <<setw(20)<<left<<obj[i].publisher
                <<setw(10)<<right<<obj[i].cost
                <<setw(10)<<right<<obj[i].stock<<endl;
                cout << "\nEnter the quantity of book:\t";
                cin >> s_stock;
                if(obj[i].stock>=s_stock)
                {
                   cout<<"\nBooks are available for price: "<<s_stock*obj[i].cost<<".\n";
                   obj[i].stock-=s_stock; 
                }
                else
                {
                  cout << "\nBook is out of the stock.";
                }
                /*cout << "\nBook is available for price: "<<s_stock*obj[i].cost<<".\n"; 
                cout<<"\n________________________________"; 
                obj[i].stock-=s_stock;*/
                flag=1;
            }
            
	}
	if(flag==0){
	    cout << "\nBook is not available.";
	    }
	}

};

int main(){
   shopdetails obj[10];
    int i, n=0, n1,choice;
    do {
        cout << "\n1. Store Data";
        cout << "\n2. Display Data";
        cout << "\n3. Search";
        cout << "\n4. Exit";
        cout <<"\nEnter your choice from above:\t";
        
        cin >> choice;

        switch (choice) {
            case 1:
                 cout << "Enter the number of data you want to enter:\t";
                 cin >> n1;
                 for (i = n; i < n+n1; i++) {
                      cout<<"\n"<<i+1<<".";
                      obj[i].accept();
                       
                    }
                    n+=n1;
                    
                   /* obj[n].accept();
                    n++;*/
                   
                break;
            case 2:
                cout <<setw(20)<<left<<"Author"
                <<setw(20)<<left<<"Title"
                <<setw(20)<<left<<"Publisher"
                <<setw(10)<<right<<"Cost"
                <<setw(10)<<right<<"Stock"<<endl;
                cout<< setfill('-')<<setw(80)<<""<<setfill(' ')<<endl;
                for (i = 0; i < n; i++) {
                    obj[i].display();
                }
                break;
            case 3:
                shopdetails::search(n, i, obj); 
                break;
            
            case 4:
                cout << "\nExiting...";
                break;
            default:
                cout << "\nInvalid choice";
        }
    } while (choice != 4);

    return 0;
}

