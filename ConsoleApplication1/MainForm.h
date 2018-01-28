#pragma once
#include "ClientForm.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Threading;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Description résumée de MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::Button^  addClient;

	private: System::Windows::Forms::TextBox^  tbIp;
	private: System::Windows::Forms::NumericUpDown^  nUDPort;
	private: System::Windows::Forms::Label^  lIP;
	private: System::Windows::Forms::Label^  lPort;
	private: List<ClientForm^>^ ct =  gcnew List<ClientForm^>;

	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->addClient = (gcnew System::Windows::Forms::Button());
			this->tbIp = (gcnew System::Windows::Forms::TextBox());
			this->nUDPort = (gcnew System::Windows::Forms::NumericUpDown());
			this->lIP = (gcnew System::Windows::Forms::Label());
			this->lPort = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUDPort))->BeginInit();
			this->SuspendLayout();
			// 
			// addClient
			// 
			this->addClient->Location = System::Drawing::Point(12, 120);
			this->addClient->Name = L"addClient";
			this->addClient->Size = System::Drawing::Size(75, 23);
			this->addClient->TabIndex = 2;
			this->addClient->Text = L"Add";
			this->addClient->UseVisualStyleBackColor = true;
			this->addClient->Click += gcnew System::EventHandler(this, &MainForm::addClient_Click);
			// 
			// tbIp
			// 
			this->tbIp->Location = System::Drawing::Point(12, 43);
			this->tbIp->Name = L"tbIp";
			this->tbIp->Size = System::Drawing::Size(115, 20);
			this->tbIp->TabIndex = 1;
			// 
			// nUDPort
			// 
			this->nUDPort->Location = System::Drawing::Point(12, 84);
			this->nUDPort->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65536, 0, 0, 0 });
			this->nUDPort->Name = L"nUDPort";
			this->nUDPort->Size = System::Drawing::Size(120, 20);
			this->nUDPort->TabIndex = 3;
			// 
			// lIP
			// 
			this->lIP->AutoSize = true;
			this->lIP->Location = System::Drawing::Point(13, 24);
			this->lIP->Name = L"lIP";
			this->lIP->Size = System::Drawing::Size(57, 13);
			this->lIP->TabIndex = 4;
			this->lIP->Text = L"IP Serveur";
			// 
			// lPort
			// 
			this->lPort->AutoSize = true;
			this->lPort->Location = System::Drawing::Point(12, 65);
			this->lPort->Name = L"lPort";
			this->lPort->Size = System::Drawing::Size(66, 13);
			this->lPort->TabIndex = 5;
			this->lPort->Text = L"Port Serveur";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(188, 167);
			this->Controls->Add(this->lPort);
			this->Controls->Add(this->lIP);
			this->Controls->Add(this->nUDPort);
			this->Controls->Add(this->tbIp);
			this->Controls->Add(this->addClient);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUDPort))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void addClient_Click(System::Object^  sender, System::EventArgs^  e) {
	int srvPort = (int)nUDPort->Value;

	try
	{
		IPAddress^ srvIp = IPAddress::Parse(tbIp->Text);
		ct->Add(gcnew ClientForm(srvIp, srvPort));
		ct[ct->Count - 1]->Show();
		//ct[1]->Show();
		

	}
	catch (Exception^ e)
	{
		Console::WriteLine("Erreur " + e->ToString());
	}
	

}
};
	
