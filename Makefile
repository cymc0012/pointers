
all: intptr fcnptr print_char

intptr: intptr.cpp
	g++ -g intptr.cpp -o intptr 

fcnptr: fcnptr.cpp
	g++ -g fcnptr.cpp -o fcnptr 

print_char:
	g++ -g print_char.cpp -o print_char

exercises:
	g++ -g exercises.cpp -o exercises

clean:
	rm -rf intptr fcnptr print_char *.dSYM 

.PHONY: clean

