#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class book{
string author,title,publisher;
float price;
int stock;

public:

  //constructor

  book(){
    price=0;
    stock=0;
     author="";
     title="";
     publisher="";
  }

  //functions

  void bookEntry(book b);   //add new book
  void bookSearch(); //search using name of author and title of book
  void bookSell(book b);   //to check if number of copies meet the requirement
  //and display and modify the stock
  void bookDisplay(book b); //to display all the data of book available
 void bookDisplay();

  
};

void book::bookSearch(){
  string a,t;
  ifstream file("bookdataa");
 book obj;

  
  cout<<"enter title and author name"<<endl;

    cin>>t;
    cin>>a;
   int c=0;
      while (file.read((char*)&obj, sizeof(obj)))
{
    
            if (obj.title==t && obj.author==a) {
               cout<<"found"<<endl;
                  bookDisplay(obj);
                  c=1;
                  cout<<"do you wish to sell y or n"<<endl;
                  char ans;
                  cin>>ans;
                  if(ans=='y'){
                  

                    bookSell(obj);
                  file.close();
                    break;
                  }
              c=1;
              
                  
                
        }

file.close();
  }
  if(!c)
   cout<<"not found"<<endl; 
}
void book::bookEntry(book obj){
string a,t,p;
float cost;
int st;

cout<<"enter book title"<<endl;
cin>>t;
obj.title=t;

cout<<"enter book author"<<endl;
cin>>a;
obj.author=a;

cout<<"enter book cost"<<endl;
cin>>cost;
obj.price=cost;

cout<<"enter book publication"<<endl;
cin>>p;
obj.publisher=p;

cout<<"enter number of books available"<<endl;
cin>>st;
obj.stock=st;



ofstream file;

file.open("bookdataa",ios::app);
           
  file.write((char*)&obj, sizeof(obj));
 
  bookDisplay(obj);
 file.close();  
}

void book::bookDisplay(book b) {
 cout<<"....................."<<endl;
  cout<<"book title:"<<b.title<<endl;
  cout<<"author name:"<<b.author<<endl;
  cout<<"published by:"<<b.publisher<<endl;
  cout<<"price:"<<b.price<<endl;
  cout<<"Number of copies available:"<<b.stock<<endl;
   cout<<"....................."<<endl;


}
void book::bookDisplay() {
 
  cout<<"book title:"<<title<<endl;
  cout<<"author name:"<<author<<endl;
  cout<<"published by:"<<publisher<<endl;
  cout<<"price:"<<price<<endl;
  cout<<"Number of copies available:"<<stock<<endl;

}

void book:: bookSell(book b){
 
  cout<<"enter number of copies you want"<<endl;
  int count;
  cin>>count;
  try{
    if(count==0){
      throw count;
    }
    else{
      if(count<=b.stock){
          b.stock-=count;
           cout<<"....................."<<endl;

          cout<<"sold"<<endl;
           cout<<"....................."<<endl;

           b.bookDisplay();
    }
      else{
         cout<<count<<" "<<b.stock<<endl;
          cout<<"....................."<<endl;

        cout<<"not enough copies"<<endl;
        
        cout<<"....................."<<endl;

      }
    }
  }
  catch(int b){
    cout<<"enter num of books greater than 0"<<endl;
  }


}


int main(){
cout<<"enter 1 to add book,2 to search book,3 to buy book,4 to exit"<<endl;
 book b[2500];
while(true){
  
  int n;
  cin>>n;
 
  int i=0;
  if(n==1){
    b[i].bookEntry(b[i]);

   book b[i];
  i++;
    

  }
  if(n==2){
    b[i].bookSearch();
  }

  if(n==3){
  
    b[i].bookSell(b[i]);
    b[i].bookDisplay(b[i]);
    
  }

    if(n==4){
    break;
  }
}


 return 0;

}
