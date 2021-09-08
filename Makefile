
all: intptr fcnptr print_char

intptr:
	g++ -g intptr.cpp -o intptr 

fcnptr:
	g++ -g fcnptr.cpp -o fcnptr 

print_char:
	g++ -g print_char.cpp -o print_char 

clean:
	rm -rf intptr fcnptr print_char *.dSYM 

