// Zach Brown
// 03/09/15
// Program 4

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string maze[20];//Array of stings to read the file into
string mazeCopy[20];
string tempmaze1[20];
string mazeFinal[20];


//**********************************funtions to check direction******************************************************
char checkNorth(int row, int column)
{
    return maze[row - 1][column];
}
char checkEast(int row, int column)
{
    return maze[row][column + 1];
}
char checkSouth(int row, int column)
{
    return maze[row + 1][column];
}
char checkWest(int row, int column)
{
    return maze[row][column - 1];
}

int mazeSolver(int row, int column, char chr)
{

    int tempcounter2 = 0;
    while (tempcounter2 <= 7)//printing the maze out to the screen for debugging
    {
        cout << maze[tempcounter2] << endl;
        tempcounter2 += 1;
    }

    if (maze[row][column] == chr)//base case
    {
        return 1;
    }

    //checking to see if there is whitespace to move to ************NORTH*****************************************CHANGE SHIT TO SWITCH CASES
    if (checkNorth(row, column) == ' ')
    {
        maze[row - 1][column] = 'O';
        switch (mazeSolver(row - 1, column, chr))
        {
        case false://when a dead end is found
            maze[row - 1][column] = 'M';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
            break;
        case 1://when a valid path is found
            maze[row - 1][column] = '.';
            return 1;
            break;


        }
    }
    if (checkNorth(row, column) == '.')//when the solver is going back over a path 
    {
        maze[row - 1][column] = 'i';//final charactor for the path being ran over twice
        switch (mazeSolver(row - 1, column, chr))
        {
        case false:
            maze[row - 1][column] = 'M';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
            break;
        case 1:
            maze[row - 1][column] = 'a';//indicating that the path should only be counted once because it went back to the start
            return 1;
            break;
        case 2://when the solver finds the starting point
            maze[row - 1][column] = '.';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return 2;
            break;

        }
    }

    if (checkNorth(row, column) == 'o')
    {
        return 2;
    }
    else if (checkNorth(row, column) == chr)
    {
        return 1;
    }
    //checking to see if there is whitespace to move to ****************EAST****************************************
    if (checkEast(row, column) == ' ')
    {
        maze[row][column + 1] = 'O';
        switch (mazeSolver(row, column + 1, chr))
        {
        case false:
            maze[row][column + 1] = 'M';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
            break;
        case 1:
            maze[row][column + 1] = '.';
            return 1;
            break;

        }

    }
    if (checkEast(row, column) == '.')
    {
        maze[row][column + 1] = 'i';
        switch (mazeSolver(row, column + 1, chr))
        {
        case false:
            maze[row][column + 1] = 'M';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
            break;
        case 1:
            maze[row][column + 1] = 'a';
            return 1;
            break;
        case 2:
            maze[row][column + 1] = '.';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return 2;
            break;
        }

    }
    if (checkEast(row, column) == 'o')
    {
        return 2;
    }
    else if (checkEast(row, column) == chr)
    {
        return 1;
    }
    //checking to see if there is whitespace to move to **********************SOUTH************************************
    if (checkSouth(row, column) == ' ')
    {
        maze[row + 1][column] = 'O';
        switch (mazeSolver(row + 1, column, chr))
        {
        case false:
            break;
            maze[row + 1][column] = 'M';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
        case 1:
            maze[row + 1][column] = '.';
            return 1;
            break;

        }



    }
    if (checkSouth(row, column) == '.')
    {
        maze[row + 1][column] = 'i';
        switch (mazeSolver(row + 1, column, chr))
        {
        case false:
            break;
            maze[row + 1][column] = 'M';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
        case 1:
            maze[row + 1][column] = 'a';
            return 1;
            break;
        case 2:
            maze[row][column + 1] = '.';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return 2;
            break;
        }
    }
    if (checkSouth(row, column) == 'o')
    {
        return 2;
    }
    else if (checkSouth(row, column) == chr)
    {
        return 1;
    }
    //checking to see if there is whitespace to move to ******************************WEST************************************
    if (checkWest(row, column) == ' ')
    {
        maze[row][column - 1] = 'O';
        switch (mazeSolver(row, column - 1, chr))
        {
        case false:
            maze[row][column - 1] = 'M';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
            break;
        case 1:
            maze[row][column - 1] = '.';
            return 1;
            break;

        }


    }
    if (checkWest(row, column) == '.')
    {
        maze[row][column - 1] = 'i';
        switch (mazeSolver(row, column - 1, chr))
        {
        case false:
            maze[row][column - 1] = 'M';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
            break;
        case 1:
            maze[row][column - 1] = 'a';
            return 1;
            break;
        case 2:
            maze[row][column - 1] = '.';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return 2;
            break;
        }
    }
    else if (checkWest(row, column) == 'i')
    {
        maze[row][column - 1] = 'i';
    }
    else if (checkWest(row, column) == 'o')
    {
        return 2;
    }
    else if (checkWest(row, column) == chr)//if the @ or ! is found
    {
        return 1;
    }



    //*******************************************if one of the checks come true******************************************
    else if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
        checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
        return false;
    else
    {
        return 1;
    }

}

int main()
{
    //###############################user requested files#####################################
    string fileName;
    cout << "What is the name of the input file?";
    getline(cin, fileName);
    ifstream fin;
    fin.open(fileName.c_str());
    while (!fin.is_open())//eeror checking for making sure the file is opened
    {
        cout << "The file could not open. Please enter the correct file: ";
        getline(cin, fileName);
        ifstream fin;
        fin.open(fileName.c_str());
        if (fin.is_open())//if file is opened, this will brek out of the error checking
        {
            break;
        }

    }
    string outname;
    cout << "What is the name of the output file?";
    getline(cin, outname);
    ofstream fout(outname);





    //**********************************raeding in the files and calling the recursive functions*****************************************


    int width;
    int height;
    int startingRow;
    int startingColumn;
    int startingRow2;
    int startingColumn2;
    fin >> width >> height;
    cout << width << " " << height << endl;
    int tempCounter = 0;
    string whitespace;//to get the whitespace from the first line
    getline(fin, whitespace);
    while (tempCounter < height)//pulling in the lines from the file and storing them in maze array***MAZE FOR FINDING @
    {
        getline(fin, maze[tempCounter]);
        tempCounter += 1;
    }



    for (int j = 0; j < width; j = j++)//finding starting posistion for the solver
    {
        for (int i = 0; i < height; i = i++)
        {
            if (maze[j][i] == 'o')
            {
                startingRow = j;
                startingColumn = i;
            }
        }
    }
    for (int j = 0; j < width; j = j++)//finding starting posistion for the solver
    {
        for (int i = 0; i < height; i = i++)
        {
            if (maze[j][i] == '@')
            {
                startingRow2 = j;
                startingColumn2 = i;
            }
        }
    }


    /*for (int i = 0; i < height; i++)
    {
    mazeCopy[i] = maze[i];
    }
    */



    mazeSolver(startingRow, startingColumn, '@');


    /* for (int i = 0; i < height; i++)
    {
    tempmaze1[i] = maze[i];
    }

    for (int i = 0; i < height; i++)
    {
    maze[i] = mazeCopy[i];
    }*/


    mazeSolver(startingRow2, startingColumn2, '!');


    int tempcounter2 = 0;
    while (tempcounter2 <= tempCounter)//printing the maze out to the screen for debugging maze
    {
        cout << maze[tempcounter2] << endl;
        tempcounter2 += 1;
    }
    //tempcounter2 = 0;
    //while (tempcounter2 <= tempCounter)//printing the maze out to the screen for debugging maze
    //{
    //    cout << mazeCopy[tempcounter2] << endl;
    //    tempcounter2 += 1;
    //}
    //tempcounter2 = 0;
    //while (tempcounter2 <= tempCounter)//printing the maze out to the screen for debugging maze
    //{
    //    cout << tempmaze1[tempcounter2] << endl;
    //    tempcounter2 += 1;
    //}
    cout << checkNorth(startingRow, startingColumn) << endl << checkEast(startingRow, startingColumn) << endl << checkSouth(startingRow, startingColumn) << endl << checkWest(startingRow, startingColumn);


    system("pause");

}