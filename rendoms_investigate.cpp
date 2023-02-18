// Дослідження властивостей ряду випадкових чисел. 
// Мета: дослідити заономірності максимальних та мінімальних згенерованих чисел, середньостатистичних чисел на парних і непарних позлиціях, 
// рівномірність заповнення простору чисел


#include <iostream>
using namespace std;
int main()
{
	srand(time(NULL));

	int const N = 10000;
	int mass[N];
	int index;

	long long sum_evens, sum_odds; // int 
	int n_evens, n_odds;
	int avg_evens, avg_odds, v_min, v_max, dmin, dmax;
	int A, B;
	int choice;
	bool oncemore;
	bool repeat;
	int requests;

	cout << "select mode\n" << "1 - fixed number of times,\n 2 - until average even values will be equal to odd the one" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "enter number of attempts requested" << endl;
		cin >> requests;

	}
	if (choice > 2 || choice < 1)
	{
		repeat = false;
		cout << "the action will be performed only once\n";
	}


	cout << "\n Attempt № \t| min |  max  | avg_evens | avg_odds | dmin | dmax" << endl;
	cout << "_______________________________________________\n";

	do
	{
		A = 0;
		B = 0;
		
		do
		{
			if (choice == 1)
			{
				B++;
				if (B < requests) repeat = true;
				else repeat = false;
			}
			

			A++;
			sum_evens = 0; // int 
			sum_odds = 0;
			n_evens = 0;
			n_odds = 0;


			for (index = 0; index < N; index++)
			{
				mass[index] = rand();
			}


			for (int i = 0; i < N; i++)
			{
				if (i % 2 == 0)
				{
					sum_evens += mass[i];
					n_evens++;
				}
			}

			for (int i = 0; i < N; i++)
			{
				if (i % 2 != 0)
				{
					sum_odds += mass[i];
					n_odds++;
				}

			}


			v_max = mass[0]; v_min = mass[0];


			for (int i = 0; i < N; i++)
			{
				if (mass[i] < v_min)
				{
					v_min = mass[i];

				}
			}

			for (int i = 0; i < N; i++)
			{
				if (mass[i] > v_max)
				{
					v_max = mass[i];
				}
			}



			int temp;
			for (int j = 1; j < N; j++)
			{
				for (int i = 1; i < N; i++)
					if (mass[i - 1] > mass[i])
					{
						temp = mass[i - 1];
						mass[i - 1] = mass[i];
						mass[i] = temp;
					}
			}


			const int D = N - 1;
			int diff[D];

			for (int i = 0; i < D; i++)
				diff[i] = mass[i + 1] - mass[i];



			dmax = diff[0]; dmin = diff[0];

			for (int i = 0; i < D; i++)
			{
				if (diff[i] < dmin)
				{
					dmin = diff[i];
				}
			}

			for (int i = 0; i < D; i++)
			{
				if (diff[i] > dmax)
				{
					dmax = diff[i];
				}
			}

			avg_evens = sum_evens / n_evens;
			avg_odds = sum_odds / n_odds;


			cout << "\t " << A << " \t " << v_min << "\t" << v_max << "\t  " << avg_evens << "\t    " << avg_odds << "\t" << dmin << "\t" << dmax << endl;

			if (choice == 2)
			{
				if (avg_evens != avg_odds) repeat = true;
				else repeat = false;

			}

		} while (repeat);

		
		cout << "once more? 1 -yes, 0 - no" << endl;
		cin >> oncemore;
	}while (oncemore);
}

/* Результати показують, що при генерації великї кількості випадкових числах(N>1000), максимальна величина наближається до 32767,
середня для чисел і на парних і на непарних позиціях наближається до половина максимальної величина, а заповнення простору чисел все більш рівномірним 
*/
