#include <iostream>
#include <string>
#include "SLData.h"

using std::cin;
using std::cout;
using std::endl;

	//https://gist.github.com/charlierm/5691020
	//http://www.cplusplus.com/doc/tutorial/arrays/

	LinkedList::LinkedList()
	{
		
		this->lenth = 0;
		this->head = NULL;
	}

	LinkedList::~LinkedList()
	{
		cout << "Have a good life!" << endl;//when the linked list deletes, print out this message
	}

	void LinkedList::add(float data)
	{
		Node* node = new Node();
		node->data = data;
		node->next = this->head;
		this->head = node;
		this->lenth++;
	}

	void LinkedList::insertToList(Node * current, float data)
	{
		Node *head = current;

		while (current->next != head)
		{
			current = current->next;
		}
	}

	
	void LinkedList::printSummary()
	{
		Node* head = this->head;

	}
	

	int main()
	{
		cout << " Sugar Level Recording Machine" << endl << endl;
		string a("0.00");
		int day(0);
		LinkedList Days[13] = {};		
		//LinkedList Weeks[2] = {};

		while (true) {
			cout << "Enter Blood Sugar Level Then Press Enter: " << endl;
			cin >> a;
			if ((a == "N") || (a == "Next")) 
			{
				//Increment to the next day (4 pts).
				day++;
				cout << "Moving to day " << day+1 << ". \n\n";
			}
			else if ((a == "D") || (a == "Day")) 
			{
				//Show the Daily summary thus far.(4 pts)
				cout << "<Here is your daily summary for day "<< day+1 <<">"<<endl;
				float max = Days[day].head->data; //use float type so we can put in an integer/float
				float min = Days[day].head->data;
				float sum = 0;
				Node* position = Days[day].head;
				for (int i = 0; i < Days[day].lenth; i++)
				{
					if (position->data > max) {
						max = position->data;
					}
					if (position->data < min) {
						min = position->data;
					}
					sum = sum + position->data;
					position = position->next;

				}
				cout << "MAX BG: " << max << endl;
				cout << "MIN BG: " << min << endl;
				cout << "SUM BG: " << sum << endl;
				cout << "BG COUNT: " << Days[day].lenth << endl <<endl;
			}
			else if ((a == "W") || (a == "Week")) 
			{
				//Show the Weekly summary thus far.(4 pts)
				int week = 1;
				int w = 0;
				if (day > 6) 
				{
					week = 2;
					w = 6;
				}
				cout << "<Here is your weekly summary for week " << week << ">" << endl;
				/*float max = Days[0].head->data;
				float min = Days[0].head->data;
				float sum = 0;
				int weekCount = 0;
				int w = 0;
				int delta = 0;
				Node* position = Days[day].head;
				for (int i = 0; i < Days[day].lenth; i++)
				{
					if (position->data > max) {
						max = position->data;
					}
					if (position->data < min) {
						min = position->data;
					}
					sum = sum + position->data;
					position = position->next;
					weekCount = weekCount + Days[w].lenth;
				}
					
				cout << "WEEKLY MAX BG: " << max << endl;
				cout << "WEEKLY MIN BG: " << min << endl;
				cout << "WEEKLY SUM BG: " << sum << endl;
				cout << "WEEKLY BG COUNT: " << weekCount << endl;
				cout << "The biggest day to day delta occured on the " << delta + 1 << " day. " << endl << endl;
			}*/
				
				float max = Days[0].head->data;
				float min = Days[0].head->data;
				float sum = 0;
				int weekCount = 0;
				int deltaDay = 0;
				float oldDelta = 0.00;
				do {
					Node* position = Days[w].head;
					weekCount = weekCount + Days[w].lenth;
					for (int i = 0; i < Days[w].lenth; i++)
					{
						if (position->data > max) 
						{
							max = position->data;
						}
						if (position->data < min)
						{
							min = position->data;
						}
						sum = sum + position->data;
						position = position->next;
					}
					if ((max - min) > oldDelta) 
					{
						oldDelta = (max - min);
						deltaDay = w;
					}
					w++;
			} while (w < day+1);
				cout << "WEEKLY MAX BG: " << max << endl;
				cout << "WEEKLY MIN BG: " << min << endl;
				cout << "WEEKLY SUM BG: " << sum << endl;
				cout << "WEEKLY BG COUNT: " << weekCount << endl;
				cout << "The biggest day to day delta occured on the " << deltaDay + 1 << " day. " << endl <<endl;
			}
			//Q: connection between days sum and n
			//Q: how to end this program
			else 
			{
				try 
				{
					if (stof(a) > 0) 
					{
						Days[day].add(stof(a));//keep track of the current day, convert strng a to an integer
					}
				}			
				catch (exception) {}		//make sure code doesn't blow up if they put in invalided input
			}
		}
	}