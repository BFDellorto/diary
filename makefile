comm=g++ -std=c++11

diarymake: main.cpp app.cpp
	$(comm) main.cpp app.cpp -o exec
