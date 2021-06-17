//Task 5.1 Variant 1

/*Дан двунаправленный закольцованный список, каждый элемент
которого содержит указатель на стек. Элементы стеков содержат
символы. Отсортировать по алфавиту элементы каждого стека и
вывести их на печать. Выполнить слияние стеков в один
упорядоченный по алфавиту стек и распечатать его.*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>


struct stack // Стек в виде односвязного списка
{
	char data;
	stack* next;
};

void initializedStack(stack** pointerToTheStack)//инициализация стека
{
	*pointerToTheStack = nullptr;
}

int isEmpty(stack** pointerToTheStack)
{
	if (pointerToTheStack == nullptr)
		return 1;// пустой
	return 0;// не пустой
}

void push(stack** pointerToTheStack, int variable)//занесение в стек
{
	stack* indicative_object = (stack*)malloc(sizeof(stack));

	if (indicative_object == nullptr)
	{
		printf("Could not allocate memory.\n");
		return;
	}

	indicative_object->data = variable;//перенаправление указателя на след элемент списка
	indicative_object->next = *pointerToTheStack;
	*pointerToTheStack = indicative_object;
	free(indicative_object);
}

int pop(stack** pointerToTheStack)//выборка из стека
{
	int variable;
	stack* temp;

	variable = (*pointerToTheStack)->data;
	temp = *pointerToTheStack;
	(*pointerToTheStack) = (*pointerToTheStack)->next;
	free( temp);

	return variable;
}

int top(stack* pointerToTheStack)//возврат верхнего элемента без удаления
{
	return pointerToTheStack->data;
}

void sorted_Insert(stack** pointerToTheStack, int variable)//Отсортированная вставка
{
	if (isEmpty(pointerToTheStack) || variable < top(*pointerToTheStack))
	{
		push(pointerToTheStack, variable);
		return;
	}

	//рекурсия
	int temp = pop(pointerToTheStack);
	sorted_Insert(pointerToTheStack, variable);
	push(pointerToTheStack, temp);
}

void sort_Stack(stack** pointerToTheStack)//Сортировка стека
{
	if (!isEmpty(pointerToTheStack))
	{
		int variable = pop(pointerToTheStack); // Удаляем верхний элемент
		sort_Stack(pointerToTheStack); // Сортируем оставшийся стек
		sorted_Insert(pointerToTheStack, variable); // Возвращаем верхний элемент в сортированный стек
	}
}

void print_Stack(stack* pointerToTheStack)//печать стека
{
	while (pointerToTheStack)
	{
		printf("%d\n", pointerToTheStack->data);
		pointerToTheStack = pointerToTheStack->next;
	}
	printf("\n");
}

void merge_Stack(stack*& object1, stack*& object2)//слияние стеков
{
	if (object1->next != nullptr)
		merge_Stack(object1->next, object2);//слияние
	push(&object2, object1->data);

	delete object1;
	object1 = nullptr;
}


struct list //Двусвязный циклический список
{
	stack* field;
	list* next, * prev;
};

list* init(stack* start)//инициализировать
{
	list* lst_element = (list*)malloc(sizeof(list));
	//задается указатель на предыдущий и следующий элемент
	lst_element->field = start;
	lst_element->next = lst_element;
	lst_element->prev = lst_element;
	return lst_element;
}

list* add_element(list* lst_element, stack* number)//добавление
{
	list* temp = (list*)malloc(sizeof(list));
	list* pointer;

	pointer = lst_element->next;//получает значения след элемента
	lst_element->next = temp;
	temp->field = number;
	temp->next = pointer;
	temp->prev = lst_element;
	pointer->prev = temp;
	free(pointer);
	return temp;
}

void list_Print(list* lst_element)//печать
{
	list* pointer;
	pointer = lst_element;
	do
	{
		print_Stack(pointer->field);
		pointer = pointer->next;
	} 	while (pointer != lst_element);
	free(pointer);
}

void merge_All(list* lst_element)//cлияние
{
	list* pointer;
	pointer = lst_element;
	do
	{
		merge_Stack(pointer->field, lst_element->field);
		pointer = pointer->next;
	} 	while (pointer != lst_element);

	free(pointer);
}

void sort_All(list* lst_element)//сортировка
{
	list* pointer;
	pointer = lst_element;
	do
	{
		sort_Stack(&pointer->field);
		pointer = pointer->next;
	} 	while (pointer != lst_element);
	free(pointer);
}

int main()
{
	stack* start;
	initializedStack(&start);
	push(&start, 0);

	list* list1;
	list1 = init(start);

	stack* stack_1;
	initializedStack(&stack_1);
	push(&stack_1, 'a');
	push(&stack_1, 'c');
	push(&stack_1, 'b');
	push(&stack_1, 'e');
	push(&stack_1, 'd');

	stack* stack_2;
	initializedStack(&stack_2);
	push(&stack_2, 'h');
	push(&stack_2, 'p');
	push(&stack_2, 'r');
	push(&stack_2, 'x');
	push(&stack_2, 'z');

	stack* stack_3;
	initializedStack(&stack_3);
	push(&stack_3, 'k');
	push(&stack_3, 'f');
	push(&stack_3, 'i');
	push(&stack_3, 'w');
	push(&stack_3, 't');
	push(&stack_3, 's');

	add_element(list1, stack_1);
	add_element(list1, stack_2);
	add_element(list1, stack_3);

	printf("Initialized stacks: ");
	list_Print(list1);
	printf("\n");

	sort_All(list1);
	printf("Sorted stacks: ");
	list_Print(list1);
	printf("\n");

	merge_All(list1);
	sort_All(list1);
	printf("Merged stacks: ");
	list_Print(list1);

	_getch();
}