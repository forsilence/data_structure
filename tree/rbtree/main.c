/*
*test program
*/

# include"_M_rb_tree.h"
# include<stdio.h>
# include<stdlib.h>
# include<time.h>

void d_print(data_type x)
{
	printf("%6d", x);
}

int main(){
	srand((unsigned)time(NULL));
	printf("<<<_M_rb_tree>>>\n");
	unsigned size=100;
	data_type ls[size];
	for(int i=0 ; i<size ; i++){
		ls[i]=rand();
	}
	_M_rbt_t rbt=_M_rbt_init(ls,size);
	_M_tree_walk(&rbt,&d_print);

	for(int i=2;i<10; i++)
	{
		printf("delete value is: %d\n",ls[i]);
		_M_rbt_node* del_node = _M_rbt_search(rbt,ls[i]);
		if(del_node != rbt.NIL)
			_M_rbt_delete(&rbt,del_node);
		else
			printf("can not find the node in tree \n");
	}
	_M_tree_walk(&rbt,&d_print);
	return 0;
}