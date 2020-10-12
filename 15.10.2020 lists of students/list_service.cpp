#include "list_service.h"

int read_list (const char * name, List_node *& head)
{
	FILE *fp = nullptr;
	List_node *tail = nullptr, *tmp = nullptr;
	int ret_code;
	
	if (head != nullptr)
	{
		return LIST_SERVICE_RET_CODES::INPUT_NON_ZERO_PTR_ERROR;
	}
	
	fp = fopen (name, "r");
	if (fp == nullptr)
	{
		return LIST_SERVICE_RET_CODES::OPEN_FILE_ERROR;
	}
	
	//Чтение головы.
	head = new List_node;
	ret_code = head->read (fp);
	if (ret_code != Student::SUCCESS)
	{
		//Поскольку чтения не получилось - head возвращаем в исходное состояние,
		//а память ему выделенную - очищаем.
		delete head;
		head = nullptr;
		if (!feof (fp))
		{
			fclose (fp);
			return LIST_SERVICE_RET_CODES::READ_HEAD_ERROR;
		}
		fclose (fp);
		//Пустой файл мы не считаем ошибкой.
		return LIST_SERVICE_RET_CODES::SUCCESS;
	}

	tail = head;
	while (1)
	{
		tmp = new List_node;
		ret_code = tmp->read (fp);
		if (ret_code != Student::SUCCESS)
		{
			delete tmp;
			if (feof (fp))
				break;
			delete_list (head), fclose (fp);
			return LIST_SERVICE_RET_CODES::BAD_FORMAT_ERROR;
		} 
		tail->set_next (tmp);
		tail = tail->get_next();
	}
	tmp = nullptr;

	if (!feof (fp))
	{
		//Файл не был считан до конца.
		delete_list (head), fclose (fp);
		return LIST_SERVICE_RET_CODES::NO_REACH_EOF_ERROR;
	}
	
	//Успешное чтение завершено.
	fclose (fp);
	return LIST_SERVICE_RET_CODES::SUCCESS;
}

void delete_list (List_node *& head_arg)
{
	List_node * next, * head;
	
	head = head_arg;
	while (head != nullptr)
	{
		next = head->get_next ();
		delete head;
		head = next;
	}
	head_arg = nullptr;
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
		case LIST_SERVICE_RET_CODES::BAD_FORMAT_ERROR:
			printf ("Incorrect format of data\n");
			break;
		default: 
			printf ("Unknown error in \"read_list\" function\n");
			break;
	}
}
