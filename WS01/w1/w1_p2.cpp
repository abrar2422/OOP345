// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Cornel - 2020/01/08
// Chris - 2021/01/14

#include <iostream>
#include <fstream>
#include "Event.h"
#include "Event.h"
extern unsigned g_sysClock;
/* input file format: a comma separated set of fields; some fields have a single parameter
T175,SComputer Starting,P,
codes
	T - time (parameter: a number representing the time--measured in seconds--when the following codes apply)
	S - start Event (parameter: a string representing the description for the Event that starts)
	E - end the Event
	P - print to screen
	A - archive
*/

// TODO: write the prototype for the main function
//         to accept command line arguments
int main(int argc, char* argv[])
{
	int i;
	std::cout << "Command Line:\n";
	// TODO: print the command line here, in the format
	// 1: first argument
	// 2: second argument
	// 3: third argument
	for (i = 0; i < argc; i++)
		std::cout << i + 1 << ": " << argv[i] << std::endl;

	std::cout << std::endl;


	// the archive can store maximum 10 Events
	sdds::Event archive[10];
	// the index of the next available position in the archive
	size_t idxArchive = 0;

	sdds::Event currentEvent;

	const size_t secInDay = 60u * 60u * 24u;// day has 86400 seconds

	for (auto day = 1; day < argc; ++day)
	{
		// each parameter for an application contains the Events from one day
		// process each one
		std::cout << "--------------------\n";
		std::cout << "    Day " << day << '\n';
		std::cout << "--------------------\n";
		std::ifstream in(argv[day]);
		char opcode = '\0';
		size_t time = secInDay + 1;
		in >> opcode >> time;

		// starting at midnight, until the end of the day
		for (::g_sysClock = 0u; ::g_sysClock < secInDay; ++::g_sysClock)
		{
			// what should happen this second
			while (time == ::g_sysClock)
			{
				// skip the delimiter
				in.ignore();
				// read the next opcode
				in >> opcode;

				// end of the file
				if (in.fail())
					break;

				// handle the operation code
				switch (opcode)
				{
				case 'T': // a new time code, this is the exit from while loop (back to for loop)
					in >> time;
					break;
				case 'S': // start a new Event, the old Event is automatically finished
					char buffer[1024];
					in.get(buffer, 1024, ',');
					currentEvent.set(buffer);
					break;
				case 'E': // end the current Event
					currentEvent.set();
					break;
				case 'P': // print to scren the information about the current Event
					currentEvent.display();
					break;
				case 'A': // add a copy of the current Event to the archive
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