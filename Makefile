run: compile link
	./api_client
clean-run: lint clean compile link test
	./api_client
compile: main.o
link: main 
lint:
	python3 ../cpplint/cpplint.py *.cpp *.h
clean: 
	rm -rf *.o


main: main.o PostRequest.o GetRequest.o
	g++ -o api_client ./main.o ./PostRequest.o ./GetRequest.o -l curl -g
main.o: main.cpp 
	g++ -c ./main.cpp -g
PostRequest.o: PostRequest.cpp PostRequest.hpp
	g++ -c PostRequest.cpp -g
GetRequest.o: GetRequest.cpp GetRequest.hpp
	g++ -c GetRequest.cpp -g
