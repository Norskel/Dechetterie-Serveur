#pragma once


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Net::NetworkInformation;


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
	private: System::Windows::Forms::DataGridView^  dgvSrvBa;
	protected:

	protected:


	private: System::Windows::Forms::Button^  btSrvBaStart;
	private: System::Windows::Forms::Button^  btSrvBaStop;
	private: System::Windows::Forms::NumericUpDown^  nSrvBaPort;


	private: System::Windows::Forms::ComboBox^  cbSrvBaIp;






	private: System::Windows::Forms::Button^  btSrvBaValid;
	private: System::Windows::Forms::Label^  stateSrvBa;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  gbServBa;
	private: System::Windows::Forms::GroupBox^  gbServBr;
	private: System::Windows::Forms::DataGridView^  dgvSrvBr;



	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btSrvBrStart;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btSrvBrStop;
	private: System::Windows::Forms::Label^  stateSrvBr;
	private: System::Windows::Forms::NumericUpDown^  nSrvBrPort;




	private: System::Windows::Forms::Button^  btSrvBrValid;
	private: System::Windows::Forms::ComboBox^  cbSrvBrIp;





	private: System::Windows::Forms::GroupBox^  gbServNFC;
	private: System::Windows::Forms::DataGridView^  dgvSrvNfc;



	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  btSrvNfcStart;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  btSrvNfcStop;
	private: System::Windows::Forms::Label^  stateSrvNfc;
	private: System::Windows::Forms::NumericUpDown^  nSrvNfcPort;




	private: System::Windows::Forms::Button^  btSrvNfcValide;
	private: System::Windows::Forms::ComboBox^  cbSrvNfcIp;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  baIp;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  baGroupe;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  brIp;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  brGroupe;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  NfcIp;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  NfcGroupe;





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
			this->dgvSrvBa = (gcnew System::Windows::Forms::DataGridView());
			this->baIp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->baGroupe = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->btSrvBaStart = (gcnew System::Windows::Forms::Button());
			this->btSrvBaStop = (gcnew System::Windows::Forms::Button());
			this->nSrvBaPort = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbSrvBaIp = (gcnew System::Windows::Forms::ComboBox());
			this->btSrvBaValid = (gcnew System::Windows::Forms::Button());
			this->stateSrvBa = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->gbServBa = (gcnew System::Windows::Forms::GroupBox());
			this->gbServBr = (gcnew System::Windows::Forms::GroupBox());
			this->dgvSrvBr = (gcnew System::Windows::Forms::DataGridView());
			this->brIp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->brGroupe = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btSrvBrStart = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btSrvBrStop = (gcnew System::Windows::Forms::Button());
			this->stateSrvBr = (gcnew System::Windows::Forms::Label());
			this->nSrvBrPort = (gcnew System::Windows::Forms::NumericUpDown());
			this->btSrvBrValid = (gcnew System::Windows::Forms::Button());
			this->cbSrvBrIp = (gcnew System::Windows::Forms::ComboBox());
			this->gbServNFC = (gcnew System::Windows::Forms::GroupBox());
			this->dgvSrvNfc = (gcnew System::Windows::Forms::DataGridView());
			this->NfcIp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NfcGroupe = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btSrvNfcStart = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btSrvNfcStop = (gcnew System::Windows::Forms::Button());
			this->stateSrvNfc = (gcnew System::Windows::Forms::Label());
			this->nSrvNfcPort = (gcnew System::Windows::Forms::NumericUpDown());
			this->btSrvNfcValide = (gcnew System::Windows::Forms::Button());
			this->cbSrvNfcIp = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSrvBa))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nSrvBaPort))->BeginInit();
			this->gbServBa->SuspendLayout();
			this->gbServBr->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSrvBr))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nSrvBrPort))->BeginInit();
			this->gbServNFC->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSrvNfc))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nSrvNfcPort))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvSrvBa
			// 
			this->dgvSrvBa->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSrvBa->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->baIp, this->baGroupe });
			this->dgvSrvBa->Location = System::Drawing::Point(270, 19);
			this->dgvSrvBa->Name = L"dgvSrvBa";
			this->dgvSrvBa->Size = System::Drawing::Size(322, 124);
			this->dgvSrvBa->TabIndex = 0;
			// 
			// baIp
			// 
			this->baIp->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->baIp->HeaderText = L"IP";
			this->baIp->Name = L"baIp";
			// 
			// baGroupe
			// 
			this->baGroupe->HeaderText = L"Groupe";
			this->baGroupe->Name = L"baGroupe";
			this->baGroupe->Width = 150;
			// 
			// btSrvBaStart
			// 
			this->btSrvBaStart->Location = System::Drawing::Point(17, 34);
			this->btSrvBaStart->Name = L"btSrvBaStart";
			this->btSrvBaStart->Size = System::Drawing::Size(75, 23);
			this->btSrvBaStart->TabIndex = 1;
			this->btSrvBaStart->Text = L"Start";
			this->btSrvBaStart->UseVisualStyleBackColor = true;
			// 
			// btSrvBaStop
			// 
			this->btSrvBaStop->Location = System::Drawing::Point(17, 63);
			this->btSrvBaStop->Name = L"btSrvBaStop";
			this->btSrvBaStop->Size = System::Drawing::Size(75, 23);
			this->btSrvBaStop->TabIndex = 2;
			this->btSrvBaStop->Text = L"Stop";
			this->btSrvBaStop->UseVisualStyleBackColor = true;
			// 
			// nSrvBaPort
			// 
			this->nSrvBaPort->Location = System::Drawing::Point(122, 101);
			this->nSrvBaPort->Name = L"nSrvBaPort";
			this->nSrvBaPort->Size = System::Drawing::Size(120, 20);
			this->nSrvBaPort->TabIndex = 3;
			// 
			// cbSrvBaIp
			// 
			this->cbSrvBaIp->FormattingEnabled = true;
			this->cbSrvBaIp->Location = System::Drawing::Point(122, 45);
			this->cbSrvBaIp->Name = L"cbSrvBaIp";
			this->cbSrvBaIp->Size = System::Drawing::Size(120, 21);
			this->cbSrvBaIp->TabIndex = 4;
			// 
			// btSrvBaValid
			// 
			this->btSrvBaValid->Location = System::Drawing::Point(628, 58);
			this->btSrvBaValid->Name = L"btSrvBaValid";
			this->btSrvBaValid->Size = System::Drawing::Size(111, 48);
			this->btSrvBaValid->TabIndex = 5;
			this->btSrvBaValid->Text = L"button3";
			this->btSrvBaValid->UseVisualStyleBackColor = true;
			// 
			// stateSrvBa
			// 
			this->stateSrvBa->AutoSize = true;
			this->stateSrvBa->BackColor = System::Drawing::Color::Red;
			this->stateSrvBa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stateSrvBa->ForeColor = System::Drawing::Color::White;
			this->stateSrvBa->Location = System::Drawing::Point(35, 101);
			this->stateSrvBa->Name = L"stateSrvBa";
			this->stateSrvBa->Size = System::Drawing::Size(41, 20);
			this->stateSrvBa->TabIndex = 6;
			this->stateSrvBa->Text = L"OFF";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(119, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Port TCP";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(119, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"IP Interface";
			// 
			// gbServBa
			// 
			this->gbServBa->Controls->Add(this->dgvSrvBa);
			this->gbServBa->Controls->Add(this->label3);
			this->gbServBa->Controls->Add(this->btSrvBaStart);
			this->gbServBa->Controls->Add(this->label2);
			this->gbServBa->Controls->Add(this->btSrvBaStop);
			this->gbServBa->Controls->Add(this->stateSrvBa);
			this->gbServBa->Controls->Add(this->nSrvBaPort);
			this->gbServBa->Controls->Add(this->btSrvBaValid);
			this->gbServBa->Controls->Add(this->cbSrvBaIp);
			this->gbServBa->Location = System::Drawing::Point(12, 12);
			this->gbServBa->Name = L"gbServBa";
			this->gbServBa->Size = System::Drawing::Size(767, 165);
			this->gbServBa->TabIndex = 9;
			this->gbServBa->TabStop = false;
			this->gbServBa->Text = L"Serveur Balance";
			// 
			// gbServBr
			// 
			this->gbServBr->Controls->Add(this->dgvSrvBr);
			this->gbServBr->Controls->Add(this->label4);
			this->gbServBr->Controls->Add(this->btSrvBrStart);
			this->gbServBr->Controls->Add(this->label5);
			this->gbServBr->Controls->Add(this->btSrvBrStop);
			this->gbServBr->Controls->Add(this->stateSrvBr);
			this->gbServBr->Controls->Add(this->nSrvBrPort);
			this->gbServBr->Controls->Add(this->btSrvBrValid);
			this->gbServBr->Controls->Add(this->cbSrvBrIp);
			this->gbServBr->Location = System::Drawing::Point(12, 183);
			this->gbServBr->Name = L"gbServBr";
			this->gbServBr->Size = System::Drawing::Size(767, 165);
			this->gbServBr->TabIndex = 10;
			this->gbServBr->TabStop = false;
			this->gbServBr->Text = L"Serveur Barrière";
			// 
			// dgvSrvBr
			// 
			this->dgvSrvBr->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSrvBr->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->brIp, this->brGroupe });
			this->dgvSrvBr->Location = System::Drawing::Point(270, 19);
			this->dgvSrvBr->Name = L"dgvSrvBr";
			this->dgvSrvBr->Size = System::Drawing::Size(322, 124);
			this->dgvSrvBr->TabIndex = 0;
			// 
			// brIp
			// 
			this->brIp->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->brIp->HeaderText = L"IP";
			this->brIp->Name = L"brIp";
			// 
			// brGroupe
			// 
			this->brGroupe->HeaderText = L"Groupe";
			this->brGroupe->Name = L"brGroupe";
			this->brGroupe->Width = 150;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(119, 29);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"IP Interface";
			// 
			// btSrvBrStart
			// 
			this->btSrvBrStart->Location = System::Drawing::Point(17, 34);
			this->btSrvBrStart->Name = L"btSrvBrStart";
			this->btSrvBrStart->Size = System::Drawing::Size(75, 23);
			this->btSrvBrStart->TabIndex = 1;
			this->btSrvBrStart->Text = L"Start";
			this->btSrvBrStart->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(119, 85);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Port TCP";
			// 
			// btSrvBrStop
			// 
			this->btSrvBrStop->Location = System::Drawing::Point(17, 63);
			this->btSrvBrStop->Name = L"btSrvBrStop";
			this->btSrvBrStop->Size = System::Drawing::Size(75, 23);
			this->btSrvBrStop->TabIndex = 2;
			this->btSrvBrStop->Text = L"Stop";
			this->btSrvBrStop->UseVisualStyleBackColor = true;
			// 
			// stateSrvBr
			// 
			this->stateSrvBr->AutoSize = true;
			this->stateSrvBr->BackColor = System::Drawing::Color::Red;
			this->stateSrvBr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stateSrvBr->ForeColor = System::Drawing::Color::White;
			this->stateSrvBr->Location = System::Drawing::Point(35, 101);
			this->stateSrvBr->Name = L"stateSrvBr";
			this->stateSrvBr->Size = System::Drawing::Size(41, 20);
			this->stateSrvBr->TabIndex = 6;
			this->stateSrvBr->Text = L"OFF";
			// 
			// nSrvBrPort
			// 
			this->nSrvBrPort->Location = System::Drawing::Point(122, 101);
			this->nSrvBrPort->Name = L"nSrvBrPort";
			this->nSrvBrPort->Size = System::Drawing::Size(120, 20);
			this->nSrvBrPort->TabIndex = 3;
			// 
			// btSrvBrValid
			// 
			this->btSrvBrValid->Location = System::Drawing::Point(628, 58);
			this->btSrvBrValid->Name = L"btSrvBrValid";
			this->btSrvBrValid->Size = System::Drawing::Size(111, 48);
			this->btSrvBrValid->TabIndex = 5;
			this->btSrvBrValid->Text = L"button6";
			this->btSrvBrValid->UseVisualStyleBackColor = true;
			// 
			// cbSrvBrIp
			// 
			this->cbSrvBrIp->FormattingEnabled = true;
			this->cbSrvBrIp->Location = System::Drawing::Point(122, 45);
			this->cbSrvBrIp->Name = L"cbSrvBrIp";
			this->cbSrvBrIp->Size = System::Drawing::Size(120, 21);
			this->cbSrvBrIp->TabIndex = 4;
			// 
			// gbServNFC
			// 
			this->gbServNFC->Controls->Add(this->dgvSrvNfc);
			this->gbServNFC->Controls->Add(this->label7);
			this->gbServNFC->Controls->Add(this->btSrvNfcStart);
			this->gbServNFC->Controls->Add(this->label8);
			this->gbServNFC->Controls->Add(this->btSrvNfcStop);
			this->gbServNFC->Controls->Add(this->stateSrvNfc);
			this->gbServNFC->Controls->Add(this->nSrvNfcPort);
			this->gbServNFC->Controls->Add(this->btSrvNfcValide);
			this->gbServNFC->Controls->Add(this->cbSrvNfcIp);
			this->gbServNFC->Location = System::Drawing::Point(12, 354);
			this->gbServNFC->Name = L"gbServNFC";
			this->gbServNFC->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->gbServNFC->Size = System::Drawing::Size(767, 165);
			this->gbServNFC->TabIndex = 10;
			this->gbServNFC->TabStop = false;
			this->gbServNFC->Text = L"Serveur NFC";
			// 
			// dgvSrvNfc
			// 
			this->dgvSrvNfc->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSrvNfc->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->NfcIp, this->NfcGroupe });
			this->dgvSrvNfc->Location = System::Drawing::Point(270, 19);
			this->dgvSrvNfc->Name = L"dgvSrvNfc";
			this->dgvSrvNfc->Size = System::Drawing::Size(322, 124);
			this->dgvSrvNfc->TabIndex = 0;
			// 
			// NfcIp
			// 
			this->NfcIp->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->NfcIp->HeaderText = L"IP";
			this->NfcIp->Name = L"NfcIp";
			// 
			// NfcGroupe
			// 
			this->NfcGroupe->HeaderText = L"Groupe";
			this->NfcGroupe->Name = L"NfcGroupe";
			this->NfcGroupe->Width = 150;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(119, 29);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(62, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"IP Interface";
			// 
			// btSrvNfcStart
			// 
			this->btSrvNfcStart->Location = System::Drawing::Point(17, 34);
			this->btSrvNfcStart->Name = L"btSrvNfcStart";
			this->btSrvNfcStart->Size = System::Drawing::Size(75, 23);
			this->btSrvNfcStart->TabIndex = 1;
			this->btSrvNfcStart->Text = L"Start";
			this->btSrvNfcStart->UseVisualStyleBackColor = true;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(119, 85);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(50, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Port TCP";
			// 
			// btSrvNfcStop
			// 
			this->btSrvNfcStop->Location = System::Drawing::Point(17, 63);
			this->btSrvNfcStop->Name = L"btSrvNfcStop";
			this->btSrvNfcStop->Size = System::Drawing::Size(75, 23);
			this->btSrvNfcStop->TabIndex = 2;
			this->btSrvNfcStop->Text = L"Stop";
			this->btSrvNfcStop->UseVisualStyleBackColor = true;
			// 
			// stateSrvNfc
			// 
			this->stateSrvNfc->AutoSize = true;
			this->stateSrvNfc->BackColor = System::Drawing::Color::Red;
			this->stateSrvNfc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stateSrvNfc->ForeColor = System::Drawing::Color::White;
			this->stateSrvNfc->Location = System::Drawing::Point(35, 101);
			this->stateSrvNfc->Name = L"stateSrvNfc";
			this->stateSrvNfc->Size = System::Drawing::Size(41, 20);
			this->stateSrvNfc->TabIndex = 6;
			this->stateSrvNfc->Text = L"OFF";
			// 
			// nSrvNfcPort
			// 
			this->nSrvNfcPort->Location = System::Drawing::Point(122, 101);
			this->nSrvNfcPort->Name = L"nSrvNfcPort";
			this->nSrvNfcPort->Size = System::Drawing::Size(120, 20);
			this->nSrvNfcPort->TabIndex = 3;
			// 
			// btSrvNfcValide
			// 
			this->btSrvNfcValide->Location = System::Drawing::Point(628, 58);
			this->btSrvNfcValide->Name = L"btSrvNfcValide";
			this->btSrvNfcValide->Size = System::Drawing::Size(111, 48);
			this->btSrvNfcValide->TabIndex = 5;
			this->btSrvNfcValide->Text = L"button9";
			this->btSrvNfcValide->UseVisualStyleBackColor = true;
			// 
			// cbSrvNfcIp
			// 
			this->cbSrvNfcIp->FormattingEnabled = true;
			this->cbSrvNfcIp->Location = System::Drawing::Point(122, 45);
			this->cbSrvNfcIp->Name = L"cbSrvNfcIp";
			this->cbSrvNfcIp->Size = System::Drawing::Size(120, 21);
			this->cbSrvNfcIp->TabIndex = 4;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(803, 670);
			this->Controls->Add(this->gbServNFC);
			this->Controls->Add(this->gbServBr);
			this->Controls->Add(this->gbServBa);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSrvBa))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nSrvBaPort))->EndInit();
			this->gbServBa->ResumeLayout(false);
			this->gbServBa->PerformLayout();
			this->gbServBr->ResumeLayout(false);
			this->gbServBr->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSrvBr))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nSrvBrPort))->EndInit();
			this->gbServNFC->ResumeLayout(false);
			this->gbServNFC->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSrvNfc))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nSrvNfcPort))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		IPHostEntry^ host = Dns::GetHostEntry(Dns::GetHostName());

		for each(IPAddress^ ip in host->AddressList)
		{
			if (ip->AddressFamily == AddressFamily::InterNetwork)
			{
				cbSrvBaIp->Items->Add(ip);
				cbSrvBrIp->Items->Add(ip);
				cbSrvNfcIp->Items->Add(ip);

				Console::WriteLine(ip->ToString());
			}

		}
		
	}
};

