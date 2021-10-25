#include "HashClient.h";

int HashClient::Hash(string phone, int i)
{
	return HashTable::Hash(phone, i);
}
int HashClient::Search(string phone)
{
	return HashTable::Search(phone);
}
void HashClient::Delete(string phone)
{
	HashTable::Delete(phone);
}