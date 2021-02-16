#pragma once
#include "View.h"

class AlarmPanelController;
class AlarmPanelView : public View
{
private:
	AlarmPanelController* _controller;

public:
	AlarmPanelView(int, std::string, AlarmPanelController*);

	virtual int View::Id();
	virtual std::string View::Name();

	virtual void View::print();	
	void print_authentication(bool);

};

