default:
	# http://stackoverflow.com/questions/8649828/what-is-wrong-with-this-use-of-stdthread
	g++ example.cpp joystick.cpp -o example -std=c++11 -lpthread

clean:
	rm example
