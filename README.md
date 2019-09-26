# MailCpp

Versendet Mails aus einem CPP-Programm. 

Verwendet OpenSSL für den SSL/TLS-Support. Die Abhängigkeit sollte per NuGet automatisch installiert werden. Das verwendete Package ist dabei [openssl-vc140-static-32_64](https://www.nuget.org/packages/openssl-vc140-static-32_64/), derzeit in Version 1.1.1.1

Verwendet standard WinSockets per TCP. SMTP-Code basiert auf [CSmtp v2.4](https://www.codeproject.com/Articles/98355/SMTP-Client-with-SSL-TLS). Alle veralteten Funktionen wurden durch die entsprechenden neuen Funktionen ausgetauscht. Das Projekt kann sowohl in 32 als auch 64 Bit kompiliert werden.

Das Programm läuft in der Console und sendet eine Testmail an die angegebene Adresse. Die Mail, sowie Absender und Empfänger können in der Datei MailCpp.cpp editiert werden.
