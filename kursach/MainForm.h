#include <fstream>
#include <unordered_map>
#include "ClientsForm.h"

std::ofstream logfile;

#pragma once

namespace kursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			this->ClientDate->MinDate = System::DateTime::Now;
			for (int i = 0;i <= 23;i++)
				TimeTable->Rows->Add(i.ToString() + ":00", "");
			logfile.open("log.txt");
			clients = new std::vector<Person>;
			mp = new std::unordered_map<Date, std::vector<Client>, Date::Hash>;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			logfile.close();
			if (components)
				delete components;
			if (clients)
				delete clients;
			if (mp)
				delete mp;
		}
	private: System::Windows::Forms::MonthCalendar^ ClientDate;

	private: std::vector<Person>* clients;
	private: std::unordered_map<Date, std::vector<Client>, Date::Hash>* mp;
	private: System::Windows::Forms::DataGridView^ TimeTable;
	private: ClientsForm^ cf;
	private: System::Windows::Forms::Button^ ClientsButton;


	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TimeColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ClientColumn;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ClientDate = (gcnew System::Windows::Forms::MonthCalendar());
			this->TimeTable = (gcnew System::Windows::Forms::DataGridView());
			this->TimeColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ClientColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ClientsButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimeTable))->BeginInit();
			this->SuspendLayout();
			// 
			// ClientDate
			// 
			this->ClientDate->Location = System::Drawing::Point(436, 69);
			this->ClientDate->MaxDate = System::DateTime(2099, 12, 31, 0, 0, 0, 0);
			this->ClientDate->MaxSelectionCount = 1;
			this->ClientDate->MinDate = System::DateTime(2023, 12, 9, 12, 56, 40, 723);
			this->ClientDate->Name = L"ClientDate";
			this->ClientDate->TabIndex = 0;
			this->ClientDate->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &MainForm::ClientDate_DateChanged);
			// 
			// TimeTable
			// 
			this->TimeTable->AllowUserToAddRows = false;
			this->TimeTable->AllowUserToDeleteRows = false;
			this->TimeTable->AllowUserToResizeColumns = false;
			this->TimeTable->AllowUserToResizeRows = false;
			this->TimeTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->TimeTable->ColumnHeadersVisible = false;
			this->TimeTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->TimeColumn,
					this->ClientColumn
			});
			this->TimeTable->Location = System::Drawing::Point(33, 18);
			this->TimeTable->MultiSelect = false;
			this->TimeTable->Name = L"TimeTable";
			this->TimeTable->ReadOnly = true;
			this->TimeTable->RowHeadersVisible = false;
			this->TimeTable->RowHeadersWidth = 51;
			this->TimeTable->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->TimeTable->RowTemplate->Height = 24;
			this->TimeTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->TimeTable->Size = System::Drawing::Size(363, 468);
			this->TimeTable->TabIndex = 3;
			this->TimeTable->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::TimeTable_CellDoubleClick);
			// 
			// TimeColumn
			// 
			this->TimeColumn->HeaderText = L"Time";
			this->TimeColumn->MinimumWidth = 6;
			this->TimeColumn->Name = L"TimeColumn";
			this->TimeColumn->ReadOnly = true;
			this->TimeColumn->Width = 125;
			// 
			// ClientColumn
			// 
			this->ClientColumn->HeaderText = L"Client";
			this->ClientColumn->MinimumWidth = 6;
			this->ClientColumn->Name = L"ClientColumn";
			this->ClientColumn->ReadOnly = true;
			this->ClientColumn->Width = 125;
			// 
			// ClientsButton
			// 
			this->ClientsButton->Location = System::Drawing::Point(484, 342);
			this->ClientsButton->Name = L"ClientsButton";
			this->ClientsButton->Size = System::Drawing::Size(119, 57);
			this->ClientsButton->TabIndex = 4;
			this->ClientsButton->Text = L"Clients";
			this->ClientsButton->UseVisualStyleBackColor = true;
			this->ClientsButton->Click += gcnew System::EventHandler(this, &MainForm::ClientsButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(678, 498);
			this->Controls->Add(this->ClientsButton);
			this->Controls->Add(this->TimeTable);
			this->Controls->Add(this->ClientDate);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Client Manager";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TimeTable))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion 
	private: void setRecords() {
		for (auto i : (*mp)[Date(ClientDate->SelectionStart)]) {
			TimeTable->Rows[i.getIdx()]->Cells[1]->Value = StdToSys(i.getName());
			if (i.isBd(Date(ClientDate->SelectionStart)))
				TimeTable->Rows[i.getIdx()]->Cells[1]->Style->BackColor = Color::Orange;
			else
				TimeTable->Rows[i.getIdx()]->Cells[1]->Style->BackColor = Color::Yellow;
		}
	}
	private: System::Void ClientDate_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
		for (int i = 0;i <= 23;i++) {
			TimeTable->Rows[i]->Cells[1]->Value = "";
			TimeTable->Rows[i]->Cells[1]->Style->BackColor = Color::White;
		}
		setRecords();
	}
	private: System::Void TimeTable_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->ColumnIndex == 1) {
			if (TimeTable->Rows[e->RowIndex]->Cells[1]->Value == "") {
				if (cf->Visible)
					return;
				Hide();
				cf->mode = e->RowIndex;
				*(cf->dt) = Date(ClientDate->SelectionStart);
				cf->Show();
			}
			else {
				Date dtbuf(ClientDate->SelectionStart);
				int i;
				for (i = 0;(*mp)[dtbuf][i].getIdx() != e->RowIndex;i++);
				String^ str = StdToSys((*mp)[dtbuf][i].toString() + ((*mp)[dtbuf][i].isBd(dtbuf) ? "!!! It will be client's birthday!!!\n" : "") + "Do you want to cancel this record?");
				if (MessageBox::Show(str, "Client", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
					TimeTable->Rows[e->RowIndex]->Cells[1]->Value = "";
					TimeTable->Rows[e->RowIndex]->Cells[1]->Style->BackColor = Color::White;
					(*mp)[dtbuf].erase((*mp)[dtbuf].begin() + i);
				}
			}
		}
	}
	private: System::Void ClientsButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cf->Visible)
			return;
		Hide();
		cf->mode = -1;
		cf->Show();
	}
	private: System::Void MainForm_Shown(System::Object^ sender, System::EventArgs^ e) {
		std::ifstream clientsInp, mpInp;
		std::string nm, ph;
		int d, m, y;
		clientsInp.open("clients.txt");
		while (getline(clientsInp, nm)) {
			getline(clientsInp, ph);
			clientsInp >> d;
			clientsInp >> m;
			clientsInp >> y;
			clientsInp.ignore();
			clients->push_back(Person(nm, ph, Date(d, m, y)));
		}
		clientsInp.close();
		int idx, pri, dz, mz, yz;
		std::string pro;
		mpInp.open("records.txt");
		while (getline(mpInp, nm)) {
			getline(mpInp, ph);
			mpInp >> d;
			mpInp >> m;
			mpInp >> y;
			mpInp >> idx;
			mpInp >> pri;
			mpInp.ignore();
			getline(mpInp, pro);
			mpInp >> dz;
			mpInp >> mz;
			mpInp >> yz;
			mpInp.ignore();
			(*mp)[Date(dz, mz, yz)].push_back(Client(nm, ph, Date(d, m, y), idx, pro, pri));
		}
		mpInp.close();
		setRecords();
		TimeTable->FirstDisplayedScrollingRowIndex = 6;
		cf = gcnew ClientsForm(this, TimeTable, clients, mp);
	}
	private: System::Void MainForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		std::ofstream clientsOut, mpOut;
		clientsOut.open("clients.txt");
		for (auto i : *clients)
			clientsOut << i.getName() << "\n" << i.getPhone() << "\n" << i.getBirthday().toFileString() << "\n";
		clientsOut.close();
		mpOut.open("records.txt");
		for (auto i : *mp)
		{
			Date d = i.first;
			for (auto j : i.second)
				mpOut << j.getName() << "\n" << j.getPhone() << "\n" << j.getBirthday().toFileString() << "\n" << j.getIdx() << " " << j.getPrice() << "\n" << j.getProc() << "\n" << d.toFileString() << "\n";
		}
		mpOut.close();
	}
};
}
