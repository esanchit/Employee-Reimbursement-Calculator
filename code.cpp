/*************************************************************************************************************
** Program Filename: Assignment 4 code
** Author: Sanchit Chopra
** Date: 17/02/2019 
** Description: This program is asking the user to input their whole trip expense particular to their category and after they are finished inputing their cost, at the end the program will be telling user's reimbursment for that trip and will ask if they want to do for any other trip also.
** Input: For this program, we asking the user to input their trip cost repseective to each category.
** Output: For the output, this program will tell the user what amount of their total trip will be reimbursed by the company.
*************************************************************************************************************/
#include<iostream>
#include<cstdlib>
#include<climits>
#include<string>
#include<stdio.h>
#include<sstream>

using namespace std;

double b_cost[10] = {};
double l_cost[10] = {};
double d_cost[10] = {};
double hotel[10] = {};
double taxi[10] = {};
double p_fee[10] = {};

/*******************************
 ** Function Name: Verify
 ** Description: This checks the input is only a positive integer.
 ** Parameter: string var;
 ** Input: We input user's input into this function and check that the input is only a postive integer.
 ** Output: If the input is not a positve integer than asking till its a positive integer.
 ******************************/
double verify(string var){
	bool error= false;
	double y;
	for (int i =0;i < var.length();i++){
		if(var.at(i) != '.' &&!(var.at(i) >= '0' && var.at(i) <= '9')){
			cout<< "The Input should only be a positive integer greater than zero.Enter again...  "<<endl;   // check whether the input is a positive integer or not.
			error = true;
			break;	
		}	

	}
	if (error) {
		cin >> var;
		return verify(var);	
	}
	y = atof(var.c_str());   // converts the string to float.
	return y;
}
/*******************************
 ** Function Name: number_of_days
 ** Description: This function tell other functions in program the number of days of the trip.
 ** Parameters: n/a.
 ** Input: The user is inputing the number of days.
 ** Output: The function is returning the number of days to other functions where needed. 
 ******************************/
int number_of_days(){
	int i;
	bool error;
	string s;
	do{
		error = false;	
		cout<<"How long was your Trip?"<<endl;   // Asking for the days of trip.
		getline(cin, s);
		for(i = 0; i < s.length(); i++){	
			if(!(s.at(i) >= '0' && s.at(i) <= '9')){   // checking the input is a positive integer.
				cout<<"Invalid Input!!! Asking again..."<<endl; // this gets printed when the input is not a positive integer and asks again to enter.
				error =true;
				break;	
			}
		}
	}while(error);
	i= atoi(s.c_str());
	if(i <1){
		do{
			cout<<"How can you have a atrip of 0 days. Please enter again..."<<endl;  // prints if the user enter 0 for the days of trip.
			cin>>i;	
		}while(i <1);	
	}
	cout<<endl;
	return i;	
}
/***************************
 ** Function name: fare_fees.
 ** Description: This function ask the user their cost for flight and other fees.
 ** Parameters: double total,double total_c.
 ** Input: The user is inputing the cost for their flight and  conference or registration fees.
 ** Output: The total of cost and other small fees are added to total expense for the user.
***************************/
void fare_fees(double &total,double &total_c){
	double y=0,x=0;
	string fare;
	string fee;
	string wrong;
	cout<<"Enter total amount of airfare, in $: ";   // Asking airfare from the user.
	cin >> fare;
	y = verify(fare);  // verifying input.
	cout<<"Enter total conference or seminar registration fees, in $: "; // Asking confernece ore registration fees.
	cin >> fee;
	x = verify(fee); // verifying input
	total_c = y + x;
	total += total_c;  // Adding the airfare and other fees to the total expense.
	cout<<endl;
}
/**************************
 ** Function Name: flght_time
 ** Descriptoin: This function ask passes to departure time and arrival time of the user to other functions.
 ** Parameters: float d_time, float a_time.
 ** Input: User input their departure time for first day and arrival time for last day.
 ** Output: The function refer the departure time and arrival time to other functions which tells which meals are not included as expense on first and last day. 
**************************/
void flight_time(float &d_time,float &a_time){
	cout<<"Enter you Departure time on the first day: ";  // Asking for the departure time from the user.
	cin>>d_time;
	while(d_time > 24.00){
		cout<<"Your Time is not valid.Please enter a valid time: ";  // This will be printed when the user did not enter a valid time.
		cin>>d_time;	
	}
	cout<<"Enter your Arrival time on the Last day: ";  // Asking for the arrival time from the user.
	cin>>a_time;
	while(a_time >24.00){
		cout<<"Your time is not valid.Please enter a valid time: ";  // This will be printed when the user did not enter a valid time.
		cin>> a_time;	
	}
	cout<<endl;
}
/*******************
 ** Function Name: get_car_rental_info.
 ** Descriptoin: This function exceeds the line limit of 20 because for getting the car information we  have car and taxi and there are some more subtasks for the car. So     getting the input verifying that input and then moving on to other subtasks and at the end getting the sum makes it a liitle long. 
 ** Input: User is inputing the type they rented for their trip and what were the cost for that type.
 ** Output: The cost for that type is first added to the total expense of the user and are also referred to other function which tell what amount will reimburse from that.
*******************/
void get_car_rental_info(int i, int &p,int n, double &type, double  &total,double &z,double &x,double &y){
	double total_t=0,total_taxi =0;
	string miles;
	string gas;
	string spent;
	double  c;
	double sum_t=0;
	string parkingfees;
	double sum=0;
	int t;
	cout<<"Which type you rented throughout your trip.Enter 1 for car and 2 for taxi: "; cin>>n;  // Asking which type the user rented throughout their trip.
	if (n == 1){	//If the user rented car this will execute.
		cout<<"Enter total spent on the rental car, in $: ";  //Asking the total cost for renting the car.
		cin>>spent;
		x= verify(spent);
		cout<<"Enter your total gas fee spent, in $: "; // Asking the total fee spent on gas.
		cin>> gas ;
		y = verify(gas);
		cout<<"1.Sedan "<<endl<<"2.SUV"<<endl<<"3.Van"<<endl<<"4.Convertible"<<endl; 
		cout<<"Enter your rental car type: "; // asking which type of car the user had
		cin>> type;	
		cout<<"Enter the total miles driven, in miles: "; // asking the total miles driven.
		cin>> miles;
		z = verify(miles);
		cout<<endl; 
		for (p = 1; p <= i;p++){
			cout<<"Enter parking fee for day "<< p <<", in $: "; // asking the parking fee per day the user spent.
			cin>> parkingfees;
			p_fee[p] = verify(parkingfees);	
			sum += p_fee[p];
		}
		total_t = x + y + sum ; // Getting the sum for all things.
		total += total_t; // adding that sum to total expense.
		cout<<endl;
	}
	else if(n ==2){	//If the user rented taxi this will execute.
		for(t =1; t<=i;t++){
		cout<<"Money spent on taxi on day "<< t <<":"; // asking for the money spent per day by the user.
		cin>> taxi[t];
		sum_t += taxi[t];  // getting the sum of all days.
		}	
	total_taxi = sum_t; 
	total += total_taxi;   //Adding the sum of taxi to total expense.
	cout<<endl;
	}
}
/****************************
 ** Function Name: get_hotel_info.
 ** Description: This function is aksing the user, their cost for hotel per night.
 ** Parameters: int h, int i, double total;
 ** Input: The user inputs Their hotel cost per night during their trip.
 ** Output: The sum of the cost of hotel throughout their trip is added to total expense and then referred to other function which tells what amount will be reimbursed from   that.
****************************/
void get_hotel_info(int h,int i, double &total){
	double total_h=0,sum_h=0;
	string hotelfee;
	for(h = 1;h < i;h++){
		cout<<"Enter hotel fee for night "<< h <<", in $: ";   //Asking how much the user spent on hotel per day.
		cin>> hotelfee;
		hotel[h] = verify(hotelfee);
		sum_h += hotel[h]; // getting sum of all days.
	}	
	total_h = sum_h;
	total += total_h;  // adding the sum to total expense.
	cout<<endl;
}
/*************************
 ** Function Name: food_eat_firstday
 ** Description: This function tells user which meals are not included as their expense for the first day by reffering to  the departure time of the user that they input       earlier.
 ** Parameter: int f,int i,flaot d_time,double total.
 ** Input: User input the cost of the meals which are included as an expense for the first day.
 ** Output: The meals which are included are added to the total expense and reffered to other function which tells what amount will be reimbursed from that.
 *************************/ 
void food_eat_firstday(int &f,int i, float &d_time,double  &total) {
	double total_first;	
	string breakfast;
	string lunch;
	string dinner;
	if(f ==1){	// Ececuting for the first day of the trip.
		cout<<"Day 1 -"<<endl;
		if( d_time > 7.00 && d_time <= 12.00){	 // if the departue time is greater than 7 am and less than 12 noon this will execute.
			cout<<"Your breakfast for Day 1 is not allowed as an expense..."<<endl; // telling that the breakfast is not included now.
			cout<<"Enter lunch cost, in $: "; // Asking for the cost the user spent on lunch.
			cin >> lunch;
			l_cost[f] = verify(lunch);
			cout<<"Enter dinner cost, in $: "; // Asking for the cost the user spent on dinner.
			cin >> dinner;
			d_cost[f] = verify(dinner);
		}
		else if( d_time > 12.00 && d_time <= 18.00){ // If the departure time is greter than 12 noon and less than 6pm this will execute.
		 	cout<<"Both, breakfast and lunch for day 1 are not allowed as an expense..."<<endl; // telling the lunch and breakfast are not included.
		 	cout<<"Enter dinner cost, in $: "; // Asking for the cost the user spent on dinner.
			cin>> dinner;
			d_cost[f] = verify(dinner);
		}
		else if( d_time > 18.00 && d_time <= 24.00){ // If the departure time is greater than 6pm and less than 24.00 this will execute.
			cout<<"All meals for Day 1 are not allowed  as an expense."<<endl;	// Telling all meals are not included.
		}
		else{ // else if non of the above execute this will execute.
			cout<<"Enter breakfast cost,in $: "; // Asking for the cost the user spent on breakfast.
			cin>> breakfast;	
			b_cost[f] = verify(breakfast);
			cout<<"Enter lunch cost,in $: "; // Asking for the cost the user spent on lunch.
			cin>> lunch;
			l_cost[f] = verify(lunch);
			cout<<"Enter dinner cost,in $: "; // Asking for the cost the user spent on dinner.
			cin>>dinner;
			d_cost[f] = verify(dinner);
		}
	}	
	total_first = b_cost[f] + l_cost[f] + d_cost[f];
	total += total_first;
	cout<<endl;
}	
/**************************
 ** Function Name: food_eat_lastday
 ** Description: This function tells the user which meals are not included as their expense on the last day by reffering to the arrival time user inputed earlier.
 ** Paramter: int f,int i,float a_time,double total.
 ** Input: The user inputs the cost of the meals which are included as an expense for the last day.
 ** Output: The cost inputed for the meals included are added to the total expense and then reffered to other function which tells what amount will be reimbursed.
 *************************/ 
void food_eat_lastday(int &f, int i , float &a_time,double  &total){
	double total_last=0;
	string breakfast;
	string lunch;
	string dinner;
	if(f == i){	// executing for th last day of the trip.
		cout<<"Day "<< i <<"- "<<endl;
		if (a_time >= 8.00 && a_time < 13.00){ // If the arrival time is greater tha 8am and less than 13 this will execute.
			cout<<" Enter breakfast cost, in $: "; // asking for the money spent on breakfast.
			cin>> breakfast;
			b_cost[f] = verify(breakfast);
			cout<<"Lunch and dinner for Day "<< i <<", are not allowed as an expense."<< endl; // Telling lunch and dinner are not included.
		}
		else if (a_time >= 13.00 && a_time < 19.00){ // If the arrival time is greter than 1pm and less than 7pm.
			cout <<"Breakfast, in $: "; // asking for the cost the user spent on breakfast.
			cin>>breakfast;
			b_cost[f] = verify(breakfast);
			cout<<"Enter lunch cost, in $: "; // asking for the cost the user spent on lunch.
			cin>>lunch;
			l_cost[f] = verify(lunch);
			cout<<"Dinner for Day "<< i <<", is not allowed as an expense."<<endl;	// asking for the cost the user spent on dinner.
		}
		else if (a_time >= 19.00){ // If the arrival time is greater than 7pm
			cout<<"Enter breakfast cost, in $: "; // asking for the cost the user spent on breakfast.
			cin>>breakfast;
			b_cost[f] = verify(breakfast);
			cout<<"Enter Lunch cost, in $: "; // asking for the cost the user spent on lunch.
			cin>>lunch;
			l_cost[f] = verify(lunch);
			cout<<"Enter dinner cost, in $: "; // asking for the cost the user spent on dinner.
			cin>>dinner;
			d_cost[f] = verify(dinner);
		}
		else { // if non of the above condition execute this will execute.
			cout <<"All meals for Day "<< i <<", are not allowed as an expense..."<<endl;	// teeling that all meals are not included.
		}
	}	
	total_last = (b_cost[f] + l_cost[f] + d_cost[f]); //adding all the cost.
	total += total_last;	// adding the sum to the total expense.
	cout<<endl;
}		
/*******************************		
 ** Function Name: food_eat_otherdays
 ** Description: this function makes user enter the cost of the meals they have except the first day and last day.
 ** Parameters: int f, int i, double total.
 ** Input: User input the cost of their meals for respective days.
 ** Output: The cost of each meal for respective day are added to total expense and then reffered to other function which tells what amount will be reimbursed. 
*******************************/
void food_eat_otherdays(int &f, int i,double &total){ 
	double sum_b=0,sum_l=0,sum_d=0,total_second;
	string breakfast;
	string lunch;
	string dinner;
	for(f = 2; f < i;f++){	// this will execute for all other days except the first and last.
		cout<<"Day" << f <<"-"<<endl;
		cout<<"Enter breakfast cost, in $: "; // asking for the cost the user spent on breakfast.
		cin>> breakfast;
		b_cost[f] = verify(breakfast);
		cout<<"Enter lunch cost, in $: ";  // asking for the cost the user spent on lunch.
		cin>> lunch;
		l_cost[f] = verify(lunch);
		cout<<"Enter dinner cost, in $: ";  // asking for the cost the user spent on dinner.
		cin>> dinner; 
		d_cost[f] = verify(dinner);					
		sum_b += b_cost[f];
		sum_l += l_cost[f];
		sum_d += d_cost[f];
	}
	total_second = (sum_b + sum_l + sum_d);	// adding all the costs for each meal. 
	total += total_second; // adding the sum to total expense.
	cout<<endl;
}
/*****************************
 ** Function Name: compare_hotelcost.
 ** Description: This function compares hotel cost of the user to that what company allows and tells what will be reimburse.
 ** Paramters: int h, int i,double reimb.
 ** Input: The hotel cost user inputed earlier is reffered in this function. 
 ** Output: The cost which will be reimburse is added to the reimbursement of the user.
 ****************************/ 
void compare_hotelcost(int h,int i,double &reimb){
	double reimb_one=0,sum_reimb_one=0;
	for(h = 1; h< i;h++){ // comparing the hotel fees per day of the user with company allowable cost.
		if(hotel[h] > 90.00){ //if hotel fees is greater than 90.00
			reimb_one = 90.00;	
		}	
		else if(hotel[h] > 0.00 && hotel[h] <=  90.00){ // if hotel fees is greater than 0 and less than 90.00
			reimb_one = hotel[h]; 	
		}
		else{ // if none of the above executes this will execute.
			reimb_one = 0.00; 	
		}	
	sum_reimb_one += reimb_one;
	}	
	reimb += sum_reimb_one; // adding the sum to the reimbursment for the user.
}
/*****************************
 ** Function Name: compare_taxicost
 ** Description : If the user had taxi throughout their trip than this will compare that cost with what company allows and tell what will reimburse.
 ** Parameters: int t, int i, double reimb.
 ** Input: The cost inputed by the user for taxi throughout their trip is reffered in this function.
 ** Output: The cost which will be reimburse is added to the reimbursment of the user.
 ****************************/ 
void compare_taxicost(int t,int i, double &reimb){
	double reimb_two=0,sum_reimb_two=0;
	for(t = 1; t<= i; t++){ // comapring the taxi fee per day of the user with company allowable cost.
		if(taxi[t] > 10.00){ // if taxi fee is greater than 10.00
			reimb_two = 10.00;	
		}
		else if (taxi[t] > 0.00 && taxi[t] <= 10.00){ // if taxi fee is greater than 0 and less than 10.00
			reimb_two = taxi[t];	
		}
		else{ // if none of the above execute this will execute.
			reimb_two = 0.00;	
		}
		sum_reimb_two += reimb_two;
	}
	reimb += sum_reimb_two; // adding the sum to the reimbursment for the user.
}
/***************************
 ** Function Name: compare_parkingfee.
 ** Description: If the user had car throughout their trip[ that this will compare the parking cost with what company allows and tell what will reimburse.
 ** Parameters: int p, int i, double reimb.
 ** Input: The cost inputed by the user for parking is reffered in this function.
 ** Output: The cost which will be reimburse is added to the reimbursment of the user.
 ***************************/ 
void compare_parkingfee(int p,int i, double &reimb){
	double reimb_three=0,sum_reimb_three=0;
	for (p= 1; p<=i;p++){ // comparing the parking fee per day of the user with comapny allowable cost.
		if(p_fee[p] > 6.00){ // if the parking fee is greater than 6.00.
			reimb_three = 6.00; 	
		}	
		else if(p_fee[p] > 0.00 && p_fee[p] <= 6.00){ // if the parking fee is greater than 0 and less than 6.00.
			reimb_three = p_fee[p];	
		}
		else{ // if none of the above execute this will execute.
			reimb_three = 0.00;	
		}
		sum_reimb_three += reimb_three; 
	}	
	reimb += sum_reimb_three; // adding the sum to the reimbursment for the user.
}
/**************************
 ** Function Name: compare_breakfast
 ** Description: This compare the user cost for the brekfast for each day and what company allows and tell what will be reimburse.
 ** Parameters: int f, int i, double reimb
 ** Input: The cost inputed by the user earlier is refferd in this function.
 ** Output: the cost which will be reimburse is added to the reimbursment of the user.
 **************************/ 
void compare_breakfast(int &f,int i,double &reimb){
	double reimb_four_b=0,sum_reimb_four=0;
	for (f = 1; f <= i;f++){  // comparing the breakfast per day of the user with company allowable cost.
		if(b_cost[f]  >= 0.00){
			if(b_cost[f] > 9.00){ // if the breakfast cost is greater than 9.00.
				reimb_four_b = 9.00;	
			}
			else if (b_cost[f] > 0.00 && b_cost[f] <= 9.00){ // if the breakfast cost is greater than 0 and less than 9.00
				reimb_four_b  = b_cost[f];	
			}
			else{ // if none of the above execute this will execute.
				reimb_four_b = 0.00;
			}
		}
		sum_reimb_four += reimb_four_b;
	}
	reimb += sum_reimb_four; // adding the sum to the reimbursment for the user.
}
/******************************
 ** Function Name: compare_lunch.
 ** Description: This function compare the cost for lunch by user and what company allows and tell what will be reimburse. 
 ** Paramters: int f, int i, double reimb.
 ** Input: The cost of lunch inputed by the user earlier are reffered in this function.
 ** Output: The cost which will be reimburse is added to the reimbursment of the user.
 *****************************/ 
void compare_lunch(int &f, int i, double &reimb){	
	double reimb_four_l=0,sum_reimb_lunch=0;
	for(f =1; f<= i;f++){ // comparing the lunch cost per day of the user with the comapany allowable cost.
		if(l_cost[f] >=0.00){	
			if( l_cost[f] > 12.00){ // if the lunch cost is greater than 12.00.
				reimb_four_l = 12.00;	
			}
			else if (l_cost[f] > 0.00 && l_cost[f] <= 12.00){ // if the lunch cost is greater than 0 and less than 12.00.
				reimb_four_l = l_cost[f];
			}
			else{ // if none of the above execute this will execute. 
				reimb_four_l = 0.00;	
			}
		}
		sum_reimb_lunch += reimb_four_l;
	}
	reimb += sum_reimb_lunch; // adding the sum to the reimbursment for the user.
}
/*******************************
 ** Function Name: compare_dinner
 ** Description: This function compare the cost for dinner by user and what company allows and tell what will be reimburse.
 ** Parameters: int f, int i, double reimb.
 ** Input: The cost of dinner inputed by the user earlier are reffered in this function.
 ** Output: The cost which will be reimburse is added tp the reimbursment of the user.
 *******************************/ 
void compare_dinner(int &f, int i, double &reimb){
	double reimb_four_d=0,sum_reimb_dinner=0;
	for(f = 1; f<=i;f++){ // comapring the dinner cost per day of the user with the comapny allowable cost.
		if(d_cost[f] >=0.00){	
			if (d_cost[f] > 16.00){ // if the dinner cost id greater than 16.00.
				reimb_four_d = 16.00;	
			}	
			else if (d_cost[f] > 0.00 && d_cost[f] <= 16.00){ // if the dinner cost is greater than 0 and less than 16.00
				reimb_four_d = d_cost[f];	
			}
			else{ // if none of the above execute this will execute.
				reimb_four_d = 0.00;	
			}
		}	
		sum_reimb_dinner += reimb_four_d;
	}
	reimb += sum_reimb_dinner; // adding the sum to the reimbursment for the user.
}
/*****************************
 ** Function Name: compare_carcost
 ** Description: This function comapre the cost for car by user and what company allows and tells what will be reimburse.
 ** Paramters: double type, int i, double reimb, double x.
 ** Input: The type and cost by user inputed are reffered in this function.
 ** Output: The cost what will be reimburse is added to the reimbursment of the user.
 ******************************/ 
void compare_carcost(double &type,int i , double &reimb,double &x) {
	double car_reimb=0,reimb_five=0,sum_reimb_five=0;
	if(type == 1){  // if the user input car type, sedan.
		car_reimb = (i * 20);
		reimb_five = car_reimb;				
	}
	else if (type == 2){ // if the user input car type,SUV.
		car_reimb = (i * 25);
		reimb_five = car_reimb;	
	}
	else if (type == 3){ // if the user input car type, Van.
		car_reimb = (i * 30);
		reimb_five = car_reimb;	
	}	
	else if(type == 4){ // if the user input car type, Convertible.
		car_reimb = (i * 50);
		reimb_five  = car_reimb;
	}
	if(reimb_five > x){ // if the reimbursment calculated is greater than the money spent by user than, the money spent by the user will be the reimbursment not the                 calculated one.
		reimb_five = x;	
	}
	sum_reimb_five = reimb_five;
	reimb += sum_reimb_five; // adding the sum to reimbursment for the user.
}
/***************************************
 ** Function Name: compare_gascost.
 ** Description: This function compare the cost of gas by user and what company allows and then tells what will be reimburse.
 ** Parameters: double type, int i, double z, double reimb, double y.
 ** Input: The miles driven by the user and total gas spent are reffered in this function.
 ** Output: The cost for gas what wil be reimburse is added to the reimbursment of the user.
 ***************************************/ 
void compare_gascost(double &type,int i, double &z, double &reimb,double &y){
	double max_reimb=0,reimb_six=0,sum_reimb_six=0;
	if(type == 1){ // if the user input car type,Sedan.
		max_reimb= (0.24 * z);
		reimb_six =  max_reimb;
	}	
	else if (type == 2){ // if the user input car type, SUV.
		max_reimb =(0.27 *  z);
		reimb_six = max_reimb;
	}
	else if(type == 3){ // if the user input car type, Van.
		max_reimb = (0.32 *  z);
		reimb_six = max_reimb;	
	}
	else if (type == 4){ // if the user input car type, Convertable. 
		max_reimb = (0.45 * z);
		reimb_six = max_reimb;
	}
	if(reimb_six > y){ // if the reimbursment calculated is greater than the money spent by user than, the money spent by the user will be the reimbursment not the                  calculated one. 
		reimb_six = y;	
	}
	sum_reimb_six = reimb_six;
	reimb += sum_reimb_six;  // adding the sum to reimbursment for the user.
}	
/******************************************
 ** Function Name: main
 ** Description : This is the main function which includes all other functions.
 ** Parameters: n/a
 ** Input: The other functions in this are having the inputs from the user and also this function is asking if the user what do again or not.
 ** Output: The total expense of the trip and total reimbursment of the trip for user.
******************************************/
int main() {
	int play =0;
	do{
		int  n = 0,p = 1,h = 1,f = 1,t = 1;
		double z = 0,x = 0,y = 0;
		double type, total_c = 0,reimb = 0,total = 0;
		float d_time,a_time;
		string var;
		string spent;
		string gas;
		string miles;
		for(int w = 0;w <10;w++){
				b_cost[w] =0;
				l_cost[w]=0;
				d_cost[w]=0;
				hotel[w]=0;
				taxi[w]=0;
				p_fee[w] =0;
		}
		int i = number_of_days();
		flight_time(d_time,a_time); 	
		fare_fees(total,total_c);  
		get_car_rental_info(i,p,n,type,total,z,x,y);
		get_hotel_info(h, i, total); 
		food_eat_firstday(f,i,d_time,total);
		food_eat_otherdays(f,i,total); 
		food_eat_lastday(f,i,a_time,total); 
		cout<<"Your total  expense for this trip is: "<< total <<endl;  // telling the user their total expense.
		compare_hotelcost(h,i,reimb);
		compare_taxicost(t,i,reimb);
		compare_parkingfee(p,i,reimb);
		compare_breakfast(f,i,reimb);
		compare_lunch(f,i,reimb);
		compare_dinner(f,i,reimb);
		compare_carcost(type,i,reimb,x);
		compare_gascost(type, i,z,reimb,y);
		reimb += total_c;
		cout<<"Your  total reimbursment for this trip is: "<< reimb  <<endl<<endl;  // telling the user their total reimbursment.
		cout<<"Do you want to make another buisness report?Enter 1 for yes and  0 for no. "<<endl; // asking if the user want to do any other buisness report.
		cin>>play;
		cin.ignore();
	}while(play == 1);
	return 0;	

}
