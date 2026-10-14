#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <functional>

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
		{"cd", cd},
		{"ls", ls},
		{"history", history}
	};

	while (input != "exit") {
		//use the commands map to call the function
		auto it = commands.find(input);
		if (it != commands.end()) {
			it->second();  // call the function
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
}

void cd() {
}

void ls() {
}

void history() {
}

void clear() {
}