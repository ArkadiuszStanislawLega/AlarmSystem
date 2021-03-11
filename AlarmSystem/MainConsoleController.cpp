#include "MainConsoleController.h"


MainConsoleController::MainConsoleController()
{
    this->_isWorking = true;
    this->_command = start;
}


MainConsoleView* MainConsoleController::GetView()
{
    return this->_view;
}
MainConsole* MainConsoleController::GetModel()
{
    return this->_model;
}



void MainConsoleController::CheckInput()
{
    std::cin >> this->_currentCommand;
}

void MainConsoleController::MainLoop()
{
    this->_view->PrintWelcome();

    while (this->_isWorking)
    {
        CheckInput();
        ConvertInput();
        MakeCommand();
    }
}

void MainConsoleController::SetModel(MainConsole* model)
{
    this->_model = model;
}

void MainConsoleController::SetView(MainConsoleView* view)
{
    this->_view = view;
}

void MainConsoleController::ConvertInput()
{
    if (this->_currentCommand == "exit")
        this->_command = ex;

    if (this->_currentCommand == "help")
        this->_command = help;

    if (this->_currentCommand == "status")
        this->_command = status;

    if (this->_currentCommand == "connect")
        this->_command = connect;

    if (this->_currentCommand == "createap")
        this->_command = createAp;

    if (this->_currentCommand == "enter")
        this->_command = enter;
    if (this->_currentCommand == "removeap")
        this->_command = removeAp;

    if (this->_currentCommand == "getpanels")
        this->_command = getPanels;
}

void MainConsoleController::MakeCommand()
{
    switch (this->_command)
    {
    case ex:
    {
        this->_isWorking = false;
        break;
    }
    case help:
    {    this->_view->PrintHelp();
        break;
    }
    case status:
    {
        PortsStatus();
        break;
    }
    case connect:
    {
        Connect();
        break;
    }
    case createAp:
    {
        CreateNewAlarmPanel();
        break;
    }
    case removeAp:
    {
        RemoveAlarmPanel();
        break;
    }

    case getPanels:
    {
        GetAlarmPanels();
        break;
    }
    case enter:
    {
        Enter();
        break;
    }
    default:
    {
        this->_view->PrintInvalidCommand();
        this->_view->PrintWelcome();
        break;
    }
    }
}

    void MainConsoleController::PortsStatus()
    {
        this->_view->PrintPortStatus(this->_model->GetPorts(), this->_model->MAX_NUMBER_OF_PORTS);
    }

    void MainConsoleController::Connect()
    {
        int idPortInput, idPort2Input;

        this->_view->PrintGetTwoPortsToConnect();
        std::cin >> idPortInput >> idPort2Input;

        if (this->_model->ConnectPort(idPortInput, idPort2Input))
            this->_view->PrintConnectPort(FindPort(idPortInput), FindPort(idPort2Input));
        else
            this->_view->PrintConnectPortsFail();

    }

    Port* MainConsoleController::FindPort(int id)
    {
        return this->_model->FindPort(id);
    }

    void MainConsoleController::Create()
    {

    }

    void MainConsoleController::Enter()
    {
        std::cout << this->_model->GetPorts()[0].GetConnectedPort()->GetParent()->GetId() << std::endl;
    }

    void MainConsoleController::CreateNewAlarmPanel()
    {
        int idInput;
        std::string nameInput;

        this->_view->CreateNewAlarmPanel();

        std::cin >> idInput >> nameInput;

        if (this->_model->CreateAlarmPanel(AlarmPanel(idInput, nameInput)))
            this->_view->CreatedNewAlarmPanel();
        else
            this->_view->CreatedNewAlarmPanelFailed();
    }

    void MainConsoleController::GetAlarmPanels()
    {
        this->_view->PrintAlarmPanels(this->_model->GetAlarmPanels(), this->_model->MAX_NUMBER_OF_DEVICES);
    }

    void MainConsoleController::RemoveAlarmPanel()
    {
        int idInput;
        this->_view->PrintGetIdOfAlarmPanel();

        std::cin >> idInput;

        if (this->_model->RemoveAlarmPanel(idInput))
            this->_view->PrintRemovedAlarmPanelSuccessful();
        else
            this->_view->PrintRemovedAlarmPanelFailed();
    }
