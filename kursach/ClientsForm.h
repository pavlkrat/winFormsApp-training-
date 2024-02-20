#include "ClientConstructor.h"
#include "ClientView.h"
#include "RecordForm.h"

#pragma once

namespace kursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ClientsForm
	/// </summary>
	public ref class ClientsForm : public System::Windows::Forms::Form
	{
	public:
		ClientsForm(Form^ mfr, System::Windows::Forms::DataGridView^ dg, std::vector<Person>* c, std::unordered_map<Date, std::vector<Client>, Date::Hash>* m) :mf(mfr), dgv(dg), clients(c), mp(m)
		{
			InitializeComponent();
			for (int i = 0;i < clients->size();i++)
				ClientsList->Items->Add(StdToSys((*clients)[i].getName()));
			dt = new Date();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ClientsForm()
		{
			if (components)
				delete components;
			if (dt)
				delete dt;
		}
	private: Form^ mf;
	private: System::Windows::Forms::ListBox^ ClientsList;
	private: System::Windows::Forms::Button^ ClientAdd;
	private: System::Windows::Forms::DataGridView^ dgv;
	private: std::vector<Person>* clients;
	private: std::unordered_map<Date, std::vector<Client>, Date::Hash>* mp;
	public: Date* dt;
	public: int mode = -1;
	protected:


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ClientsList = (gcnew System::Windows::Forms::ListBox());
			this->ClientAdd = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ClientsList
			// 
			this->ClientsList->FormattingEnabled = true;
			this->ClientsList->ItemHeight = 16;
			this->ClientsList->Location = System::Drawing::Point(48, 40);
			this->ClientsList->Name = L"ClientsList";
			this->ClientsList->Size = System::Drawing::Size(274, 132);
			this->ClientsList->TabIndex = 0;
			this->ClientsList->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ClientsForm::ClientsList_MouseDoubleClick);
			// 
			// ClientAdd
			// 
			this->ClientAdd->Location = System::Drawing::Point(373, 69);
			this->ClientAdd->Name = L"ClientAdd";
			this->ClientAdd->Size = System::Drawing::Size(124, 68);
			this->ClientAdd->TabIndex = 1;
			this->ClientAdd->Text = L"Сreate new";
			this->ClientAdd->UseVisualStyleBackColor = true;
			this->ClientAdd->Click += gcnew System::EventHandler(this, &ClientsForm::ClientAdd_Click);
			// 
			// ClientsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(545, 209);
			this->Controls->Add(this->ClientAdd);
			this->Controls->Add(this->ClientsList);
			this->Name = L"ClientsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ClientsForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ClientsForm::ClientsForm_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ClientsList_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		int it = ClientsList->SelectedIndex;
		if (it == -1)
			return;
		if (mode == -1) {
			Hide();
			ClientView^ cw = gcnew ClientView(this, ClientsList, clients, it);
			cw->Show();
		}
		else {
			RecordForm^ rf = gcnew RecordForm(mf, dgv, mp, dt, mode, &(*clients)[it]);
			rf->Show();
			Hide();
		}
	}

	private: System::Void ClientAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		ClientConstructor^ cc = gcnew ClientConstructor(this, ClientsList, clients);
		Enabled = false;
		cc->Show();
	}
	private: System::Void ClientsForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (e->CloseReason == CloseReason::UserClosing)
		{
			e->Cancel = true;
			mf->Show();
			Hide();
		}
	}
};
}
