#include<iostream>
#include<fstream>
#define SIZE 1000
#include<string>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
struct flightrow{
	string rowNumber;
	string className;
	string flightseat;
	int count;
};
class flights{
	public:
		string flight_number;
		string departure_date_time;
		string departure_airport_code;
		string arrival_airport_code;
		flightrow seat[60];
		int no_of_rows;
		int no_of_seats;
		int econum;
		int bnum;
		int fulnum;
		int count;
	public:
		void setflights(string fnum,string dateTime,string depCode,string arrCode,flightrow st[],int j,int bnum,int Enum);
		void display_available_flights();
		void view_flights();
		void seat_availability(int);
		void seat_booking(string,string,string);
		void exit();
};
void flights::setflights(string fnum,string dateTime,string depCode, string arrCode,flightrow st[],int j,int Bnum,int Enum ){
	flight_number=fnum;
	departure_date_time=dateTime;
	departure_airport_code=depCode;
	arrival_airport_code=arrCode;
	no_of_rows=j;
	bnum=Bnum;
	econum=Enum;
	int a=0;
	for(a=0;a<j;a++){
		seat[a].rowNumber=st[a].rowNumber;
		seat[a].className=st[a].className;
		seat[a].flightseat=st[a].flightseat;
		seat[a].count=st[a].count;
	}
}
void flights::display_available_flights(){
	cout<<flight_number<<endl;
	cout<<departure_date_time<<endl;
	cout<<departure_airport_code<<endl;
	cout<<arrival_airport_code<<endl;
	/*int i,j;
	for(i=0;i<no_of_rows;i++){
		for(j=0;j<3;j++){
			cout<<seat<<" "<<endl;
		}
	}*/
	//cout<<no_of_rows<<endl;
	cout<<"B::";
	cout<<bnum<<endl;
	cout<<"E::";
	cout<<econum<<endl;
}
void flights::view_flights(){
	cout<<flight_number<<endl;
	cout<<departure_date_time<<endl;
	cout<<departure_airport_code<<endl;
	cout<<arrival_airport_code<<endl;
	cout<<"B::";
	cout<<bnum<<endl;
	cout<<"E::";
	cout<<econum<<endl;
}
void flights::seat_availability(int no_of_seats){
	int i,x;
	count=0;
	for(i=0;i<no_of_rows;i++){
		x=((seat[i].flightseat).length());
		count=count+x;
	}
	if(no_of_seats<count){
		cout<<"Available!!!!"<<endl;
	}
	else{
		cout<<"Not Available!!!"<<endl;
	}
	//cout<<no_of_rows<<endl;
	//cout<<count<<endl;
}
void flights::seat_booking(string rownum,string clsnum,string seatno){
	int i,j,k,count=0;
	for(i=0;i<no_of_rows;i++){
		if(((seat[i].rowNumber).compare(rownum)==0)&&((seat[i].className).compare(clsnum)==0)){
					size_t find=seat[i].flightseat.find(seatno);
					if(find!=-1){
						cout<<"Available!!!"<<endl;
						seat[i].flightseat.erase(seat[i].flightseat.begin()+find);
					}
					else{
						cout<<"not Available!!!!"<<endl;
					}
					
		}
	}
}
int main(){
	string line,fnum,dateTime,depCode,arrCode;
	flightrow seat[60];
	string c;
	string s1("B");
	string s2("E");
	int count_line,space,i,j,k,n,flag;
	fstream myfile;
	myfile.open("flights.txt",ios::in);
	while(getline(myfile,line)){
		if(line==""){
			space++;
		}
	}
	myfile.close();
	n=space+1;
	flights obj[n];
	myfile.open("flights.txt",ios::in);
	for(i=0;i<n;i++){
		int bnum=0,Enum=0;
		getline(myfile,line);
		fnum=line;
		getline(myfile,line);
		dateTime=line;
		getline(myfile,line);
		depCode=line;
		getline(myfile,line);
		arrCode=line;
		getline(myfile,line);
		j=0;
		while(line!=""){
			stringstream x(line);
			getline(x,c,' ');
			seat[j].rowNumber=c;
			getline(x,c,' ');
			seat[j].className=c;
			int num = 1;
			if(s1.compare(c)==0){
				bnum=bnum+num;
			}
			else if(s2.compare(c)==0){
				Enum=Enum+num;
			}
			getline(x,c,' ');
			seat[j].flightseat=c;
			//seatcount=(seat[j].flightseat).length();
			//seatcount=seat[j].count;
			j++;
			getline(myfile,line);
		}
		//cout<<j<<endl;
		obj[i].setflights(fnum,dateTime,depCode,arrCode,seat,j,bnum,Enum);
}
myfile.close();
int opr;
do{
	cout<<"\n *******main menu******\n";
	cout<<"\n 1.Display available flights";
	cout<<"\n 2.View flights \n";
	cout<<"\n 3.seat availability\n";
	cout<<"\n 4.seat booking\n";
	cout<<"\n 5.exit\n";
	cout<<"Enter your option ::";
	cin>>opr;
	switch(opr){
		case 1:
			for(i=0;i<n;i++){
				obj[i].display_available_flights();
			}
			break;
		case 2:
			{
			string flightnumber;
			cout<<"Enter the flight you want to view ::";
			cin>>flightnumber;
			for(i=0;i<n;i++){
				if((obj[i].flight_number).compare(flightnumber)==0){
					obj[i].view_flights();
					flag=1;
				}
			}
			if(flag==0){
				cout<<"not valid";
			}
			break;
	}
		case 3:
		{
			string fnumber;
			int no_of_seat;
			cout<<"Enter the flight you want to view seat availability ::";
			cin>>fnumber;
			for(i=0;i<n;i++){
				if((obj[i].flight_number).compare(fnumber)==0){
					cout<<"Enter no of seats required ::";
					cin>>no_of_seat;
					obj[i].seat_availability(no_of_seat);
					flag=1;
				}
			}
			if(flag==0){
				cout<<"not valid";
			}
			
			break;
	}
	case 4:{
		string f2number,rownum,clsnum,seatno;
		cout<<"Enter the flight you want booking::";
			cin>>f2number;
			for(i=0;i<n;i++){
				if((obj[i].flight_number).compare(f2number)==0){
					cout<<"Row number ::";
					cin>>rownum;
					cout<<"class name ::";
					cin>>clsnum;
					cout<<"seat number ::";
					cin>>seatno;
					obj[i].seat_booking(rownum,clsnum,seatno);
					flag=1;
				}
			}
			if(flag==0){
				cout<<"not vallid";
			}
		break;
	}
	case 5:
	ofstream myfile1;
	myfile1.open("flights.dat");
		for(i=0;i<n;i++){
			myfile1<<obj[i].flight_number<<endl;
			myfile1<<obj[i].departure_date_time<<endl;
			myfile1<<obj[i].departure_airport_code<<endl;
			myfile1<<obj[i].arrival_airport_code<<endl;
			for(k=0;k<obj[i].no_of_rows;k++){
				myfile1<<obj[i].seat[k].rowNumber<<" "<<obj[i].seat[k].className<<" "<<obj[i].seat[k].flightseat<<endl;
			}
			myfile1<<endl;
		}
		myfile1.close();
		break;			
	}
}while(opr!=5);
}










































































































































