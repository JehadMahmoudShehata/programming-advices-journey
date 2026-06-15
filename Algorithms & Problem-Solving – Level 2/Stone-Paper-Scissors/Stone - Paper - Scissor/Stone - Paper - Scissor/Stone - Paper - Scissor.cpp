#include <iostream>
#include <cstdlib>
#include<ctime>

using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissor = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

int RandomNumber(int From , int To)
{
	return rand() % (To - From + 1) + From;
}

string WinnerName(enWinner Winner)
{
	string ArrWinnerName[3] = { "Player1" , "Computer","No Winner" };
	return ArrWinnerName[Winner - 1];
}

struct stRoundsInfo {

	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName ="";

};

struct stGameResult {

	short GameRounds = 0;
	short Player1WinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner Winner;
	string WinnerName="";

};

enGameChoice ReadPlayer1Choice()
{
	short Player1Choice = 0;
	do {
		cout << "\nYour Choice: [1]Stone , [2]Paper , [3]Scissor?\n";
		cin >> Player1Choice;

	} while (Player1Choice < 1 || Player1Choice > 3);

	return (enGameChoice)Player1Choice;
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

enWinner WhoWonTheRound(stRoundsInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;

		}
		break;
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissor)
		{
			return enWinner::Computer;
		}
		break;
	case enGameChoice::Scissor:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			return enWinner::Computer;

		}
		break;
	}

	return enWinner::Player1;

}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	if (Player1WinTimes < ComputerWinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
	
}

string ChoiceName(enGameChoice Choice)
{
	string ArrChoiceName[3] = { "Stone" , "Paper" , "Scissor" };
	return ArrChoiceName[Choice - 1];

}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2f");
		break;
	case enWinner::Computer:
		system("color 4f");
		cout << "\a";
		break;
	default:
		system("color 6f");
	}
}

void PrintRoundResult(stRoundsInfo RoundInfo)
{
	cout << "\n _____________________ Round[" << RoundInfo.RoundNumber << "]  _____________________ \n\n";
	cout << "Player1 Choice : " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner : " << RoundInfo.WinnerName << endl;
	cout << "_____________________________________\n\n";

	SetWinnerScreenColor(RoundInfo.Winner);
}

stGameResult FillGameResult(short HowManyRounds , short Player1WinTimes , short ComputerWinTimes , short DrawTimes)
{
	stGameResult GameResult;

	GameResult.GameRounds = HowManyRounds;
	GameResult.Player1WinTimes = Player1WinTimes;
	GameResult.ComputerWinTimes = ComputerWinTimes;
	GameResult.DrawTimes = DrawTimes;
	GameResult.Winner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
	GameResult.WinnerName = WinnerName(GameResult.Winner);

	return GameResult;

}

stGameResult PlayGame(short HowManyRounds)
{
	stRoundsInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\n\n Round[" << GameRound << "] begins : \n\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player1)
			Player1WinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;

		PrintRoundResult(RoundInfo);
	}

	return FillGameResult(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOfTabs)
{
	string Tab = "";
	for (short i = 1; i < NumberOfTabs; i++)
	{
		Tab = Tab+'\t';
		cout << Tab;
	}
	return Tab;
}

short ReadHowManyRounds()
{
	short GameRound = 1;
	do {
		cout << "\nHow Many Rounds 1 to 10?\n";
		cin >> GameRound;

	} while (GameRound < 1 || GameRound > 10);

	return GameRound;
}

void Resetscreen()
{
	system("cls");
	system("color 0F");
}

void ShowGameOverScreen()
{
	cout << Tabs(2) << "______________________________________\n\n";
	cout << Tabs(2) << "     ++++++ Game Over ++++++\n\n";
	cout << Tabs(2) << "______________________________________\n\n";

}

void ShowGameFinalResults(stGameResult GameResults)
{
	cout << Tabs(2) << "___________________[Game Results]______________________\n\n";
	cout << Tabs(2) << "Game Rounds     : " << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player1 Won Times       : " << GameResults.Player1WinTimes << endl;
	cout << Tabs(2) << "Computer Won Times      : " << GameResults.ComputerWinTimes << endl;
	cout << Tabs(2) << "DrawTimes      : " << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner    : " << GameResults.WinnerName << endl;
	cout << Tabs(2) << "_________________________________________________________\n\n";
	SetWinnerScreenColor(GameResults.Winner);
}

void StartGame()
{
	char PlayAgain = 'Y';

	do {

		Resetscreen();
		stGameResult GameResult = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowGameFinalResults(GameResult);

		cout << endl << Tabs(3) << "Do You Want To Play Again ? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;

}

