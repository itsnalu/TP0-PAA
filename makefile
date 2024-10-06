all:
	gcc main.c -o main 

run:
	main
clean:
	rm ./bin/* ./obj/*

