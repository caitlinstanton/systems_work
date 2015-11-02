#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

typedef struct listnode{
	char name[256];
	int number;
} node;

node* create(char* n, int num, int file) {
	node* added = (node*)malloc(sizeof(node));
	strncpy(added->name, n, strlen(n));
	added->number = num;
	write(file, &added, sizeof(node));
	return added;
}

void read_from_file(int num,node* buff, int fd) {
	lseek(fd,num*sizeof(node),SEEK_SET);
	read(fd,buff,sizeof(node));
}

void print_node(node n) {
	printf("Number: %i -- Name: %s\n",n.number,n.name);
}

int main(){
	int fd = open("lineup.txt",O_CREAT | O_RDWR | O_TRUNC,0644);
	if (fd < 0) {
		printf("Error %d - %s",errno,strerror(errno));
                return errno;
	}

	node* player = (node*)malloc(sizeof(node));
	int writing;

	strcpy(player->name,"Granderson");
	player->number = 3;
	writing = write(fd,player,sizeof(node));
	if (writing < 0) {
		printf("Error %d - %s",errno,strerror(errno));
                return errno;
	}

	strcpy(player->name,"Wright");
        	player->number = 5;
        	writing = write(fd,player,sizeof(node));
        	if (writing < 0) {
                	printf("Error %d - %s",errno,strerror(errno));
                	return errno;
        	}

	strcpy(player->name,"Murphy");
        	player->number = 28;
       	 	writing = write(fd,player,sizeof(node));
        	if (writing < 0) {
                	printf("Error %d - %s",errno,strerror(errno));
                	return errno;
        	}

	strcpy(player->name,"Cespedes");
        	player->number = 52;
       	 	writing = write(fd,player,sizeof(node));
        	if (writing < 0) {
                	printf("Error %d - %s",errno,strerror(errno));
               	 	return errno;
        	}

	strcpy(player->name,"Duda");
        	player->number = 21;
        	writing = write(fd,player,sizeof(node));
        	if (writing < 0) {
                	printf("Error %d - %s",errno,strerror(errno));
                	return errno;
        	}

	strcpy(player->name,"d'Arnaud");
        	player->number = 7;
        	writing = write(fd,player,sizeof(node));
        	if (writing < 0) {
                	printf("Error %d - %s",errno,strerror(errno));
                	return errno;
        	}

	strcpy(player->name,"Conforto");
        	player->number = 30;
        	writing = write(fd,player,sizeof(node));
        	if (writing < 0) {
                	printf("Error %d - %s",errno,strerror(errno));
                	return errno;
        	}

	strcpy(player->name,"Flores");
        	player->number = 4;
        	writing = write(fd,player,sizeof(node));
        	if (writing < 0) {
                	printf("Error %d - %s",errno,strerror(errno));
                	return errno;
        	}

	strcpy(player->name,"Harvey");
        	player->number = 34;
        	writing = write(fd,player,sizeof(node));
        	if (writing < 0) {
                	printf("Error %d - %s",errno,strerror(errno));
                	return errno;
        	}

	close(fd);

	//Creating file
	fd = open("lineup.txt",O_RDONLY);
	if (fd < 0) {
		printf("Error %d - %s",errno,strerror(errno));
		return errno;
	}

	//Printing original file
	int i,buff;
	printf("Original lineup:\n");
	node* tmp =(node*)malloc(sizeof(node));
	for (i = 0; i < 9; i++) {
		buff = read(fd,tmp,sizeof(node));
		if (buff < 0) {
			printf("Error %d - %s",errno,strerror(errno));
        	        return errno;
		} else {
			printf("#%i:	Bytes Read: %lu		Name: %s	Number: %d\n",
				i,sizeof(node),tmp->name,tmp->number);
		}
	}

	//Finding a node
	int input;
	printf("Input a number from 0-9 to select a Mets player\n");
	scanf("%i\n",&input);
	node find = *((node*)malloc(sizeof(node)));
	read_from_file(input,&find,fd);
	printf("Here's what you were looking for:\n");
	print_node(find);

	//Editing a node
	int input1;
        printf("Input a number from 0-9 to select a Mets player\n");
        scanf("%i\n",&input1);
        node find1 = *((node*)malloc(sizeof(node)));
        read_from_file(input1,&find,fd);
	strcpy(find1.name,"Lagares");
	find1.number = 12;
        printf("Here's what changed:\n");
        print_node(find1);

	//Printing edited file
	printf("Edited lineup");
        node* tmp1 =(node*)malloc(sizeof(node));
        for (i = 0; i < 9; i++) {
                buff = read(fd,tmp1,sizeof(node));
                if (buff < 0) {
                        printf("Error %d - %s",errno,strerror(errno));
                        return errno;
                } else {
                        printf("#%i:    Bytes Read: %lu         Name: %s	Number: %d\n", 
				i,sizeof(node),tmp1->name,tmp1->number);
                }
        }

	return 0;
}
