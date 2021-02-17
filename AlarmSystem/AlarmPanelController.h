#pragma once
#include "AlarmPanel.h"
#include "AlarmPanelView.h"

class AlarmPanelController
{
private:
	AlarmPanel* _model;
	AlarmPanelView* _view;
	
	int _input_pin{ 0 };
	int _input_password{ 0 };
	 
public:
	AlarmPanelController(AlarmPanel*, AlarmPanelView*);
	void get_input();
	void set_model(AlarmPanel* model);
	void set_view(AlarmPanelView* view);
	void login();
};

