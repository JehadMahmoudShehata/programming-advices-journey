#include <iostream>
#include "clsLoginScreen.h"

using namespace std;

int main()
{

	while (true)
	{
		CurrentUser.ClearObject();
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}

	}

	system("pause>0");
	return 0;

}


