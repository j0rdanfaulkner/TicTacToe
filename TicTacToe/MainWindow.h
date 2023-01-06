#pragma once
#include<iostream>
#include<cstdlib>
namespace TicTacToe {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		// constant variables for the number of rows and columns
		const int ROWS = 3;
		const int COLS = 3;
		int currentTurn;
		int positionOwner;
		MainWindow(void)
		{
			InitializeComponent();
			startGame();
		}
		void startGame()
		{
			currentTurn = rand() % 2;
			MessageBox::Show("Player " + currentTurn + " will go first", "Starting Player", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
	private: System::Void btnR1C1_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlBackground;
	private: System::Windows::Forms::Panel^ pnlGameArea;
	private: System::Windows::Forms::Button^ btnR3C3;

	private: System::Windows::Forms::Button^ btnR3C2;

	private: System::Windows::Forms::Button^ btnR3C1;

	private: System::Windows::Forms::Button^ btnR2C3;

	private: System::Windows::Forms::Button^ btnR2C2;

	private: System::Windows::Forms::Button^ btnR2C1;

	private: System::Windows::Forms::Button^ btnR1C3;

	private: System::Windows::Forms::Button^ btnR1C2;

	private: System::Windows::Forms::Button^ btnR1C1;
	private: System::Windows::Forms::Panel^ pnlInformation;

	private: System::Windows::Forms::Label^ lblDescription;
	private: System::Windows::Forms::Label^ lblCurrentTurn;
	private: System::Windows::Forms::Button^ btnReset;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnlBackground = (gcnew System::Windows::Forms::Panel());
			this->pnlInformation = (gcnew System::Windows::Forms::Panel());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->lblDescription = (gcnew System::Windows::Forms::Label());
			this->lblCurrentTurn = (gcnew System::Windows::Forms::Label());
			this->pnlGameArea = (gcnew System::Windows::Forms::Panel());
			this->btnR3C3 = (gcnew System::Windows::Forms::Button());
			this->btnR3C2 = (gcnew System::Windows::Forms::Button());
			this->btnR3C1 = (gcnew System::Windows::Forms::Button());
			this->btnR2C3 = (gcnew System::Windows::Forms::Button());
			this->btnR2C2 = (gcnew System::Windows::Forms::Button());
			this->btnR2C1 = (gcnew System::Windows::Forms::Button());
			this->btnR1C3 = (gcnew System::Windows::Forms::Button());
			this->btnR1C2 = (gcnew System::Windows::Forms::Button());
			this->btnR1C1 = (gcnew System::Windows::Forms::Button());
			this->pnlBackground->SuspendLayout();
			this->pnlInformation->SuspendLayout();
			this->pnlGameArea->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlBackground
			// 
			this->pnlBackground->BackColor = System::Drawing::Color::Maroon;
			this->pnlBackground->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlBackground->Controls->Add(this->pnlInformation);
			this->pnlBackground->Controls->Add(this->pnlGameArea);
			this->pnlBackground->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlBackground->Location = System::Drawing::Point(0, 0);
			this->pnlBackground->Name = L"pnlBackground";
			this->pnlBackground->Size = System::Drawing::Size(484, 461);
			this->pnlBackground->TabIndex = 0;
			// 
			// pnlInformation
			// 
			this->pnlInformation->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlInformation->BackColor = System::Drawing::Color::Firebrick;
			this->pnlInformation->Controls->Add(this->btnReset);
			this->pnlInformation->Controls->Add(this->lblDescription);
			this->pnlInformation->Controls->Add(this->lblCurrentTurn);
			this->pnlInformation->Location = System::Drawing::Point(75, 384);
			this->pnlInformation->Name = L"pnlInformation";
			this->pnlInformation->Size = System::Drawing::Size(350, 64);
			this->pnlInformation->TabIndex = 9;
			// 
			// btnReset
			// 
			this->btnReset->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnReset->BackColor = System::Drawing::Color::DarkRed;
			this->btnReset->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnReset->FlatAppearance->BorderSize = 5;
			this->btnReset->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnReset->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btnReset->Location = System::Drawing::Point(121, 38);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(108, 23);
			this->btnReset->TabIndex = 2;
			this->btnReset->Text = L"Reset Game";
			this->btnReset->UseVisualStyleBackColor = false;
			// 
			// lblDescription
			// 
			this->lblDescription->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblDescription->AutoSize = true;
			this->lblDescription->Location = System::Drawing::Point(76, 19);
			this->lblDescription->Name = L"lblDescription";
			this->lblDescription->Size = System::Drawing::Size(184, 18);
			this->lblDescription->TabIndex = 1;
			this->lblDescription->Text = L"Player 1: Xs, Player 2: Os";
			// 
			// lblCurrentTurn
			// 
			this->lblCurrentTurn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblCurrentTurn->AutoSize = true;
			this->lblCurrentTurn->Location = System::Drawing::Point(119, 0);
			this->lblCurrentTurn->Name = L"lblCurrentTurn";
			this->lblCurrentTurn->Size = System::Drawing::Size(106, 18);
			this->lblCurrentTurn->TabIndex = 0;
			this->lblCurrentTurn->Text = L"Current Turn:";
			// 
			// pnlGameArea
			// 
			this->pnlGameArea->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pnlGameArea->BackColor = System::Drawing::Color::Firebrick;
			this->pnlGameArea->Controls->Add(this->btnR3C3);
			this->pnlGameArea->Controls->Add(this->btnR3C2);
			this->pnlGameArea->Controls->Add(this->btnR3C1);
			this->pnlGameArea->Controls->Add(this->btnR2C3);
			this->pnlGameArea->Controls->Add(this->btnR2C2);
			this->pnlGameArea->Controls->Add(this->btnR2C1);
			this->pnlGameArea->Controls->Add(this->btnR1C3);
			this->pnlGameArea->Controls->Add(this->btnR1C2);
			this->pnlGameArea->Controls->Add(this->btnR1C1);
			this->pnlGameArea->Location = System::Drawing::Point(75, 25);
			this->pnlGameArea->Name = L"pnlGameArea";
			this->pnlGameArea->Size = System::Drawing::Size(350, 350);
			this->pnlGameArea->TabIndex = 0;
			// 
			// btnR3C3
			// 
			this->btnR3C3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR3C3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnR3C3->FlatAppearance->BorderSize = 5;
			this->btnR3C3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR3C3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR3C3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnR3C3->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR3C3->Location = System::Drawing::Point(247, 247);
			this->btnR3C3->Name = L"btnR3C3";
			this->btnR3C3->Size = System::Drawing::Size(100, 100);
			this->btnR3C3->TabIndex = 8;
			this->btnR3C3->Text = L"X";
			this->btnR3C3->UseVisualStyleBackColor = true;
			// 
			// btnR3C2
			// 
			this->btnR3C2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR3C2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnR3C2->FlatAppearance->BorderSize = 5;
			this->btnR3C2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR3C2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR3C2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnR3C2->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR3C2->Location = System::Drawing::Point(125, 247);
			this->btnR3C2->Name = L"btnR3C2";
			this->btnR3C2->Size = System::Drawing::Size(100, 100);
			this->btnR3C2->TabIndex = 7;
			this->btnR3C2->Text = L"X";
			this->btnR3C2->UseVisualStyleBackColor = true;
			// 
			// btnR3C1
			// 
			this->btnR3C1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR3C1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnR3C1->FlatAppearance->BorderSize = 5;
			this->btnR3C1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR3C1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR3C1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnR3C1->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR3C1->Location = System::Drawing::Point(3, 247);
			this->btnR3C1->Name = L"btnR3C1";
			this->btnR3C1->Size = System::Drawing::Size(100, 100);
			this->btnR3C1->TabIndex = 6;
			this->btnR3C1->Text = L"X";
			this->btnR3C1->UseVisualStyleBackColor = true;
			// 
			// btnR2C3
			// 
			this->btnR2C3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR2C3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnR2C3->FlatAppearance->BorderSize = 5;
			this->btnR2C3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR2C3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR2C3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnR2C3->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR2C3->Location = System::Drawing::Point(247, 125);
			this->btnR2C3->Name = L"btnR2C3";
			this->btnR2C3->Size = System::Drawing::Size(100, 100);
			this->btnR2C3->TabIndex = 5;
			this->btnR2C3->Text = L"X";
			this->btnR2C3->UseVisualStyleBackColor = true;
			// 
			// btnR2C2
			// 
			this->btnR2C2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR2C2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnR2C2->FlatAppearance->BorderSize = 5;
			this->btnR2C2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR2C2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR2C2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnR2C2->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR2C2->Location = System::Drawing::Point(125, 125);
			this->btnR2C2->Name = L"btnR2C2";
			this->btnR2C2->Size = System::Drawing::Size(100, 100);
			this->btnR2C2->TabIndex = 4;
			this->btnR2C2->Text = L"X";
			this->btnR2C2->UseVisualStyleBackColor = true;
			// 
			// btnR2C1
			// 
			this->btnR2C1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR2C1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnR2C1->FlatAppearance->BorderSize = 5;
			this->btnR2C1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR2C1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR2C1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnR2C1->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR2C1->Location = System::Drawing::Point(3, 125);
			this->btnR2C1->Name = L"btnR2C1";
			this->btnR2C1->Size = System::Drawing::Size(100, 100);
			this->btnR2C1->TabIndex = 3;
			this->btnR2C1->Text = L"X";
			this->btnR2C1->UseVisualStyleBackColor = true;
			// 
			// btnR1C3
			// 
			this->btnR1C3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR1C3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnR1C3->FlatAppearance->BorderSize = 5;
			this->btnR1C3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR1C3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR1C3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnR1C3->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR1C3->Location = System::Drawing::Point(247, 3);
			this->btnR1C3->Name = L"btnR1C3";
			this->btnR1C3->Size = System::Drawing::Size(100, 100);
			this->btnR1C3->TabIndex = 2;
			this->btnR1C3->Text = L"X";
			this->btnR1C3->UseVisualStyleBackColor = true;
			// 
			// btnR1C2
			// 
			this->btnR1C2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR1C2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnR1C2->FlatAppearance->BorderSize = 5;
			this->btnR1C2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR1C2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR1C2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnR1C2->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR1C2->Location = System::Drawing::Point(125, 3);
			this->btnR1C2->Name = L"btnR1C2";
			this->btnR1C2->Size = System::Drawing::Size(100, 100);
			this->btnR1C2->TabIndex = 1;
			this->btnR1C2->Text = L"X";
			this->btnR1C2->UseVisualStyleBackColor = true;
			// 
			// btnR1C1
			// 
			this->btnR1C1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR1C1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnR1C1->FlatAppearance->BorderSize = 5;
			this->btnR1C1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR1C1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR1C1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnR1C1->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR1C1->Location = System::Drawing::Point(3, 3);
			this->btnR1C1->Name = L"btnR1C1";
			this->btnR1C1->Size = System::Drawing::Size(100, 100);
			this->btnR1C1->TabIndex = 0;
			this->btnR1C1->Text = L"X";
			this->btnR1C1->UseVisualStyleBackColor = true;
			this->btnR1C1->Click += gcnew System::EventHandler(this, &MainWindow::btnR1C1_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Firebrick;
			this->ClientSize = System::Drawing::Size(484, 461);
			this->Controls->Add(this->pnlBackground);
			this->Font = (gcnew System::Drawing::Font(L"EurostileEF", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->MaximumSize = System::Drawing::Size(800, 800);
			this->MinimumSize = System::Drawing::Size(500, 500);
			this->Name = L"MainWindow";
			this->Text = L"Tic-Tac-Toe";
			this->pnlBackground->ResumeLayout(false);
			this->pnlInformation->ResumeLayout(false);
			this->pnlInformation->PerformLayout();
			this->pnlGameArea->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
};
}
