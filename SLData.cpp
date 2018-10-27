//Yikai Peng
//Oct.25
//SLData.cpp

#include <iostream>
#include <string>
#include <cmath>
#include "SLData.h"

using std::cin;
using std::cout;
using std::endl;

	//Linked list example:https://gist.github.com/charlierm/5691020

	LinkedList::LinkedList()
	{
		
		this->lenth = 0;
		this->head = NULL;
	}

	LinkedList::~LinkedList()
	{
		
	}

	void LinkedList::add(float data)
	{
		Node* node = new Node();
		node->data = data;
		node->next = this->head;
		this->head = node;
		this->lenth++;
	}


	int main()
	{
		cout << " Sugar Level Recording Machine" << endl << endl;
		cout << "Please enter your blood sugar level, then press enter to put in next record: " << endl;
		cout << "Press 'N' or 'Next' for next day records" << endl;
		cout << "Press 'Quit' to exit this machine" << endl;
		cout << "To get daily summary, press 'D' or 'Day'" << endl;
		cout << "To get weekly summary, press 'W' or 'Week'" << endl;
		string a("0.00");
		int day(0);
		LinkedList Days[13] = {};		
		//LinkedList Weeks[2] = {};

		while (true) {
			cout << "\nBlood Sugar Level / Any options above: ";
			cin >> a;
			if ((a == "N") || (a == "Next")) 
			{
				//Increment to the next day (4 pts).
				day++;
				cout << "\nDay " << day << " data ends" << "\nNow moving to day " << day + 1 << endl << endl;
			}
			else if ((a == "D") || (a == "Day")) 
			{
				//Show the Daily summary thus far.(4 pts)
				cout << "\n<Here is your daily summary for day "<< day+1 <<">"<<endl;
				float max = Days[day].head->data; //use float type so we can put in an integer/float
				float min = Days[day].head->data;
				float sum = 0;
				Node* position = Days[day].head;
				for (int i = 0; i < Days[day].lenth; i++)
				{
					position = position->next;
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
				cout << "\n<Here is your weekly summary for week " << week << ">" << endl;
				
				float max = Days[w].head->data;
				float min = Days[w].head->data;
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
					if (w != 0) {
						if ((abs((Days[w].lenth) - Days[(w - 1)].lenth)) > oldDelta) //Will have to change to match new def of delta
						{
							oldDelta = (abs((Days[w].lenth) - Days[(w - 1)].lenth));
							deltaDay = w;
						}
					}
					w++;
					} while (w < day+1);
					/*if ((max - min) > oldDelta)
					{
						oldDelta = (max - min);
						deltaDay = w;
					}*/
			
				cout << "WEEKLY MAX BG: " << max << endl;
				cout << "WEEKLY MIN BG: " << min << endl;
				cout << "WEEKLY SUM BG: " << sum << endl;
				cout << "WEEKLY BG COUNT: " << weekCount << endl;
				cout << "The biggest day to day delta was from day " << deltaDay << " to day " << deltaDay+1 << endl;
				//cout << "The biggest day to day delta " << oldDelta << " occured on day " << deltaDay+1 << endl << endl;
			}
			else if (a == "Quit")
			{
				cout << "Have a good life!" << endl; //when quit, print out this message
				exit(0);
			}
			else 
			{
				try 
				{
					if (stof(a) > 0) 
					{
						Days[day].add(stof(a)); //keep track of the current day, convert strng a to an integer
					}
				}			
				catch (exception) {} //make sure code doesn't blow up if they put in invalided input
			}
		}
	}