#pragma once
#include<iostream>
#include<cstdlib>
#include<string>
#include "OpponentSelectionWindow.h"
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
		// constant variables to hold the total number of rows and columns
		const int ROWS = 3;
		const int COLS = 3;
		// variable to store the current player number
		int currentPlayer;
		// variables to store the player number that claimed the corresponding position
		int ownerR1C1, ownerR1C2, ownerR1C3, ownerR2C1, ownerR2C2, ownerR2C3, ownerR3C1, ownerR3C2, ownerR3C3;
		// variables to store the number of wins each player has
		int player1Wins, player2Wins;
		// variable to store boolean value of whether there is a winner yet or not
		bool isWinner = false;
		// variable for storing the results of answering 'Yes' or 'No' to message box prompts
		System::Windows::Forms::DialogResult result;
		MainWindow(void)
		{
			OpponentSelectionWindow^ selectOpponentForm = gcnew OpponentSelectionWindow;
			selectOpponentForm->Show();
			if (selectOpponentForm->opponentType == 1)
			{

			}
			else if (selectOpponentForm->opponentType == 2)
			{

			}
			InitializeComponent();
			StartGame();
		}
		void StartGame()
		{
			ResetGame();
			currentPlayer = (rand() % 2) + 1;
			MessageBox::Show("Player " + currentPlayer + " will go first", "Starting Player", MessageBoxButtons::OK, MessageBoxIcon::Information);
			ShowCurrentTurn(currentPlayer);
			UpdateWinCounters();
		}
		void UpdateWinCounters()
		{
			lblPlayer1Wins->Text = player1Wins.ToString();
			lblPlayer2Wins->Text = player2Wins.ToString();
		}
		void ShowCurrentTurn(int currentPlayer)
		{
			if (currentPlayer == 1)
			{
				lblCurrentPlayer->Text = "<";
			}
			else if (currentPlayer == 2)
			{
				lblCurrentPlayer->Text = ">";
			}
		}
		void EndCurrentTurn(int currentPlayerNo)
		{
			if (currentPlayerNo == 1)
			{
				currentPlayer = 2;
			}
			else if (currentPlayerNo == 2)
			{
				currentPlayer = 1;
			}
			CheckForWinner();
			ShowCurrentTurn(currentPlayer);
		}
		/// <summary>
		/// resets all buttons / positions back to their default properties
		/// </summary>
		void ResetGame()
		{
			isWinner = false;
			// reset buttons
			btnR1C1->Text = "";
			btnR1C1->Enabled = true;
			btnR1C1->BackColor = Color::Firebrick;
			btnR1C2->Text = "";
			btnR1C2->Enabled = true;
			btnR1C2->BackColor = Color::Firebrick;
			btnR1C3->Text = "";
			btnR1C3->Enabled = true;
			btnR1C3->BackColor = Color::Firebrick;
			btnR2C1->Text = "";
			btnR2C1->Enabled = true;
			btnR2C1->BackColor = Color::Firebrick;
			btnR2C2->Text = "";
			btnR2C2->Enabled = true;
			btnR2C2->BackColor = Color::Firebrick;
			btnR2C3->Text = "";
			btnR2C3->Enabled = true;
			btnR2C3->BackColor = Color::Firebrick;
			btnR3C1->Text = "";
			btnR3C1->Enabled = true;
			btnR3C1->BackColor = Color::Firebrick;
			btnR3C2->Text = "";
			btnR3C2->Enabled = true;
			btnR3C2->BackColor = Color::Firebrick;
			btnR3C3->Text = "";
			btnR3C3->Enabled = true;
			btnR3C3->BackColor = Color::Firebrick;
			// reset claimed spaces
			ownerR1C1 = 0;
			ownerR1C2 = 0;
			ownerR1C3 = 0;
			ownerR2C1 = 0;
			ownerR2C2 = 0;
			ownerR2C3 = 0;
			ownerR3C1 = 0;
			ownerR3C2 = 0;
			ownerR3C3 = 0;
		}
		void CheckForWinner()
		{
			// 2D int array for game (to store the player number for each claimed space)
			int game[3][3] = { { ownerR1C1, ownerR1C2, ownerR1C3 },
							   { ownerR2C1, ownerR2C2, ownerR2C3 },
							   { ownerR3C1, ownerR3C2, ownerR3C3 } };
			// ROW 1 ACROSS
			//      C0  C1  C2
			//	R0  X	X	X
			//	R1  -	-	-
			//	R2  -	-	-
			if (game[0][0] == game[0][1] && game[0][0] == game[0][2] && game[0][1] == game[0][2])
			{
				if (game[0][0] != 0 && game[0][1] != 0 && game[0][2] != 0)
				{
					btnR1C1->BackColor = Color::Green;
					btnR1C2->BackColor = Color::Green;
					btnR1C3->BackColor = Color::Green;
					MessageBox::Show("Player " + game[0][0].ToString() + " Wins!", "Winner", MessageBoxButtons::OK, MessageBoxIcon::Information);
					isWinner = true;
					if (game[0][0] == 1)
					{
						player1Wins++;
					}
					else if (game[0][0] == 2)
					{
						player2Wins++;
					}
				}
			}
			// ROW 2 ACROSS
			//      C0  C1  C2
			//	R0  -	-	-
			//	R1  X	X	X
			//	R2  -	-	-
			else if (game[1][0] == game[1][1] && game[1][0] == game[1][2] && game[1][1] == game[1][2])
			{
				if (game[1][0] != 0 && game[1][1] != 0 && game[1][2] != 0)
				{
					btnR2C1->BackColor = Color::Green;
					btnR2C2->BackColor = Color::Green;
					btnR2C3->BackColor = Color::Green;
					MessageBox::Show("Player " + game[1][0].ToString() + " Wins!", "Winner", MessageBoxButtons::OK, MessageBoxIcon::Information);
					isWinner = true;
					if (game[1][0] == 1)
					{
						player1Wins++;
					}
					else if (game[1][0] == 2)
					{
						player2Wins++;
					}
				}
			}
			// ROW 3 ACROSS
			//      C0  C1  C2
			//	R0  -	-	-
			//	R1  -	-	-
			//	R2  X	X	X
			else if (game[2][0] == game[2][1] && game[2][0] == game[2][2] && game[2][1] == game[2][2])
			{
				if (game[2][0] != 0 && game[2][1] != 0 && game[2][2] != 0)
				{
					btnR3C1->BackColor = Color::Green;
					btnR3C2->BackColor = Color::Green;
					btnR3C3->BackColor = Color::Green;
					MessageBox::Show("Player " + game[2][0].ToString() + " Wins!", "Winner", MessageBoxButtons::OK, MessageBoxIcon::Information);
					isWinner = true;
					if (game[2][0] == 1)
					{
						player1Wins++;
					}
					else if (game[2][0] == 2)
					{
						player2Wins++;
					}
				}
			}
			// COLUMN 1 DOWN
			//      C0  C1  C2
			//	R0  X	-	-
			//	R1  X	-	-
			//	R2  X	-	-
			else if (game[0][0] == game[1][0] && game[0][0] == game[2][0] && game[1][0] == game[2][0])
			{
				if (game[0][0] != 0 && game[1][0] != 0 && game[2][0] != 0)
				{
					btnR1C1->BackColor = Color::Green;
					btnR2C1->BackColor = Color::Green;
					btnR3C1->BackColor = Color::Green;
					MessageBox::Show("Player " + game[0][0].ToString() + " Wins!", "Winner", MessageBoxButtons::OK, MessageBoxIcon::Information);
					isWinner = true;
					if (game[0][0] == 1)
					{
						player1Wins++;
					}
					else if (game[0][0] == 2)
					{
						player2Wins++;
					}
				}
			}
			// COLUMN 2 DOWN
			//      C0  C1  C2
			//	R0  -	X	-
			//	R1  -	X	-
			//	R2  -	X	-
			else if (game[0][1] == game[1][1] && game[0][1] == game[2][1] && game[1][1] == game[2][1])
			{
				if (game[0][1] != 0 && game[1][1] != 0 && game[2][1] != 0)
				{
					btnR1C2->BackColor = Color::Green;
					btnR2C2->BackColor = Color::Green;
					btnR3C2->BackColor = Color::Green;
					MessageBox::Show("Player " + game[0][1].ToString() + " Wins!", "Winner", MessageBoxButtons::OK, MessageBoxIcon::Information);
					isWinner = true;
					if (game[0][1] == 1)
					{
						player1Wins++;
					}
					else if (game[0][1] == 2)
					{
						player2Wins++;
					}
				}
			}
			// COLUMN 3 DOWN
			//      C0  C1  C2
			//	R0  -	-	X
			//	R1  -	-	X
			//	R2  -	-	X
			else if (game[0][2] == game[1][2] && game[0][2] == game[2][2] && game[1][2] == game[2][2])
			{
				if (game[0][2] != 0 && game[1][2] != 0 && game[2][2] != 0)
				{
					btnR1C3->BackColor = Color::Green;
					btnR2C3->BackColor = Color::Green;
					btnR3C3->BackColor = Color::Green;
					MessageBox::Show("Player " + game[0][2].ToString() + " Wins!", "Winner", MessageBoxButtons::OK, MessageBoxIcon::Information);
					isWinner = true;
					if (game[0][2] == 1)
					{
						player1Wins++;
					}
					else if (game[0][2] == 2)
					{
						player2Wins++;
					}
				}
			}
			// DIAGONAL LEFT-TO-RIGHT
			//      C0  C1  C2
			//	R0  X	-	-
			//	R1  -	X	-
			//	R2  -	-	X
			else if (game[0][0] == game[1][1] && game[0][0] == game[2][2] && game[1][1] == game[2][2])
			{
				if (game[0][0] != 0 && game[1][1] != 0 && game[2][2] != 0)
				{
					btnR1C1->BackColor = Color::Green;
					btnR2C2->BackColor = Color::Green;
					btnR3C3->BackColor = Color::Green;
					MessageBox::Show("Player " + game[0][0].ToString() + " Wins!", "Winner", MessageBoxButtons::OK, MessageBoxIcon::Information);
					isWinner = true;
					if (game[0][0] == 1)
					{
						player1Wins++;
					}
					else if (game[0][0] == 2)
					{
						player2Wins++;
					}
				}
			}
			// DIAGONAL RIGHT-TO-LEFT
			//      C0  C1  C2
			//	R0  -	-	X
			//	R1  -	X	-
			//	R2  X	-	-
			else if (game[0][2] == game[1][1] && game[0][2] == game[2][0] && game[1][1] == game[2][0])
			{
				if (game[0][2] != 0 && game[1][1] != 0 && game[2][0] != 0)
				{
					btnR1C3->BackColor = Color::Green;
					btnR2C2->BackColor = Color::Green;
					btnR3C1->BackColor = Color::Green;
					MessageBox::Show("Player " + game[0][2].ToString() + " Wins!", "Winner", MessageBoxButtons::OK, MessageBoxIcon::Information);
					isWinner = true;
					if (game[0][2] == 1)
					{
						player1Wins++;
					}
					else if (game[0][2] == 2)
					{
						player2Wins++;
					}
				}
			}
			// NO WINNER (DRAW)
			//	-	-	-
			//	-	-	-
			//	-	-	-
			int count = 0;
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLS; j++)
				{
					if (game[i][j] != 0)
					{
						count++;
					}
				}
			}
			if (count == 9 && isWinner == false)
			{
				isWinner = false;
				btnR1C1->BackColor = Color::OrangeRed;
				btnR1C2->BackColor = Color::OrangeRed;
				btnR1C3->BackColor = Color::OrangeRed;
				btnR2C1->BackColor = Color::OrangeRed;
				btnR2C2->BackColor = Color::OrangeRed;
				btnR2C3->BackColor = Color::OrangeRed;
				btnR3C1->BackColor = Color::OrangeRed;
				btnR3C2->BackColor = Color::OrangeRed;
				btnR3C3->BackColor = Color::OrangeRed;
				result = MessageBox::Show("It's a draw! Do you want to start over?", "It's a Draw!", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				if (result == System::Windows::Forms::DialogResult::Yes)
				{
					StartGame();
					for (int i = 0; i < ROWS; i++)
					{
						for (int j = 0; j < COLS; j++)
						{
							game[i][j] = 0;
						}
					}
				}
				else
				{
					Application::Exit();
				}
			}
			if (isWinner == true)
			{
				result = MessageBox::Show("Do you want a rematch?", "Rematch", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				if (result == System::Windows::Forms::DialogResult::Yes)
				{
					StartGame();
					for (int i = 0; i < ROWS; i++)
					{
						for (int j = 0; j < COLS; j++)
						{
							game[i][j] = 0;
						}
					}
				}
				else
				{
					Application::Exit();
				}
			}
		}
	private:
		System::Void btnR1C1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ownerR1C1 = currentPlayer;
			if (ownerR1C1 == 1)
			{
				btnR1C1->Text = "X";
			}
			else if (ownerR1C1 == 2)
			{
				btnR1C1->Text = "O";
			}
			btnR1C1->Enabled = false;
			EndCurrentTurn(ownerR1C1);
		}
		System::Void btnR1C2_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ownerR1C2 = currentPlayer;
			if (ownerR1C2 == 1)
			{
				btnR1C2->Text = "X";
			}
			else if (ownerR1C2 == 2)
			{
				btnR1C2->Text = "O";
			}
			btnR1C2->Enabled = false;
			EndCurrentTurn(ownerR1C2);
		}
		System::Void btnR1C3_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ownerR1C3 = currentPlayer;
			if (ownerR1C3 == 1)
			{
				btnR1C3->Text = "X";
			}
			else if (ownerR1C3 == 2)
			{
				btnR1C3->Text = "O";
			}
			btnR1C3->Enabled = false;
			EndCurrentTurn(ownerR1C3);
		}
		System::Void btnR2C1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ownerR2C1 = currentPlayer;
			if (ownerR2C1 == 1)
			{
				btnR2C1->Text = "X";
			}
			else if (ownerR2C1 == 2)
			{
				btnR2C1->Text = "O";
			}
			btnR2C1->Enabled = false;
			EndCurrentTurn(ownerR2C1);
		}
		System::Void btnR2C2_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ownerR2C2 = currentPlayer;
			if (ownerR2C2 == 1)
			{
				btnR2C2->Text = "X";
			}
			else if (ownerR2C2 == 2)
			{
				btnR2C2->Text = "O";
			}
			btnR2C2->Enabled = false;
			EndCurrentTurn(ownerR2C2);
		}
		System::Void btnR2C3_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ownerR2C3 = currentPlayer;
			if (ownerR2C3 == 1)
			{
				btnR2C3->Text = "X";
			}
			else if (ownerR2C3 == 2)
			{
				btnR2C3->Text = "O";
			}
			btnR2C3->Enabled = false;
			EndCurrentTurn(ownerR2C3);
		}
		System::Void btnR3C1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ownerR3C1 = currentPlayer;
			if (ownerR3C1 == 1)
			{
				btnR3C1->Text = "X";
			}
			else if (ownerR3C1 == 2)
			{
				btnR3C1->Text = "O";
			}
			btnR3C1->Enabled = false;
			EndCurrentTurn(ownerR3C1);
		}
		System::Void btnR3C2_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ownerR3C2 = currentPlayer;
			if (ownerR3C2 == 1)
			{
				btnR3C2->Text = "X";
			}
			else if (ownerR3C2 == 2)
			{
				btnR3C2->Text = "O";
			}
			btnR3C2->Enabled = false;
			EndCurrentTurn(ownerR3C2);
		}
		System::Void btnR3C3_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ownerR3C3 = currentPlayer;
			if (ownerR3C3 == 1)
			{
				btnR3C3->Text = "X";
			}
			else if (ownerR3C3 == 2)
			{
				btnR3C3->Text = "O";
			}
			btnR3C3->Enabled = false;
			EndCurrentTurn(ownerR3C3);
		}
		System::Void btnReset_Click(System::Object^ sender, System::EventArgs^ e)
		{
			result = MessageBox::Show("Do you wish to reset the number of wins for each player too?", "Reset Win Counters", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				player1Wins = 0;
				player2Wins = 0;
			}
			StartGame();
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
	private: System::Windows::Forms::Label^ lblPlayer1;
	private: System::Windows::Forms::Label^ lblPlayer2;
	private: System::Windows::Forms::Label^ lblPlayer1Wins;
	private: System::Windows::Forms::Label^ lblPlayer2Wins;
	private: System::Windows::Forms::Label^ lblCurrentPlayer;
	private: System::Windows::Forms::Button^ btnR1C2;
	private: System::Windows::Forms::Button^ btnR1C1;
	private: System::Windows::Forms::Panel^ pnlInformation;
	private: System::Windows::Forms::Label^ lblDescription;
	private: System::Windows::Forms::Label^ lblCurrentTurn;
	private: System::Windows::Forms::Button^ btnReset;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->pnlBackground = (gcnew System::Windows::Forms::Panel());
			this->pnlInformation = (gcnew System::Windows::Forms::Panel());
			this->lblCurrentPlayer = (gcnew System::Windows::Forms::Label());
			this->lblPlayer2Wins = (gcnew System::Windows::Forms::Label());
			this->lblPlayer1Wins = (gcnew System::Windows::Forms::Label());
			this->lblPlayer2 = (gcnew System::Windows::Forms::Label());
			this->lblPlayer1 = (gcnew System::Windows::Forms::Label());
			this->btnReset = (gcnew System::Windows::Forms::Button());
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
			this->pnlInformation->Controls->Add(this->lblCurrentPlayer);
			this->pnlInformation->Controls->Add(this->lblPlayer2Wins);
			this->pnlInformation->Controls->Add(this->lblPlayer1Wins);
			this->pnlInformation->Controls->Add(this->lblPlayer2);
			this->pnlInformation->Controls->Add(this->lblPlayer1);
			this->pnlInformation->Controls->Add(this->btnReset);
			this->pnlInformation->Controls->Add(this->lblCurrentTurn);
			this->pnlInformation->Location = System::Drawing::Point(75, 379);
			this->pnlInformation->Name = L"pnlInformation";
			this->pnlInformation->Size = System::Drawing::Size(350, 64);
			this->pnlInformation->TabIndex = 9;
			// 
			// lblCurrentPlayer
			// 
			this->lblCurrentPlayer->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblCurrentPlayer->AutoSize = true;
			this->lblCurrentPlayer->Location = System::Drawing::Point(163, 18);
			this->lblCurrentPlayer->Name = L"lblCurrentPlayer";
			this->lblCurrentPlayer->Size = System::Drawing::Size(16, 18);
			this->lblCurrentPlayer->TabIndex = 7;
			this->lblCurrentPlayer->Text = L"<";
			// 
			// lblPlayer2Wins
			// 
			this->lblPlayer2Wins->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblPlayer2Wins->AutoSize = true;
			this->lblPlayer2Wins->Location = System::Drawing::Point(288, 37);
			this->lblPlayer2Wins->Name = L"lblPlayer2Wins";
			this->lblPlayer2Wins->Size = System::Drawing::Size(18, 18);
			this->lblPlayer2Wins->TabIndex = 6;
			this->lblPlayer2Wins->Text = L"0";
			// 
			// lblPlayer1Wins
			// 
			this->lblPlayer1Wins->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblPlayer1Wins->AutoSize = true;
			this->lblPlayer1Wins->Location = System::Drawing::Point(35, 38);
			this->lblPlayer1Wins->Name = L"lblPlayer1Wins";
			this->lblPlayer1Wins->Size = System::Drawing::Size(18, 18);
			this->lblPlayer1Wins->TabIndex = 5;
			this->lblPlayer1Wins->Text = L"0";
			// 
			// lblPlayer2
			// 
			this->lblPlayer2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblPlayer2->AutoSize = true;
			this->lblPlayer2->Location = System::Drawing::Point(254, 13);
			this->lblPlayer2->Name = L"lblPlayer2";
			this->lblPlayer2->Size = System::Drawing::Size(90, 18);
			this->lblPlayer2->TabIndex = 4;
			this->lblPlayer2->Text = L"Player 2 (O)";
			// 
			// lblPlayer1
			// 
			this->lblPlayer1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblPlayer1->AutoSize = true;
			this->lblPlayer1->Location = System::Drawing::Point(7, 13);
			this->lblPlayer1->Name = L"lblPlayer1";
			this->lblPlayer1->Size = System::Drawing::Size(90, 18);
			this->lblPlayer1->TabIndex = 3;
			this->lblPlayer1->Text = L"Player 1 (X)";
			// 
			// btnReset
			// 
			this->btnReset->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnReset->BackColor = System::Drawing::Color::DarkRed;
			this->btnReset->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnReset->FlatAppearance->BorderSize = 5;
			this->btnReset->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnReset->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btnReset->Location = System::Drawing::Point(121, 36);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(108, 23);
			this->btnReset->TabIndex = 2;
			this->btnReset->Text = L"Reset Game";
			this->btnReset->UseVisualStyleBackColor = false;
			this->btnReset->Click += gcnew System::EventHandler(this, &MainWindow::btnReset_Click);
			// 
			// lblCurrentTurn
			// 
			this->lblCurrentTurn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblCurrentTurn->AutoSize = true;
			this->lblCurrentTurn->Location = System::Drawing::Point(123, 0);
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
			this->pnlGameArea->Location = System::Drawing::Point(75, 11);
			this->pnlGameArea->Name = L"pnlGameArea";
			this->pnlGameArea->Size = System::Drawing::Size(350, 350);
			this->pnlGameArea->TabIndex = 0;
			// 
			// btnR3C3
			// 
			this->btnR3C3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR3C3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnR3C3->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnR3C3->FlatAppearance->BorderSize = 5;
			this->btnR3C3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR3C3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR3C3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnR3C3->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR3C3->Location = System::Drawing::Point(247, 247);
			this->btnR3C3->Name = L"btnR3C3";
			this->btnR3C3->Size = System::Drawing::Size(100, 100);
			this->btnR3C3->TabIndex = 8;
			this->btnR3C3->Text = L"X";
			this->btnR3C3->UseVisualStyleBackColor = true;
			this->btnR3C3->Click += gcnew System::EventHandler(this, &MainWindow::btnR3C3_Click);
			// 
			// btnR3C2
			// 
			this->btnR3C2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR3C2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnR3C2->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnR3C2->FlatAppearance->BorderSize = 5;
			this->btnR3C2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR3C2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR3C2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnR3C2->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR3C2->Location = System::Drawing::Point(125, 247);
			this->btnR3C2->Name = L"btnR3C2";
			this->btnR3C2->Size = System::Drawing::Size(100, 100);
			this->btnR3C2->TabIndex = 7;
			this->btnR3C2->Text = L"X";
			this->btnR3C2->UseVisualStyleBackColor = true;
			this->btnR3C2->Click += gcnew System::EventHandler(this, &MainWindow::btnR3C2_Click);
			// 
			// btnR3C1
			// 
			this->btnR3C1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR3C1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnR3C1->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnR3C1->FlatAppearance->BorderSize = 5;
			this->btnR3C1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR3C1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR3C1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnR3C1->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR3C1->Location = System::Drawing::Point(3, 247);
			this->btnR3C1->Name = L"btnR3C1";
			this->btnR3C1->Size = System::Drawing::Size(100, 100);
			this->btnR3C1->TabIndex = 6;
			this->btnR3C1->Text = L"X";
			this->btnR3C1->UseVisualStyleBackColor = true;
			this->btnR3C1->Click += gcnew System::EventHandler(this, &MainWindow::btnR3C1_Click);
			// 
			// btnR2C3
			// 
			this->btnR2C3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR2C3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnR2C3->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnR2C3->FlatAppearance->BorderSize = 5;
			this->btnR2C3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR2C3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR2C3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnR2C3->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR2C3->Location = System::Drawing::Point(247, 125);
			this->btnR2C3->Name = L"btnR2C3";
			this->btnR2C3->Size = System::Drawing::Size(100, 100);
			this->btnR2C3->TabIndex = 5;
			this->btnR2C3->Text = L"X";
			this->btnR2C3->UseVisualStyleBackColor = true;
			this->btnR2C3->Click += gcnew System::EventHandler(this, &MainWindow::btnR2C3_Click);
			// 
			// btnR2C2
			// 
			this->btnR2C2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR2C2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnR2C2->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnR2C2->FlatAppearance->BorderSize = 5;
			this->btnR2C2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR2C2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR2C2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnR2C2->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR2C2->Location = System::Drawing::Point(125, 125);
			this->btnR2C2->Name = L"btnR2C2";
			this->btnR2C2->Size = System::Drawing::Size(100, 100);
			this->btnR2C2->TabIndex = 4;
			this->btnR2C2->Text = L"X";
			this->btnR2C2->UseVisualStyleBackColor = true;
			this->btnR2C2->Click += gcnew System::EventHandler(this, &MainWindow::btnR2C2_Click);
			// 
			// btnR2C1
			// 
			this->btnR2C1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR2C1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnR2C1->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnR2C1->FlatAppearance->BorderSize = 5;
			this->btnR2C1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR2C1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR2C1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnR2C1->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR2C1->Location = System::Drawing::Point(3, 125);
			this->btnR2C1->Name = L"btnR2C1";
			this->btnR2C1->Size = System::Drawing::Size(100, 100);
			this->btnR2C1->TabIndex = 3;
			this->btnR2C1->Text = L"X";
			this->btnR2C1->UseVisualStyleBackColor = true;
			this->btnR2C1->Click += gcnew System::EventHandler(this, &MainWindow::btnR2C1_Click);
			// 
			// btnR1C3
			// 
			this->btnR1C3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR1C3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnR1C3->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnR1C3->FlatAppearance->BorderSize = 5;
			this->btnR1C3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR1C3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR1C3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnR1C3->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR1C3->Location = System::Drawing::Point(247, 3);
			this->btnR1C3->Name = L"btnR1C3";
			this->btnR1C3->Size = System::Drawing::Size(100, 100);
			this->btnR1C3->TabIndex = 2;
			this->btnR1C3->Text = L"X";
			this->btnR1C3->UseVisualStyleBackColor = true;
			this->btnR1C3->Click += gcnew System::EventHandler(this, &MainWindow::btnR1C3_Click);
			// 
			// btnR1C2
			// 
			this->btnR1C2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR1C2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnR1C2->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnR1C2->FlatAppearance->BorderSize = 5;
			this->btnR1C2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR1C2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR1C2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnR1C2->Font = (gcnew System::Drawing::Font(L"EurostileEF", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnR1C2->Location = System::Drawing::Point(125, 3);
			this->btnR1C2->Name = L"btnR1C2";
			this->btnR1C2->Size = System::Drawing::Size(100, 100);
			this->btnR1C2->TabIndex = 1;
			this->btnR1C2->Text = L"X";
			this->btnR1C2->UseVisualStyleBackColor = true;
			this->btnR1C2->Click += gcnew System::EventHandler(this, &MainWindow::btnR1C2_Click);
			// 
			// btnR1C1
			// 
			this->btnR1C1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnR1C1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnR1C1->FlatAppearance->BorderColor = System::Drawing::Color::Maroon;
			this->btnR1C1->FlatAppearance->BorderSize = 5;
			this->btnR1C1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::LightCoral;
			this->btnR1C1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Maroon;
			this->btnR1C1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
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