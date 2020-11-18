#include "list.h"

int List::read (const char * name)//, List_node *& head)
{
	FILE *fp = nullptr;
	List_node *tail = nullptr, *tmp = nullptr;
	int ret_code;
	
	if (head != nullptr)
	{
		return RET_CODES::INPUT_NON_ZERO_PTR_ERROR;
	}
	
	fp = fopen (name, "r");
	if (fp == nullptr)
	{
		return RET_CODES::OPEN_FILE_ERROR;
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
			return RET_CODES::READ_HEAD_ERROR;
		}
		fclose (fp);
		//Пустой файл мы не считаем ошибкой.
		return RET_CODES::SUCCESS;
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
			clear_list (), fclose (fp);
			return RET_CODES::BAD_FORMAT_ERROR;
		} 
		tail->next = tmp, tmp->prev = tail;
		tail = tail->next;
	}
	tmp = nullptr;

	if (!feof (fp))
	{
		//Файл не был считан до конца.
		clear_list (), fclose (fp);
		return RET_CODES::NO_REACH_EOF_ERROR;
	}
	
	//Успешное чтение завершено.
	fclose (fp);
	return RET_CODES::SUCCESS;
}

void List::clear_list (void)
{
	List_node * next;
	
	while (head != nullptr)
	{
		next = head->get_next ();
		delete head;
		head = next;
	}
	head = nullptr;
}

void List::print (int max_print, FILE *fp)
{
	int i;
	List_node * head = this->head;
	if (head == nullptr)
		fprintf (fp, "Empty list\n");
	for (i = 0; (i < max_print) && (head != nullptr); i++)
	{
		fprintf (fp, "%d) ", i);
		head->print (fp);
		fprintf (fp, "\n");
		head = head->next;
	}
}

void List::error_handler (int er)
{
	switch (er)
	{
		case RET_CODES:: INPUT_NON_ZERO_PTR_ERROR:
			printf ("Non zero pointer was given for \"read_list\" function\n");
			break;
		case RET_CODES:: OPEN_FILE_ERROR:
			printf ("Can't open file\n");
			break;
		case RET_CODES:: READ_HEAD_ERROR:
			printf ("Can't read a \"head\"\n");
			break;
		case RET_CODES:: NO_REACH_EOF_ERROR:
			printf ("Can't reach EOF\n");
			break;
		case RET_CODES::BAD_FORMAT_ERROR:
			printf ("Incorrect format of data\n");
			break;
		default: 
			printf ("Unknown error in \"read_list\" function\n");
			break;
	}
}

int List::get_length (void) const
{
	List_node * head = this->head;
	int i = 0;
	
	while (head != nullptr)
	{
		i++;
		head = head->next;
	}
	return i;
}