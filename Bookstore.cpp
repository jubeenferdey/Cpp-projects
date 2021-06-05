#include<bits/stdc++.h>
using namespace std;

class Book{
    char *title, *author, *publisher;
    float *price;
    int *stock;

    public:
    Book(){
        author = new char[30];
        title = new char[30];
        publisher = new char [50];
        price = new float;
        stock = new int;
    }

    // Function Declaration // 

    void setData();
    void displayData();
    void editData();    
    int search(char[], char[]);
    void buyBook();
};


void Book::setData(){
    cin.ignore();
    cout<<"Enter Title Name: "; cin.getline(title,30);
    cout<<"Enter Author Name: "; cin.getline(author, 30);
    cout<<"Enter the Publication: "; cin.getline(publisher, 50);
    cout<<"Enter the Price: "; cin>>*price;
    cout<<"Enter the Stock Quanitity: "; cin>>*stock;

    cout<<"\n \t Book Added Successfully."<<endl;
    cout<<" \n Press Any KEY to Continue..."<<flush;
    cin.ignore();
    cin.get();
    return;
}

void Book::editData(){
    cin.ignore();
    cout<<"Enter Title Name: "; cin.getline(title,30);
    cout<<"Enter Author Name: "; cin.getline(author, 30);
    cout<<"Enter the Publication: "; cin.getline(publisher, 50);
    cout<<"Enter the Price: "; cin>>*price;
    cout<<"Enter the Stock Quanitity: "; cin>>*stock;

    cout<<" Details have been edited for the Book. "<<endl;
    cout<<"\n Press Any KEY to Continue..."<<flush;
    cin.ignore();
    cin.get();
    return;
}

void Book::displayData(){
    cout<<"Title: "<<title<<endl;
    cout<<"Author: "<<author<<endl;
    cout<<"Publication: "<<publisher<<endl;
    cout<<"Price: "<<*price<<endl;
    cout<<"Stock: "<<*stock<<endl;

    cout<<"\n Press Any KEY to Continue..."<<flush;
    cin.ignore();
    cin.get();
    return;
}

int Book::search(char title[20], char author[20]){
    if(strcmp(title, this->title)==0 && strcmp(author, this->author) ==0  )
        return 1;
    else    
        return 0;
}

void Book::buyBook(){
    int count;

    cout<<"Enter the Number of Books to buy: ";
    cin>>count;

    if(count<=*stock){
        *stock = *stock - count;
        cout<<"Books Bought Successfully!! ";
        cout<<"Amount: Rs. "<<(*price)*count;
    }
    else{
        cout<<"Required Copies are not available in the stock!";
    }

    cout<<"\n \n \n Press Any KEY to Continue..."<<flush;
    cin.ignore();
    cin.get();
    return;

}

int main(){
    Book *book[20];
    int count = 0, choice, it;
    char title[20], author[20];
    
    while(true){
        system("cls");
        cout<<"\n \n Welcome to the Book Store Management System!"
            << "\n ------------------------------------------------"
            << "\n1. Add a New Book "
            << "\n2. Buy a Book"
            << "\n3. Search a Book"
            << "\n4. Edit Details of a Book"
            << "\n5. Exit"
            <<"\nEnter your Choice: ";    cin>>choice;

    switch(choice){
        case 1:
            book[count] = new Book;
            book[count]->setData();
            count++;
            break;

        case 2:
        cin.ignore();
        cout<<"Enter Title of the Book: "; cin.getline(title,20);
        cout<<"Enter Author of the Book: ";cin.getline(author, 20);

            for(it=0; it<count; it++){
                if(book[it]->search(title,author) ){
                    book[it]->buyBook();
                    break;
                }
            }

            if(it==count)
                cout<<"This Book is not in Stock. "<<endl;
                break;

        case 3:
        cin.ignore();
        cout<<"Enter Title of the Book: "; cin.getline(title,20);
        cout<<"Enter Author of the Book: ";cin.getline(author, 20);

            for(it=0; it<count; it++){
                if(book[it]->search(title,author) ){
                    cout<<"Book Found Successfully!! ";
                    book[it]->displayData();
                    break;
                }
            }
            if(count==it)
                cout<<"This Book is not in Stock. "<<endl;
                break;

        case 4:

        cin.ignore();
        cout<<"Enter Title of the Book: "; cin.getline(title,20);
        cout<<"Enter Author of the Book: ";cin.getline(author, 20);

            for(it=0; it<count; it++){
                if(book[it]->search(title, author)){
                    cout<<"Book Found Successfully!! "<<endl;
                    book[it]->setData();
                    break;
                }
            }

            if(count==it)
            cout<<"This Book is Not in Stock. "<<endl;
            break;

        case 5:
        exit(0);

        default:
        cout<<"Invalid Choice Entered.";
        break;

        }
    }
}