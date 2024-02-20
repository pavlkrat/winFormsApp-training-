#include <unordered_map>
#include "MainLib.h"

#pragma once

namespace kursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ RecordForm
	/// </summary>
	public ref class RecordForm : public System::Windows::Forms::Form
	{
	public:
		RecordForm(Form^ mfr, System::Windows::Forms::DataGridView^ dg, std::unordered_map<Date, std::vector<Client>, Date::Hash>* m, Date* d, int i, Person* p) :mf(mfr), mp(m), dt(d), idx(i), per(p), dgv(dg)
		{
			InitializeComponent();
			NameLabel->Text = StdToSys(per->getName());
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~RecordForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NumericUpDown^ ProcPrice;
	protected:
	private: Form^ mf;
	private: System::Windows::Forms::TextBox^ ProcType;
	private: System::Windows::Forms::Label^ TypeLabel;
	private: System::Windows::Forms::Label^ PriceLabel;
	private: System::Windows::Forms::Button^ RecordButton;
	private: System::Windows::Forms::Label^ NameLabel;
	private: System::Windows::Forms::DataGridView^ dgv;
	private: std::unordered_map<Date, std::vector<Client>, Date::Hash>* mp;
	private: Person* per;
	private: Date* dt;
	private: int idx;
	private: System::Windows::Forms::Label^ RecordName;

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
			this->ProcPrice = (gcnew System::Windows::Forms::NumericUpDown());
			this->ProcType = (gcnew System::Windows::Forms::TextBox());
			this->TypeLabel = (gcnew System::Windows::Forms::Label());
			this->PriceLabel = (gcnew System::Windows::Forms::Label());
			this->RecordButton = (gcnew System::Windows::Forms::Button());
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->RecordName = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProcPrice))->BeginInit();
			this->SuspendLayout();
			// 
			// ProcPrice
			// 
			this->ProcPrice->Location = System::Drawing::Point(141, 151);
			this->ProcPrice->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->ProcPrice->Name = L"ProcPrice";
			this->ProcPrice->Size = System::Drawing::Size(120, 22);
			this->ProcPrice->TabIndex = 0;
			this->ProcPrice->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// ProcType
			// 
			this->ProcType->Location = System::Drawing::Point(141, 89);
			this->ProcType->Name = L"ProcType";
			this->ProcType->Size = System::Drawing::Size(100, 22);
			this->ProcType->TabIndex = 1;
			this->ProcType->Text = L"-";
			// 
			// TypeLabel
			// 
			this->TypeLabel->AutoSize = true;
			this->TypeLabel->Location = System::Drawing::Point(67, 89);
			this->TypeLabel->Name = L"TypeLabel";
			this->TypeLabel->Size = System::Drawing::Size(42, 16);
			this->TypeLabel->TabIndex = 2;
			this->TypeLabel->Text = L"Type:";
			// 
			// PriceLabel
			// 
			this->PriceLabel->AutoSize = true;
			this->PriceLabel->Location = System::Drawing::Point(68, 151);
			this->PriceLabel->Name = L"PriceLabel";
			this->PriceLabel->Size = System::Drawing::Size(41, 16);
			this->PriceLabel->TabIndex = 3;
			this->PriceLabel->Text = L"Price:";
			// 
			// RecordButton
			// 
			this->RecordButton->Location = System::Drawing::Point(141, 205);
			this->RecordButton->Name = L"RecordButton";
			this->RecordButton->Size = System::Drawing::Size(101, 31);
			this->RecordButton->TabIndex = 4;
			this->RecordButton->Text = L"Ready";
			this->RecordButton->UseVisualStyleBackColor = true;
			this->RecordButton->Click += gcnew System::EventHandler(this, &RecordForm::RecordButton_Click);
			// 
			// NameLabel
			// 
			this->NameLabel->AutoSize = true;
			this->NameLabel->Location = System::Drawing::Point(138, 37);
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size(44, 16);
			this->NameLabel->TabIndex = 5;
			this->NameLabel->Text = L"label1";
			// 
			// RecordName
			// 
			this->RecordName->AutoSize = true;
			this->RecordName->Location = System::Drawing::Point(70, 36);
			this->RecordName->Name = L"RecordName";
			this->RecordName->Size = System::Drawing::Size(47, 16);
			this->RecordName->TabIndex = 6;
			this->RecordName->Text = L"Name:";
			// 
			// RecordForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(405, 271);
			this->Controls->Add(this->RecordName);
			this->Controls->Add(this->NameLabel);
			this->Controls->Add(this->RecordButton);
			this->Controls->Add(this->PriceLabel);
			this->Controls->Add(this->TypeLabel);
			this->Controls->Add(this->ProcType);
			this->Controls->Add(this->ProcPrice);
			this->Name = L"RecordForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RecordForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &RecordForm::RecordForm_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProcPrice))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RecordButton_Click(System::Object^ sender, System::EventArgs^ e) {
		dgv->Rows[idx]->Cells[1]->Value = NameLabel->Text;
		Client cl(per->getName(), per->getPhone(), per->getBirthday(), idx, SysToStd(ProcType->Text), (int)ProcPrice->Value);
		if (cl.isBd(*dt))
			dgv->Rows[idx]->Cells[1]->Style->BackColor = Color::Orange;
		else
			dgv->Rows[idx]->Cells[1]->Style->BackColor = Color::Yellow;
		(*mp)[*dt].push_back(cl);
		Close();
	}
	private: System::Void RecordForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		mf->Show();
	}
};
}
