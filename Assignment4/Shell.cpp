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
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>
#include <sstream>
using namespace std;

vector<string> commandHistory;
const string HISTORY_FILE = "shell_history.txt";

void pwd();
void ls();
void history();
void clear();
void executeCommand(const string& input);

int main() {
	ifstream file(HISTORY_FILE);
	string line;
	while (getline(file, line)) {
		if (!line.empty()) {
			commandHistory.push_back(line);
		}
	}

	string input;

	unordered_map<string, void(*)()> commands{
		{"pwd", pwd},
		{"ls", ls},
		{"history", history},
		{"clear", clear}
	};

	while (true) {
		cout << "$ ";
		if (!getline(cin, input)) break;
		if (input.empty()) continue;

		commandHistory.push_back(input);

		if (input == "exit") {
			break;
		}

		auto it = commands.find(input);
		if (it != commands.end()) {
			it->second();
		} else {
			executeCommand(input);
		}
	}

	ofstream outfile(HISTORY_FILE);
	for (const auto& cmd : commandHistory) {
		outfile << cmd << "\n";
	}

	return 0;
}

void pwd() {
	char buffer[1024];
	if (getcwd(buffer, sizeof(buffer)) != nullptr) {
		cout << buffer << "\n";
	} else {
		perror("getcwd");
	}
}

void ls() {
	vector<string> args = {"ls"};
	pid_t pid = fork();
	if (pid == 0) {
		vector<char*> argv;
		argv.push_back(const_cast<char*>(args[0].c_str()));
		argv.push_back(nullptr);
		execvp(argv[0], argv.data());
		_exit(1);
	} else if (pid > 0) {
		wait(0);
	}
}

void history() {
	for (size_t i = 0; i < commandHistory.size(); ++i) {
		cout << (i + 1) << "  " << commandHistory[i] << "\n";
	}
}

void clear() {
	system("clear");
}

void executeCommand(const string& input) {
	
}