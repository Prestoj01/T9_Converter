compile: PhoneNum
	gcc Project-4.c PhoneNum.o -Wall -o PhoneNum.exe

PhoneNum:
	gcc -c PhoneNum.c -o PhoneNum.o

run:
	./PhoneNum.exe input.txt output.txt -d

clean:
	rm -f *.exe