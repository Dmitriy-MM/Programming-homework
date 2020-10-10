#include "list_service.h"

int read_list (const char * name, List_node *& head)
{
	FILE *fp = nullptr;
	List_node *tail = nullptr;
	const int LEN = 1234;
	char buf[LEN] = {0};
	int value;
	
	if (head != nullptr)
	{
		return LIST_SERVICE_RET_CODES::INPUT_NON_ZERO_PTR_ERROR;
	}
	
	fp = fopen (name, "r");
	if (fp == nullptr)
	{	//Файл не открылся.
		return LIST_SERVICE_RET_CODES::OPEN_FILE_ERROR;
	}
	
	//Чтение головы.
	if (fscanf (fp, "%s%d", buf, &value) != 2)
	{
		//В файле не получилось считать голову.
		fclose (fp);
		return LIST_SERVICE_RET_CODES::READ_HEAD_ERROR;
	}
	else 
	{
		head = new List_node (buf, value);
	}
	
	tail = head;
	while ( (fscanf (fp, "%s%d", buf, &value) == 2) )
	{
		tail->set_next (new List_node (buf, value));
		tail = tail->get_next();
	}
	if (!feof (fp))
	{
		//Файл не был считан до конца.
		delete_list (head);
		fclose (fp);
		return LIST_SERVICE_RET_CODES::NO_REACH_EOF_ERROR;
	}
	
	//Успешное чтение завершено.
	fclose (fp);
	return LIST_SERVICE_RET_CODES::SUCCESS;
}

void delete_list (List_node * head)
{
	List_node * next;
	
	while (head != nullptr)
	{
		next = head->get_next ();
		head->~List_node ();
		head = next;
	}
}

void print_list (List_node * head, int max_print, FILE *fp)
{
	int i;
	for (i = 0; (i < max_print) && (head != nullptr); i++)
	{
		head->print (fp);
		fprintf (fp, "\n");
		head = head->get_next ();
	}
}

void LIST_SERVICE_RET_CODES::error_handler (int er)
{
	switch (er)
	{
		case LIST_SERVICE_RET_CODES:: INPUT_NON_ZERO_PTR_ERROR:
			printf ("Non zero pointer was given for \"read_list\" function\n");
			break;
		case LIST_SERVICE_RET_CODES:: OPEN_FILE_ERROR:
			printf ("Can't open file\n");
			break;
		case LIST_SERVICE_RET_CODES:: READ_HEAD_ERROR:
			printf ("Can't read a \"head\"\n");
			break;
		case LIST_SERVICE_RET_CODES:: NO_REACH_EOF_ERROR:
			printf ("Can't reach EOF\n");
			break;
		default: 
			printf ("Unknown error in \"read_list\" function\n");
			break;
	}
}