#include "CSmtp.h"
#include <iostream>

int main()
{
	bool bError = false;

	try
	{
		CSmtp mail;

		mail.SetSMTPServer("smtp.gmx.net", 587);
		mail.SetSecurityType(USE_TLS);

		mail.SetLogin("roland.paltz@gmx.net");
		mail.SetPassword("pass");
		mail.SetSenderName("User");
		mail.SetSenderMail("roland.paltz@gmx.net");
		mail.SetReplyTo("roland.paltz@gmx.net");
		mail.SetSubject("The message");
		mail.AddRecipient("roland.paltz@gmx.net");
		mail.SetXPriority(XPRIORITY_NORMAL);
		//mail.SetXMailer("The Bat! (v3.02) Professional");
		mail.AddMsgLine("Hello,");
		mail.AddMsgLine("");
		mail.AddMsgLine("...");
		mail.AddMsgLine("How are you today?");
		mail.AddMsgLine("");
		mail.AddMsgLine("Regards");

		mail.AddAttachment("bitmap1.bmp");
		//mail.AddAttachment("c:\\test2.exe");
		//mail.AddAttachment("c:\\test3.txt");
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
