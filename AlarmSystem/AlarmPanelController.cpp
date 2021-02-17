#include "AlarmPanelController.h"

AlarmPanelController::AlarmPanelController(AlarmPanel* model, AlarmPanelView* view)
{
	_model = model;
	_view = view;
}

void AlarmPanelController::get_input()
{

}

void AlarmPanelController::set_model(AlarmPanel* model)
{
	_model = model;
}

void AlarmPanelController::set_view(AlarmPanelView* view)
{
	_view = view;
}
