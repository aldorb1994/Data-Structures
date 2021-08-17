//Author: Aldo Ramirez Boldo, Patrick Schneider
//Serial number: 051, 059
//Due Date: September 25th, 2019
//Programming Assignment Number 2
//Fall 2019 - CS 3358 - 001
//
//Instructor: Husain Gholoom.
//
// This Program is designed to build a matrix, adds every row, column, and
//diagonal, and checks to see if every side adds up to the same number.

#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>


using namespace std;

//*****************************************************************
// This function generates the random numbers and outputs
// a 2 dimensional vector array.
//
// matrix 2d vector array of random numbers
// matrixSize size desired by user
//*******************************************************************
void matrixGenerator(vector< vector<int> > &matrix , int matrixSize)
{
    
    for(int i=0;i < matrixSize ;i++)
    {
        for(int j = 0;j < matrixSize; j++)
        {
            matrix[i][j] = rand() % (1 - ((matrixSize*matrixSize)));
        }
    }
    
    for(int i = 0;i < matrixSize;i++)
    {
        for(int j=0;j< matrixSize; j++)
        {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }

}

//*****************************************************************
// This function adds all the rows, columns, and diagonal numbers;
// then outputs each addition.
//
// matrix 2d vector array of random numbers
// matrixSize size desired by user
//*******************************************************************
void totalSums(vector< vector<int> > &matrix , int matrixSize)
{
    int diagonalSum1 = 0; // right side diagonal addition
    int diagonalSum2 = 0; // left side diagonal addition
    int rowSum = 0; // every row addition
    int columnSum = 0; // every column addition
    
    
    for (int i = 0; i < matrixSize; i++)
    {
        for ( int j = 0; j < matrixSize; j++)
        {
            rowSum += matrix[i][j];
        }
        cout << "Sum of numbers in Row \t#" << i + 1<< " =\t" << rowSum << endl;
        rowSum = 0;
    }
    
    cout << endl << endl;
    
    for (int i = 0; i < matrixSize; i++)
    {
        for ( int j = 0; j < matrixSize; j++)
        {
            columnSum += matrix[j][i];
        }
        cout << "Sum of numbers in Column \t#" << i + 1 << " =\t" << columnSum << endl;
        columnSum = 0;
    }

    for(int i = 0; i < matrixSize; i++)
    {
        for(int j = 0; j < matrixSize; j++)
        {
            if(i==j)
                diagonalSum1 += matrix[i][j];
            if((i + j) == matrixSize - 1)
                diagonalSum2 += matrix[i][j];
        }
    }
    
    cout << endl << endl;
    cout << "Sum of numbers in first diagonal\t= " << diagonalSum1 << endl;
    cout << "Sum of numbers in second diagonal\t= " << diagonalSum2 << endl;
    
    if (diagonalSum2 != diagonalSum1)
    {
        cout<< "\n\nThe above is not a perfect matrix.\n\n";
    }
    else if(diagonalSum1 == diagonalSum2)
    {
        cout << "\n\nThe above matrix is a perfect matrix.\n\n";
    }
    
    }


int main(){
    
    int matrixSize; //size of matrix desired by user
    int perfectNumber = 0; //checks to see if it makes it a perfect matrix
    string choice; //choice to decide to continue using program
    
    
    cout << "Welcome to my perfect matrix program. The function "
         << "of the program is to: " << endl << endl;
    cout << "\t1. Allow the user to enter the size of the perfect"
         << "matrix ,such as N. N>=2 and <= 11." << endl;
    cout << "\t2. Create a 2 D vector array of size N x N." << endl;
    cout << "\t3. Populate the 2 D vector array with distinct "
         << "random numbers." << endl;
    cout << "\t4. Display the perfect number , sum for each "
         << "row, column, and\n\tdiagonals then determine whether"
         << "the numbers in N x N vector\n\tarray are perfect matrix numbers."
         << endl << endl;
  
    do{
        cout << "Enter the size of the matrix: ";
        cin >> matrixSize;
   
        if(matrixSize < 2 || matrixSize > 11)
        {
            cout << "Error *** Invalid choice - Size must be > 1 and < 11\n";
            cout << endl;
            cout << "Enter the size of the matrix: ";
            cin >> matrixSize;
        }
      
      
        cout << endl << endl;
        cout << "The perfect matrix that is created for size " << matrixSize << ": \n\n";
        
        vector< vector<int> > matrix(matrixSize,vector<int>(matrixSize));
        matrixGenerator(matrix, matrixSize);
        
        for(int i = 0;i < matrixSize;i++)
        {
            for(int j=0;j< matrixSize; j++)
            {
                perfectNumber = perfectNumber + matrix[i][j];
            }
        }

      
        cout << "\n\nThe perfect number is : " << (perfectNumber/3);
        cout << endl << endl;
        
        totalSums(matrix, matrixSize);
        
        cout << "Would you like to find another perfect matrix - Enter y or Y "
             << "for yes\nor n or N for no: ";
        cin >> choice;
        if(choice != "n" && choice != "N" &&
           choice != "y" && choice != "Y")
        {
            cout << "Error *** Invalid choice - Must enter y|Y or n|N" << endl;
            cin >> choice;
        }
    }while(choice == "y" || choice == "Y");
    
    cout << "This algorithm is implemented by Aldo Ramirez Boldo ";
    cout << "and Patrick Schneider." << endl;
    cout << "September 25 - 2019" << endl;
    

    return 0;
}


