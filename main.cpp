//
//  main.cpp
//  Final_project_part-1
//  Created by Tanvi on 14/12/20.
//

#include "Header.h"


//************************************************
//        function declaration
//**************************************************
//bool isValidDate(int, int, int);
void insert_apartment_lease();    //function to write record in binary file
void display_apt_lease(int);    //function to display account details given by user
void update_apartment_lease(int);    //function to modify record of file
void delete_lease(int);//function to delete record of file
void search_apt(int, int, int);
void display_all_lease();        //function to display all account details
void intro();//introductory screen function


int main() {
    intro();
    
    //int hashTableSize=100;
    int ch;
    apartment apt;
    
    string labels[] = {"Error","Add Renter Information","Modify the Leasing Information","Close Leasing","Search apartment","Display Leasing information", "Exit"};
    int num, m, y;
    //string num= to_stro
    int d;
for (;ch!=6;) {
      for(int i = 1; i<7; i++){
        cout << i <<". "<< labels[i] << endl;
      }
      cout<<"Enter your Choice: ";
      cin>>ch;
    switch (ch){
        case 1:
            //cout<<"Enter key to be inserted: "<<endl;
            //cin>>key;
            insert_apartment_lease();
        break;
        case 2:
            cout<<"\n\tEnter The apartment No. : "; cin>>num;
            update_apartment_lease(num);
        break;
        case 3:
            cout<<"\n\tEnter The apartment No. : ";
            cin>>num;
            delete_lease(num);
        break;
        case 4:
            cout<<"\n\tEnter the date to search :"; cin>>d>>m>>y;
            search_apt(d,m,y);
        break;
        case 5:
            display_all_lease();
        break;
        case 6:
            cout << "Thank you so much for using this program Bye"<< endl;
            cout << "EXIT from the Program" << endl;
        break;
        default:
         cout<<"Error....Wrong Choice Entered"<<endl;
          continue;
      }//switch
}  // loop end

    return 0;
}
//***************************************************************
//        function to insert in file
//****************************************************************


void insert_apartment_lease()
{
    
    apartment apt;
    ofstream outFile;
    outFile.open("apartment.txt",ios::app);
    apt.add_apt();
    outFile.write((char*)&apt, sizeof(apartment));
    outFile.close();
    
}

//**************************************************
//        function to modify record of file
//***************************************************

void update_apartment_lease(int n)
{
    bool found=false;
    apartment apt;
    fstream File;
    File.open("apartment.txt",ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!File.eof() && found==false)
    {
        File.read((char*)&apt, sizeof(apartment));
        if(apt.re_aptno()==n)
        {
            apt.show_apt_info();
            cout<<"\n\nEnter the new apartment details "<<endl;
            apt.modify_apt_info();
            int pos=(-1)*static_cast<int>(sizeof(apartment));
            File.seekp(pos,ios::cur);
            File.write((char*)&apt, sizeof(apartment));
            cout<<"\n\t Record Updated \n";
            found=true;
          }
    }
    File.close();
    if(found==false)
        cout<<"\n\t Record Not Found \n";
}

//***************************************************
//        function to delete record of file
//****************************************************


void delete_lease(int n)
{
    apartment apt;
    ifstream inFile;
    ofstream outFile;
    inFile.open("apartment.txt");
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat");
    inFile.seekg(0,ios::beg);
    while(inFile.read((char*)&apt, sizeof(apartment)))
    {
        if(apt.re_aptno()!=n)
        {
            outFile.write((char*)&apt, sizeof(apartment));
        }
    
    }
    if (apt.re_aptno()==n)
    {
        cout<<"\n\tRecord Deleted \n"<< endl;
    }
    else
    {
        cout<<"\n\tyou have entered wrong Apt Number \n"<<endl;
    }
    inFile.close();
    outFile.close();
    remove("apartment.txt");
    rename("Temp.dat","apartment.txt");
    
}
//***************************************************************
//        function to read specific record from file
//****************************************************************

void search_apt(int d, int m, int y)
{
    apartment apt;
    bool flag=false;
    ifstream inFile;
    inFile.open("apartment.txt");
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\nAPARTMENT DETAILS\n";

    while(inFile.read((char*)&apt, sizeof(apartment)))
    {
       if(apt.isDate(d, m, y))
        {
            apt.show_apt_info(); // show apartment info from model
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\nApartment number does not exist\n"<<endl;
}

//***************************************************************
//        function to display all leasing list
//****************************************************************

void display_all_lease()
{
    apartment apt;
    ifstream inFile;
    inFile.open("apartment.txt",ios::in|ios::out| ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    
    cout<<"\n\n\t\tAPARTMENT RENTER LIST\n\n";
    cout<<"==========================================================\n";
    cout<<"START_DATE   END_DATE    Apt no.    NAME       MONTHLY_RENT\n";
    cout<<"==========================================================\n";
    while(inFile.read((char*)&apt, sizeof(apartment)))
    {
        apt.report();
    }
    inFile.close();
    cout << "\n" <<endl;
}


//***************************************************************
//        INTRODUCTION FUNCTION
//****************************************************************
void intro()
{
    cout<<"\nAPARTMENT LEASING";
    cout<<"\n   MANAGEMENT";
    cout<<"\n     SYSTEM";
    cout<<"\nMADE BY : Tanvi";
    cout<<"\nSCHOOL : University of New Haven";
    cout<<"\nSUBMITTED TO : Ms. Liberty Page"<<endl;
}
//***************************************************************
//                END OF PROJECT
//***************************************************************
           

