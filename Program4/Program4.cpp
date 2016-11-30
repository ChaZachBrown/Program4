// Zach Brown
// 03/09/15
// Program 4

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string maze[20];//Array of stings to read the file into



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
    
    //int tempcounter2 = 0;
    //while (tempcounter2 <= 10)//printing the maze out to the screen for debugging
    //{
    //    cout << maze[tempcounter2] << endl;
    //    tempcounter2 += 1;
    //}

    if (maze[row][column] == chr)//base case
    {
        return 1;
    }
 
    //checking to see if there is whitespace to move to ************NORTH*****************************************
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
            maze[row - 1][column] = 'M';//when a dead end is found
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
            break;
 
        case 2://when the solver finds the starting point
            maze[row - 1][column] = '.';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ')
                return 2;
            break;
 

        }
    }

    if (checkNorth(row, column) == 'o')
    {
        return 3;
    }
    else if (checkNorth(row, column) == chr)
    {
        return 1;
    }
    //checking to see if there is whitespace to move to ****************EAST****************************************
    if (checkEast(row, column) == ' ')
    {
       maze[row][column + 1] = 'O';
        switch (mazeSolver(row, column+1, chr))
        {
        case false://when a dead end is found
            maze[row][column + 1] = 'M';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
            break;
        case 1://when a valid path is found
            maze[row][column + 1] = '.';
            return 1;
            break;

        }

    }
    if (checkEast(row, column) == '.')//when the solver is going back over a path 
    {
        maze[row][column + 1] = 'i';//final charactor for the path being ran over twice
        switch (mazeSolver(row, column + 1, chr))
        {
        case false://when a dead end is found
            maze[row][column + 1] = 'M';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
            break;

        case 2://when the solver finds the starting point
            maze[row][column + 1] = '.';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ')
                return 2;
            break;

        }

    }
    if (checkEast(row, column) == 'o')
    {
        return 3;
    }
    else if (checkEast(row, column) == chr)
    {
        return 1;
    }
    //checking to see if there is whitespace to move to **********************SOUTH************************************
    if (checkSouth(row, column) == ' ')
    {
        maze[row+1][column] = 'O';
        switch (mazeSolver(row + 1, column, chr))
        {
        case false://when a dead end is found
            maze[row + 1][column] = 'M';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
            break;
        case 1://when a valid path is found
            maze[row + 1][column] = '.';
            return 1;
            break;
      
        }

        
    
    }
    if (checkSouth(row, column) == '.')//when the solver is going back over a path 
    {
        maze[row + 1][column] = 'i';//final charactor for the path being ran over twice
        switch (mazeSolver(row + 1, column, chr))
        {
        case false://when a dead end is found
            break;
            maze[row + 1][column] = 'M';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
 
        case 2://when the solver finds the starting point
            maze[row][column + 1] = '.';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ')
                return 2;
            break;
        }
    }
    if (checkSouth(row, column) == 'o')
    {
        return 3;
    }
    else if (checkSouth(row, column) == chr)
    {
        return 1;
    }
    //checking to see if there is whitespace to move to ******************************WEST************************************
    if (checkWest(row, column) == ' ')
    {
        maze[row][column - 1] = 'O';
        switch (mazeSolver(row, column-1, chr))
        {
        case false://when a dead end is found
            maze[row][column - 1] = 'M';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                 checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
            break;
        case 1://when a valid path is found
            maze[row][column - 1] = '.';
            return 1;
            break;
      
        }
      
  
    }
    if (checkWest(row, column) == '.')//when the solver is going back over a path 
    {
        maze[row][column - 1] = 'i';//final charactor for the path being ran over twice
        switch (mazeSolver(row, column - 1, chr))
        {
        case false://when a dead end is found
            maze[row][column - 1] = 'M';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ' &&
                checkNorth(row, column) != 'i' && checkEast(row, column) != 'i' && checkSouth(row, column) != 'i' && checkWest(row, column) != 'i')
                return false;
            break;
 
        case 2://when the solver finds the starting point
            maze[row][column - 1] = '.';
            if (checkNorth(row, column) != ' ' && checkEast(row, column) != ' ' && checkSouth(row, column) != ' ' && checkWest(row, column) != ' ')
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



  mazeSolver(startingRow, startingColumn, '@');

  
   mazeSolver(startingRow2, startingColumn2, '!');


   int counter3 = 0;
   for (int j = 0; j < width; j = j++)//counting and putting the right characters in the right place
   {
       for (int i = 0; i < height; i = i++)
       {
           if (maze[j][i] == '.')
           {
               counter3++;
           }
           if (maze[j][i] == 'i')
           {
               counter3 = counter3 + 1;
               maze[j][i] = '.';
           }
           if (maze[j][i] == 'M')
           {
               maze[j][i] = ' ';
           }
           if (maze[j][i] == 'O')
           {
               maze[j][i] = ' ';
           }
       }
   }
   cout << counter3;




    
    int tempcounter2 = 0;
    while (tempcounter2 <= tempCounter)//printing the maze to file 
    {
        fout << maze[tempcounter2] << endl;
        tempcounter2 += 1;
    }
    fout << endl << "Legend:" << endl << "* - wall" << endl << "@ - item"<< endl << "o - starting position" << endl << "! - ending position" << endl;
    fout << "Number of moves to solve :" << " " << counter3 << endl;
    system("pause");

}