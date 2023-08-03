#include "Monkey.h"

Monkey::Monkey() : inspectedItems{0}, divisible{0}
{
}

void Monkey::AddItem(const int item)
{
	this->items.push(item);
}

void Monkey::SetOperation(const std::string& operationOp, const std::string& operationVal)
{
	this->operationOp = operationOp;
	this->operationVal = operationVal;
}

void Monkey::SetDivisible(const int divisible)
{
	this->divisible = divisible;
}

int Monkey::GetOperatedValue(const int item)
{
	int newItem = operationVal.compare("old") == 0 ? item : stoi(operationVal);

	if (operationOp.compare("*") == 0)
		return newItem * item;

	if (operationOp.compare("+") == 0)
		return newItem + item;

	return 0;
}

void Monkey::ThrowItem(const std::shared_ptr<Monkey> monkey, const int item)
{
	monkey->AddItem(item);
}

void Monkey::ShowItems()
{
	std::queue<int> showItems = items;
	while (!showItems.empty())
	{
		std::cout << showItems.front() << ", ";
		showItems.pop();
	}
}

int Monkey::GetInspectedItems()
{
	return inspectedItems;
}

void Monkey::Turn()
{
	while (!items.empty())
	{
		//Inspect first element of the queue
		const int item = items.front();
		items.pop();
		inspectedItems++;

		//Calculates new worry level
		int newItem = GetOperatedValue(item);

		//Relief divided by 3
		newItem /= 3;

		//Test
		ThrowItem(newItem % divisible == 0 ? trueMonkey : falseMonkey, newItem);
	}
}

void Monkey::SetTrueMonkey(const std::shared_ptr<Monkey> monkey)
{
	trueMonkey = monkey;
}

void Monkey::SetFalseMonkey(const std::shared_ptr<Monkey> monkey)
{
	falseMonkey = monkey;
}