#pragma once

class Item
{
	public:
		Item(int value)
		{
			this->value = value;
			this->next = 0;
		}
		int GetValue()
		{
			return value;
		}
		void ToString()
		{
		
		}
		Item* next;

	private:
		int value;
		

};

Item* Reverse(Item* i, Item** ni)
{
	if(i->next == 0)
	{
		*ni = new Item(i->GetValue());
		return *ni;
	}
	Item* tail = Reverse(i->next, ni);
	tail->next = new Item(i->GetValue());
	return tail->next;
}

void main()
{
	Item* i = new Item(1);
	i->next = new Item(2);
	i->next->next = new Item(3);
	i->next->next->next = new Item(4);

	Item* ni = 0;
	Item* tail = Reverse(i, &ni);

	int a = 0;

}

