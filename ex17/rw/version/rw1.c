#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

struct Database {
	int max_rows;
	int max_data;
	struct Address rows[MAX_ROWS];
};

// 将某个文件与其相对应的数据链接
struct Connection {
	FILE *file;
	struct Database *db;
};

void Database_close(struct Connection *conn)
{
	if(conn) {
		if(conn->file)	fclose(conn->file);
		if(conn->db)	free(conn->db);
		free(conn);
	}
}

//void die(const char *message)
void die(struct Connection* conn, const char* message)
{
	if(errno){
		perror(message);
	}else {
		printf("ERROR: %s\n", message);
	}
	
	Database_close(conn);

	exit(1);
}

void die_o(const char* message)
{
	if(errno) {
		perror(message);
	}else {
		printf("ERROR: %s\n", message);
	}

	exit(1);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n",addr->id,addr->name,addr->email);
}

void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db,sizeof(struct Database), 1, conn->file);
	if(rc != 1)
		die(conn, "Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode, int max_rows, int max_data)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if(!conn)
		die(conn, "Memory error");
	
	conn->db = malloc(sizeof(struct Database));
	if(!conn->db)
		die(conn, "Memory error");

	conn->db->max_rows = max_rows;
	conn->db->max_data = max_data;

	if(mode == 'c') {
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");
	
		if(conn->file) {
			Database_load(conn);
		}
	}

	if(!conn->file)
		die(conn, "Failed to open the file");

	return conn;
}

void Database_write(struct Connection *conn)
{
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);

	if(rc != 1)
		die(conn, "Failed to write database.");

	rc = fflush(conn->file);
	if(rc == -1) // EOF == -1
		die(conn, "Cann't flush database");
}

void Database_create(struct Connection *conn)
{
	int i = 0;
	
	// for(i = 0; i < MAX_ROWS; ++i) {
	// changed
	for(i = 0; i < conn->db->max_rows; ++i) {
		// make a prototype to initialize it
		struct Address addr = {.id = i, .set = 0};
		// then just assign it
		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &(conn->db->rows[id]);
	if(addr->set) {
		die(conn, "Already set, delete it first");
	}

	addr->set = 1;
	// WARNING: bug, read the "How To Break it" and fix this
	char *res;

	// res = strncpy(addr->name, name, MAX_DATA);
	res = strncpy(addr->name, name, conn->db->max_data);

	//addr->name[MAX_DATA - 1] = '\0';
	addr->name[conn->db->max_data - 1] = '\0';
	if(!res)
		die(conn, "Name copy failed");
	
	// res = strncpy(addr->email, email. MAX_DATA);
	res = strncpy(addr->email,email, conn->db->max_data);
	// addr->email[MAX_DATA - 1] = '\0';
	addr->email[conn->db->max_data - 1] = '\0';
	if(!res)
		die(conn, "Email copy failed");
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &(conn->db->rows[id]);

	if(addr->set) {
		Address_print(addr);
	} else {
		die(conn, "ID is not set");
	}
}

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
	int i = 0;
	// for(i = 0; i < MAX_ROWS; ++i) {
	for(i = 0; i < conn->db->max_rows; ++i) {
		if(conn->db->rows[i].set) {
			Address_print(&(conn->db->rows[i]));
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc < 3) {
		die_o("USAGE: ex17 <dbfile> <action> [action params]");
	/*change*/}

	char *filename = argv[1];
	char action = argv[2][0];

	// changed
	int max_rows = 0;
	int max_data = 0;
	if(action == 'c') {
		max_rows = atoi(argv[3]);
		max_data = atoi(argv[4]);
	}
	// end

	struct Connection *conn = Database_open(filename, action, max_rows, max_data);
	int id = 0;

	if(argc > 3 && action != 'c') id = atoi(argv[3]); // 将参数(address编号)转为整型
	if(id >= MAX_ROWS && action != 'c')
		die(conn, "There's not that many records.");

	switch(action) {
		case 'c':
			Database_create(conn);
			Database_write(conn);
			printf("max_rows:%d, max_data:%d\n",conn->db->max_rows, conn->db->max_data);
			break;

		case 'g':
			if(argc != 4)
				die(conn, "Need an ID to get");

			Database_get(conn,id);
			printf("max_rows:%d, max_data:%d\n",conn->db->max_rows, conn->db->max_data);
			break;

		case 's':
			if(argc != 6)
				die(conn, "Need ID, name and email to set");
			
			Database_set(conn,id,argv[4],argv[5]);
			Database_write(conn);
			printf("max_rows:%d, max_data:%d\n",conn->db->max_rows, conn->db->max_data);
			break;

		case 'd':
			if(argc != 4) {
				die(conn, "Need an ID to delete");
			}
			Database_delete(conn,id);
			Database_write(conn);
			printf("max_rows:%d, max_data:%d\n",conn->db->max_rows, conn->db->max_data);
			break;

		case 'l':
			Database_list(conn);
			printf("max_rows:%d, max_data:%d\n",conn->db->max_rows, conn->db->max_data);
			break;

		default:
			die(conn, "Invaild action, only: c=create, g=get, s=set, d=delete, l=list");

	}

	Database_close(conn);

	return 0;
}
