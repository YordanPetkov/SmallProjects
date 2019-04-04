#include <CkImap.h>

void ChilkatSample(void)
    {
    CkImap imap;

    bool success;

    //  Anything unlocks the component and begins a fully-functional 30-day trial.
    success = imap.UnlockComponent("Anything for 30-day trial");
    if (success != true) {
        std::cout << imap.lastErrorText() << "\r\n";
        return;
    }

    //  Turn on session logging:
    imap.put_KeepSessionLog(true);

    //  Connect to GMail
    //  Use TLS
    imap.put_Ssl(true);
    imap.put_Port(993);
    success = imap.Connect("imap.gmail.com");
    if (success != true) {
        std::cout << imap.lastErrorText() << "\r\n";
        return;
    }

    //  Login
    //  Your login is typically your GMail email address.
    success = imap.Login("username@gmail.com","myPassword");
    if (success != true) {
        std::cout << imap.lastErrorText() << "\r\n";
        return;
    }

    //  Select an IMAP mailbox
    success = imap.SelectMailbox("Inbox");
    if (success != true) {
        std::cout << imap.lastErrorText() << "\r\n";
        return;
    }

    //  Show the session log.
    std::cout << imap.sessionLog() << "\r\n";

    //  Disconnect from the IMAP server.
    success = imap.Disconnect();

    }
