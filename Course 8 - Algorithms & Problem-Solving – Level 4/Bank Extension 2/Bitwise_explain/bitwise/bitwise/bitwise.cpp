#include<iostream>
#include<bitset>

using namespace std;

// Global Variables
// Each permission is represented by one bit.

short Read = 1;    // 0 0 0 1
short Write = 2;   // 0 0 1 0
short Delete = 4;  // 0 1 0 0
short Execute = 8; // 1 0 0 0

struct stUser {
	string Name;
	string Password;
	short Permissions;
};

void PrintPermission(stUser User1)
{
	if ((User1.Permissions & Read) == Read)
	{
		// Example: After the user answers all questions,
		// let's assume that User.Permissions = 11 (1011 in binary).
		// User.Permissions = 11 -> 1011
		// Read             = 1  -> 0001
		// 1011
		// 0001
		// ----
		// 0001
		// Since the result is equal to Read,
		// the user has Read permission.                                         

		cout << "\nUser Can Read\n";
	}

	if ((User1.Permissions & Write) == Write)
	{
		cout << "\nUser Can Write\n";
	}

	if ((User1.Permissions & Delete) == Delete)
	{
		cout << "\nUser Can Delete\n";
	}

	if ((User1.Permissions & Execute) == Execute)
	{
		cout << "\nUser Can Execute\n";
	}
}

void ReadUserPermission(stUser& User1) // User1.Permissions = 0
{
	char Answer = 'n';

	cout << "Do You Want To Read?\n";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		// If the user chooses Y:
		// Current Permissions = 0000
		// Read                = 0001
		// 0000
		//   |
		// 0001
		// ----
		// 0001
		// The user now has Read permission.
		User1.Permissions = User1.Permissions | Read;
	}

	cout << "\nCurrent Number In Decimal: " << User1.Permissions << endl;
	// bitset<4> displays the value using 4 bits.
	cout << "\nCurrent Number In Binary: " << bitset<4>(User1.Permissions) << endl;

	cout << "\nDo You Want To Write?\n";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		// If the user chooses Y:
		// Current Permissions = 0001
		// Write               = 0010
		//
		// 0001
		//   |
		// 0010
		// ----
		// 0011
		//
		// The user now has Write and Read permissions.
		User1.Permissions = User1.Permissions | Write;
	}

	cout << "\nCurrent Number In Decimal: " << User1.Permissions << endl;
	cout << "\nCurrent Number In Binary: " << bitset<4>(User1.Permissions) << endl;

	cout << "\nDo You Want To Delete?\n";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		User1.Permissions = User1.Permissions | Delete;
	}

	cout << "\nCurrent Number In Decimal: " << User1.Permissions << endl;
	cout << "\nCurrent Number In Binary: " << bitset<4>(User1.Permissions) << endl;

	cout << "\nDo You Want To Execute?\n";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		User1.Permissions = User1.Permissions | Execute;
	}

	cout << "\nCurrent Number In Decimal: " << User1.Permissions << endl;
	cout << "\nCurrent Number In Binary: " << bitset<4>(User1.Permissions) << endl;

	// Summary:
	// Each bit represents a specific permission.
	// If the bit is 1, the user has that permission.
	// If the bit is 0, the user does not have that permission.
}

int main()
{
	stUser User1;
	User1.Name = "Jehad Mahmoud";
	User1.Password = "1221";
	User1.Permissions = 0;

	ReadUserPermission(User1);
	PrintPermission(User1);

	return 0;
}