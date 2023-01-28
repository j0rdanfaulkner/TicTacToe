#pragma once

namespace TicTacToe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for OpponentSelectionWindow
	/// </summary>
	public ref class OpponentSelectionWindow : public System::Windows::Forms::Form
	{
	public:
		// variable to store the selected opponent type
		int opponentType;
		OpponentSelectionWindow(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OpponentSelectionWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlBackground;
	private: System::Windows::Forms::Panel^ pnlSelectionArea;
	private: System::Windows::Forms::Label^ lblSelectOpponent;
	private: System::Windows::Forms::Label^ lblTicTacToe;


	private: System::Windows::Forms::Button^ btnHuman;

	private: System::Windows::Forms::Button^ btnCPU;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(OpponentSelectionWindow::typeid));
			this->pnlBackground = (gcnew System::Windows::Forms::Panel());
			this->pnlSelectionArea = (gcnew System::Windows::Forms::Panel());
			this->lblSelectOpponent = (gcnew System::Windows::Forms::Label());
			this->lblTicTacToe = (gcnew System::Windows::Forms::Label());
			this->btnHuman = (gcnew System::Windows::Forms::Button());
			this->btnCPU = (gcnew System::Windows::Forms::Button());
			this->pnlBackground->SuspendLayout();
			this->pnlSelectionArea->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlBackground
			// 
			this->pnlBackground->BackColor = System::Drawing::Color::Maroon;
			this->pnlBackground->Controls->Add(this->pnlSelectionArea);
			this->pnlBackground->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlBackground->Location = System::Drawing::Point(0, 0);
			this->pnlBackground->Name = L"pnlBackground";
			this->pnlBackground->Size = System::Drawing::Size(334, 311);
			this->pnlBackground->TabIndex = 0;
			// 
			// pnlSelectionArea
			// 
			this->pnlSelectionArea->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pnlSelectionArea->BackColor = System::Drawing::Color::Firebrick;
			this->pnlSelectionArea->Controls->Add(this->lblSelectOpponent);
			this->pnlSelectionArea->Controls->Add(this->lblTicTacToe);
			this->pnlSelectionArea->Controls->Add(this->btnHuman);
			this->pnlSelectionArea->Controls->Add(this->btnCPU);
			this->pnlSelectionArea->Location = System::Drawing::Point(25, 56);
			this->pnlSelectionArea->Name = L"pnlSelectionArea";
			this->pnlSelectionArea->Size = System::Drawing::Size(282, 180);
			this->pnlSelectionArea->TabIndex = 0;
			// 
			// lblSelectOpponent
			// 
			this->lblSelectOpponent->AutoSize = true;
			this->lblSelectOpponent->Location = System::Drawing::Point(59, 63);
			this->lblSelectOpponent->Name = L"lblSelectOpponent";
			this->lblSelectOpponent->Size = System::Drawing::Size(165, 23);
			this->lblSelectOpponent->TabIndex = 4;
			this->lblSelectOpponent->Text = L"Select Opponent:";
			// 
			// lblTicTacToe
			// 
			this->lblTicTacToe->AutoSize = true;
			this->lblTicTacToe->Location = System::Drawing::Point(86, 20);
			this->lblTicTacToe->Name = L"lblTicTacToe";
			this->lblTicTacToe->Size = System::Drawing::Size(110, 23);
			this->lblTicTacToe->TabIndex = 3;
			this->lblTicTacToe->Text = L"Tic-Tac-Toe";
			// 
			// btnHuman
			// 
			this->btnHuman->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnHuman->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->btnHuman->FlatAppearance->MouseOverBackColor = System::Drawing::Color::IndianRed;
			this->btnHuman->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHuman->Font = (gcnew System::Drawing::Font(L"Eurostile LT Std Ext Two", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnHuman->Location = System::Drawing::Point(149, 105);
			this->btnHuman->Name = L"btnHuman";
			this->btnHuman->Size = System::Drawing::Size(116, 57);
			this->btnHuman->TabIndex = 2;
			this->btnHuman->Text = L"VS HUMAN";
			this->btnHuman->UseVisualStyleBackColor = true;
			this->btnHuman->Click += gcnew System::EventHandler(this, &OpponentSelectionWindow::btnHuman_Click);
			// 
			// btnCPU
			// 
			this->btnCPU->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnCPU->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->btnCPU->FlatAppearance->MouseOverBackColor = System::Drawing::Color::IndianRed;
			this->btnCPU->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCPU->Font = (gcnew System::Drawing::Font(L"Eurostile LT Std Ext Two", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCPU->Location = System::Drawing::Point(17, 105);
			this->btnCPU->Name = L"btnCPU";
			this->btnCPU->Size = System::Drawing::Size(116, 57);
			this->btnCPU->TabIndex = 1;
			this->btnCPU->Text = L"VS CPU";
			this->btnCPU->UseVisualStyleBackColor = true;
			this->btnCPU->Click += gcnew System::EventHandler(this, &OpponentSelectionWindow::btnCPU_Click);
			// 
			// OpponentSelectionWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(334, 311);
			this->Controls->Add(this->pnlBackground);
			this->Font = (gcnew System::Drawing::Font(L"Eurostile LT Std", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(500, 500);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(350, 350);
			this->Name = L"OpponentSelectionWindow";
			this->Text = L"Select Opponent";
			this->pnlBackground->ResumeLayout(false);
			this->pnlSelectionArea->ResumeLayout(false);
			this->pnlSelectionArea->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCPU_Click(System::Object^ sender, System::EventArgs^ e)
	{
		opponentType = 1;
	}
	private: System::Void btnHuman_Click(System::Object^ sender, System::EventArgs^ e)
	{
		opponentType = 2;
	}
};
}
