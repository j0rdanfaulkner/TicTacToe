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
		OpponentSelectionWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
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
			this->pnlSelectionArea->Controls->Add(this->label2);
			this->pnlSelectionArea->Controls->Add(this->label1);
			this->pnlSelectionArea->Controls->Add(this->button2);
			this->pnlSelectionArea->Controls->Add(this->button1);
			this->pnlSelectionArea->Location = System::Drawing::Point(25, 56);
			this->pnlSelectionArea->Name = L"pnlSelectionArea";
			this->pnlSelectionArea->Size = System::Drawing::Size(282, 180);
			this->pnlSelectionArea->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::IndianRed;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Eurostile LT Std Ext Two", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(17, 105);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 57);
			this->button1->TabIndex = 1;
			this->button1->Text = L"VS CPU";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Maroon;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::IndianRed;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Eurostile LT Std Ext Two", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(149, 105);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(116, 57);
			this->button2->TabIndex = 2;
			this->button2->Text = L"VS HUMAN";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(86, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 23);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Tic-Tac-Toe";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(59, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(165, 23);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Select Opponent:";
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
	};
}
