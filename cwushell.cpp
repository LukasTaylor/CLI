/*

Lukas Taylor
1/17/2018
  */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

bool toContinue = true;

void help()
{
  cout << "\n\t********************************************************************\n";
  cout << "\t\t\t\t   HELP SCREEN";
  cout << "\n\t********************************************************************\n\n";

  cout << "mv\t" << "Enter mv <file1> <file2> to move file1 contents to file2.\n\n";
  cout << "ls\t" << "Enter ls to list content of current directory.\n\n";
  cout << "cmp\t" << "Enter cmp <filename1> <filename2> to compare files and \n" 
     << "\treturns the byte difference.\n\n";
  cout << "tail\t" << "Enter tail <filename> to print last 10 lines of specified file.\n"
     << "\tEnter tail -n(x) <filename> to print last (x) lines.\n\n";
  cout << "cat\t" << "Enter cat <filename>\n"
     << "\tprints contents of file.\n\n";
  cout << "exit\t" << "Enter exit to exit cwushell.\n";
}

/*If user enters exit*/
void exit()
{
  exit(0);
}

/*welcomes user to the cwushell*/
void welcomeScreen()
{
    cout << "\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\t                 cwushell\n";
    cout << "\t==============================================\n";
    cout << "\t      Writen by Lukas Taylor\n";
    cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "\n\n";
}

/*user prompt*/
void shellPrompt()
{
   /*The prompt is printed as "<user>@<host> <cwd> >"*/
    printf("\nlukas@lukas-cwushell:~$ ");
}

void run()
{
  /*Welcome screen prompt*/
  welcomeScreen();
  for(;;){
    /*displays user, host, and cwd*/
    shellPrompt();
    /*for user input*/
    char userInput[100];
    /*char pointer for command line args*/
    char* argArray[3];
    /*Get user input from console*/
    cin.getline(userInput, 100);
    /*If user types exit*/
    if(strcmp(userInput, "exit") == 0)
    {
      toContinue = false;
      exit();
    }
    /*Tokenize command string*/
    char* token;
    int i = 0;
    token = strtok(userInput, " \t");
    /*while token exists each token is set to index i*/
    while(token != NULL)
    {
      argArray[i] = token;
      token = strtok(NULL, " ");
      i++;
    }
    /*if user enters "ls" make system call to ls*/
    if(strcmp(argArray[0], "ls") == 0)
    {
      system("ls");
    }
    /*if user enters "mv" make system call to mv*/
    if(strcmp(argArray[0], "mv") == 0)
    {
      /*file 1 and file 2 appended to ss*/
      stringstream ss;
      ss << "mv" << " " << argArray[1] << " " << argArray[2];
      /*sets ss as contents of stream and copies*/
      system(ss.str().c_str());
    }
    /*if cmp is entered*/
    if(strcmp(argArray[0], "cmp") == 0)
    {
      stringstream ss;
      ss << "cmp" << " " << argArray[1] << " " << argArray[2];
      system(ss.str().c_str());
    }
    /*if cat is entered*/
    if(strcmp(argArray[0], "cat") == 0)
    {
      stringstream ss;
      ss << "cat" << " " << argArray[1] << " " << argArray[2];
      system(ss.str().c_str());
    }
    /*if tail is entered*/
    if(strcmp(argArray[0], "tail") == 0)
    {
      stringstream ss;
      /*prints last 10 lines of file*/
      if(argArray[2] == NULL)
      {
        ss << "tail" << " " << argArray[1];
        system(ss.str().c_str());
      }
      /*user specifies n lines to print*/
      else if(argArray[2] != NULL)
      {
        ss << "tail" << " " << argArray[1] << " " << argArray[2];
        system(ss.str().c_str());
      }
      else
      {
        printf("Tail malfunction");
      }
    }
    if(strcmp(argArray[0], "help") == 0)
    {
      help();
    }
  }
}

int main(int argc, char *argv[])
{
  run();
  return (0);
}