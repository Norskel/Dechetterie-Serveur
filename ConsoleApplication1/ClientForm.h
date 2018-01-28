#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Text;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Threading;
	using namespace System::IO;
	using namespace System::ComponentModel;


	delegate void DPrintLog(String^ msg);

	/// <summary>
	/// Description résumée de ClientForm
	/// </summary>
	public ref class ClientForm : public System::Windows::Forms::Form
	{
	public:
		ClientForm(IPAddress^ ip, int port)
		{
			InitializeComponent();

			_ip = ip;
			this->tbIp->Text = _ip->ToString();
			_port = port;
			this->nUDPort->Value = (Decimal)_port;
			_client = gcnew TcpClient();
			_serveur = gcnew IPEndPoint(_ip, _port);
			
			
			
			//TE = gcnew Thread(gcnew ThreadStart(this, &Client::TEd));
			TR = gcnew Thread(gcnew ThreadStart(this, &ClientForm::TRd));
			//TE->Name = "Thread Reception Client " + _id;
			TR->Name = "Thread Envoie Client " + _id;
			dPrintLogClient = gcnew DPrintLog(this,&ClientForm::printLog);

			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ClientForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tbClientLog;
	private: System::Windows::Forms::Label^  lClientEtat;
	private: System::Windows::Forms::Button^  btClientCo;

	private: System::Windows::Forms::TextBox^  tbClientSend;
	private: System::Windows::Forms::Button^  btClientSend;
	private: System::Windows::Forms::Button^  btClientClose;
	private: DPrintLog^ dPrintLogClient;
	protected:

	private:
		/// <summary>
		/// private:
		IPAddress^ _ip;
		int _port;
		TcpClient^ _client;
		Boolean _etat = false;
		Thread^ TE;
		Thread^ TR;
		IPEndPoint^ _serveur;
		int _id;
		StreamReader^ srClient;
		StreamWriter^ swClient;
		NetworkStream^ _stream;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::NumericUpDown^  nUDPort;
	private: System::Windows::Forms::TextBox^  tbIp;


	private: System::Windows::Forms::ComboBox^  cbEncode;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  checkState;
	private: System::ComponentModel::IContainer^  components;



		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tbClientLog = (gcnew System::Windows::Forms::TextBox());
			this->lClientEtat = (gcnew System::Windows::Forms::Label());
			this->btClientCo = (gcnew System::Windows::Forms::Button());
			this->tbClientSend = (gcnew System::Windows::Forms::TextBox());
			this->btClientSend = (gcnew System::Windows::Forms::Button());
			this->btClientClose = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbEncode = (gcnew System::Windows::Forms::ComboBox());
			this->nUDPort = (gcnew System::Windows::Forms::NumericUpDown());
			this->tbIp = (gcnew System::Windows::Forms::TextBox());
			this->checkState = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUDPort))->BeginInit();
			this->SuspendLayout();
			// 
			// tbClientLog
			// 
			this->tbClientLog->Location = System::Drawing::Point(12, 12);
			this->tbClientLog->Multiline = true;
			this->tbClientLog->Name = L"tbClientLog";
			this->tbClientLog->ReadOnly = true;
			this->tbClientLog->Size = System::Drawing::Size(284, 268);
			this->tbClientLog->TabIndex = 1;
			// 
			// lClientEtat
			// 
			this->lClientEtat->AutoSize = true;
			this->lClientEtat->BackColor = System::Drawing::Color::Red;
			this->lClientEtat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lClientEtat->ForeColor = System::Drawing::Color::White;
			this->lClientEtat->Location = System::Drawing::Point(202, 50);
			this->lClientEtat->Name = L"lClientEtat";
			this->lClientEtat->Size = System::Drawing::Size(38, 18);
			this->lClientEtat->TabIndex = 15;
			this->lClientEtat->Text = L"OFF";
			// 
			// btClientCo
			// 
			this->btClientCo->Location = System::Drawing::Point(6, 19);
			this->btClientCo->Name = L"btClientCo";
			this->btClientCo->Size = System::Drawing::Size(75, 23);
			this->btClientCo->TabIndex = 14;
			this->btClientCo->Text = L"Connect";
			this->btClientCo->UseVisualStyleBackColor = true;
			this->btClientCo->Click += gcnew System::EventHandler(this, &ClientForm::btClientCo_Click);
			// 
			// tbClientSend
			// 
			this->tbClientSend->Location = System::Drawing::Point(12, 286);
			this->tbClientSend->Name = L"tbClientSend";
			this->tbClientSend->Size = System::Drawing::Size(284, 20);
			this->tbClientSend->TabIndex = 12;
			// 
			// btClientSend
			// 
			this->btClientSend->Location = System::Drawing::Point(302, 284);
			this->btClientSend->Name = L"btClientSend";
			this->btClientSend->Size = System::Drawing::Size(75, 23);
			this->btClientSend->TabIndex = 11;
			this->btClientSend->Text = L"Send";
			this->btClientSend->UseVisualStyleBackColor = true;
			this->btClientSend->Click += gcnew System::EventHandler(this, &ClientForm::btClientSend_Click);
			// 
			// btClientClose
			// 
			this->btClientClose->Location = System::Drawing::Point(6, 48);
			this->btClientClose->Name = L"btClientClose";
			this->btClientClose->Size = System::Drawing::Size(75, 23);
			this->btClientClose->TabIndex = 10;
			this->btClientClose->Text = L"Disconnect";
			this->btClientClose->UseVisualStyleBackColor = true;
			this->btClientClose->Click += gcnew System::EventHandler(this, &ClientForm::btClientClose_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->cbEncode);
			this->groupBox1->Controls->Add(this->nUDPort);
			this->groupBox1->Controls->Add(this->tbIp);
			this->groupBox1->Controls->Add(this->btClientCo);
			this->groupBox1->Controls->Add(this->lClientEtat);
			this->groupBox1->Controls->Add(this->btClientClose);
			this->groupBox1->Location = System::Drawing::Point(302, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(249, 110);
			this->groupBox1->TabIndex = 16;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Configuration";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Encodage";
			// 
			// cbEncode
			// 
			this->cbEncode->FormattingEnabled = true;
			this->cbEncode->Location = System::Drawing::Point(87, 74);
			this->cbEncode->Name = L"cbEncode";
			this->cbEncode->Size = System::Drawing::Size(104, 21);
			this->cbEncode->TabIndex = 19;
			// 
			// nUDPort
			// 
			this->nUDPort->Location = System::Drawing::Point(87, 48);
			this->nUDPort->Name = L"nUDPort";
			this->nUDPort->Size = System::Drawing::Size(104, 20);
			this->nUDPort->TabIndex = 17;
			// 
			// tbIp
			// 
			this->tbIp->Location = System::Drawing::Point(87, 22);
			this->tbIp->MaxLength = 16;
			this->tbIp->Name = L"tbIp";
			this->tbIp->Size = System::Drawing::Size(105, 20);
			this->tbIp->TabIndex = 16;
			// 
			// checkState
			// 
			this->checkState->Enabled = true;
			this->checkState->Tick += gcnew System::EventHandler(this, &ClientForm::checkState_Tick);
			// 
			// ClientForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(564, 315);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->tbClientSend);
			this->Controls->Add(this->btClientSend);
			this->Controls->Add(this->tbClientLog);
			this->Name = L"ClientForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ClientForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUDPort))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


		void TRd()
		{
			String^ data;
			while (true)
			{
				try
				{
					//data = srClient->ReadLine();
					//Console::WriteLine(data);
					//this->Invoke(dPrintLogClient, data);

					if (_stream->CanRead)
					{
						array<Byte>^ myReadBuffer = gcnew array<Byte>(1024);
						String^ myCompleteMessage = "";
						int numberOfBytesRead = 0;

						// Incoming message may be larger than the buffer size.
						do
						{
							numberOfBytesRead = _stream->Read(myReadBuffer, 0, myReadBuffer->Length);
							myCompleteMessage = String::Concat(myCompleteMessage,Encoding::ASCII->GetString(myReadBuffer, 0, numberOfBytesRead));
						} while (_stream->DataAvailable);

						this->Invoke(dPrintLogClient, myCompleteMessage);

						// Print out the received message to the console.
						Console::WriteLine("You received the following message : {0}",
							myCompleteMessage);
					}
					
				}
				catch (Exception^ e)
				{

				}

				//this->tbClientLog->AppendText(data);
				
			}
		}
		void Send(String^ msg)
		{
			//swClient = gcnew StreamWriter(_client->GetStream());
			////_stream->BeginWrite()
			//this->Invoke(dPrintLogClient,"> " + msg);
			//swClient->WriteLine(msg);
			//swClient->Flush();
			//swClient->Close();
			try
			{
				if (_stream->CanWrite)
				{
					array<Byte>^ myWriteBuffer = Encoding::ASCII->GetBytes(
						msg);
					_stream->Write(myWriteBuffer, 0, myWriteBuffer->Length);
				}

			}
			catch (Exception^ e)
			{
				this->Invoke(dPrintLogClient, "[Erreur] Connexion impossible \n");
				Console::WriteLine("Erreur " + e);
				_etat = false;
			}



		}
		void Start()
		{
			
			try
			{
				_client->Connect(_serveur);
				
				srClient = gcnew StreamReader(_client->GetStream(), Encoding::ASCII);
				_stream = _client->GetStream();
				TR->Start();
				_etat = true;
				//TE->Start();
			}
			catch (Exception^ e)
			{
				this->Invoke(dPrintLogClient,"[Erreur] Connexion impossible \n");
				Console::WriteLine("Erreur " + e);
				_etat = false;
			}


		}
		void printLog(String^ msg)
		{
			try
			{
				tbClientLog->AppendText(msg);
			}
			catch (Exception^ e)
			{

				//Console::WriteLine("Erreur " + e + msg);
				
			}
			
		}


#pragma endregion
	private: System::Void btClientCo_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Start();

	}
	private: System::Void btClientClose_Click(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void btClientSend_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Send(this->tbClientSend->Text);
	}


private: System::Void checkState_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (_etat)
	{
		this->cbEncode->Enabled = false;
		this->nUDPort->Enabled = false;
		this->tbIp->Enabled = false;
		this->btClientClose->Enabled = true;
		this->btClientCo->Enabled = false;
		lClientEtat->Text = "ON";
		lClientEtat->BackColor = Color::Lime;
	}
	else
	{
		this->cbEncode->Enabled = true;
		this->nUDPort->Enabled = true;
		this->tbIp->Enabled = true;
		this->btClientClose->Enabled = false;
		this->btClientCo->Enabled = true;
		lClientEtat->Text = "OFF";
		lClientEtat->BackColor = Color::Red;
	}
	_etat = _client->Connected;
}
};

