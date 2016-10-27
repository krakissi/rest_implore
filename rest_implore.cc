/*
    rest_implore
    mperron (2016)

    A basic utility for creating HTTP REST API calls. The output can be piped
    into netcat or a similar utility to interact with a remote API.
*/
#include <iostream>
#include <string>
#include <vector>

#include <cstdio>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv){
    bool interactive = isatty(fileno(stdin));

    string str;
    vector<string> headers, body;

    goto accept_headers;
    while(getline(cin, str).good()){
        if(str.length() == 0)
            break;

        headers.push_back(str);

        accept_headers:
        if(interactive)
            cerr << "> ";
    }

    // Use environment var for Host if available.
    string hostname = "nse-rest-ace";
    {
        const char *server = getenv("server");

        if(server)
            hostname.assign(server);
    }

    headers.push_back("Connection: close");
    headers.push_back("Host: " + hostname);

    // Process body.
    if(cin.good()){
        goto accept_body;
        while(getline(cin, str).good()){
            body.push_back(str);

            accept_body:
            if(interactive)
                cerr << "# ";
        }
    }

    if(interactive)
        cerr << endl << "--- --- ---" << endl;

    string text_headers, text_body;

    if(body.size()){
        for(auto a : body)
            text_body.append(a + "\n");

        headers.push_back("Content-Type: application/json");
        headers.push_back("Content-Length: " + to_string(text_body.length() - 1));
    }

    for(auto a : headers)
        text_headers.append(a + "\n");

    // Send request.
    cout << text_headers << endl << text_body;

    return 0;
}
