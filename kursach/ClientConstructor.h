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
	/// —водка дл€ ClientConstructor
	/// </summary>
	public ref class ClientConstructor : public System::Windows::Forms::Form
	{
	public:
		ClientConstructor(Form^ cfr, System::Windows::Forms::ListBox^ l, std::vector<Person>* cl) :cf(cfr), lb(l), clients(cl)
		{
			InitializeComponent();
			this->BirthDate->MaxDate = System::DateTime::Now;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ClientConstructor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ NameSurname;
	protected:
	private: Form^ cf;
	private: System::Windows::Forms::TextBox^ PhoneNumber;
	private: System::Windows::Forms::DateTimePicker^ BirthDate;
	private: System::Windows::Forms::Label^ NameLabel;
	private: System::Windows::Forms::Label^ PhoneLabel;
	private: System::Windows::Forms::Label^ BirthDayLabel;
	private: System::Windows::Forms::Button^ ConfirmButton;
	private: System::Windows::Forms::ListBox^ lb;
	private: std::vector<Person>* clients;

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
			this->NameSurname = (gcnew System::Windows::Forms::TextBox());
			this->PhoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->BirthDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->PhoneLabel = (gcnew System::Windows::Forms::Label());
			this->BirthDayLabel = (gcnew System::Windows::Forms::Label());
			this->ConfirmButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// NameSurname
			// 
			this->NameSurname->Location = System::Drawing::Point(130, 50);
			this->NameSurname->MaxLength = 50;
			this->NameSurname->Name = L"NameSurname";
			this->NameSurname->Size = System::Drawing::Size(181, 22);
			this->NameSurname->TabIndex = 0;
			// 
			// PhoneNumber
			// 
			this->PhoneNumber->Location = System::Drawing::Point(130, 103);
			this->PhoneNumber->MaxLength = 13;
			this->PhoneNumber->Name = L"PhoneNumber";
			this->PhoneNumber->Size = System::Drawing::Size(181, 22);
			this->PhoneNumber->TabIndex = 1;
			this->PhoneNumber->Text = L"+375291111111";
			// 
			// BirthDate
			// 
			this->BirthDate->Location = System::Drawing::Point(130, 161);
			this->BirthDate->Name = L"BirthDate";
			this->BirthDate->Size = System::Drawing::Size(200, 22);
			this->BirthDate->TabIndex = 2;
			// 
			// NameLabel
			// 
			this->NameLabel->AutoSize = true;
			this->NameLabel->Location = System::Drawing::Point(40, 53);
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size(47, 16);
			this->NameLabel->TabIndex = 3;
			this->NameLabel->Text = L"Name:";
			// 
			// PhoneLabel
			// 
			this->PhoneLabel->AutoSize = true;
			this->PhoneLabel->Location = System::Drawing::Point(40, 109);
			this->PhoneLabel->Name = L"PhoneLabel";
			this->PhoneLabel->Size = System::Drawing::Size(49, 16);
			this->PhoneLabel->TabIndex = 4;
			this->PhoneLabel->Text = L"Phone:";
			// 
			// BirthDayLabel
			// 
			this->BirthDayLabel->AutoSize = true;
			this->BirthDayLabel->Location = System::Drawing::Point(40, 161);
			this->BirthDayLabel->Name = L"BirthDayLabel";
			this->BirthDayLabel->Size = System::Drawing::Size(61, 16);
			this->BirthDayLabel->TabIndex = 5;
			this->BirthDayLabel->Text = L"BirthDay:";
			// 
			// ConfirmButton
			// 
			this->ConfirmButton->Location = System::Drawing::Point(130, 257);
			this->ConfirmButton->Name = L"ConfirmButton";
			this->ConfirmButton->Size = System::Drawing::Size(167, 70);
			this->ConfirmButton->TabIndex = 6;
			this->ConfirmButton->Text = L"Ready";
			this->ConfirmButton->UseVisualStyleBackColor = true;
			this->ConfirmButton->Click += gcnew System::EventHandler(this, &ClientConstructor::ConfirmButton_Click);
			// 
			// ClientConstructor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(435, 426);
			this->Controls->Add(this->ConfirmButton);
			this->Controls->Add(this->BirthDayLabel);
			this->Controls->Add(this->PhoneLabel);
			this->Controls->Add(this->NameLabel);
			this->Controls->Add(this->BirthDate);
			this->Controls->Add(this->PhoneNumber);
			this->Controls->Add(this->NameSurname);
			this->Name = L"ClientConstructor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ClientConstructor";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ClientConstructor::ClientConstructor_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ConfirmButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrEmpty(NameSurname->Text) || String::IsNullOrEmpty(PhoneNumber->Text)) {
			MessageBox::Show("Fill all fields");
			return;
		}
		std::string ph = SysToStd(PhoneNumber->Text);
		if (!checkNumber(ph)) {
			MessageBox::Show("Incorrect phone number");
			return;
		}
		std::string ns = SysToStd(NameSurname->Text);
		for (auto i : *clients)
			if (ns == i.getName()) {
				MessageBox::Show("Client with this name already exists");
				return;
			}
		Date dt(BirthDate->Value);
		Person p(ns, ph, dt);
		clients->push_back(p);
		lb->Items->Add(StdToSys(p.getName()));
		NameSurname->Text = "";
		PhoneNumber->Text = "+375291111111";
	}
	private: System::Void ClientConstructor_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		cf->Enabled = true;
	}
};
}
