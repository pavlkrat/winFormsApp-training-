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
	/// —водка дл€ ClientView
	/// </summary>
	public ref class ClientView : public System::Windows::Forms::Form
	{
	public:
		ClientView(Form^ cfr, System::Windows::Forms::ListBox^ l, std::vector<Person>* cl, int id) :cf(cfr), lb(l), clients(cl), idx(id)
		{
			InitializeComponent();
			ClientInfo->Text = StdToSys((*cl)[id].toString());
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ClientView()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: Form^ cf;
	private: std::vector<Person>* clients;
	private: System::Windows::Forms::Button^ DeleteButton;
	private: System::Windows::Forms::RichTextBox^ ClientInfo;
	private: System::Windows::Forms::ListBox^ lb;
	private: int idx;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->ClientInfo = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// DeleteButton
			// 
			this->DeleteButton->Location = System::Drawing::Point(144, 197);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(90, 45);
			this->DeleteButton->TabIndex = 0;
			this->DeleteButton->Text = L"Delete";
			this->DeleteButton->UseVisualStyleBackColor = true;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &ClientView::DeleteButton_Click);
			// 
			// ClientInfo
			// 
			this->ClientInfo->Location = System::Drawing::Point(61, 36);
			this->ClientInfo->Name = L"ClientInfo";
			this->ClientInfo->ReadOnly = true;
			this->ClientInfo->Size = System::Drawing::Size(246, 136);
			this->ClientInfo->TabIndex = 1;
			this->ClientInfo->Text = L"";
			// 
			// ClientView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(373, 279);
			this->Controls->Add(this->ClientInfo);
			this->Controls->Add(this->DeleteButton);
			this->Name = L"ClientView";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ClientView";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ClientView::ClientView_FormClosed);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show("Delete?", "Confirm", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
			clients->erase(clients->begin() + idx);
			lb->Items->RemoveAt(idx);
			Close();
		}
	}
	private: System::Void ClientView_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		cf->Show();
	}
};
}
