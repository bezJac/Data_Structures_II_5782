#pragma once
#include <iostream>
#include <queue>
using namespace std;


class HuffmanNode
{
	friend class compareNode;
	friend class huffmanTree;
public:
	string str;
	int frequency;
	HuffmanNode* left;
	HuffmanNode* right;

public:
	HuffmanNode() {}
	HuffmanNode(int _frequency, string _str = "", HuffmanNode* _left = NULL, HuffmanNode* _right = NULL)
	{
		str = _str;
		frequency = _frequency;
		left = _left;
		right = _right;
	}
	HuffmanNode(HuffmanNode* _left = NULL, HuffmanNode* _right = NULL)
	{
		if (_left->frequency == _right->frequency)
		{
			left = _right;
			right = _left;
		}
		else
		{
			left = _left;
			right = _right;
		}
		frequency = _left->frequency + right->frequency;
		str = "";
	}
	

};

class compareNode
{
public:
	bool operator()(HuffmanNode* const& n1, HuffmanNode* const& n2)
	{

		return n1->frequency > n2->frequency;


	}
	
};





