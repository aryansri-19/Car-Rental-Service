#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define total 130
int cls = 100;
int prm = 20;
int lux = 10;
string username, password;
class Car_Rental
{
    string name, address;
    long phone_no;
    int start_date, end_date;
    string car_type;
    public:
    Car_Rental()
    {}
    Car_Rental(string user, string add, long phone, string car, int sd, int ed)
    {
        name = user;
        address = add;
        phone_no = phone;
        car_type = car;
        start_date = sd;
        end_date = ed;
    }
    void classic()
    {
        cout << "--------------------" << endl;
        cout << "\n1. Classic Car (CLS)\n" << endl;
        cout << "3/5 ***\n4 seater arrangement\nNon-automatic gear system\n15km/l mileage\n$25 per day" << endl;
    }
    void premium()
    {
        cout << "--------------------" << endl;
        cout << "\n1. Premium Car (PRM)\n" << endl;
        cout << "4/5 ****\n5 seater arrangement\nAutomatic gear system\n18km/l mileage\n$50 per day" << endl;
    }
    void luxury()
    {
        cout << "--------------------" << endl;
        cout << "\n1. Luxury Car (LUX)\n" << endl;
        cout << "5/5 *****\n7 seater arrangement\nAutomatic gear system\n22km/l mileage\n$100 per day" << endl;
        cout << "--------------------" << endl;
    }
    int checkForAvailability(string car)
    {
        if(car=="CLS")
        {
            if(cls>0)
            {
                cout << "The classic car is available." << endl;
                cls = cls - 1;
                return 1;
            }
            else
            {
                cout << "Sorry, the classic car is not available at the moment." << endl;
                return 0;
            }
        }
        else if(car=="PRM")
        {
            if(prm>0)
            {
                cout << "The premium car is available." << endl;
                prm = prm - 1;
                return 1;
            }
            else
            {
                cout << "Sorry, premium car is not available at the moment." << endl;
                return 0;
            }
        }
        else if(car=="LUX")
        {
            if(lux>0)
            {
                cout << "The luxury car is available." << endl;
                lux = lux - 1;
                return 1;
            }
            else
            {
                cout << "Sorry, the luxury car is not available at the moment." << endl;
                return 0;
            }
        }
        else
        {
            cout << "Invalid Input. Enter again." << endl;
            return -1;
        }
    }
	int totalDays(int startDate, int endDate)
	{
		int days;
		int year1 = startDate%100;
		int year2 = endDate%100;
		int month1 = (startDate%10000)/100;
		int month2 = (endDate%10000)/100;
		int day1 = (startDate%1000000)/10000;
		int day2 = (endDate%1000000)/10000;
		if(year1==year2)
		{
			if(month1==month2)
			{
				days = day2-day1;
			}
			else
			{
				if(month1==2)
					days = 28-day1 + (month2-month1-1)*30 + day2;
				else if(month1==4||month1==6||month1==9||month1==11)
					days = 30-day1 + (month2-month1-1)*30 + day2;
				else
					days = 31-day1 + (month2-month1-1)*30 + day2;
			}
		}
		else
		{
			if(month1==2)
				days = 28-day1 + (11-month1+month2)*30 + (year2-year1-1)*365 + day2;
			else if(month1==4||month1==6||month1==9||month1==11)
				days = 30-day1 + (11-month1+month2)*30 + (year2-year1-1)*365 + day2;
			else
				days = 31-day1 + (11-month1+month2)*30 + (year2-year1-1)*365 + day2;
		}
		return days;
	}
    void calculateRent(int days)
    {
		int amount;
        if(this->car_type=="CLS")
			amount = 25;
		else if(this->car_type=="PRM")
			amount = 50;
		else
			amount = 100;
		cout << "Total rent fee: " << days*amount << endl;
    }
    void details()
    {
        cout << "We have 3 categories of cars for renting." << endl;
        classic();
        premium();
        luxury();
    }
	void display()
	{
		int days = this->totalDays(start_date,end_date);
		cout << "Name of the customer: " << name << endl;
		cout << "Address: " << address << endl;
		cout << "Contact details: " << phone_no << endl;
		cout << "Car selected: " << car_type << endl;
		cout << "Rented for " << days << " days" << endl;
		calculateRent(days);
		cout << "----------Thank you for choosing us----------";
    }
};
bool check(string user)
{
    if(user.length()<5)
    return false;
    else
    {
        for(int i=0;i<user.size();i++)
        {
            if(user.at(i)>='0'&&user[i]<='9')
            return false;
        }
        return true;
    }
}
bool checkp(string pass)
{
    if(pass.length()<5)
    return false;
    return true;
}
void login()
{
    cout << "Enter the username: ";
    cin >> username;
    if(!check(username))
    {
        cout << "The username does not exist." << endl;
        login();
    }
	else
	{
		cout << "Enter the password: ";
		cin >> password;
    }
}
void registration()
{ 
    label1: cout << "Set your username (atleast 5 characters and only alphabets): ";
    cin >> username;
    if(!check(username))
    {
        cout << "Invalid username. Enter again" << endl;
        goto label1;
    }
    else
    {
        label: cout << "Set your password (atleast 5 characters): ";
        cin >> password;
        if(!checkp(password))
        {
            cout << "Invalid password. Enter again" << endl;
            goto label;
        }
    }
}
int main()
{
    Car_Rental cr;
    cout << "----------Car Rental Service----------" << endl;
    cout << "Register yourself (R) / Existing User (E) " << endl;
    char choice;
    cin >> choice;
    if(choice=='R')
    registration();
    else if(choice=='E')
    login();
    else
    {
        cout << "Invalid Input" << endl;
        main();
    }
    cr.details();
    cin.ignore();
	string car_choice;
	correct_choice: cout << "Enter your preferred car code: ";
	getline(cin,car_choice);
    if(car_choice!="CLS"&&car_choice!="PRM"&&car_choice!="LUX")
    {
        cout << "Invalid Input. Enter again" << endl;
        goto correct_choice;
    }
    cout << endl << "Enter the customer's name: ";
    string customer_name, drop_address;
    long contact;
    int date_of_rent, date_of_return;
    getline(cin,customer_name);
    cout << "Enter the drop location: ";
    getline(cin,drop_address);
    cout << "Enter the customer's phone number: ";
    cin >> contact;
    cout << "Enter the dates for rent and return (ddmmyy): ";
    cin >> date_of_rent >> date_of_return;
    Car_Rental customer(customer_name,drop_address,contact,car_choice,date_of_rent,date_of_return);
	customer.display();
	
}