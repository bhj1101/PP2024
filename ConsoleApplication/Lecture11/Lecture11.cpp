#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
int main() {

	int count = 0;
	while (true)
	{
		auto start = chrono::high_resolution_clock::now();
		this_thread::sleep_for(chrono::seconds(1));
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration<double, milli>(end - start).count();
		cout << duration - 1000 << "ms" << endl;
		count++;
	}
	return 0;
}