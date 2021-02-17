#pragma once
#include "View.h"

class AlarmPanelController;
class AlarmPanelView : public View
{
private:
	AlarmPanelController* _controller;

public:
	AlarmPanelView(int = 0, std::string = "Alarm Panel View" );

	virtual int View::Id();
	virtual std::string View::Name();

	virtual void View::print();	
	void print_authentication(bool);
	void set_controller(AlarmPanelController* controller);
};

