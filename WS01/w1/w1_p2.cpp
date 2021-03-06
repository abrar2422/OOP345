// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Cornel - 2020/01/08
// Chris - 2021/01/14

#include <iostream>
#include <fstream>
#include "event.h"
#include "event.h"

int main(int argc, char* argv[])
{
std::cout << "Command Line:\n";
for (int i = 0; i < argc; i++)
{
	std::cout << i + 1 << ": " << argv[i] << std::endl;
}


std::cout << std::endl;

// the archive can store maximum 10 events
sdds::Event archive[10];
// the index of the next available position in the archive
size_t idxArchive = 0;

sdds::Event currentEvent;

const size_t secInDay = 60u * 60u * 24u;// day has 86400 seconds

for (auto day = 1; day < argc; ++day)
{
	// each parameter for an application contains the events from one day
	// process each one
	std::cout << "--------------------\n";
	std::cout << "    Day " << day << '\n';
	std::cout << "--------------------\n";
	std::ifstream in(argv[day]);
	char opcode = '\0';
	size_t time = secInDay + 1;
	in >> opcode >> time;

	// starting at midnight, until the end of the day
	for (::g_sysClock = 174u; ::g_sysClock < secInDay; ++::g_sysClock)
	{
		// what should happen this second
		while (time == ::g_sysClock)
		{
			in.ignore();
			in >> opcode;
			if (in.fail())
				break;
			// handle the operation code
			switch (opcode)
			{
			case 'T': // a new time code, this is the exit from while loop (back to for loop)
				in >> time;
				break;
			case 'S': // start a new event, the old event is automatically finished
				char buffer[1024];
				in.get(buffer, 1024, ',');
				currentEvent.set(buffer);
				break;
			case 'E': // end the current event
				currentEvent.set();
				break;
			case 'P': // print to scren the information about the current event
				currentEvent.display();
				break;
			case 'A': // add a copy of the current event to the archive
				sdds::Event copy(currentEvent);
				archive[idxArchive++] = copy;
				break;
			}
		}
	}
}

// print the archive
std::cout << "--------------------\n";
std::cout << "    Archive\n";
std::cout << "--------------------\n";
for (auto i = 0u; i < idxArchive; ++i)
	archive[i].display();
std::cout << "--------------------\n";
}
