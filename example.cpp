#include "joystick.h"

#include <thread>

using namespace std;

void gotEvent(struct js_event e) {
	cout << "Event at time: " << (int)e.time << endl
		<< "\tType: " << (int)e.type << endl
		<< "\tAxis/Btn Number: " <<  (int)e.number << endl
		<< "\tValue: " << (int)e.value << endl;
}

void followJoystick() {
	Joystick inp = Joystick("/dev/input/js0", gotEvent);
	inp.getInput();
}

int main() {
	thread t1(followJoystick);
	t1.join();
	return 0;
}

