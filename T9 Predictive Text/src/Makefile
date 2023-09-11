%.o: %.c
	gcc -Wall -std=c11 -g -c -o $@ $<

trieTest: trie.o trieTest.o
	gcc -g -o $@ $^ -lcheck

app: trie.o app.o
	gcc -g -o $@ $^ -lcheck

clean:
	rm -rf *.o trieTest app

