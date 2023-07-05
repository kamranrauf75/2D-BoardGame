#include <iostream>
using namespace std;

void inputBoard(int** arr, int rows, int cols)
{

 cout << "Enter " << rows << " rows of " 
         << cols << " integers each:\n";

	for (int i = 0; i < rows; i++)	 
	{
		cout << "\n\tRow " << i + 1 << endl;
		for (int j = 0; j < cols; j++)
		{
		cout << "\n\tColumn " << j + 1 << endl;

		if ((i == 0 && j == 0))
			{
				arr[i][j] = 1;
				cout<<"First block already alloted"<<endl;
			}

		else
			{

			cin >> arr[i][j];
			
			}

		}
		cout << endl;
	}

}


void findPossibility(int** arr, int rows, int columns)
{
	for (int i = 0; i < rows; i++) // Printing the 2D Array
	{
		cout << endl;
		for (int j = 0; j < columns; j++)
		{
			cout << arr[i][j] << " ";
		}
	}

	arr[0][0] = 5;
	
	for (int i = 0; i < rows; i++) // Finding the Path
	{
		for (int j = 0; j < columns; j++)
		{
			if (arr[i][j] == 5 && i + 1 < rows && arr[i + 1][j] == 1 )
			{
				arr[i + 1][j] = 5;
			}
			if (arr[i][j] == 5 && j + 1 < columns  && arr[i][j + 1] == 1 )
			{
				arr[i][j + 1] = 5;
			}
		}
	}
	

	cout << endl << endl;
	
	if (arr[rows - 1][columns - 1] == 5)
	{
		cout << "Output : True" << endl;
	}
	else
	{
		cout << "Output : False" << endl;
	}

}

int main()
{
int** array = NULL; // Declaing a 2D Pointer of Integer Data Type 
	int rows = 0;
	int cols = 0;

	cout << "Enter rows: "; // Prompting User for Input
	cin >> rows;
	cout << endl << "Enter columns: "; // Prompting User for Input
	cin >> cols;

	array = new int* [rows]; 
	for (int i = 0; i < rows; i++)
	{
		array[i] = new int[cols];
	}

	inputBoard(array, rows, cols); // Calling the InputBoard Function
	findPossibility(array, rows, cols); // Calling the findPossiblity Function

	delete[] array; // Deleting the 2D Array

	return 0;
}

