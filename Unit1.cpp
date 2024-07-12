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
        Zmodyfikowany = false;
        NazwaPliku = "";  //#1
        //AnsiString NazwaPliku = ""; //#2
        RichEdit1->PlainText = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Nowy1Click(TObject *Sender)
{
        if(Application->MessageBoxA("Czy utworzyæ nowy plik?", "", MB_YESNOCANCEL | MB_ICONQUESTION) == IDYES)
        {
                if(Zmodyfikowany)
                {
                        int odp = Application->MessageBoxA("Plik zostal zmodyfikowany. Zapisac?", "", MB_YESNO | MB_ICONQUESTION);
                        if(odp==IDYES)
                        {
                                Zapisz1Click(Sender);
                                RichEdit1->Lines->Clear();
                                NazwaPliku = "";
                                Form1->Caption = "Note";
                        }else if(odp==IDNO)
                        {
                                //return;
                                RichEdit1->Lines->Clear();
                                NazwaPliku = "";
                                Form1->Caption = "Note";
                        }
                }else
                {
                        RichEdit1->Lines->Clear();
                        NazwaPliku = "";
                        Form1->Caption = "Note";
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Otwrz1Click(TObject *Sender)
{
        if(OpenDialog1->Execute())
        {
                try
                {
                        RichEdit1->Lines->LoadFromFile(OpenDialog1->FileName);
                        NazwaPliku = OpenDialog1->FileName;
                        Zmodyfikowany = false;
                        Form1->Caption = "Note - " + ExtractFileName(OpenDialog1->FileName);
                }
                catch(...)
                {
                        Application->MessageBoxA("B³¹d otwarcia pliku. Upewnij siê, ¿e plik istnieje na dysku","B³¹d!", MB_OK | MB_ICONERROR);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapisz1Click(TObject *Sender)
{
        if(NazwaPliku != "")
        {
                RichEdit1->Lines->SaveToFile(NazwaPliku);
                NazwaPliku = OpenDialog1->FileName;
                Form1->Caption = "Note - " + ExtractFileName(SaveDialog1->FileName);
        }
        else if(SaveDialog1->Execute())
        {
                try
                {
                        NazwaPliku = SaveDialog1->FileName;
                        RichEdit1->Lines->SaveToFile(NazwaPliku);
                        Zmodyfikowany = false;
                        Form1->Caption = "Note - " + ExtractFileName(SaveDialog1->FileName);
                }catch(...)
                {
                        Application->MessageBox("Zapis zakoñczy³ siê niepowodzeniem.", "B³¹d!", MB_OK | MB_ICONERROR);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapiszjako1Click(TObject *Sender)
{
        if (SaveDialog1->FileName == "")
        {
                if(SaveDialog1->Execute())
                {
                        //try
                        //{
                                NazwaPliku = SaveDialog1->FileName;
                                RichEdit1->Lines->SaveToFile(NazwaPliku);
                                Zmodyfikowany = false;
                                Form1->Caption = "Note - " + ExtractFileName(SaveDialog1->FileName);
                        //}catch(...)
                        //{
                        //       Application->MessageBox("Zapis zakoñczy³ siê niepowodzeniem.", "B³¹d!", MB_OK | MB_ICONERROR);
                        //}
                }
        }else
        {
                SaveDialog1->FileName = "";
                //SaveDialog1->FileName = NazwaPliku;//ExtractFileName(SaveDialog1->FileName - SaveDialog1->Filter);
                if(SaveDialog1->Execute())
                {
                        //try
                        //{
                                NazwaPliku = SaveDialog1->FileName;
                                RichEdit1->Lines->SaveToFile(NazwaPliku);
                                Zmodyfikowany = false;
                                Form1->Caption = "Note - " + ExtractFileName(SaveDialog1->FileName);
                        //}catch(...)
                        //{
                        //        Application->MessageBox("Zapis zakoñczy³ siê niepowodzeniem.", "B³¹d!", MB_OK | MB_ICONERROR);
                        //}
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Wyj1Click(TObject *Sender)
{
        int odp1 = Application->MessageBoxA("Czy zakoñczyc program?", "", MB_YESNO | MB_ICONQUESTION);
        {
                if(odp1 == IDYES)
                {
                        if(Zmodyfikowany)
                        {
                                int odp = Application->MessageBoxA("Plik zostal zmodyfikowany. Zapisac?", "", MB_YESNOCANCEL | MB_ICONQUESTION);
                                if(odp==IDYES)
                                  Zapisz1Click(Sender);
                                else if(odp==IDCANCEL)
                                       return;
                        }
                Application->Terminate();
                }else if(odp1 == IDNO)
                {
                        Action = caNone;
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Kopiuj1Click(TObject *Sender)
{
        RichEdit1->CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Wytnij1Click(TObject *Sender)
{
        RichEdit1->CutToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Wklej1Click(TObject *Sender)
{
        RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RichEdit1Change(TObject *Sender)
{
        Zmodyfikowany = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Oprogramie1Click(TObject *Sender)
{
        Application->MessageBoxA("Note \nVersion 1.0.0.0 \nby Damian Kie³basa \n2016 \ncopyleft \nAll rights reversed", "O programie", MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Cofnij1Click(TObject *Sender)
{
        RichEdit1->Undo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::U1Click(TObject *Sender)
{
        RichEdit1->SelText = " ";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zaznaczwszystko1Click(TObject *Sender)
{
        RichEdit1->SelectAll();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Cofnij2Click(TObject *Sender)
{
        RichEdit1->Undo();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Kopiuj2Click(TObject *Sender)
{
        RichEdit1->CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Wytnij2Click(TObject *Sender)
{
        RichEdit1->CutToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Wklej2Click(TObject *Sender)
{
        RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Usu1Click(TObject *Sender)
{
        RichEdit1->SelText = " ";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zaznaczwszystko2Click(TObject *Sender)
{
        RichEdit1->SelectAll();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Znajd1Click(TObject *Sender)
{
        FindDialog1->FindText = RichEdit1->SelText;
        FindDialog1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Znajd2Click(TObject *Sender)
{
        FindDialog1->FindText = RichEdit1->SelText;
        FindDialog1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        RichEdit1->SelStart = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Find(TObject *Sender)
{
        TSearchTypes st;
        TFindDialog *cd;
        int newpos;

        if ((cd = dynamic_cast<TFindDialog *> (Sender)) == 0)
            MessageBox(NULL, "B³¹d!", "ZnajdŸ", MB_OK | MB_ICONEXCLAMATION);

        if (cd->Options.Contains(frMatchCase))
            st << stMatchCase;
        //if (cd->Options.Contains(frWholeWord))
            //st << stWholeWord;

        if (RichEdit1->SelLength)
            RichEdit1->SelStart += 1;

        newpos = RichEdit1->FindText(cd->FindText,
                        RichEdit1->SelStart,
                        RichEdit1->Text.Length(),
                        st);

        if (newpos != -1)
        {
                RichEdit1->SelStart = newpos;
                RichEdit1->SelLength = cd->FindText.Length();
        }
        else
        {
                MessageBox(NULL, "Koniec dokumentu.", "ZnajdŸ", MB_OK | MB_ICONINFORMATION);
                RichEdit1->SelStart = 0;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Drukuj1Click(TObject *Sender)
{
        if(PrintDialog1->Execute()) 
        { 
                Printer()->BeginDoc(); // inicjowanie pracy drukarki 
                for(int i = 0; i < RichEdit1->Lines->Count; i++) // drukowanie zawartoœci wszystkich linijek w RichEdit 
                Printer()->Canvas->TextOut(400, 400, RichEdit1->Lines->Strings[i]); // funkcja TextOut pobiera trzy argumenty z których pierwszy okreœla odleg³oœæ drukowanego tekstu od lewego brzegu, a drugi od górnego brzegu kartki, natomiast trzeci parametr to drukowany tekst z RichEdit 
                Printer()->EndDoc(); // koñczenie pracy drukarki 
        } 
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Czcionka1Click(TObject *Sender)
{
        //FontDialog1->Font= RichEdit1->Font;
        if (FontDialog1->Execute())
        {
                RichEdit1->Font->Name = FontDialog1->Font->Name;
                RichEdit1->Font->Color = FontDialog1->Font->Color;
                RichEdit1->Font->Size = FontDialog1->Font->Size;
                RichEdit1->Font->Style = FontDialog1->Font->Style;
        }
        //RichEdit1->SelAttributes->Assign(FontDialog1->Font);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        int odp1 = Application->MessageBoxA("Czy zakoñczyc program?", "", MB_YESNO | MB_ICONQUESTION);
        {
                if(odp1 == IDYES)
                {
                        if(Zmodyfikowany)
                        {
                                int odp = Application->MessageBoxA("Plik zostal zmodyfikowany. Zapisac?", "", MB_YESNOCANCEL | MB_ICONQUESTION);
                                if(odp==IDYES)
                                  Zapisz1Click(Sender);
                                else if(odp==IDCANCEL)
                                       return;
                        }
                Application->Terminate();
                }else if(odp1 == IDNO)
                {
                        Action = caNone;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zawijanietekstu1Click(TObject *Sender)
{
        if(Zawijanietekstu1->Checked==true)
        {
                Zawijanietekstu1->Checked=false;
                RichEdit1->WordWrap=false;
                RichEdit1->ScrollBars=ssBoth;
        }else
        {
                Zawijanietekstu1->Checked=true;
                RichEdit1->WordWrap=true;
                RichEdit1->ScrollBars=ssVertical;
        }
}
//---------------------------------------------------------------------------

