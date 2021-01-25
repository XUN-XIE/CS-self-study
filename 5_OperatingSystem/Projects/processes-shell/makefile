wish: wish.o parseLine.o builtIn.o List.o auxFunc.o
	gcc -o wish wish.o parseLine.o builtIn.o List.o auxFunc.o
clean:
	rm wish.o parseLine.o builtIn.o List.o auxFunc.o
wish.o: wish.c
	gcc -c wish.c

parseLine.o: parseLine.c
	gcc -c parseLine.c

builtIn.o: builtIn.c
	gcc -c builtIn.c

List.o: List.c
	gcc -c List.c

auxFunc.o: auxFunc.c
	gcc -c auxFunc.c
