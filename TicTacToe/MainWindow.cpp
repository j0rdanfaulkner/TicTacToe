#include "OpponentSelectionWindow.h"

using namespace System;
using namespace System::Windows::Forms;

// entry point of application
[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TicTacToe::OpponentSelectionWindow form;
	Application::Run(% form);
}