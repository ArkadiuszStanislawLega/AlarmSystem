#pragma once
class AlarmPanel;
class AlarmPanelView;

class AlarmPanelController
{
private:
	AlarmPanel* _model;
	AlarmPanelView* _view;

public:
	AlarmPanelController(AlarmPanel* = 0, AlarmPanelView* = 0);
	void get_input();
	void set_model(AlarmPanel* model);
	void set_view(AlarmPanelView* view);
};

