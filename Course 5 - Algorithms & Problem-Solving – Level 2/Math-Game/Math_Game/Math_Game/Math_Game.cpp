#include <iostream>
#include <ctime>
#include<cstdlib>

using namespace std;

enum enQuestionLevel { EasyLevel = 1, MidLevel = 2, HardLevel = 3, MixLevel = 4 };
enum enOperationType { Addition = 1, Substraction = 2, Multiplication = 3, Division = 4, MixOp = 5 };

struct stQuestion {

	int Number1=0;
	int Number2=0;
	enOperationType OpType;
	enQuestionLevel QuesstionLevel;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;

};

struct stQuiz
{
	stQuestion QuestionList[100];
	short NumberOfQuestion;
	short NumberOfWrongAnswers = 0;
	short NumberOfRightAnswers = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OpType;
	bool IsPass = false;

};

int RandomNumber(int From , int To)
{
	return rand() % (To - From + 1) + From;
}

short ReadHowManyQuestions()
{
	short NumberOfQuestion = 0;
	do {
		cout << endl << " How Many Questions Do You Want To Answer?\n";
		cin >> NumberOfQuestion;

	} while (NumberOfQuestion < 0 || NumberOfQuestion>10);

	return NumberOfQuestion;
}

int SimpleCalculater(int Number1, int Number2, enOperationType OperationType)
{
	switch (OperationType)
	{
	case enOperationType::Addition:
		return Number1 + Number2;
	case enOperationType::Substraction:
		return Number1 - Number2;
	case enOperationType::Multiplication:
		return Number1 * Number2;
	case enOperationType::Division:
		return (Number2 != 0) ? (Number1 / Number2) : 0;
	default:
		return Number1 + Number2;
	}

}

enQuestionLevel ReadQuestionsLevel()
{
	short QuestionLevel = 0;
	do {
		cout << endl << " Enter Questions Level : [1]Easy , [2]Mid , [3]Hard , [4]Mix\n";
		cin >> QuestionLevel;
	} while (QuestionLevel < 1 || QuestionLevel > 4);

	return (enQuestionLevel)QuestionLevel;

}

enOperationType ReadOpType()
{
	short OpType = 0;
	do {
		cout << endl << " Enter Operation Type : [1]Addition , [2]Substraction , [3]Multiplication , [4]Division , [5]Mix \n";
		cin >> OpType;
	} while (OpType < 1 || OpType > 5);

	return (enOperationType)OpType;
}

enOperationType GetOperationType()
{
	int Op = RandomNumber(1, 4);
	return (enOperationType)Op;
}

stQuestion GenerateQuestions(enQuestionLevel  QuestionLevel, enOperationType OpType)
{
	stQuestion Questions;

	if (QuestionLevel == enQuestionLevel::MixLevel)
	{
		QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
	}

	if (OpType == enOperationType::MixOp)
	{
		OpType = GetOperationType();
	}

	Questions.OpType = OpType;

	switch (QuestionLevel)
	{
	case enQuestionLevel::EasyLevel:

		Questions.Number1 = RandomNumber(1, 10);
		Questions.Number2 = RandomNumber(1, 10);
		Questions.CorrectAnswer = SimpleCalculater(Questions.Number1, Questions.Number2, Questions.OpType);
		Questions.QuesstionLevel = QuestionLevel;
		return Questions;

	case enQuestionLevel::MidLevel:

		Questions.Number1 = RandomNumber(10, 50);
		Questions.Number2 = RandomNumber(10, 50);
		Questions.CorrectAnswer = SimpleCalculater(Questions.Number1, Questions.Number2, Questions.OpType);
		Questions.QuesstionLevel = QuestionLevel;
		return Questions;

	case enQuestionLevel::HardLevel:

		Questions.Number1 = RandomNumber(50, 100);
		Questions.Number2 = RandomNumber(50, 100);
		Questions.CorrectAnswer = SimpleCalculater(Questions.Number1, Questions.Number2, Questions.OpType);
		Questions.QuesstionLevel = QuestionLevel;
		return Questions;

	}

	return Questions;

}

void GenerateQuizQuestions(stQuiz& Quiz)
{
	for (short Questions = 0; Questions < Quiz.NumberOfQuestion; Questions++)
	{
		Quiz.QuestionList[Questions] = GenerateQuestions(Quiz.QuestionLevel, Quiz.OpType);
	}

}

string GetOpTypeSympol(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Addition:
		return " + ";
	case enOperationType::Substraction:
		return " - ";
	case enOperationType::Multiplication:
		return " * ";
	case enOperationType::Division:
		return " / ";
	default:
		return " Mix ";

	}
}

void PrintTheQuestion(stQuiz& Quiz, short QuestionNumber)
{
	cout << "\n";
	cout << " Question [ " << QuestionNumber + 1 << " / " << Quiz.NumberOfQuestion << " ]\n\n";
	cout << Quiz.QuestionList[QuestionNumber].Number1 << endl;
	cout << Quiz.QuestionList[QuestionNumber].Number2 << endl;
	cout << GetOpTypeSympol(Quiz.QuestionList[QuestionNumber].OpType)<< endl;
	cout << "\n ____________ " << endl;

}

int ReadPlayerAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;

}

void SetColorScreen(bool Right)
{
	if (Right)
	{
		system("color 2f");
	}
	else
	{
		cout << "\a";
		system("color 4f");
	}
}

void CorrectTheQuestionAnswer(stQuiz& Quiz, short QuestionNumber)
{
	if (Quiz.QuestionList[QuestionNumber].PlayerAnswer != Quiz.QuestionList[QuestionNumber].CorrectAnswer)
	{
		Quiz.QuestionList[QuestionNumber].AnswerResult = false;
		Quiz.NumberOfWrongAnswers++;
		cout << " \n WRONG ANSWER =( \n";
		cout << " The Right Answer Is : ";
		cout << Quiz.QuestionList[QuestionNumber].CorrectAnswer;

	}
	else {

		Quiz.QuestionList[QuestionNumber].AnswerResult = true;
		Quiz.NumberOfRightAnswers++;
		cout << " \n RIGHT ANSWER =) \n";
	}

	cout << endl;
	SetColorScreen(Quiz.QuestionList[QuestionNumber].AnswerResult);

}

void AskAndCorrectQuestionsListAnswer(stQuiz& Quiz)
{
	for (short QuestionNumber = 0 ; QuestionNumber < Quiz.NumberOfQuestion; QuestionNumber++)
	{
		PrintTheQuestion(Quiz, QuestionNumber);
		Quiz.QuestionList[QuestionNumber].PlayerAnswer = ReadPlayerAnswer();
		CorrectTheQuestionAnswer(Quiz, QuestionNumber);
	}

	Quiz.IsPass = Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAnswers;


}

string GetFinalResultsText(bool Right)
{
	if (Right)
	{
		return "\n PASS =) \n";
	}
	else 
	{
		return "\n FAIL =( \n";
	}

}

string GetQuestionLevelText(enQuestionLevel QuestionLevel)
{
	string ArrQuestionLevelText[4] = { " Easy " , " Mid " , " Hard " , " Mix " };
	return ArrQuestionLevelText[QuestionLevel-1];
}

void PrintQuizResults(stQuiz& Quiz)
{
	cout << "\n";
	cout << "____________________________\n\n";
	cout << " Final Results is " << GetFinalResultsText(Quiz.IsPass);
	cout << "\n_________________________________\n\n";

	cout << "Number Of Questions: " << Quiz.NumberOfQuestion << endl;
	cout << "Question Level     : " << GetQuestionLevelText(Quiz.QuestionLevel) << endl;
	cout << "OpType             : " << GetOpTypeSympol(Quiz.OpType) << endl;
	cout << "Number Of Right Answers : " << Quiz.NumberOfRightAnswers << endl;
	cout << "Number Of Wrong Answers : " << Quiz.NumberOfWrongAnswers << endl;
	cout << "___________________________________\n";


}

void PlayMathQuizGame()
{
	stQuiz Quiz;
	Quiz.NumberOfQuestion = ReadHowManyQuestions();
	Quiz.QuestionLevel = ReadQuestionsLevel();
	Quiz.OpType = ReadOpType();

	GenerateQuizQuestions(Quiz);
	AskAndCorrectQuestionsListAnswer(Quiz);
	PrintQuizResults(Quiz);

}

void ResetScreen()
{
	system("cls");
	system("color 0f");
}

void StartQuiz()
{
	char PlayAgain = 'Y';
	do {

		ResetScreen();
		PlayMathQuizGame();
		cout << endl << "Do You Want To Play Again? Y/N \n";
		cin >> PlayAgain;

	} while (PlayAgain == 'y' || PlayAgain == 'Y');

}

int main()
{
	srand((unsigned)time(NULL));

	StartQuiz();

	return 0;

}


