#pragma once
#include <Windows.h>
#include "ArregloCG.h"
#include "circuloG.h"
#include "circuloM.h"


namespace Juego {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		cg*obj1;
		cm*objm;
		cm*obj2m;
		Arrcg*arreglo;

		int tCG;
		int vCG;
		bool iCG;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  timer1;
			 Graphics ^d;
	public:
		MyForm(void)
		{
			InitializeComponent();
			d = this->CreateGraphics();
			obj1 = new cg(d,5,5,100,50,5);
			objm = new cm(d,5,5,50,50,5);
			obj2m = new cm(d, 5, 5, 50, 50, 5);
			arreglo = new Arrcg();
			tCG = 0;
			vCG = 0;
			iCG = true;
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
	{

		System::Drawing::Graphics^gr = this->CreateGraphics();
		SolidBrush^brocha = gcnew SolidBrush(Color::White);
		float a = gr->VisibleClipBounds.Width;
		float  l = gr->VisibleClipBounds.Height;
		gr->FillRectangle(brocha, 0, 0, (int)a, (int)l);

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		
	}
	private: System::Void eventLog1_EntryWritten(System::Object^  sender, System::Diagnostics::EntryWrittenEventArgs^  e) {
	
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^gr = this->CreateGraphics();
	//crear hasta cierta cantidad;
		obj2m->mover(d);
		
		if (iCG)
		{
			if (tCG == obj1->get_tiempo())
			{
				if (vCG<obj1->get_veces())
				{
					cg* obj2 = new cg(d, 5, 5, 100, 50, 5);
					arreglo->agregar(obj2);
					tCG = 0;
					vCG++;
				}
				else
				{
				//asdasdsdqwe
					iCG = false;
				}
			}
			tCG = tCG + 1;
		}
			for (int i=0; i<arreglo->get_N();i++)
		{
			arreglo->obtener(i)->mover(gr);
		}
		
	}
	};
}
