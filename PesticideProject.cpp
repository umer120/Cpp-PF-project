#include <iostream>
#include <fstream>
using namespace std;
const int ROWS = 4;
const int COLS = 6;
void printMenu();
void addEntry(int[][COLS]);
void filledLocations(int[][COLS]);
void deleteValue(int[][COLS]);
void largestOccuringNumbers(int[][COLS]);
void calculateAverage(int[][COLS]);
void fieldHavingMaxSuccessScore(int[][COLS]);
void receiveDataFromFile(int[][COLS], ifstream&);
void results(int[][COLS]);
int main()
{
	int fieldAndLocations[ROWS][COLS];
	ifstream inFile;
	cout << "Receiving Data From File.....\nWaiting....\n";
	receiveDataFromFile(fieldAndLocations, inFile);
	if (!inFile)
	{
		return 0;
	}
	int choice;
	do
	{
		cout << "\t\t********** Menu **********\n";
		printMenu();
		cout << "Enter choice: ";
		cin >> choice;
		if (choice == 1)
		{
			addEntry(fieldAndLocations);
		}
		else if (choice == 2)
		{
			filledLocations(fieldAndLocations);
		}
		else if (choice == 3)
		{
			deleteValue(fieldAndLocations);
		}
		else if (choice == 4)
		{
			largestOccuringNumbers(fieldAndLocations);
		}
		else if (choice == 5)
		{
			calculateAverage(fieldAndLocations);
		}
		else if (choice == 6)
		{
			fieldHavingMaxSuccessScore(fieldAndLocations);
		}
		else if (choice == 0)
		{
			cout << "Ending....\n\tThanks for using our service...\n";
		}
	} while (choice != 0);
	return 0;
}
void receiveDataFromFile(int arr[][COLS],ifstream& inputFile)
{
	inputFile.open("Data.txt");
	if (inputFile.is_open()) 
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				inputFile >> arr[i][j];
			}
		}
		inputFile.close();
		cout << "Data received from file successfully.\n" << endl;
		cout << "The Results we got from File are as follows......\n";
		results(arr);
	}
	else 
	{
		cout << "Unable to open the file to receive data." << endl;
	}
}
void results(int Arr[][COLS])
{
	for (int m = 0; m < ROWS; m++)
	{
		cout << "\t|---------------|---------------|---------------|---------------|---------------|---------------|\n";
		cout << "Field " << m + 1 << " |";
		for (int n = 0; n < COLS; n++)
		{
			cout << "\t" << Arr[m][n] << "\t|";
		}
		cout << endl;
	}
	cout << "\t|---------------|---------------|---------------|---------------|---------------|---------------|\n\n";
}
void printMenu()
{
	cout << "Press 1 to insert new test result.\n";
	cout << "Press 2 to display total number of results in table.\n";
	cout << "Press 3 to delete any test value from table\n";
	cout << "Press 4 to display the 2 most frequent values in table\n";
	cout << "Press 5 to display average scores of each field\n";
	cout << "Press 6 to display field having maximum success score.\n";
	cout << "Press 0 to exit the program.\n";
}
void addEntry(int arr[][COLS])
{
	int field,value;
	do
	{
		cout << "Enter the field in which you want to enter a value: ";
		cin >> field;
		if ((field<1) || (field>4))
		{
			cout << "ERROR!! FIELD DOESN'T EXIST!!\n";
		}
	} while ((field<1) || (field>4));
	do
	{
		cout << "Enter the value you want to enter: ";
		cin >> value;
		if (value < -1)
		{
			cout << "ERROR!! VALUE SHALL BE GREATER OR EQUAL TO -1 BECAUSE -1 MEANS EMPTY LOCATION!!\n";
		}
	} while (value < -1);
	for (int i = 0; i < 6; i++)
	{
		if (arr[field-1][i] == -1)
		{
			arr[field-1][i] = value;
			cout << value << " is entered in field " << field << " at location " << i + 1 << endl << endl;
			return;
		}
	}
	cout << "Field " << field << " is full! No Empty location found!!!\n\n";
}
void filledLocations(int checkArray[][COLS])
{
	int count = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (checkArray[i][j] != -1)
			{
				count++;
			}
		}
	}
	cout << "There are " << count << " score values entered in table.\n\n";
}
void deleteValue(int deleteValueOfArray[][COLS])
{
	int field, loc;
	do
	{
		cout << "Enter the field from which you want to delete a value: ";
		cin >> field;
		if ((field<1) || (field>4))
		{
			cout << "ERROR!! FIELD DOESN'T EXIST!!\n";
		}
	} while ((field<1) || (field>4));
	do
	{
		cout << "Enter the location of the value you want to delete: ";
		cin >> loc;
		if ((loc<1) || (loc>6))
		{
			cout << "ERROR!! LOCATION RANGES FROM 1 TO 6 !!\n";
		}
	} while ((loc<1) || (loc>6));
	if (deleteValueOfArray[field - 1][loc - 1] == -1) 
	{
		cout << "No value found at location " << loc << " in field " << field << endl << endl;
	}
	else 
	{
		deleteValueOfArray[field - 1][loc - 1] = -1;
		cout << "Value at location " << loc << " in field " << field << " is deleted" << endl << endl;
	}
}
void largestOccuringNumbers(int arr[][COLS])
{
	int max1 = -1, max2 = -1;
	int max1Count = 0, max2Count = 0;
	for (int i = 0; i < ROWS; ++i) 
	{
		for (int j = 0; j < COLS; ++j) 
		{
			if (arr[i][j] != -1) 
			{
				int count = 1;  
				for (int k = i; k < ROWS; ++k) 
				{
					for (int l = (k == i) ? j + 1 : 0; l < COLS; ++l) 
					{
						if (arr[k][l] == arr[i][j]) 
						{
							count++;
						}
					}
				}
				if (count > max1Count) 
				{
					max2 = max1;
					max2Count = max1Count;
					max1 = arr[i][j];
					max1Count = count;
				}
				else if (count > max2Count && arr[i][j] != max1) 
				{
					max2 = arr[i][j];
					max2Count = count;
				}
			}
		}
	}
	cout << "The top two most frequent values are: " << max1 << " and " << max2 << endl;
	cout << "The first value occurs " << max1Count << " times." << endl;
	cout << "The second value occurs " << max2Count << " times." << endl << endl;
}
void calculateAverage(int Average[][COLS])
{
	for (int a = 0; a < ROWS; a++)
	{
		double sumOfLoc = 0;
		double counter = 0;
		for (int b = 0; b < COLS; b++)
		{
			if (Average[a][b] != -1)
			{
				sumOfLoc += Average[a][b];
				counter++;
			}
		}
		if (counter == 0)
		{
			cout << "Field" << a + 1 << " average: empty field\n";
		}
		else
		{
			double average = sumOfLoc / counter;
			cout << "Field" << a + 1 << " average: " << average << endl;
		}
	}
}
void fieldHavingMaxSuccessScore(int arr[][COLS])
{
	int maxScore = 0;
	int maxField = -1;
	for (int y = 0; y < ROWS; y++) 
	{
		int fieldMax = -1;
		for (int z = 0; z < COLS; z++) 
		{
			int score = arr[y][z];
			if (score > fieldMax) 
			{
				fieldMax = score;
			}
		}
		if (fieldMax > maxScore) 
		{
			maxScore = fieldMax;
			maxField = y + 1;
		}
	}
	if (maxField == -1) 
	{
		cout << "No field has success scores." << endl << endl;
	}
	else 
	{
		cout << "Field" << maxField << " has the maximum success score." << endl << endl;
	}
}
