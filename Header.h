//****************************************************
//                   CLASS USED IN PROJECT
//****************************************************
//  Final_project_part-1
//
//  Created by Tanvi Patel on 23/11/20.
//  Copyright © 2020 Tanvi Patel. All rights reserved.
//

#define Header_H
#include <iostream>
#include<vector>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<string>
#include<sstream>
using namespace std; // Namespace call
class apartment
{
    int AptNo;
    char name[50];
    int tableSize=100;
    double monthly_rent;
    int date,month,year;
    int d1,m1,y1;
    char type;
public:
    void add_apt();    //function to get data from user
    void show_apt_info() const;    //function to show data on screen
    void modify_apt_info();    //function to add new data
    int re_aptno() const;// return apt number
    int lease_date() const;
    void report() const;//function to show data in
    bool isDate(int, int, int);
};
