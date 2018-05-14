#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>

using namespace std;
ofstream fout("output.txt");

int main()
{
	setlocale(LC_ALL, "Russian");

	class Field
	{
	private:
		vector <vector <char> > field;
	public:
		Field()
		{
			for (int i = 0; i < 8; i++)
				field.push_back(vector <char>(8, '-'));
		}
		void queens()
		{
			int k = 0;
			for (int q1 = 0; q1 < 64; q1++)
			{
				for (int q2 = q1+1; q2 < 64; q2++)
				{
					for (int q3 = q2+1; q3 < 64; q3++)
					{
						for (int q4 = q3+1; q4 < 64; q4++)
						{
							for (int q5 = q4+1; q5 < 64; q5++)
							{
								clear();
								field[q1/8][q1%8] = 'Q';
								field[q2/8][q2%8] = 'Q';
								field[q3/8][q3%8] = 'Q';
								field[q4/8][q4%8] = 'Q';
								field[q5/8][q5%8] = 'Q';
								attack();
								if (check())
								{
									fout << ++k << ")\n";
									print();
								}
							}
						}
					}
				}
			}
		}
		void clear()
		{
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++)
					field[i][j] = '-';
		}
		void print()
		{
			fout << "---------------------------------" << endl;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
					if (field[i][j] != '*')
						fout << "| " << field[i][j] << ' ';
					else
						fout << "|   ";
				fout << '|' << endl << "---------------------------------" << endl;
			}
			fout << endl;
		}
		void attack()
		{
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++)
					if (field[i][j] == 'Q')
					{
						for (int z = 0; z < 8; z++)
						{
							if (field[z][j] == '-')
								field[z][j] = '*';
						}
						for (int z = 0; z < 8; z++)
						{
							if (field[i][z] == '-')
								field[i][z] = '*';
						}
						int qX = j;
						int qY = i;

						while (qX != 0 && qY != 0)
						{
							qX--;
							qY--;
						}
						while (qX != 8 && qY != 8)
						{
							if (field[qY][qX] == '-')
								field[qY][qX] = '*';
							qX++;
							qY++;
						}

						qX = j;
						qY = i;

						while (qX != 7 && qY != 0)
						{
							qX++;
							qY--;
						}
						while (qX != -1 && qY != 8)
						{
							if (field[qY][qX] == '-')
								field[qY][qX] = '*';
							qX--;
							qY++;
						}
					}

		}
		bool check()
		{
			for (int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++)
					if (field[i][j] == '-')
						return false;
			return true;
		}
	};
	Field a;
	a.queens();
	cout << endl << "Done";
	fout.close();

	_getch();
	return 0;
}
