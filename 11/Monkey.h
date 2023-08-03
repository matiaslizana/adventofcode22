#pragma once
#include <queue>
#include <string>
#include <memory>
#include <iostream>

class Monkey
{
private:
	std::queue<int> items;
	std::string operationOp;
	std::string operationVal;
	int divisible;
	std::shared_ptr<Monkey> trueMonkey;
	std::shared_ptr<Monkey> falseMonkey;
	int inspectedItems;

public:
	Monkey();

	void AddItem(const int item);
	void SetOperation(const std::string& operationOp, const std::string& operationVal);
	void SetDivisible(const int divisible);
	void SetTrueMonkey(const std::shared_ptr<Monkey> monkey);
	void SetFalseMonkey(const std::shared_ptr<Monkey> monkey);
	int GetOperatedValue(int item);
	void ThrowItem(const std::shared_ptr<Monkey> monkey, int item);
	void ShowItems();
	int GetInspectedItems();
	void Turn();
};

