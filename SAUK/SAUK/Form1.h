#pragma once

namespace SAUK {

	using namespace System;
	using namespace System::Text;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::IO::Ports;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  tempLabel;
	private: System::Windows::Forms::Label^  locationLabel;
	protected: 
	protected: 
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::TrackBar^  tempTrackBar;
	private: System::Windows::Forms::TrackBar^  locationTrackBar;
	private: System::Windows::Forms::Label^  stateLabel;

	private: String^ s;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  connectButton;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  sendButton;


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tempLabel = (gcnew System::Windows::Forms::Label());
			this->locationLabel = (gcnew System::Windows::Forms::Label());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->tempTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->locationTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->stateLabel = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->connectButton = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tempTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->locationTrackBar))->BeginInit();
			this->SuspendLayout();
			// 
			// tempLabel
			// 
			this->tempLabel->AutoSize = true;
			this->tempLabel->Location = System::Drawing::Point(46, 31);
			this->tempLabel->Name = L"tempLabel";
			this->tempLabel->Size = System::Drawing::Size(74, 13);
			this->tempLabel->TabIndex = 7;
			this->tempLabel->Text = L"�����������";
			// 
			// locationLabel
			// 
			this->locationLabel->AutoSize = true;
			this->locationLabel->Location = System::Drawing::Point(46, 99);
			this->locationLabel->Name = L"locationLabel";
			this->locationLabel->Size = System::Drawing::Size(65, 13);
			this->locationLabel->TabIndex = 8;
			this->locationLabel->Text = L"���������";
			// 
			// serialPort1
			// 
			this->serialPort1->BaudRate = 115200;
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &Form1::serialPort1_DataReceived);
			// 
			// tempTrackBar
			// 
			this->tempTrackBar->Location = System::Drawing::Point(33, 47);
			this->tempTrackBar->Maximum = 30;
			this->tempTrackBar->Minimum = -30;
			this->tempTrackBar->Name = L"tempTrackBar";
			this->tempTrackBar->Size = System::Drawing::Size(104, 45);
			this->tempTrackBar->TabIndex = 9;
			this->tempTrackBar->ValueChanged += gcnew System::EventHandler(this, &Form1::TrackBar_ValueChanged);
			// 
			// locationTrackBar
			// 
			this->locationTrackBar->Location = System::Drawing::Point(33, 115);
			this->locationTrackBar->Name = L"locationTrackBar";
			this->locationTrackBar->Size = System::Drawing::Size(104, 45);
			this->locationTrackBar->TabIndex = 10;
			this->locationTrackBar->Value = 10;
			this->locationTrackBar->ValueChanged += gcnew System::EventHandler(this, &Form1::TrackBar_ValueChanged);
			// 
			// stateLabel
			// 
			this->stateLabel->AutoSize = true;
			this->stateLabel->Location = System::Drawing::Point(50, 195);
			this->stateLabel->Name = L"stateLabel";
			this->stateLabel->Size = System::Drawing::Size(61, 13);
			this->stateLabel->TabIndex = 11;
			this->stateLabel->Text = L"C��������";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// connectButton
			// 
			this->connectButton->Location = System::Drawing::Point(170, 101);
			this->connectButton->Name = L"connectButton";
			this->connectButton->Size = System::Drawing::Size(85, 23);
			this->connectButton->TabIndex = 12;
			this->connectButton->Text = L" ����������";
			this->connectButton->UseVisualStyleBackColor = true;
			this->connectButton->Click += gcnew System::EventHandler(this, &Form1::connectButton_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(170, 57);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(85, 21);
			this->comboBox1->TabIndex = 13;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// sendButton
			// 
			this->sendButton->Location = System::Drawing::Point(45, 151);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(75, 23);
			this->sendButton->TabIndex = 14;
			this->sendButton->Text = L"�������";
			this->sendButton->UseVisualStyleBackColor = true;
			this->sendButton->Click += gcnew System::EventHandler(this, &Form1::sendButton_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(279, 237);
			this->Controls->Add(this->sendButton);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->connectButton);
			this->Controls->Add(this->stateLabel);
			this->Controls->Add(this->locationTrackBar);
			this->Controls->Add(this->tempTrackBar);
			this->Controls->Add(this->locationLabel);
			this->Controls->Add(this->tempLabel);
			this->Name = L"Form1";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"SAUK";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tempTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->locationTrackBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void SetPortName()
			 {
				 this->comboBox1->Items->Clear();	
				 this->comboBox1->Text="";				
				 array<String^>^ serialPorts = nullptr;
				 try
				 {
					 // Get a list of serial port names.
					 serialPorts = SerialPort::GetPortNames();
					 for each(String^ port in serialPorts)
					 {
						 this->comboBox1->Items->Add(port);
						 comboBox1->SelectedIndex = 0;
					 }
					 if(comboBox1->SelectedIndex == -1)							
						 s=L"��� ������";					 					
				 }
				 catch (Win32Exception^)
				 {
					 s=L"��� ������";						
				 }					
			 }
	private: bool Connect()
			 {
				 try
				 {
					 if(!serialPort1->IsOpen)
						 serialPort1->Open();

					 if(serialPort1->IsOpen)
					 {
						 serialPort1->Encoding=Encoding::ASCII;	
						 return true;
					 }
					 else
						 return false;
				 }
				 catch(...)
				 {	
					 return false;
				 }
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 SetPortName();
				 s=L"���������";
				 sendButton->Enabled=false;
			 }
	private: System::Void TrackBar_ValueChanged(System::Object^  sender, System::EventArgs^  e) {

				 tempLabel->Text=String::Format("����������� {0} C",tempTrackBar->Value);
				 locationLabel->Text=String::Format("��������� {0}",locationTrackBar->Value);

			 }
	private: System::Void serialPort1_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
				 s=serialPort1->ReadExisting();
				 String^ r="reset";

				 for(int i=0;i<=(s->Length-r->Length);i++)
				 {
					 if(String::Compare(s,i,r,0,r->Length)==0)
					 {
						 s=L"�������";
						 return;
					 }	
				 }				 
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 stateLabel->Text=s;
			 }
	private: System::Void connectButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(Connect())
				 {
					 s=L"���������";
					 sendButton->Enabled=true;
				 }
				 else
					 s=L"��� �����������";
			 }
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 if(!serialPort1->IsOpen)
				 {
					 serialPort1->PortName=comboBox1->SelectedItem->ToString();						 
				 }
			 }
	private: System::Void sendButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 array<Byte>^ B = gcnew array<Byte>(2); 
				 B[0]=tempTrackBar->Value;
				 B[1]=locationTrackBar->Value;				 
				 serialPort1->Write("WR");
				 serialPort1->Write(B,0,2);	
			 }
	private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 if(serialPort1->IsOpen)
					 serialPort1->Close();
			 }
	};
}

