#include <emscripten/emscripten.h>
#include <iostream>
#include <chrono>

extern "C" {
	
int _fact(int n)
{
	if (n == 1) { return 1; }
	return n * _fact(n - 1);
}	
	
void EMSCRIPTEN_KEEPALIVE
fact(int n)
{
	auto t1 = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= n; i++) {
		if (i % 1000 == 0) {
			auto t2 = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
			std::cout << "call factorial("
					  << std::to_string(i) << "): "
					  << duration
					  << std::endl;
		}
		
		_fact(i);
	}
}

} // extern "C"

int main()
{
	return 0;
}
