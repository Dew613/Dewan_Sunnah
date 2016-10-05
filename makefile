strtest: Strwrk.c
	gcc Strwrk.c -o strtest
clean:
	rm *~

run: strtest
	./strtest
