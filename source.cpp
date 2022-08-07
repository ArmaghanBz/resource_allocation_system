#include<string>
#include <stdio.h>
#include<iostream>
using namespace std;
class System {
public:
	int totalProjects;
	int NoOfResources;
	/*int allocated[5][3];
	int maxneed[5][3];
	int available[3];*/
	void bankers_algo()
	{
		cout << "\n\n\t\t\tHere\n\t\t\t R1 --> C++ \n\t\t\t R2 --> java \n\t\t\t R3 --> python \n\n";
			/*cout << "\tEnter Allocated Project Resources\n\n";
			for (int i = 0; i < 5; i++)
			{
				cout << "\t\tFor project : " << i + 1 << endl;
				for (int j = 0; j < 3; j++)
				{
					cout << "\n\t\t\tNumber of Resource R" << j + 1 << ":";
					cin >> allocated[i][j];
				}
			}
			cout << "\tEnter Maximum Need of Resources\n\n";
			for (int i = 0; i < 5; i++)
			{
				cout << "\t\tFor project : " << i + 1 << endl;
				for (int j = 0; j < 3; j++)
				{
					cout << "\n\t\t\tNumber of Resource R" << j + 1 << ":";
					cin >> maxneed[i][j];
				}
			}
			cout << "\tEnter available number of Resources \n\n";
			for (int i = 0; i < 3; i++)
			{
				cout << "\t\t\tFor R" << i + 1 << ":";
				cin >> available[i];
			}*/
		int allocated[5][3] = { { 0,1,0 }, { 2, 0, 0 },{ 3, 0, 2 } ,{ 2, 1, 1 }, { 0 , 0 , 2 } };
		int maxneed[5][3] = { { 7, 5, 3 },{ 3, 2, 2 }, { 9, 0, 2 } ,{ 4, 2, 2 },{5,3,3} };
		int available[3] = { 3, 3, 2 };
		int f[5];
		int ans[5];
		int ind = 0;
		for (int k = 0; k < 5; k++)
		{
			f[k] = 0;
		}
		int need[5][3];
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 3; j++)
				need[i][j] = maxneed[i][j] - allocated[i][j];
		}
		int y = 0;
		for (int k = 0; k < 5; k++)
		{
			for (int i = 0; i < 5; i++)
			{
				if (f[i] == 0)
				{
					int flag = 0;
					for (int j = 0; j < 3; j++)
					{
						if (need[i][j] > available[j])
						{
							flag = 1;
							break;
						}
					}
					if (flag == 0)
					{
						ans[ind++] = i;
						for (y = 0; y < 3; y++)
							available[y] += allocated[i][y];
						f[i] = 1;
					}
				}
			}
		}
		int flag = 1;
	deadlock:
		if (flag == 0)
		{
			printf("\n\n\t\t\tThis system is not safe");
			exit(1);
		}
		/*for (int i = 0; i < 5; i++)
		{
			if (f[i] == 0)
			{
				flag = 0;
				printf("\n\n\t\t\tThis system is not safe");
				break;
			}
		}*/
		cout << "\n\t\tAllocated Resources" << "\n";
		cout << "		R1		R2		R3\n";
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (allocated[i][j] < 0)
				{
					flag = 0;
					goto deadlock;
				}
				cout << "		" << allocated[i][j];
				if (j == 2)
					cout << endl;
			}
		}
		cout << "\n\t\tMaxneed" << "\n";
		cout << "		R1		R2		R3\n";
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (maxneed[i][j] < 0)
				{
					flag = 0;
					goto deadlock;
				}
				cout << "		" << maxneed[i][j];
				if (j == 2)
					cout << endl;
			}
		}
		cout << "\n\t\tRemaining Resources" << "\n";
		cout << "		R1		R2		R3\n";
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (need[i][j] < 0)
				{
					flag = 0;
					goto deadlock;
				}
				cout << "		" << need[i][j];
				if (j == 2)
					cout << "\n";
			}
		}
		if (flag == 1)
		{
			printf("\n\n\t\t\tThis System is SAFE\n");
			for (int i = 0; i < 5 - 1; i++)
				printf("\n\t\t\tProject P%d is completed \n", ans[i]);
			printf("\n\t\t\tProject P%d is completed\n", ans[5 - 1]);
		}
	}
	void loginFun()
	{
		int login;
		string username, password;
	main:
		cout << "\n\n\t\t\t\t\t**********************************\n\n";
		cout << "\t\t\t\t\tProject Resources Allocated System";
		cout << "\n\n\t\t\t\t\t**********************************\n\n";
		cout << "\n\t\t\t1)Press 1 for login\n";
		cout << "\n\t\t\t2)Press 2 to exit\n";
		cout << "\n\t\t\t Your input : ";
		cin >> login;
		system("cls");
		if (login == 1)
			goto login;
		else if (login == 2)
			goto exit;
		system("cls");
		cout << "\n\n\t\t\tError!!\n\n\n";
		goto main;
	login:
		cout << "\n\n\t\t\t\t\t********************\n\n";
		cout << "\t\t\t\t\t\tLOGIN\n";
		cout << "\n\t\t\t\t\t********************\n\n\n";
		cout << "\t\t\t\tUser name : ";
		cin >> username;
		cout << "\n\n\t\t\t\tEnter Password : ";
		cin >> password;
		system("cls");
		if (username == "Ali" && password == "123")
		{
			bankers_algo();
		}
		else
		{
			system("CLS");
			cout << "\n\n\t\t\t\Try again!!\n\n";
			goto login;
		}
	exit:
		cout << "System is exit";
	}
};
int main()
{
	System obj;
	obj.loginFun();
	system("pause");
	return (0);
}
