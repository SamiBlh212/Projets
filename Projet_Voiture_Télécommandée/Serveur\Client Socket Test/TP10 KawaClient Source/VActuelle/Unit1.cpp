//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::B_ConnecterClick(TObject *Sender)
{
	ClientSocket1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	// le timer ne sert qu'à l'affichage régulier de l'état de la connexion
	// (vert ou rouge) exmple : Shape1->Brush->Color = clGreen;

	// a completer

	if( ClientSocket1->Active == true )
	{
		Shape_Etat->Brush->Color = clGreen;
	}
	else
	{
		Shape_Etat->Brush->Color = clRed;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B_DeconnecterClick(TObject *Sender)
{
	ClientSocket1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
	AnsiString data;
	data = Edit1->Text;
	ClientSocket1->Socket->SendText(data);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connect(TObject *Sender, TCustomWinSocket *Socket)

{
    AnsiString salut = "Bonjour, que puis-je faire pour vous ?";
	AnsiString cava = "Oui parfaitement, vous aimeriez commander quelque chose ?";
	AnsiString cafe = "Le voila";
	AnsiString addition = "Votre café fera 2€";

	AnsiString data;
	data = ClientSocket1->Socket-> ReceiveText();

	if(data =="bonjour"||"Bonjour"||"Salut"||"salut")
	{
	   Memo1->Text = salut;
	}

	if(data =="ça va"||"cava"||"ca va")
	{
	   Memo1->Text = cava;
	}

	if(data =="un café svp"||"un café s'il vous plait"||"j'aimerais avoir un café s'il vous plait"||"un cafe svp"||"un café sil vous plait"||"un cafe sil vous plait")
	{
	   Memo1->Text = cafe;
	}
}
//---------------------------------------------------------------------------


