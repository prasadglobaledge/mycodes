objects1 = main.o create_node.o my_atoi.o insert_element.o search_tree.o find_min.o find_max.o delete_element.o display_tree.o
objects = main.c create_node.c my_atoi.c insert_element.c search_tree.c find_min.c find_max.c delete_element.c display_tree.c

exe : $(objects1)
			gcc -o $@ -Wall $^ 

$(objects1) : $(objects)
			gcc -c $^

.PHONY : clean

clean :
			rm main.o create_node.o my_atoi.o insert_element.o search_tree.o find_min.o find_max.o delete_element.o display_tree.o
					
