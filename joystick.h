#include <linux/joystick.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <linux/ioctl.h>

class Joystick {
public:
	Joystick(const char *js_device, void (*setCallback)(struct js_event e));
	~Joystick();
	void getInput();

	/* Some state things */
	bool busy() { return _busy; };
	bool connected() { return _connected; };
	int number_of_buttons() { return _number_of_buttons; };
	int number_of_axes() { return _number_of_axes; };
	int button(int index);
	int axis(int index);

private:
	bool _busy = false;
	bool _connected = false;
	int _number_of_buttons;
	int _number_of_axes;
	__s16 *_axis;
	__s16 *_button;

	void (*callback)(struct js_event e);
	int fd;
	bool wait_for_next_event(struct js_event *e);
};
