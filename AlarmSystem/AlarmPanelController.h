#pragma once
#include "AlarmPanel.h"
#include "AlarmPanelView.h"

class AlarmPanelController
{
private:
	AlarmPanel* _model;
	AlarmPanelView* _view;

public:
	AlarmPanelController(AlarmPanel*, AlarmPanelView*);
	void get_input();
};

