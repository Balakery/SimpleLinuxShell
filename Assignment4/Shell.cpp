#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <functional>
#include <fcntl.h>
#include <io.h>

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd
#else
#include <unistd.h> // for getcwd
#endif

using namespace std;

void pwd();
void cd();
void ls();
void history();
void clear();

int main() {
	string input;
	cout << "User: ";
	cin >> input;

	vector<string> commandHistory;
	commandHistory.push_back(input);

	unordered_map<string, void(*)()> commands{
		{"pwd", pwd},
		{"ls", ls},
		{"history", history},
		{"clear", clear}
	};

	while (getline(cin, input)) {
		//exit
		if (input == "exit") break;
		commandHistory.push_back(input);

		string command = input;
		string inputFile = "";
		string outputFile = "";

		int fd[2];
		int saved_stdout = dup(STDOUT_FILENO);
		int saved_stdin = dup(STDIN_FILENO);
		
		//use the commands map to call the function
		auto it = commands.find(input);
		if (it != commands.end()) {
			it->second();
		}
		else {
			cout << "Unknown command\n";
		}
		
		cout << "User: ";
		cin >> input;
	}
	return 0;
}

void pwd() {
	char buffer[1024];
	if (getcwd(buffer, sizeof(buffer)) != nullptr) {
		cout << "Current Directory: " << buffer << endl << endl;
	}
	else {
		cout << "Error!" << endl;
	}
}

void ls() {

}

void history() {

}

void clear() {

}