#include "list_2.h"


int List_2::read (FILE *fp)
{
	List_2_node *tail = nullptr, *tmp = nullptr;
	int ret_code;
	int i = 0;
	
	if (head != nullptr)
	{
		return RET_CODES::INPUT_NON_ZERO_PTR_ERROR;
	}
	
	if (m <= 0)
		return SUCCESS;
	
	//Чтение головы.
	head = new List_2_node;
	ret_code = head->read (fp);
	if (ret_code != Student::SUCCESS)
	{
		//Поскольку чтения не получилось - head возвращаем в исходное состояние,
		//а память ему выделенную - очищаем.
		delete head;
		head = nullptr;
		// if (!feof (fp))
		// {
			// fclose (fp);
			// return RET_CODES::READ_HEAD_ERROR;
		// }
		// return RET_CODES::SUCCESS; - ЕСЛИ МЫ НЕ БУДЕМ СЧИТАТЬ ОШИБКОЙ ПУСТОЙ ФАЙЛ ЗНАЧИТ БУДЕТ БЕСКОНЕЧНОЕ ДЕРЕВО.
		return RET_CODES::READ_HEAD_ERROR;
	}
	i++;
	
	tail = head;
	while (1)
	{
		if (i >= m)
		{
			break;
		}
		tmp = new List_2_node;
		ret_code = tmp->read (fp);
		if (ret_code != Student::SUCCESS)
		{
			delete tmp;
			if (feof (fp))
				break;
			clear_list ();//, fclose (fp);
			return RET_CODES::BAD_FORMAT_ERROR;
		} 
		tail->next = tmp, tmp->prev = tail;
		tail = tail->next;
		i++;
	}
	tmp = nullptr;

	if ((!feof (fp)) && (i < m))
	{
		printf ("ne pishi\n");
		//Файл не был считан до конца.
		clear_list ();//, fclose (fp);
		return RET_CODES::NO_REACH_EOF_ERROR;
	}
	
	//Успешное чтение завершено.
	//fclose (fp);
	return RET_CODES::SUCCESS;
}

void List_2::clear_list (void)
{
	List_2_node * next;
	
	while (head != nullptr)
	{
		next = head->get_next ();
		delete head;
		head = next;
	}
	head = nullptr;
}

void List_2::print (FILE *fp)
{
	int i;
	List_2_node * head = this->head;
	if (head == nullptr)
		fprintf (fp, "Empty list\n");
	for (i = 0; (i < List_2::r) && (head != nullptr); i++)
	{
		fprintf (fp, "%d) ", i);
		head->print (fp);
		fprintf (fp, ";");
		head = head->next;
	}
}

void List_2::error_handler (int er)
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

int List_2::get_length (void) const
{
	List_2_node * head = this->head;
	int i = 0;
	
	while (head != nullptr)
	{
		i++;
		head = head->next;
	}
	return i;
}

int List_2::operator< (const List_2& second_list2)
{
	const int TRUE = 1, FALSE = 0;
	
	if (second_list2.head == nullptr)
			return FALSE;
	else if (this->head == nullptr)
			return TRUE;
	else 
		return (*(this->head) < *(second_list2.head));
}