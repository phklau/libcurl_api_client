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


main: main.o
	g++ -o api_client ./main.o -l curl
main.o: main.cpp
	g++ -c ./main.cpp