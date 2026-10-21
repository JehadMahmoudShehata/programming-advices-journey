#pragma once
#include <iostream>
#include<queue>
#include<stack>

using namespace std;

class clsQueueLine
{
private:

	struct stTime {

		time_t t = time(0);
		int _Hour = localtime(&t)->tm_hour;
		int _min = localtime(&t)->tm_min;
		int _sec = localtime(&t)->tm_sec;

	};

	struct stDate
	{
		time_t t = time(0);
		short _Day = localtime(&t)->tm_mday;
		short _Month = localtime(&t)->tm_mon;
		short _Year = localtime(&t)->tm_year + 1900;
	};
	
	int _Duration = 0;
	
	struct _stQueueInfo
	{
		string _Prefix = "";
		int _TotalTickts = 0;
		int _ServedClients = 0;
		int _WaitingClients = 0;
	};

	_stQueueInfo _QueueInfo;

	struct _stTicketInfo
	{
		stTime _Time;
		stDate _Date;
		string _Prefix = "";
		int _NumberOfTickt = 0;
		int _WaitingClients = 0;
		int _servedTime = 0;
	};

	_stTicketInfo _Ticket;

	queue<_stTicketInfo>_QueueLine;


public:

	clsQueueLine(const string &Prefix, const int &Duration)
	{
		_QueueInfo._Prefix = Prefix;
        _Duration = Duration;
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t\t\t------------------------------\n";
		cout << "\t\t\t\t\t\tQueue Info";
		cout << "\n\t\t\t\t\t------------------------------\n\n";
		cout << "\t\t\t\t\tPrefix     = " << _QueueInfo._Prefix << "\n";
		cout << "\t\t\t\t\tTotal Tickets   = " << _QueueInfo._TotalTickts << "\n";
		cout << "\t\t\t\t\tServed Clients  = " << _QueueInfo._ServedClients << "\n";
		cout << "\t\t\t\t\tWaiting Clients = " << _QueueInfo._WaitingClients << "\n";
		cout << "\n\t\t\t\t\t------------------------------\n";

	}

	void IssueTicket()
	{
		_QueueInfo._TotalTickts++;
		_QueueInfo._WaitingClients++;

		_Ticket._Prefix = _QueueInfo._Prefix;
		_Ticket._NumberOfTickt = _QueueInfo._TotalTickts;


		_Ticket._WaitingClients = _QueueLine.size();
		_Ticket._servedTime = _Ticket._WaitingClients * _Duration;
		_QueueLine.push(_Ticket);

	}

	void PrintTicketsLineRTL()
	{
		if (_QueueLine.size() == 0)
		{
			return;
		}

		queue< _stTicketInfo>Temp = _QueueLine;
		_stTicketInfo Ticket;

		cout << "\t\t\t\tTickets: ";

		for (int i = 0; i < _QueueLine.size(); i++)
		{
			Ticket = Temp.front();
			cout << Ticket._Prefix << Ticket._NumberOfTickt << " <-- ";
			Temp.pop();
		}
		cout << "\n";
	}

	void PrintTicketsLineLTR()
	{
		if (_QueueLine.size() == 0)
		{
			return;
		}

		queue< _stTicketInfo>Temp = _QueueLine;
		stack<_stTicketInfo>TempStack;
		_stTicketInfo Ticket;

		cout << "\t\t\t\tTickets: ";

		while (!Temp.empty())
		{
		    Ticket = Temp.front();
			TempStack.push(Ticket);
			Temp.pop();
		}

		while (!TempStack.empty())
		{
			Ticket = TempStack.top();
			cout << Ticket._Prefix << Ticket._NumberOfTickt << " --> ";
			TempStack.pop();
		}
	
		cout << "\n";

	}

	void PrintAllTickets()
	{
		queue< _stTicketInfo>Temp = _QueueLine;

		cout << "\n\n\t\t\t\t\t\t---Tickets---";
		cout << "\n\t\t\t\t\t------------------------------\n";

		for (int i = 0; i < _QueueLine.size(); i++)
		{
			_stTicketInfo Ticket = Temp.front();
			cout << "\t\t\t\t\t\t      " << Ticket._Prefix << Ticket._NumberOfTickt << "\n";

			cout << "\n\t\t\t\t\t      " << Ticket._Date._Day << "/" << Ticket._Date._Month << "/" << Ticket._Date._Year << " - "
				<< Ticket._Time._Hour << ":" << Ticket._Time._min << ":" << Ticket._Time._sec << "\n";
			cout << "\t\t\t\t\t      Waiting Clients = " << Ticket._WaitingClients << "\n";
			cout << "\t\t\t\t\t        Serve Time In  " << "\n";
			cout << "\t\t\t\t\t\t  " << Ticket._servedTime << " Minutes.";
			cout << "\n\t\t\t\t\t------------------------------\n\n";
			cout << "\n\t\t\t\t\t------------------------------\n\n";

			Temp.pop();

		}
		cout << "\n";

	}

	void ServeNextClient()
	{
		_QueueInfo._ServedClients++;
		_QueueInfo._WaitingClients--;
		_QueueLine.pop();
	}




};

