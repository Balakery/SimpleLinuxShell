#include <vector>
#include <string>
#include <iostream>
#ifdef _WIN32
#include <direct.h> // for _getcwd
#define getcwd _getcwd
#else
#include <unistd.h> // for getcwd
#endif
#include <map>

using namespace std;

int main() {
	string input;
	cout << "User: ";
	cin >> input;
	
	map<int, string> dict;
	dict[1] = "pwd";
	dict[2] = "ls";
	dict[3] = "history";
	dict[4] = "cd";

	vector<string> commandHistory;


	while (input != "exit") {

	}
	return 0;
}