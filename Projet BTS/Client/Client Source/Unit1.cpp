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
	// A compléter
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	// le timer ne sert qu'à l'affichage régulier de l'état de la connexion
	// (vert ou rouge) exmple : Shape1->Brush->Color = clGreen;

	// a completer
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B_DeconnecterClick(TObject *Sender)
{
    // A compléter
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
	// a completer
}
//---------------------------------------------------------------------------

