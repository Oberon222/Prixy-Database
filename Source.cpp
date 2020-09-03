#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;

class Database
{
protected:
	string connectionString = "database.txt";
	bool isConnect = false;

	bool IsConnectedImmitatingConnectivitiyIssues()
	{
		return (rand() % 10 < 6);
	}
	
public:

	virtual bool Connect(string userConnectionString)
	{
		srand(time(0));

		if (userConnectionString == connectionString)
		{
			isConnect = IsConnectedImmitatingConnectivitiyIssues();
		}

		else
			return isConnect;
	}


	virtual void Log(string msg)
	{
		ofstream fout;
		fout.open(connectionString, fstream::app);
		bool isOpen = fout.is_open();
		if (!isOpen) cout << "Error!" << endl;

		fout << msg << endl;
		fout.close();
	}
};


class DatabaseProxy : public Database
{

public:

	void Log(string msg) override
	{
		if (!Connect(connectionString))
		{
			connectionString = "localTempDatabase.txt";
			
		}

		else
		{
			connectionString = "database.txt";
			ifstream fin;
			fin.open("localTempDatabase.txt");
			while (!fin.eof())
			{
				string tmp;
				getline(fin, tmp);

			}
			fin.close();
		}

		ofstream fout(connectionString, fstream::app);
		fout << " data i chas :)" << msg << endl;
		fout.close();
	}
};



int main()
{
	srand(time(0));
	DatabaseProxy dp;
	dp.Log("Some text");


	system("pause");
	return 0;
}