#include "CSmtp.h"
#include <iostream>

int main()
{
	bool bError = false;

	try
	{
		// Mailer Instanz erstellen
		CSmtp mail;

		// SMTP-server und Port setzen
		mail.SetSMTPServer("smtp.web.de", 587);
		/* 
		Verschluesselung auswaehlen:
		NO_SECURITY,
		USE_TLS,
		USE_SSL,
		DO_NOT_SET
		 */
		mail.SetSecurityType(USE_TLS);

		// Benutzername angeben
		mail.SetLogin("afvvsgvfdtherwgk@web.de");
		// Passwort eingeben
		mail.SetPassword("PASSWORT HIER");
		
		// Sendername
		mail.SetSenderName("Max Muster");
		// Senderadresse, meist gleich dem Benutzername
		mail.SetSenderMail("afvvsgvfdtherwgk@web.de");
		// Antwortadresse setzen
		mail.SetReplyTo("afvvsgvfdtherwgk@web.de");
		// Betreff setzen
		mail.SetSubject("Testnachricht MailCpp");

		// Empfaenger hinzuf�gen
		mail.AddRecipient("roland.paltz@gmx.net");

		/*
		Prioritaet setzen. Wird nicht von allen Mailclients behandelt
		XPRIORITY_HIGH,
		XPRIORITY_NORMAL,
		XPRIORITY_LOW
		*/
		mail.SetXPriority(XPRIORITY_NORMAL);

		/*
		Nachricht zeilenweise einfuegen
		*/
		mail.AddMsgLine("Hallo,");
		mail.AddMsgLine("");
		mail.AddMsgLine("Dies ist ein Test.");
		mail.AddMsgLine("Hier folgen noch ein paar weitere Zeilen");
		mail.AddMsgLine("");
		mail.AddMsgLine("Adios");

		/*
		Anhang angeben. Datei wird base64 encoded angehangen. 
		Nur der Dateipfad wird ben�tigt
		*/
		mail.AddAttachment("bitmap1.bmp");

		// Mail senden
		mail.Send();
	}
	catch (ECSmtp e)
	{
		std::cout << "Error: " << e.GetErrorText().c_str() << ".\n";
		bError = true;
	}
	if (!bError)
		std::cout << "Mail was send successfully.\n";
	return 0;
}
