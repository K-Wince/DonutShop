/* MP1 - Kaden Wince - 9/22/2021
* 
* Goal of this program is to receive input from the user the amount of donuts the customer
* ordered and then calculate the cost and then get how much the customer paid and then
* show the change that is due and how many coins/dollars they will receive back
*/

#include <iostream>
using namespace std;

int main()
{
	// Declare the variables needed
	int regDonut     = 0; int dozenReg   = 0;
	int fancyDonut   = 0; int dozenFancy = 0;
	int appleFrit    = 0;
	double cost      = 0;
	double tax       = 0;
	double nonRTax   = 0;
	double totalCost = 0;
	double custPaid  = 0;
	double change    = 0;
	int dollars      = 0;
	int quarters     = 0;
	int dimes        = 0;
	int nickels      = 0;
	int pennies      = 0;

	// Start of Getting Input from User for Amount of Donuts
	cout << "Number of regular donuts ordered: ";
	cin >> regDonut;
	cout << "Number of fancy donuts ordered:   ";
	cin >> fancyDonut;
	cout << "Number of apple fritters ordered: ";
	cin >> appleFrit;

	// Calculate the cost
	dozenReg = regDonut / 12;     // Get the dozens of regs
	dozenFancy = fancyDonut / 12; // Get the dozens of fancy
	regDonut = regDonut % 12;     // Make the remaining amount of donuts less than dozen
	fancyDonut = fancyDonut % 12; // Make less than dozen

	cost = (dozenReg * 7.99) + (regDonut * 0.75) + (dozenFancy * 8.49) + 
		(fancyDonut * 0.85) + (appleFrit * 1.50);  // Get the cost of all the donuts
	nonRTax = cost * 0.075;                        // Calculate the Non-Rounded Tax
	tax = (int((nonRTax + 0.005) * 100)) / 100.0;  // Round the tax up or down depending
	totalCost = cost + tax;                        // Get the total Cost
	cout << "Customer owes: $" << totalCost;       // State the total Cost

	// Get the User Input on what the Customer Pays
	cout << "\nCustomer pays: $";
	cin >> custPaid;

	// Calculate the change given back
	change = custPaid - totalCost;   // Gives the change back needs
	double finalChange = change;     // Created since change variable is being manipulated

	// Calculate the coins and dollars to give back
	dollars = int(change);              change = change - dollars;         
	quarters = (change + 0.005) / 0.25; change = change - (quarters * 0.25);
	dimes = (change + 0.005) / 0.10;    change = change - (dimes * 0.10);
	nickels = (change + 0.005) / 0.05;  change = change - (nickels * 0.05);
	pennies = (change + 0.005) / 0.01;  change = change - (pennies * 0.01);

	// Print out the Change Due and Money given back
	if (finalChange != 0) {                              // If the change isn't 0
		// States final change
		cout << "Change owed is $" << finalChange << " - ";

		// Decides whether the amount is multiple quantities or not and adjusts accordingly
		if (dollars > 1) { cout << dollars << " dollars, "; }
			else if (dollars == 1) { cout << dollars << " dollar, "; }
		if (quarters > 1) { cout << quarters << " quarters, "; }
			else if (quarters == 1) { cout << quarters << " quarter, "; }
		if (dimes > 1) { cout << dimes << " dimes, "; }
			else if (dimes == 1) { cout << dimes << " dime, "; }
		if (nickels > 1) { cout << nickels << " nickels, "; }
			else if (nickels == 1) { cout << nickels << " nickel, "; }
		if (pennies > 1) { cout << pennies << " pennies. "; }
			else if (pennies == 1) { cout << pennies << " penny. "; }

	} else {                                             // If the change is 0
		cout << "Exact payment received - no change owed.";
	}
}