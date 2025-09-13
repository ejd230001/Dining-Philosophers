all:
	g++ implementation/CoarseGrain.cpp implementation/CoarsePetersenLock.cpp implementation/Philosopher.cpp -std=c++11 -pthread -o coarse
	g++ implementation/FineGrain.cpp implementation/FinePetersenLock.cpp implementation/Philosopher.cpp -std=c++11 -pthread -o fine

clean:
	rm -f coarse fine