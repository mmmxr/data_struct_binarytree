bin_tree:bin_tree.c seqqueue.c
	gcc -o $@ $^

.PHONY:clean
	rm -f bin_tree
