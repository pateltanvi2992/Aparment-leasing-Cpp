//
//  model.cpp
//  Final_project_part-1
//
//  Created by Tanvi on 23/11/20.
//

#include "Header.h"
#include<iostream>

using namespace std; // Namespace call

bool isCheckDate(int m, int d, int y)
{
  //dates start in 2020
  if (!(2020<= y )  )
     return false;
  if (! (1<= m && m<=12) ) // months between 1 to 12
     return false;
  if (! (1<= d && d<=31) ) // dates between 1 to 31
     return false;
  if ( (d==31) && (m==2 || m==4 || m==6 || m==9 || m==11) ) // if month= 2, 4, 6, 9, 11 days=30
     return false;
  if ( (d==30) && (m==2) )
     return false;
  if ( (m==2) && (d==29) && (y%4!=0) )
     return false;
  if ( (m==2) && (d==29) && (y%400==0) )
     return true;
  if ( (m==2) && (d==29) && (y%100==0) )
     return false;
  if ( (m==2) && (d==29) && (y%4==0)  )
     return true;
 
  return true;
}
// function to add Apartment detail

void apartment::add_apt()
{
        
        cout<<"\nEnter the leasing start date(dd mm yyyy) format: ";
        cin>>date>>month>>year;
            
            while(!isCheckDate(month, date, year))
            {
                if(isCheckDate(month, date, year)==false)
                {
                    cout<<"Please enter right date "<< endl;
                }
                cout<<"\nEnter the leasing start date(dd mm yyyy) format: ";
                cin>>date>>month>>year;
            }
            
        cout<<"\nEnter the leasing end date(dd mm yyyy) format: ";
        d1=date;m1=month;y1=year+1;
        cout<<d1<<"/"<<m1<<"/"<<y1<<endl;
        cout << "Enter apartment No :";
        cin>>AptNo;
       //AptNoVec.push_back(AptNo);
        
        cout<<"\nEnter Name of the renter : ";
        cin.ignore();
        cin.getline(name,50);
        
        cout<<"\nEnter the monthly rent : ";
        cin>>monthly_rent;

    cout<<"\nLease Created..\n"<<endl;
}

//show apartment deatail
void apartment::show_apt_info() const
{
    cout<<"\nLeasing start date : "<< date <<"/"<< month <<"/"<< year;
    cout<<"\nLeasing end date : "<< d1 <<"/"<< m1 <<"/"<< y1;
    std::cout<<"\nApartment No. : "<<AptNo;
    cout<<"\nRenter Name : ";
    cout<<name;
    
    cout<<"\nMonthly rent : "<<monthly_rent <<"\n"<< endl ;
}

//update apartment information
void apartment::modify_apt_info() // function for enter modify
{
    cout<<"\nModify Leasing start date : ";
    cin>>date>>month>>year;
    cout<<"\nModify Leasing end date : ";
    d1 = date; m1 = month; y1= year;
    cout<<d1 <<"/" <<m1<<"/"<< "/"<<y1<< endl;
    cout<<"Apartment No. : "<<AptNo<<endl;
    cout<<"\nModify Renter Name : ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\nModify Monthly rent : ";
    cin>>monthly_rent;
}
//return apartment info
int apartment::re_aptno() const // retrive apt number
{
    return AptNo;
}

//return apartment leasing date
int apartment::lease_date() const // retrive leasing date
{
    return date;
    return month;
    return year;
}
bool apartment::isDate(int date1, int month1, int year1)
{
    apartment apt;
    if(date==date1 && month==month1 && year==year1)
    {
        return true;
    }
    else
        return false;
}


void apartment::report() const// data for table format
{
    cout << date<<"/" <<month<<"/"<<year<<"   "<<d1<<"/"<<m1<<"/"<<y1<<"    "<<AptNo <<"        "<<name<<"       "<<monthly_rent<< endl;
}

