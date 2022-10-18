//Steven Howell Homework 3

#include <iostream>
#include <stack>
#include <queue>
#include <array>
#include <bits/stdc++.h>
using namespace std;



int hor = 0; //global dimensions for the width and height of the map
int ver = 0;
/*
 * //test code that gives correct response for comparison
void PrintOut(int *arr, int i, int j, int m, int n, int *path, int pi)
{

    if (i == m - 1)
    {
        for (int k = j; k < n; k++) {
            path[pi + k - j] = *((arr + i * n) + k);
            //cout<<*((arr + i * n) + k)<<endl;
        }
        for (int l = 0; l < pi + n - j; l++)
            cout << path[l] << " ";
        cout << endl;
        return;
    }

    if (j == n - 1)
    {
        for (int k = i; k < m; k++)
            path[pi + k - i] = *((arr + k * n) + j);
        for (int l = 0; l < pi + m - i; l++)
            cout << path[l] << " ";
        cout << endl;
        return;
    }

    // Add the current cell to the path being generated
    path[pi] = *((arr + i * n) + j);

    // Print all the paths that are possible after moving down
    PrintOut(arr, i + 1, j, m, n, path, pi + 1);

    // Print all the paths that are possible after moving right
    PrintOut(arr, i, j + 1, m, n, path, pi + 1);

    // Print all the paths that are possible after moving diagonal
    PrintOut(arr, i + 1, j + 1, m, n, path, pi + 1);
}




//attempt 1 using 2d array failure does not work crashes program

void PrintOut2(int *arr, vector<vector<int> > mapping, int i, int j, int m, int n, vector<int> path = {})
{

    if (i < 0 || j < 0 || i >= m ||
        j >= n || mapping[i][j] == 1)
        return;
    if(i == m-1 && j==n-1){
        path.push_back(*(arr + i * n + j));

        for(int tmp = 0; tmp < path.size();tmp++){
            cout<<path[tmp]<<"";
        }
        cout<<endl;
        return;

    }

    mapping[i][j] = 1;

    // Print all the paths that are possible after moving down
    PrintOut2(arr,mapping, i + 1, j, m, n, path);

    // Print all the paths that are possible after moving right
    PrintOut2(arr,mapping, i, j + 1, m, n, path);

    // Print all the paths that are possible after moving diagonal
    PrintOut2(arr,mapping, i + 1, j + 1, m, n, path);

    path.pop_back();
    mapping[i][j] = 0;
}

*/
//attempt2 works using 2d array and stores data as a vector
/*
 * arr is 2d array pointer int i, j is the current position in the map m and n are the size of the map
 * path is the current path that is blank upon first initialization and then gets updated each time
 */
void PrintOut3(int **arr, int i, int j, int m, int n, vector<int> path = {})
{


    //cout<<"i and m "<<i<<" "<<m<<endl;
    if (i == m - 1) //if i is at the last column then use for loop to push back all the possible paths
    {
        //cout<<"i if statement triggered"<<endl;
        for (int k = j; k < n; k++) {
            //cout<<arr[i][k]<<endl;
            path.push_back(arr[i][k]);
            //cout<<*((arr + i * n) + k)<<endl;
        }
        for (int l : path)
            cout << l << " ";
        cout << endl;
        return;// program reaches it collusion
    }
    //cout<<"j and n "<<j<<" "<<n<<endl;
    if (j == n - 1)//if j is at the last row then use for loop to push back all the possible paths
    {
        for (int k = i; k < m; k++) {
            //cout<<arr[k][j]<<endl;
            path.push_back(arr[k][j]);
        }
        for (int l : path)
            cout << l << " "; //print all values in path
        cout << endl;
        return; // program reaches it collusion
    }


    //mapping[i][j] = 1;
    path.push_back(arr[i][j]); // store all movements that are not the end in the array based on the current cell i,j

    // Print out the paths that are possible after moving down
    PrintOut3(arr, i + 1, j, m, n, path);

    // Print out paths that are possible after moving right
    PrintOut3(arr, i, j + 1, m, n, path);

    // Print out the paths that are possible after moving diagonal
    PrintOut3(arr, i + 1, j + 1, m, n, path);

    path.pop_back(); // backtrack on failure by clearing the last position in the path
    //mapping[i][j] = 0;
}






// The main function that prints all paths from
// top left to bottom right in a matrix 'mat' of size mXn
/*
void PAP(int *mat, int m, int n)
{
    int *path = new int[m+n];
    //cout<<path<<endl;
    PrintOut(mat, 0, 0, m, n, path, 0);
}

void Start_Print(int *mx, int m, int n)
{
    vector<int> path;
    vector<vector<int> > mapping(2, vector<int>(3, 0));
    PrintOut2(mx,mapping, 0, 0, m, n);
}
 */
//this was mostly here for figuring out how to put a 2d array into printout properly and do all adjustments in an isolated method.
void Start_Print2(int **mx, int m, int n)
{
    //vector<int> path;
    //vector<vector<int> > mapping(2, vector<int>(3, 0));
    PrintOut3(mx, 0, 0, m, n); //start the print-out

    // Delete the array created
    for (int i = 0; i < m; i++) // To delete the inner
        // arrays
        delete[] mx[i];
    delete[] mx; // To delete the outer array
    // which contained the pointers
    // of all the inner arrays

}
//print menu
void menu(){
    std::cout.width(20);
    std::cout<<"MENU"<<std::endl<<std::endl<<"Horizontal Axis (0), Vertical Axis (1), Start \n"
                                             "Discovery (2),"<<std::endl;
    std::cout<<"Exit Program (3)"<<std::endl<<"Choose?";

}





// make a disposition based on input
std::string decision(const std::string& user_input){
    std::string key = "null";

    std::string del = " ";//parameter to use
    std::stringstream ss(user_input);
    std::string word;
    std::vector<std::string> wordlist{};//command vector
/*
while (!ss.eof()) {

    getline(ss, word, del);
    std::cout << word << std::endl;
}
*/

    while (ss >> word) {//splits string by space
        //std::cout << word << std::endl;

        wordlist.push_back(word);//puts the individual strings into a vector
        if(wordlist.size()>2){//if there is are 3 detected inputs then return error
            std::cout<<"Input has too many parameters. Please try again."<<std::endl;
            //wordlist.empty();
            return key;
            //break;
        }
    }
    //checks if the first input matches the command number and is a valid input
    if((wordlist.at(0) == ("0")||
        wordlist.at(0) == ("1"))&&
       wordlist.size()!=2){
        std::cout<<"No input parameter"<<std::endl;
        return key;
    }
    /*
    else if ((wordlist.at(0) == ("2")||
              wordlist.at(0) == ("3")||
              wordlist.at(0) == ("5")||
              wordlist.at(0) == ("8")||
              wordlist.at(0) == ("9")||
              wordlist.at(0) == ("11"))&&
             wordlist.size()!=1){
        std::cout<<"too many inputs"<<std::endl;
        return key;

    }
     */
    //check valid input or if the input value is 0
    if(wordlist.size() == 2){
        for(char i : wordlist.at(1)) {
            if (!std::isdigit(i)) {
                std::cout << "input is not a int or is negative" << std::endl;
                return key;
            }
        }

    }


    if(wordlist.at(0) == "0"){
        hor = stoi(wordlist.at(1)); //store the array horizontal dimensions
    }

    else if(wordlist.at(0) == "1"){
        ver = stoi(wordlist.at(1)); //store the array vertical dimensions


    }

    else if(wordlist.at(0) == "2"){
        if(hor != 0 && ver!=0){//checks to make sure array has size

            int count = 0;

            int **map = new int*[hor]; //make 2d array using dynamic arrays modified to not need memory address
            //int map2[hor][ver];

            for (int i = 0; i < hor; i++) {

                // Declare a memory block
                // of size n
                map[i] = new int[ver];//add vertical to dynamic array
            }
            /*

            for (int j = 0; j < hor; j++) {
                for (int i = 0; i < ver; i++) {

                    map2[i][j] = ++count;
                    //cout<<map[i][j]<<" ";


                }
                //cout<<endl;
            }
             */

            //count = 0;
            for (int i = 0; i < hor; i++) {
                for (auto j = 0; j < ver; j++) {

                    map[i][j] = ++count;// assign values to each position in the array
                    //cout<<map[i][j]<<" ";


                }
                //cout<<endl;
            }
            //PAP(*map2, hor, ver);
            //cout<<endl;
            Start_Print2(map, hor, ver);//print out array
            /*
            int* map = new int[hor*ver];


            for (int j = 0; j < hor; j++) {
                for (int i = 0; i < ver; i++) {

                    *(map + j * ver + j) = ++count;


                }
                cout<<endl;
            }
            for (int i = 0; i < hor; i++) {
                for (int j = 0; j < ver; j++) {

                    // Print values of the
                    // memory block
                    cout << *(map + i * ver + j)
                         << " ";
                }
                cout << endl;
            }
             */

            //int mat[3][3] = { {1, 2, 3}, {4, 5, 6}, { 7, 8, 9 }};
            //PAP(*map, hor, ver);

            //Start_Print(map, hor, ver);



            /*
            vector<vector<int>> map2;
            for (int j = 0; j < hor; j++) {
                for (int i = 0; i < ver; i++) {
                    count += 1;
                    map2[j].push_back( count);
                }
            }
            vector<int>ans;
            AllPrintOut(map, hor, ver);
            */

        }
        else if(ver != 0){
            cout<<"make sure the horizontal column has a value"<<endl; // error code
        }
        else{
            cout<<"make sure the vertical column has a value"<<endl; //error code
        }

    }
    else if(wordlist.at(0) == "3"){
        key = "exit"; //pass exit code
    }

    return key;
}






int main()
{
    //cout << NoP(3, 3)<<endl;

    std::string exit = "go";
    //vector<vector<int>> map;
    while(exit != "exit") {

        menu();
        std::string u_input;
        getline(std::cin,u_input);




        exit = decision(u_input);//decide on output checks if it should exit

    }
    std::cout<<"Program finished have a nice day!"<<std::endl;//a friendly message
    return 0;
}