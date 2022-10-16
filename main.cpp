

#include <iostream>
#include <stack>
#include <queue>
#include <array>
#include <bits/stdc++.h>
using namespace std;



void PrintOut(int *arr, int i, int j, int m, int n, int *path, int pi)
{

    if (i == m - 1)
    {
        for (int k = j; k < n; k++)
            path[pi + k - j] = *((arr + i * n) + k);
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

// The main function that prints all paths from
// top left to bottom right in a matrix 'mat' of size mXn
void PAP(int *mat, int m, int n)
{
    int *path = new int[m+n];

    PrintOut(mat, 0, 0, m, n, path, 0);
}

void menu(){
    std::cout.width(20);
    std::cout<<"MENU"<<std::endl<<std::endl<<"Horizontal Axis (0), Vertical Axis (1), Start \n"
                                             "Discovery (2),"<<std::endl;
    std::cout<<"Exit Program (3)"<<std::endl<<"Choose?";

}





int hor = 0;
int ver = 0;

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
        hor = stoi(wordlist.at(1));
    }

    else if(wordlist.at(0) == "1"){
        ver = stoi(wordlist.at(1));


    }

    else if(wordlist.at(0) == "2"){
        if(hor != 0 && ver!=0){

            int map[hor][ver];
            int count = 0;

            for (int j = 0; j < hor; j++) {
                for (int i = 0; i < ver; i++) {
                    count += 1;
                    map[j][i] = count;


                }
            }

            //int mat[3][3] = { {1, 2, 3}, {4, 5, 6}, { 7, 8, 9 }};
            //PAP(*map, hor, ver);
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
            cout<<"make sure the horizontal column has a value"<<endl;
        }
        else{
            cout<<"make sure the vertical column has a value"<<endl;
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