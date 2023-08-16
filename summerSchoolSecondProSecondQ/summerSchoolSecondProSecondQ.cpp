//MOVIE TICKET CALCULATION - THIS IS PERFORMED WELL.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//I am entering the values required for the question
	int numberOfTickets;
	char refreshment;
	char couponCode;
	char circle;

	//constant parameters for calculating operations.
	const int kingCircle = 75;
	const int queenCircle = 150;
	
	//originalPrize and updated prize. Updated prize will be updated when there is a discount.
	float originalPrize = 0.0; //this depends on whether is king or queen.
	//int percentageTen = 0; //this is for evaluating percentageTen.
	//int percentageTwo = 0; //this is for evaluating percentageTwo.
	int refreshmentPrize = 0; //this is based 0, when there is a refreshment, this will be updated.
	double totalCost;

	//We are taking number of tickets.
	while (true)
	{
		cout << "Enter the number of tickets: ";
		cin >> numberOfTickets;

		if (numberOfTickets < 5 || numberOfTickets > 40)
			cout << "Minimum of 5 and Maximum of 40 Tickets" << endl;
		else
			break;
	}

	//We are taking refreshment choice and the coupon code choice. These values must be lowercase letters.
	do
	{
		cout << "Do you want refreshment: ";
		cin >> refreshment;

		cout << "Do you have coupon code: ";
		cin >> couponCode;

	} while (!((refreshment >= 'a' && refreshment <= 'z')&&(couponCode >= 'a' && couponCode <= 'z')));
	

	//We are taking the circle: king or queen.
	while (true)
	{
		cout << "Enter the circle: ";
		cin >> circle;

		if (!(circle == 'k' || circle == 'q'))
			cout << "Invalid Input" << endl;
		else
			break;
	}

	//Mandatory choices. We have to get k or q for updating originalPrize.
	if (circle == 'k')
		originalPrize += numberOfTickets * 75;

	else if (circle == 'q')
		originalPrize += numberOfTickets * 150;

	//Optional choices. If there is a refreshment, we will update refreshmentPrize, otherwise it will be same.
	if (refreshment == 'y')
		refreshmentPrize += numberOfTickets * 50;
	
	if (numberOfTickets >= 20) //we have to update originalPrize for percentage 10%, 2%.
		originalPrize = ((originalPrize * 90) / 100);

	if (couponCode == 'y') //If there was applied for percentage of 10, which means we are applying that prize again percentages of 2%.
		originalPrize = ((originalPrize * 98) / 100);

	//We get the summation of originalPrize and refreshmentPrize according to calculations above.
	totalCost = originalPrize + refreshmentPrize;

	cout << endl;
	cout << "Ticket cost: $" << totalCost << endl;
}