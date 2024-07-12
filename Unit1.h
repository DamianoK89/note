//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include <StdActns.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TRichEdit *RichEdit1;
        TMainMenu *MainMenu1;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TMenuItem *P1;
        TMenuItem *Edycja1;
        TMenuItem *Pomoc1;
        TMenuItem *Oprogramie1;
        TMenuItem *Nowy1;
        TMenuItem *Otwrz1;
        TMenuItem *N1;
        TMenuItem *Zapisz1;
        TMenuItem *Zapiszjako1;
        TMenuItem *N2;
        TMenuItem *Wyj1;
        TMenuItem *Kopiuj1;
        TMenuItem *Wytnij1;
        TMenuItem *Wklej1;
        TMenuItem *U1;
        TMenuItem *N3;
        TMenuItem *Cofnij1;
        TMenuItem *N4;
        TMenuItem *Znajd1;
        TMenuItem *N5;
        TMenuItem *Zaznaczwszystko1;
        TPopupMenu *PopupMenu1;
        TMenuItem *Cofnij2;
        TMenuItem *N6;
        TMenuItem *Kopiuj2;
        TMenuItem *Wytnij2;
        TMenuItem *Wklej2;
        TMenuItem *Usu1;
        TMenuItem *N7;
        TMenuItem *Zaznaczwszystko2;
        TMenuItem *N8;
        TMenuItem *Znajd2;
        TFindDialog *FindDialog1;
        TPrintDialog *PrintDialog1;
        TMenuItem *Drukuj1;
        TMenuItem *N9;
        TMenuItem *Format1;
        TMenuItem *Czcionka1;
        TFontDialog *FontDialog1;
        TMenuItem *Zawijanietekstu1;
        void __fastcall Nowy1Click(TObject *Sender);
        void __fastcall Otwrz1Click(TObject *Sender);
        void __fastcall Zapisz1Click(TObject *Sender);
        void __fastcall Zapiszjako1Click(TObject *Sender);
        void __fastcall Wyj1Click(TObject *Sender);
        void __fastcall Kopiuj1Click(TObject *Sender);
        void __fastcall Wytnij1Click(TObject *Sender);
        void __fastcall Wklej1Click(TObject *Sender);
        void __fastcall RichEdit1Change(TObject *Sender);
        void __fastcall Oprogramie1Click(TObject *Sender);
        void __fastcall Cofnij1Click(TObject *Sender);
        void __fastcall U1Click(TObject *Sender);
        void __fastcall Zaznaczwszystko1Click(TObject *Sender);
        void __fastcall Cofnij2Click(TObject *Sender);
        void __fastcall Kopiuj2Click(TObject *Sender);
        void __fastcall Wytnij2Click(TObject *Sender);
        void __fastcall Wklej2Click(TObject *Sender);
        void __fastcall Usu1Click(TObject *Sender);
        void __fastcall Zaznaczwszystko2Click(TObject *Sender);
        void __fastcall Znajd1Click(TObject *Sender);
        void __fastcall Znajd2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Find(TObject *Sender);
        void __fastcall Drukuj1Click(TObject *Sender);
        void __fastcall Czcionka1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Zawijanietekstu1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        AnsiString NazwaPliku;
        bool Zmodyfikowany;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
