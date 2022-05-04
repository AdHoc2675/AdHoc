#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream f1("a.txt");
	ofstream f2("b.txt");

	int n, count = 0, sum = 0;
	double average;

	while (!f1.eof()) {
		f1 >> n;
		count++;
		sum = sum + n;
	}
	average = (double)sum / count;
	f2 << "input size: " << count << "\n";
	f2 << "Total Sum: " << sum << "\n";
	f2 << "The Average: " << average << "\n";

	f1.close();
	f2.close();

	return 0;
}