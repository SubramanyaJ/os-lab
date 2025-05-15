all:
	gcc main_fifo.c -o main_fifo
	cat ./data.txt | ./main_fifo
	gcc main_lru.c -o main_lru
	cat ./data.txt | ./main_lru
	gcc main_optimal.c -o main_optimal
	cat ./data.txt | ./main_optimal
